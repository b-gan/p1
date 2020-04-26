#!/bin/sh

STARTING='SetUP,MatrixMult';
echo ${STARTING} > serial_timings.csv
echo ${STARTING} > parallel_timings.csv
for i in {1..1000} #this is for matrix size
do
    ./matrix_serial $i >> serial_timings.csv
    ./matrix_parallel $i 4 >> parallel_timings.csv
done
