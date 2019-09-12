#!/bin/bash
g++ gen.cpp -o gen
g++ brute.cpp -o brute -O2
./gen>input
time ./a.out<input>output
echo my
time ./brute<input>answer
echo std
diff answer output -w -B
