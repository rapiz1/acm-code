#!/bin/bash
g++ 4.cxx -o 4.out -g
g++ 4-brute.cxx -o 4-brute.out -g
echo start
while [[ $? -eq 0 ]]
do
	echo new round
	python gen.py > data.in
	./4.out < data.in > data-4.out
	./4-brute.out < data.in > data-4-brute.out
	diff -q data-4.out data-4-brute.out
done
