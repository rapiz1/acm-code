#!/bin/bash
while [[ $? -eq 0 ]]
do
  echo pass
  python gen.py > input
  ./a.out<input>output
  ./std<input>answer
  diff output answer -w
done
