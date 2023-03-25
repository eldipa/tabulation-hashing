import sys

for line in sys.stdin:
    name, remain = line.split(",", 1)
    assert name.startswith("results_cache")

    # results_cache_32_32_12_f_1_32768_8_run_402511
    _, _, ibits, hbits, order, himpl, blen, csz, casso, _, _ = name.split("_")

    table = f"{ibits}-{hbits}"

    print(table, order, himpl, blen, csz, casso, remain, sep=',', end="")

