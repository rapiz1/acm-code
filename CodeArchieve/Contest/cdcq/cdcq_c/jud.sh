#!/bin/bash
#g++ brute.cpp -o brute -O2
g++ gen.cpp -o gen
./gen>cdcq_c.in
./a.out<cdcq_c.in
#./brute<cdcq_c.in>answer
#diff output answer -w -B
