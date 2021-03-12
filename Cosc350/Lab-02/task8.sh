#!/bin/sh
#task8.sh

count=0
for i in $@; do
    count=`expr $count + 1`
    if [ $count -gt 1 ]; then
        echo "Please only input one argument"
        exit 1
    fi
    if [ $count -eq 1 ]; then
        number=$1
        sum=0
        while [ $number -gt 0 ]; do
            remainder=`expr $number % 10`
            number=`expr $number / 10`
            sum=`expr $sum + $remainder`
        done
        echo "The sum is: $sum"
        exit 1
    fi
done
exit 0