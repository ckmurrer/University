How to run: 
make sure to call the make file.
then there are two options you can do to run.
First is you can use mpiexec -n (node size) ./vectors to run the getting started with scatter program
Second is mpiexec -n (node size) ./main
however to run main you will have to go into the code and uncomment out the different functions you wish to test as they all contain high memory usage and have issues running all at the same time. 

A) What is the theoretical time complexity of your algorithms (best and worst case), in terms of the
input size?
    The theoretical time complexity of my algorithms are for addition and subtraction are O(N/P) which is the elements within the matrix N and the amount of nodes being used for P. Best case would be O(1) and worst would be O(N). The time complexity for the inner product it would be O(2N/P) because we scatter the amount of elements across two vectors that are found on each P node. The best case would be O(1) where little to no processing is required to produce an outcome. where the wost case would be O(2N) because there are some instances when you only use one node and that singular node is doing all the calculations and processes alone. The Transpose is simial to the addition and subtractions best and worst time complexities where it has a best of O(1) and a worst of O(N). 

B) According to the data, does adding more nodes perfectly divide the time taken by the program?
    When more nodes are added to the program the time does increase by alot when doing calculations of an over 10x10 matrix. However the timing is not perfectly divided up by the nodes because the there are some cases where a node gets one or two more sets of elements to do calculations on while the others get a few less so will possibly be finished before the node with the higher amount of elements.

C) What are some real-world software examples that would need the above routines? Why? Would they benefit greatly from using your distributed code?
    Some real world examples on who could use my code are mathmaticians trying to solve massive matricies because there gets to a point when a certain amount of memory on something like a calculator becomes inadequate and higher computational power is needed. They could benefit from using it because since it is paralelized the time it takes to do most calculations is quicker than those done in serial.

D) How could the code be improved in terms of usability, efficiency, and robustness?
    As of right now my code has some issues with its multiplying matrix function to where (it may sound clique) it runs flawlessly on my machine through the terminal but when running it through SSH onto the HPCL linux lab it seg faults on anything other than one node. There are also memory leaks that dont make any sense because everything thats being malloced is being freed so its a little confusing.    

