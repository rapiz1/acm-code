#!/bin/sh
for((i=0;i<100;i++)){
./gen
./a.out<input>output
./checker | grep 0
echo $i done
}
