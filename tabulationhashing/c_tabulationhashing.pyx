from libc.stdint cimport uint32_t, uint64_t
import cython


# We support uint32_t and uint64_t input and output (hashes)
# without much trouble.
# However take into account that the count of functions generated and compiled
# will be the cross product of these fused types and the functions.
#
# With 2 functions (hash and hash_vec), 2 input types (uint32_t, uint64_t)
# and 2 output/hashes types (uint32_t, uint64_t) we will end up with
# 2x2x2 = 8 functions in total
ctypedef fused hash_dtype:
    uint32_t
    uint64_t

ctypedef fused input_dtype:
    uint32_t
    uint64_t


@cython.boundscheck(False)
@cython.wraparound(False)
@cython.infer_types(True)
def hash_x(input_dtype x, hash_dtype[::1] table):
    cdef:
        hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7
        input_dtype x0, x1, x2, x3, x4, x5, x6, x7

    x0 = x & 0x000000ff
    x1 = (x >> 8) & 0x000000ff
    x2 = (x >> 16) & 0x000000ff
    x3 = (x >> 24) & 0x000000ff

    # Note: table is assumed to be C-contiguous array of
    # 256 x 4 hash_dtype numbers. This is declared in the
    # function signature as 'hash_dtype[::1]'
    # With this, we can avoid the multiplication required
    # manage non-one strides (aka non-contiguous arrays)
    h0 = table[x0]
    h1 = table[x1 + 256]
    h2 = table[x2 + 256 * 2]
    h3 = table[x3 + 256 * 3]

    h = h0 ^ h1 ^ h2 ^ h3

    if input_dtype is uint64_t:
        x4 = (x >> 32) & 0x000000ff
        x5 = (x >> 40) & 0x000000ff
        x6 = (x >> 48) & 0x000000ff
        x7 = (x >> 56) & 0x000000ff

        h4 = table[x4 + 256 * 4]
        h5 = table[x5 + 256 * 5]
        h6 = table[x6 + 256 * 6]
        h7 = table[x7 + 256 * 7]

        h ^= h4 ^ h5 ^ h6 ^ h7

    return h


# Note: out must be zeroed before calling hash_vec
@cython.boundscheck(False)
@cython.wraparound(False)
@cython.infer_types(True)
@cython.cdivision(True)
def hash_vec(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out, uint32_t batch_len):
    cdef:
        hash_dtype hi
        input_dtype x, xi

        uint32_t batch_start = 0, batch_end = batch_len, vec_size = xvec.shape[0]
        uint32_t row, shift, rebase
        uint32_t nrows

    # This 'if' will disappear after the compilation by Cython
    # and the number of rows should be propagated (no variable at all)
    # by the C compiler
    if input_dtype is uint32_t:
        nrows = 4
    elif input_dtype is uint64_t:
        nrows = 8
    else:
        assert False

    # Calculate the position of the last "complete" batch
    # We'll handle the (possible) last incomplete batch later
    last_batch_end = vec_size - (vec_size % batch_len)

    # Disable the GIL as this loop will not interact with the Python VM
    with nogil:
        # Perform 2 rounds:
        #   - the first round will process all the complete lines
        #   - the second round will process the last incomplete batch, if any
        while (1):
            # Hash the input vector by batches.
            # The idea is that a batch of the input vector, output vector and tables
            # will be in the cache avoiding unnecessary memory accesses inside
            # the inner loops.
            # Once the particular batch finishes, the while-loop iterates again
            # and issue up to 6 memory accesses (1 for the input vector, 1 for the output
            # vector and 4 for the 4-rows table) and the cycle starts again
            #
            # Note: cython cannot handle range-loops with steps unknown in compile-time
            # See https://github.com/cython/cython/issues/1106
            while batch_start < last_batch_end:
                # The C compiler should be smart enough to unroll this for loop
                # as nrows is known in compilation type and
                # it is quite small (4 o 8)
                #
                # With this for we should have in cache only 1 table row at time
                # plus the batch of input and output vectors
                for row in range(0, nrows):
                    shift = row * 8
                    rebase = row * 256
                    for i in range(batch_start, batch_end):
                        x = xvec[i]

                        xi = (x >> shift) & 0x000000ff
                        hi = table[xi + rebase]

                        out[i] ^= hi

                batch_start = batch_end
                batch_end += batch_len

            # Last, probably partial batch. This even handles the case that
            # the input vector is smaller than a single
            #
            # Note: batch_start should be set to last_batch_end by now
            # so if there is another partial batch to hash, update last_batch_end
            # and batch_end too
            batch_end = batch_start + (vec_size - batch_start)
            last_batch_end = batch_end

            # If the last batch is complete it means that it was already
            # processed it in the previous iteration (first round) and
            # we can finish, otherwise do a second round
            #
            # With this trick we have 1 branch check (aka if) per batch
            # (well technically more due the for loops)
            if batch_start == batch_end:
                break
