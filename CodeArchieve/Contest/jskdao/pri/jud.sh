#!/bin/bash
g++ gen.cpp -O2 -o gen
g++ st.cpp -o b.out -O2
g++ a.cpp
./gen>input
echo ss
time ./b.out>std
echo std
time ./a.out>my
echo my
diff my std
