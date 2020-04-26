.PHONY: all serial parallel clean 

all: serial parallel

serial: matrix_serial.c
	gcc -o matrix_serial matrix_serial.c
	touch serial_timings.csv

parallel: matrix_parallel.c
	gcc −g −Wall −fopenmp −o matrix_parallel matrix_parallel.c
	touch parallel_timings.csv

clean:
	rm matrix_serial serial_timings.csv matrix_parallel parallel_timings.csv