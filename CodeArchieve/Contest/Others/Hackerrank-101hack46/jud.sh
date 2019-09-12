#!/bin/bash
g++ gen.cpp -o gen
g++ brute.cpp -o brute -O2
./gen>input
./brute<input>answer
./a.out<input>output
diff answer output --brief
