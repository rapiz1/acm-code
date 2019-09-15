#!/bin/bash

find . -name output|xargs rm
find . -name input|xargs rm
find . -name "*.out"|xargs rm
find . -name "*.in"|xargs rm
find . -name "*.ans"|xargs rm
find . -name gen|xargs rm
find . -name std|xargs rm
find . -name brute|xargs rm
find . -name "gen.cpp"|xargs rm
find . -name "brute.cpp"|xargs rm
find . -name "std.cpp"|xargs rm
