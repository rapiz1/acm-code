#!/bin/bash
g++ brute.cpp -o brute -O2
g++ gen.cpp -o gen
./gen>cdcq_a.in
./a.out<cdcq_a.in>output
./brute<cdcq_a.in>answer
diff output answer -w -B
