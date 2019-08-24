#!/bin/bash
python tree.py>in
./a.out<in
echo ""
./brute<in
