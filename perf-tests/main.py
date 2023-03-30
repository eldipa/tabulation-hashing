from tabulationhashing.tabulationhashing import TabulationHashing
import numpy as np

import sys, time, os

try:
    input_bits, hash_bits, dataset_len_order= map(int, sys.argv[1:4])
    himpl = sys.argv[4]
    batch_len = int(sys.argv[5])
except:
    print("Bad arguments")
    print("Usage: perf.py <input_bits> <hash_bits> <dataset_len_order> <himpl> <batch_len>")
    sys.exit(1)

assert himpl in ('f', 'b', 'l')
assert (himpl == 'b' and batch_len > 0) or (himpl in ('f', 'l') and batch_len == 0)

dataset_len = 1 << dataset_len_order

if himpl == 'l':
    print(f"Linear Hashing {input_bits}-{hash_bits}", file=sys.stderr)
    random_state = np.random.RandomState(0)
    A = np.full(
            shape=(dataset_len),
            fill_value=random_state.randint(0, (2**hash_bits)-1),
            dtype=(np.uint32 if hash_bits == 32 else np.uint64),
            )

    B = np.full(
            shape=(dataset_len),
            fill_value=random_state.randint(0, (2**hash_bits)-1),
            dtype=(np.uint32 if hash_bits == 32 else np.uint64),
            )
else:
    print(f"TabulationHashing {input_bits}-{hash_bits}", file=sys.stderr)
    thashing = TabulationHashing(input_bits, hash_bits, 0, batch_len=batch_len)

print(f"Generating {dataset_len} (2^{dataset_len_order}) numbers", file=sys.stderr)
random_state = np.random.RandomState(31416)
xvec = random_state.randint(
        0,
        (2**input_bits)-1,
        size=dataset_len,
        dtype=(np.uint32 if input_bits == 32 else np.uint64)
        )

out = np.empty_like(xvec, dtype=(np.uint32 if hash_bits == 32 else np.uint64))


CPU = int(os.getenv('CPU', 0))
print(f"CPU affinity to CPU {CPU}", file=sys.stderr)
os.sched_setaffinity(0, {CPU})

print(f"Computing the hashes", file=sys.stderr)
elapsed_times = []
for _ in range(2048):
    dummy = random_state.randint(
            0,
            2**31,
            size=1<<20,
            dtype=np.uint32
            )

    del dummy

    if himpl == 'l':
        t = time.monotonic_ns()
        out = (xvec * A) + B
        elapsed = time.monotonic_ns() - t
    else:
        t = time.monotonic_ns()
        out = thashing.hash_vec(xvec, out)
        elapsed = time.monotonic_ns() - t

    assert out.shape == (dataset_len,)
    assert out.dtype == (np.uint32 if hash_bits == 32 else np.uint64)
    elapsed_times.append(elapsed)

table_name = f"{input_bits}-{hash_bits}"
for elapsed in elapsed_times:
    print(table_name, dataset_len_order, himpl, batch_len, elapsed, sep=',')
