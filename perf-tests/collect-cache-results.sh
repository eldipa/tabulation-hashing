#!/usr/bin/bash

set -eo pipefail

if [ "$1" = "" ]; then
    exit 1
fi

RUN=$1
DST=cache-results-run-$RUN.csv

echo 'table,order,himpl,blen,cache_sz,cache_asso,Dr,D1mr,Dw,D1mw' > $DST

for fname in $(ls -1 results_cache_*_run_$RUN*); do
    cg_annotate \
        --show-percs=no \
        --threshold=0   \
        --show=Dr,D1mr,Dw,D1mw \
        $fname |  sed 's/,//g' | awk -v FOO=$fname '/hash_impl[.]c:hash_vec/ {print FOO "," $1 "," $2 "," $3 "," $4}'
done | python build-csv-from-cache-results.py >> $DST
