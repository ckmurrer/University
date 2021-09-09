Cody Murrer
Cosc 420 High-Performance Computing
9/8/21

This lab was given with the intentions to introduce us as students to the basics of OpenMP and MPI as well as parallel programming.
Since this was the first lab given of the semester it is meant to give introduce new material while also refreshing us on the C
programming language. With this lab we had learned how to use basic MPI functions to split up a program to run using multiple nodes
to run the same program multiple times in one exectution. We were first introduced to this topic during lecture and were actually able to
apply it toward the first task of this lab which was to make use of the MPI tools to run a Hello World program called hello.c to learn how exactly 
each node handles the task given. The second given task of this lab was to produce a program to test the primality of a user given input
using the MPI tools we were shown in class to split up the amount of numbers that needed to be checked to test for the primality of the 
user given input I had called bigNumbers.c. To do this we had to take the square root of the input then find out how to split each node and where to start each one to begin its segment of integers it will be checking to find the inputs primality.

How to run
To create the executables run the make command which will compile with mpicc hello.c and bigNumbers.c to produce the executables hello and bigNumbers.
To run hello.c it can be ran by using mpiexec -n (number of nodes) ./hello
To run bigNumbers.c it can be ran by using mpiexec -n (number of nodes) ./bigNumbers (number you wish to check primality for)
To remove the executable files you can run make clean but next time you try to run you need to recompile.

Questions
a) What is the theoretical time complexity of your algorithms (best and worst case), in terms of the input size?
    The theoretical time complexity of the primality algorithms are the best case being O(1) because there is a possibility that the first number being tested is found to be a divisor of the number being tested which in this programs case is usually 2. The worst case can be O(sqrt(n)/k). Which means that n is the user input that is being given through the command line and k is the number of nodes being allocated to be used which. This happens when the number being tested had proved to be prime and the program had to run and test all cases until its out of cases to test and terminates.

b) For this specific task, the structure and flow of your program may drastically influence the runtime. What steps did/can you take to gain performance of the entire process?
    In this case of finding the primality of a given number I had saw that as the amount of nodes used increased the quicker the program had completed its instructions. When running the time command while testing the program I had used many different cases which had shown that the bigger the number had indeed gained more efficient through the use of more nodes because each node is dividing the numbers being checked between themselves. Because of the use of more nodes we can see an increase of efficiency rather than having a little amount of nodes used to find the primality of a big number which casues each node to have a larger work load.

c) According to the data, does adding more nodes perfectly divide the time taken by the program?
    When testing the program using the time command in through the command line it was hard to determine if it actually perfectly divides the time that is taken to compute the primality of a given integer. However with some of the test cases I had tried I had noticed that not all nodes got an equal amount of numbers to check through in some cases. When the number is larger there was a more even spread of integers between each node being used to test but when testing smaller numbers the margin was significantly smaller as to how many numbers each node was to test often leaving some to do more test than others. So I belive that in my programs inctance it does not perfectly divide the time taken but it does however greatly shorten its execution time.

d) Justify/prove the fact that one needs only check up to √N in the brute force primality test.
    Since sqrt(N)*sqrt(N)=N then taking the root of N is a good use to split its number to be able to then test even less cases to find the numbers primality. So by knowing that.
    Let x and y be a factor of a number N.

e) How could the code be improved in terms of usability, efficiency, and robustness?
    The code could be further improved through the algorithm I had used. If it was to be changed more to allow all nodes to have an almost even divide of integers then it could possibly run faster so all nodes would roughly have the same amount of time needed to complete their tasks. As for usability and robustness i had tested my program with a very large number and it had performed weirdly and didnt give proper output even when spread across 8 different nodes to divide the work load between.