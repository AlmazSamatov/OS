#!/bin/bash

if [ ! -f num ]; then
echo 0 > num
fi

n=$( tail -n 1 num )
n=$((n+1))
echo $n >> num
