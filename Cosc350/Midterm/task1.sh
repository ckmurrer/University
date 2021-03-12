#!/bin/sh
#task1.sh

sum=0
for i in $@; do
    if [ `expr $i % 2` != 0 ]; then
        sum=`expr $i + $sum`
    fi
done
echo "The sum of the odd arguments are: $sum"
exit 0 