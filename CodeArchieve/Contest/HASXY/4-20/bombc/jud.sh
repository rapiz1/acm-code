#!/bin/bash
g++ gen.cpp -o gen
g++ brute.cpp -o brute -O2
./gen>bombc.in
./brute
./a.out
diff bombc.ans bombc.out
