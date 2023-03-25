#!/usr/bin/bash

set -eo pipefail

if [ "$1" = "" ]; then
    exit 1
fi

RUN=$1
DST=runtime-results-run-$RUN.csv

echo 'table,order,himpl,blen,timens' > $DST
cat $(ls -1 results_runtime_*_run_$RUN*) >> $DST
