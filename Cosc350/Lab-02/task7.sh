#!/bin/sh
#task7.sh

echo "Please input an integer to find its factorial:"
read factInput
echo "$factInput's factorial is"
x=1

while [ $factInput -gt 1 ];do
    x=`expr $x \* $factInput`
    factInput=`expr $factInput - 1`
done
echo $x
exit 0