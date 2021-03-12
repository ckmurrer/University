#!/bin/sh
#task6a.sh

echo "Please input an odd number greater than or equal to three:";
read userInput;

if [ `expr $userInput % 2` -eq 0 ]; then
    echo "input was not an odd number"
    exit 1
elif [ $userInput -lt 3 ]; then
    echo "input was not greater than or equal to 3"
    exit 1
else
    echo
    bottomDiamond=`expr $userInput - 2`
    for i in `seq 1 2 $userInput`; do
        for k in `seq $i 2 $userInput`; do
            echo -n " " 
        done
        for j in `seq 1 $i`; do
            echo -n "*"
        done
        echo
    done 
    
   	for i in `seq  $bottomDiamond -2 1`; do
		for k in `seq $userInput -2 $i`; do
			echo -n " "
		done
		for j in `seq 1 $i`; do
			echo -n "*"
		done
		echo
    done
    exit 1
fi

exit 0