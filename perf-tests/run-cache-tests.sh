#!/usr/bin/bash
set -eo pipefail

run=$$

cachetest () {
    input_bits=$1
    hash_bits=$2
    dataset_len_order=$3
    hash_impl=$4
    batch_len=$5
    cache_sz=$6
    cache_asso=$7
    cache_asso_valgrind=$7

    # simulate fully-associative
    if [ "$cache_asso" = "0" ]; then
        cache_asso_valgrind=$(( $cache_sz / 64 ))
    fi

    valgrind \
        --tool=cachegrind  \
        --D1=${cache_sz},${cache_asso_valgrind},64     \
        --cachegrind-out-file=results_cache_${input_bits}_${hash_bits}_${dataset_len_order}_${hash_impl}_${batch_len}_${cache_sz}_${cache_asso}_run_${run} \
        ./main ${input_bits} ${hash_bits} ${dataset_len_order} ${hash_impl} ${batch_len}

}

echo "RUN: $run"
# See how 'full' performs when there is room in the cache
# for a 32x32 table
#
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 32   32   12    f       1   32768     0
cachetest 32   32   16    f       1   32768     0
cachetest 32   32   20    f       1   32768     0
cachetest 32   32   22    f       1   32768     0

# Same but for a 64x64 table
#
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    f       1   32768     0
cachetest 64   64   16    f       1   32768     0
cachetest 64   64   20    f       1   32768     0
cachetest 64   64   22    f       1   32768     0

# Same but for a 64x64 table using a 'batch' impl
#
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b       1   32768     0
cachetest 64   64   16    b       1   32768     0
cachetest 64   64   20    b       1   32768     0
cachetest 64   64   22    b       1   32768     0


# See how 'full' performs when the cache is too small
# for a 64x64 table
#
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    f       1   16384     0
cachetest 64   64   16    f       1   16384     0
cachetest 64   64   20    f       1   16384     0
cachetest 64   64   22    f       1   16384     0

# Same table but with a 'batch' impl
# batch = 1
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b       1   16384     0
cachetest 64   64   16    b       1   16384     0
cachetest 64   64   20    b       1   16384     0
cachetest 64   64   22    b       1   16384     0

# batch = 4
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b       4   16384     0
cachetest 64   64   16    b       4   16384     0
cachetest 64   64   20    b       4   16384     0
cachetest 64   64   22    b       4   16384     0

# batch = 8
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b       8   16384     0
cachetest 64   64   16    b       8   16384     0
cachetest 64   64   20    b       8   16384     0
cachetest 64   64   22    b       8   16384     0

# batch = 16
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b      16   16384     0
cachetest 64   64   16    b      16   16384     0
cachetest 64   64   20    b      16   16384     0
cachetest 64   64   22    b      16   16384     0

# batch = 32
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b      32   16384     0
cachetest 64   64   16    b      32   16384     0
cachetest 64   64   20    b      32   16384     0
cachetest 64   64   22    b      32   16384     0

# batch = 64
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b      64   16384     0
cachetest 64   64   16    b      64   16384     0
cachetest 64   64   20    b      64   16384     0
cachetest 64   64   22    b      64   16384     0


# On 64-64 table with 16k cache with 8-way assoc
# see how the himpl behave in a more "real" cache
#
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    f       1   16384     8
cachetest 64   64   16    f       1   16384     8
cachetest 64   64   20    f       1   16384     8
cachetest 64   64   22    f       1   16384     8

# batch = 1
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b       1   16384     8
cachetest 64   64   16    b       1   16384     8
cachetest 64   64   20    b       1   16384     8
cachetest 64   64   22    b       1   16384     8

# batch = 4
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b       4   16384     8
cachetest 64   64   16    b       4   16384     8
cachetest 64   64   20    b       4   16384     8
cachetest 64   64   22    b       4   16384     8

# batch = 8
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b       8   16384     8
cachetest 64   64   16    b       8   16384     8
cachetest 64   64   20    b       8   16384     8
cachetest 64   64   22    b       8   16384     8

# batch = 16
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b      16   16384     8
cachetest 64   64   16    b      16   16384     8
cachetest 64   64   20    b      16   16384     8
cachetest 64   64   22    b      16   16384     8

# batch = 32
#                                    |--- cache ---|
#       input hash  ord  impl batch     sz     asso
cachetest 64   64   12    b      32   16384     8
cachetest 64   64   16    b      32   16384     8
cachetest 64   64   20    b      32   16384     8
cachetest 64   64   22    b      32   16384     8


echo "Collecting results for run $run"
./collect-cache-results.sh $run
