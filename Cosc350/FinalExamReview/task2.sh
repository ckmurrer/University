# Write a bash script which takes a sequence of integers as arguments
# and calculates the multiplication of integers and displays the results
# Ex. ./mult.sh 1 2 3 4

#!/bin/bash

let sum=1

if [ $# -eq 0 ]; then
    echo "No arguments passed";
    exit 0;
fi

for x in $*
do
	let sum=$sum*$x
done
echo "multiplication of arguments is $sum";
exit 0;
