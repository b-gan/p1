#!/bin/sh

STARTING='SetUP,MatrixMult';
echo ${STARTING} > serial_timings.csv
echo ${STARTING} > parallel_timings.csv
for i in {1..1000} #this is for matrix size
do
    ./matrix_serial $i >> serial_timings.csv
    ./matrix_parallel $i 4 >> parallel_timings.csv  #4 for the 4 threads
for i in {1..3}
do  
	python create_memconfig.py 4 0 0  

done

#num cpu, num gpu, gpu type, num of MC, L1 inst shared, L1 size, L1 assoc, L2 size, L2 assoc
# L1 latency (10), L2 latency, L1 block size, L2 block size, Memory Latency, GPU L1 Size
# GPU L1 assoc (16), GPU L2 size, GPU L2 assoc, L1 latency, L2 latency, L1 blocksize, L2 blocksize (22)
