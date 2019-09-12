#!/bin/bash
g++ gen.cpp -o gen
g++ std.cpp -o std -O2
./gen>input
time ./a.out<input>output
echo my
time ./std<input>answer
echo std
diff answer output
