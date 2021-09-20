#!/bin/bash

find . -name output -delete
find . -name input -delete
find . -name "*.out" -delete
find . -name "*.in" -delete
find . -name "*.ans" -delete
find . -name gen -delete
find . -name std -delete
find . -name brute -delete
find . -name "gen.cpp" -delete
find . -name "brute.cpp" -delete
find . -name "std.cpp" -delete
#find -type f -atime +1 -exec sh -c 'file "{}" | grep ELF > /dev/null' \; -delete
