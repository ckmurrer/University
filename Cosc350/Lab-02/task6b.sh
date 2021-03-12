#!/bin/sh
#task6b.sh

echo "Please input an odd number greater than or equal to three for the base:";
read userInput;
echo "Please specify the legnth of the tail:";
read userTail;

# data validation checks if the base even or not then checks if its greater than 3
if [ `expr $userInput % 2` -eq 0 ]; then
    echo "input was not an odd number"
    exit 1
elif [ $userInput -lt 3 ]; then
    echo "input was not greater than or equal to 3"
    exit 1
else
    botTriangle=`expr $userInput - 2`
# top triangle rows for loop incrementing by 2 to userInput
    for i in `seq 1 2 $userInput`; do
        echo
# top triangle spacing for right aligned        
            for k in `seq $i $userInput`; do
                echo -n " "
            done
# top triangle asterisks shape from 1 to i
        for j in `seq 1 $i`; do
            echo -n "*"
        done
    done 
# for loop that sets the tail after the top triangle had finished
    for m in `seq 1 $userTail`; do
        echo -n "*"
    done
    echo
# bottom triangle rows for loop decrementing by 2 to userInput-2    
    for i in `seq $botTriangle -2 1`; do
# bottom triangle spacing for right aligned    
        for k in `seq $userInput -1 $i`; do
            echo -n " "
        done
# bottom triangle asterisks shape from 1 to i        
        for j in `seq 1 $i`; do
            echo -n "*"
        done
        echo
    done
fi
exit 0