#include "hash_impl.h"
#include <stdio.h>
#include <stdlib.h>


// Fill the buffer of the given size (in bytes) with random
// numbers
void fillrandom(char* buf, uint32_t sz, int seed) {
    srandom(seed);
    for (uint32_t i = 0; i < (sz / 4); i++) {
        ((uint32_t*) buf)[i] = random();
    }
}

void alloc_cache_line_aligned(size_t min_sz, char** ptr, char** aligned) {
    *ptr = malloc(min_sz + 63);
    *aligned = (char*) (((uintptr_t)(*ptr) + 63) & (~(uintptr_t)63));
}

int main(int argc, char* argv[]) {
    // Bad call
    int ret = -1;

    if (argc != 6) {
        printf("Bad arguments\nUsage: perf.py <input_bits> <hash_bits> <dataset_len_order> <hash_impl> <batch_len>\n");
        goto bad_prog_call;
    }

    // Parameter validation
    ret = -2;

    uint32_t input_bits = atoi(argv[1]);
    uint32_t hash_bits = atoi(argv[2]);
    uint32_t dataset_len_order = atoi(argv[3]);
    char hash_impl = argv[4][0];
    uint32_t batch_len = atoi(argv[5]);

    if (input_bits != 32 && input_bits != 64) {
        printf("Bad input_bits\n");
        goto bad_parameter;
    }

    if (hash_bits != 32 && hash_bits != 64) {
        printf("Bad hash_bits\n");
        goto bad_parameter;
    }

    if (batch_len <= 0) {
        printf("Bad batch_len\n");
        goto bad_parameter;
    }

    if (dataset_len_order > 30 || dataset_len_order == 0) {
        printf("Bad dataset_len_order\n");
        goto bad_parameter;
    }

    if (hash_impl != 'f' && hash_impl != 'b') {
        printf("Bad hash_impl\n");
        goto bad_parameter;
    }

    // Define dataset len
    uint32_t dataset_len = 1 << dataset_len_order;

    // Calc input/hash vector element size
    size_t input_dtype_sz = (input_bits==32? sizeof(uint32_t) : sizeof(uint64_t));
    size_t hash_dtype_sz = (hash_bits==32? sizeof(uint32_t) : sizeof(uint64_t));

    // Table rows count
    size_t nrows = (input_bits==32? 4 : 8);

    char *aligned;

    // Alloc table
    uint32_t table_mem_sz = 256 * nrows * hash_dtype_sz;
    char *table;
    alloc_cache_line_aligned(table_mem_sz, &table, &aligned);
    if (table == NULL) {
        goto bad_alloc_table;
    }

    memviewslice table_view = {aligned, {table_mem_sz / hash_dtype_sz}};

    // Alloc xvec (input vector)
    uint32_t xvec_mem_sz = dataset_len * input_dtype_sz;
    char* xvec;
    alloc_cache_line_aligned(xvec_mem_sz, &xvec, &aligned);
    if (xvec == NULL) {
        goto bad_alloc_xvec;
    }

    memviewslice xvec_view = {aligned, {xvec_mem_sz / input_dtype_sz}};

    // Alloc hash vector
    uint32_t hvec_mem_sz = dataset_len * hash_dtype_sz;
    char* hvec;
    alloc_cache_line_aligned(hvec_mem_sz, &hvec, &aligned);
    if (hvec == NULL) {
        goto bad_alloc_out;
    }

    memviewslice hvec_view = {aligned, {hvec_mem_sz / hash_dtype_sz}};


    // Initialize the table
    fillrandom(table_view.data, table_mem_sz, 0);

    // Initialize the input vector
    fillrandom(xvec_view.data, xvec_mem_sz, 31416);


    // Alloc, read and write a bunch of data to populate the cache
    // with dummy entries.
    // If we don't do this, we may see cache hits during the hash computation
    // because we put them there during the initialization, not because
    // the hash func is doing something cleaver.
    //
    // Assume a 1MB L1 cache.
    void* dummy = malloc(1 << 20);
    if (dummy == NULL) {
        goto bad_alloc_dummy;
    }
    fillrandom(dummy, 1 << 20, 42);
    free(dummy);

    // Compute the hash using the selected tabulation hashing implementation
    switch (hash_impl) {
        case 'b': // batch
            switch ((input_bits << 8) + hash_bits) {
                case (32 << 8) + 32:
                    hash_vec_batch_32_32(NULL, xvec_view, table_view, hvec_view, batch_len);
                    break;
                case (64 << 8) + 32:
                    hash_vec_batch_64_32(NULL, xvec_view, table_view, hvec_view, batch_len);
                    break;
                case (32 << 8) + 64:
                    hash_vec_batch_32_64(NULL, xvec_view, table_view, hvec_view, batch_len);
                    break;
                case (64 << 8) + 64:
                    hash_vec_batch_64_64(NULL, xvec_view, table_view, hvec_view, batch_len);
                    break;
                default:
                    printf("unexpected hash_impl cfg\n");
            }

            break;
        case 'f': // full
            switch ((input_bits << 8) + hash_bits) {
                case (32 << 8) + 32:
                    hash_vec_full_32_32(NULL, xvec_view, table_view, hvec_view);
                    break;
                case (64 << 8) + 32:
                    hash_vec_full_64_32(NULL, xvec_view, table_view, hvec_view);
                    break;
                case (32 << 8) + 64:
                    hash_vec_full_32_64(NULL, xvec_view, table_view, hvec_view);
                    break;
                case (64 << 8) + 64:
                    hash_vec_full_64_64(NULL, xvec_view, table_view, hvec_view);
                    break;
                default:
                    printf("unexpected hash_impl cfg\n");
            }
            break;
        default:
            printf("unexpected hash_impl\n");
    }

    // Good bye
    ret = 0;

bad_alloc_dummy:
    free(hvec);
bad_alloc_out:
    free(xvec);
bad_alloc_xvec:
    free(table);
bad_alloc_table:
bad_parameter:
bad_prog_call:
    return ret;
}
