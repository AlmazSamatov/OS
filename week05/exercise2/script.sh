#!/bin/bash

if [ ! -f num ]; then
echo 0 > num
fi

counter = 0

while [ $counter -le 2000 ]
do
counter='expr $counter + 1'
sleep 0.2
n = 'tail -1 num'
expr $n + 1 >> num
done

