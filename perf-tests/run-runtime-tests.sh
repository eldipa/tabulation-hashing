#!/usr/bin/bash
set -eo pipefail

run=$$

perfest () {
    input_bits=$1
    hash_bits=$2
    dataset_len_order=$3
    hash_impl=$4
    batch_len=$5

    python main.py ${input_bits} ${hash_bits} ${dataset_len_order} ${hash_impl} ${batch_len} > \
        results_runtime_${input_bits}_${hash_bits}_${dataset_len_order}_${hash_impl}_${batch_len}_run_${run}

}

echo "RUN: $run"

perfest 32   32   12    f       0
perfest 32   32   16    f       0
perfest 32   32   20    f       0
perfest 32   32   22    f       0

perfest 64   64   12    f       0
perfest 64   64   16    f       0
perfest 64   64   20    f       0
perfest 64   64   22    f       0

perfest 64   64   12    b       1
perfest 64   64   16    b       1
perfest 64   64   20    b       1
perfest 64   64   22    b       1

perfest 64   64   12    b       4
perfest 64   64   16    b       4
perfest 64   64   20    b       4
perfest 64   64   22    b       4

perfest 64   64   12    b       8
perfest 64   64   16    b       8
perfest 64   64   20    b       8
perfest 64   64   22    b       8

perfest 64   64   12    b      16
perfest 64   64   16    b      16
perfest 64   64   20    b      16
perfest 64   64   22    b      16

perfest 64   64   12    b      32
perfest 64   64   16    b      32
perfest 64   64   20    b      32
perfest 64   64   22    b      32

./collect-runtime-results.sh $run
