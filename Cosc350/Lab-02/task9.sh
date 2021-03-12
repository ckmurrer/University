#!/bin/sh
#task9.sh

echo "Please enter a directory Path"
read dirInput
# checks if there is a valid directory
if [ -d $dirInput ]; then
    counter=0
# loops the amount of times allowed to search for a file
    while [ $counter -lt 3 ]; do
        counter=`expr $counter + 1`
        echo "Please enter the name of a readable file"
        read filInput
# checks if the number of failed attempts exceeds allowed amount        
        if [ $counter -eq 3 ]; then
            echo "Attempts to find file exceeded"
            exit 2
# checks if there is a readable file within the directory            
        elif [ -e "$dirInput/$filInput" ] && [ -r "$dirInput/$filInput" ]; then
            echo "Please enter the word you are searching for"
            read worInput
            isThere=$(grep -c $worInput "$dirInput/$filInput")
# checks if grep found at least one instance of the users word
            if [ $isThere -gt 0 ]; then
                echo "$worInput FOUND!"
                exit 0
            else
                echo "$worInput NOT FOUND"
                exit 4
            fi
# checks if the file exists within the directory is not readable              
        elif [ -e "$dirInput/$filInput" ] && [ ! -r $filInput ]; then
                echo "File is not readable"
                exit 3
        else 
            echo "File not found"
        fi
    done
else
    echo "Directory not found"
    exit 1
fi
exit 0