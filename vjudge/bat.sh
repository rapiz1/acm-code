#!/bin/bash
while [[ $? -eq 0 ]]
do
  echo pass
  python gen.py > input
  echo my
  time ./a.out<input>output
  echo brute
  time ./brute<input>answer
  diff output answer -w
done
