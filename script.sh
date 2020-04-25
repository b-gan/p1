#!/bin/sh

STARTING='SetUP,MatrixMult';
echo ${STARTING} > serial_timings.csv
echo ${STARTING} > parallel_timings.csv
for i in {1..1000}
do
    ./matrix_serial $i >> serial_timings.csv
    ./matrix_parallel $i >> parallel_timings.csv
done
