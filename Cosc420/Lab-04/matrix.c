#include "matrix.h"
// initializes the matrix
void initMatrix(matrix* A, int rows, int cols){
	A->rows = rows;
    A->cols = cols;
    A->data = malloc(A->rows*A->cols*sizeof(int));
}
// populates the matrix
void populateMatrix(matrix* A, int rows, int cols){
    int i,j;
    for(i=0; i<rows; i++){
        for (j=0; j < cols; j++){
            ACCESS((*A),i,j) = rand()%10+1;
        }
    }
}
// prints the matrix
void printMatrix(matrix* A){
    int i,j;
    for(i=0; i<A->rows;i++){
        for(j=0; j<A->cols;j++){
           printf("%.03d | ",ACCESS((*A),i,j));
        }
        printf("\n");
    }
}

void copyMatrix(matrix* A, matrix* B){
    A->rows = B->rows;
    A->cols = B->cols;
    int size = B->rows*B->cols;
    if(B->data){
        A->data = malloc(size*sizeof(int));
        int i;
        for(int i=0; i<size; i++){
            A->data[i] = B->data[i];
        }
    }else{
        printf("Original matrix is empty\n");
    }
}

// idk how to fix mem leak
matrix matrixAddition(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank){
// error checking to see if the matrix is nxn    
    matrix addTotal;
    if(A->cols!=B->cols){
       printf("Why are we here? Just to suffer?\nInvalid matrix dimensions btw.\n");
       return addTotal;
    }
    initMatrix(&addTotal,A->rows,A->cols);
    int matSize = A->rows*A->cols;
    int* sendCount = malloc(wSize*sizeof(int));
    int* displace = malloc(wSize*sizeof(int));
    int minSend = matSize/wSize;
// from the notes in class
    int i;
    for(i=0; i<wSize; i++){
        sendCount[i] = minSend; // sets the min send amount per node
    }
// from the notes in class    
    for(i=0; i<matSize%wSize;i++){
        sendCount[i]+=1; // if there is a node that will get more than the others
    }
//from the notes in class
    displace[0] = 0;
    for(int i=1; i<wSize; i++){
        displace[i] = displace[i-1] + sendCount[i-1]; // displacement to keep track of the sent nodes
    }

    int* recBufA = malloc(sendCount[rank]*sizeof(int));
    int* recBufB = malloc(sendCount[rank]*sizeof(int));

    MPI_Scatterv(
        A->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacement
        MPI_INT,            //datatype
        recBufA,            //recieve buffer
        sendCount[rank],    //recieve counter
        MPI_INT,            //recieve datatype
        0,                  //root
        world               //comm
    );
    MPI_Scatterv(
        B->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacment
        MPI_INT,            //datatype
        recBufB,            //recieve buffer
        sendCount[rank],    //recieve counter 
        MPI_INT,            //recieve datatype
        0,                  //root
        world               //comm
    );

    int* temp = malloc(matSize*sizeof(int));
    for(i=0; i<minSend; i++){
        temp[i] = recBufA[i]+recBufB[i]; // temp variable buffer to store added variables
    }
    MPI_Gatherv(
        temp,               //send buffer
        minSend,            //send count
        MPI_INT,            //send type
        addTotal.data,           //recieve buffer
        sendCount,          //recieve count
        displace,           //recieve type
        MPI_INT,            //datatype
        0,                  //root
        world               //comm
    );

    free(temp);
    free(sendCount);
    free(displace);
    free(recBufA);
    free(recBufB);    
	return addTotal;
}
// idk how to fix mem leak
matrix matrixSubtraction(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank){
    matrix subTotal;
    if(A->cols!=B->cols){
       printf("Why are we here? Just to suffer?\nInvalid matrix dimensions btw.\n");
       return subTotal;
    }
    initMatrix(&subTotal,A->rows,A->cols);
    int* temp;
    int matSize = A->rows*A->cols;
    int* sendCount = malloc(wSize*sizeof(int));
    int* displace = malloc(wSize*sizeof(int));
    int minSend = matSize/wSize;

    int i;
    for(i=0; i<wSize; i++){
        sendCount[i] = minSend;
        //displace[i] = minSend*i;
    }
    for(i=0; i<matSize%wSize;i++){
        sendCount[i]+=1;
    }

    displace[0] = 0;
    for(int i=1; i<wSize; i++){
        displace[i] = displace[i-1] + sendCount[i-1];
    }

    int* recBufA = malloc(sendCount[rank]*sizeof(int));
    int* recBufB = malloc(sendCount[rank]*sizeof(int));

       MPI_Scatterv(
        A->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacement
        MPI_INT,            //datatype
        recBufA,            //recieve buffer
        sendCount[rank],    //recieve counter
        MPI_INT,            //recieve datatype
        0,                  //root
        world               //comm
    );
    MPI_Scatterv(
        B->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacment
        MPI_INT,            //datatype
        recBufB,            //recieve buffer
        sendCount[rank],    //recieve counter 
        MPI_INT,            //recieve datatype
        0,                  //root
        world               //comm
    );
    temp = malloc(matSize*sizeof(int));
    for(i=0; i<minSend; i++){
        temp[i] = recBufA[i]-recBufB[i];
    }
       MPI_Gatherv(
        temp,               //send buffer
        minSend,            //send count
        MPI_INT,            //send type
        subTotal.data,           //recieve buffer
        sendCount,          //recieve count
        displace,           //recieve type
        MPI_INT,            //datatype
        0,                  //root
        world               //comm
    );

    free(temp);
    free(sendCount);
    free(displace);
    free(recBufA);
    free(recBufB);    
	return subTotal;
}
// gives almost proper output only works with NxN matrix idk how to fix
matrix matrixMutiplication(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank){
    matrix matTrans,vecOne,vecTwo,test; // transpose matrix horizontal and vertical vectors
    
    if(A->cols!=B->rows){
        printf("This aint it cheif. Invalid input. Rank: %d\n",rank);
        return test;
    }

    matTrans = matrixTranspose(B); // takes the transpose of a passed matrix
    initMatrix(&vecOne,1,A->cols); // initializes a vector
    initMatrix(&vecTwo,B->rows,1); // initializes a vector
    if(rank == 0){
        initMatrix(&test,A->rows,A->cols);
    }
    int size = A->rows*matTrans.rows; 
    //int* multTotal = malloc(size*sizeof(int));
    // compile with -std=c99
    for(int i=0; i<A->rows; i++){
        for(int j=0; j<matTrans.rows; j++){
            for(int k=0; k< A->cols; k++){
                vecTwo.data[k] = matTrans.data[j*A->cols+k];
                vecOne.data[k] = ACCESS((*A),i,k);
            }
            test.data[INDEX((*B),i,j)] = innerProduct(&vecOne,&vecTwo,world,wSize,rank);
        //  multTotal[INDEX((*B),i,j)] = innerProduct(&vecOne,&vecTwo,world,wSize,rank); // gets the inner produc of the to vectors
            if(rank == 0){
                //test.data[INDEX((*B),i,j)] = temp;
            }
        }
    }
    //test.data = multTotal;
    //free(multTotal); // gives invalid free() possible cause of mem leak? pls im dying why does it giv mem errors when uncommented
    free(matTrans.data);
    free(vecTwo.data);
    free(vecOne.data);
    return test;
}
// probably has memory leaks
int innerProduct(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank){
    int inProd = 0;
    int temp = 0;
    int matSize = A->rows*A->cols;
    int* sendCount = malloc(wSize*sizeof(int));
    int* displace = malloc(wSize*sizeof(int));
    int* recBufA = malloc(matSize*sizeof(int));
    int* recBufB = malloc(matSize*sizeof(int));
    int minSend = matSize/wSize;
// from class notes
    int i;
    for(i=0; i<wSize; i++){
        sendCount[i] = minSend;
    }
// from class notes
    for(i=0; i<matSize%wSize;i++){
        sendCount[i]++;
    }
// from class notes
    displace[0] = 0;
    for(int i=1; i<wSize; i++){
        displace[i] = displace[i-1] + sendCount[i-1];
    }

      MPI_Scatterv(
        A->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacement
        MPI_INT,            //datatype
        recBufA,            //recieve buffer
        sendCount[rank],    //recieve counter
        MPI_INT,            //recieve datatype
        0,                  //root
        world               //comm
    );
    MPI_Scatterv(
        B->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacment
        MPI_INT,            //datatype
        recBufB,            //recieve buffer
        sendCount[rank],    //recieve counter 
        MPI_INT,            //recieve datatype
        0,                  //root
        world               //comm
    );

    for(i=0; i<minSend; i++){
        temp += recBufA[i]*recBufB[i]; // sets temp equal to the product between the vectors
    }

    MPI_Reduce(
        &temp,              //send Buffer
        &inProd,            //recieve buffer 
        1,                  //count
        MPI_INT,            //datatype
        MPI_SUM,            //opperation
        0,                  //root
        world               //comm
    );

    free(sendCount);
    free(displace);
    free(recBufA);
    free(recBufB);  
    return inProd;
}

matrix matrixTranspose(matrix* A){
    int size = A->rows*A->cols;
    matrix tPose;
    tPose.cols = A->rows;
    tPose.rows = A->cols;
    tPose.data = malloc(size*sizeof(int));
    int i,j;
    for (i = 0; i < A->cols; i++) {
        for (j = 0; j < A->rows; j++) {
            tPose.data[i*A->rows+j] = ACCESS((*A),j,i);
        }
    }
    return tPose;
}

int* gaussJordan(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank){
    matrix tempMatOne,tempMatTwo;
    matrix* copyA, *copyB;
    // checks if the rows are the same if not return an empty matrix
    if(A->rows != B->rows){
        printf("Invalid matrix size\n");
        return NULL;
    }

    initMatrix(&tempMatOne, A->rows, A->cols);
    initMatrix(&tempMatTwo, B->rows, B->cols);
    copyA=&tempMatOne;
    copyB=&tempMatTwo;
    copyMatrix(copyA,A);
    copyMatrix(copyB,B);

    int scatterA[wSize], displaceA[wSize];
    int i;
    int plsWork = (copyA->rows%wSize);
    // setting up to scatter matrix A
    for(i = 0; i< wSize; i++){
        scatterA[i] = (copyA->rows/wSize)*copyA->cols;
    }
    for(i = 0; i<plsWork; i++){
        scatterA[i] += copyA->cols;
    }
    // setup displacement for A
    for(i = 0; i<wSize; i++){
      if(i == 0){
          displaceA[i] = 0;
      }else{
          displaceA[i] += scatterA[i-1];
      }
    }

    int scatterB[wSize], displaceB[wSize];
    int j;
    int workPls = (copyB->rows%wSize);
    // setting up to scatter matrix B
    for(j = 0; j<wSize; j++){
        scatterB[j] = (copyB->rows/wSize)*copyB->cols;
    } 
    for(j = 0; j<workPls; j++){
        scatterB[j] += copyB->cols;
    }
    // setup displacement for B
    for(j = 0; j<wSize; j++){
      if(j == 0){
          displaceB[j] = 0;
         
      }else{
          displaceB[j] += scatterB[j-1];
      }
    }

    int* matAScatter = malloc(scatterA[rank]* sizeof(int));
    int* matBScatter = malloc(scatterB[rank] * sizeof(int));
    int aPivot[copyA->rows],bPivot[copyB->rows], scale[copyA->rows];
    int k,l,z;
    for(k = 0; k<copyA->rows; k++){
        if(rank == 0){
            for(l = 0; l< copyA->rows; l++){
                scale[l] = ACCESS((*copyA),l,k)/ACCESS((*copyA),k,k); 
            }
            for(l = 0; l< copyA->cols; l++){
                aPivot[l] = ACCESS((*copyA),k,l);
            }
            for(l = 0; l< copyB->cols; l++){
                bPivot[l] = ACCESS((*copyB),k,l);
            }
        }

        MPI_Scatterv(
            copyA->data,
            scatterA,
            displaceA,
            MPI_INT,
            aPivot,
            scatterA[rank],
            MPI_INT,
            0,
            world
        );

        MPI_Scatterv(
            copyB->data,
            scatterB,
            displaceB,
            MPI_INT,
            bPivot,
            scatterB[rank],
            MPI_INT,
            0,
            world
        );

        MPI_Bcast(
            &scale,
            copyA->rows,
            MPI_INT,
            0,
            world
        );

        MPI_Bcast(
            &aPivot,
            copyA->rows,
            MPI_INT,
            0,
            world
        );

        MPI_Bcast(
            &bPivot,
            copyB->rows,
            MPI_INT,
            0,
            world
        );

        for(z = 0; z<scatterA[rank]/copyA->cols; z++){
            if(k == z+(displaceA[rank]/copyA->cols)){
                continue;
            }
            for(l = 0; l<copyA->cols; l++){
                matAScatter[INDEX((*copyA),z,l)] = matAScatter[INDEX((*copyA),z,l)] - (scale[z+(displaceA[rank]/copyA->cols)]*aPivot[l]);
            }
            for(l = 0; l<copyB->cols; l++){
                 matBScatter[INDEX((*copyB),z,l)] = matBScatter[INDEX((*copyB),z,l)] - (scale[z+(displaceA[rank]/copyA->cols)]*aPivot[l]);
            }
        }
     
        MPI_Gatherv(
            matAScatter,
            scatterA[rank],
            MPI_INT,
            copyA->data,
            scatterA,
            displaceA,
            MPI_INT,
            0,
            world            
        );
        MPI_Gatherv(
            matBScatter,
            scatterB[rank],
            MPI_INT,
            copyB->data,
            scatterB,
            displaceB,
            MPI_INT,
            0,
            world
        );
     //   free(matBScatter);
      //  free(matAScatter);
    }
    if(rank == 0){
        int diagScale[copyA->cols];
        for(z = 0; z< copyA->rows; z++){
            for(l = 0; l< copyA->cols; l++){
                if(z == l){
                    diagScale[z] = ACCESS((*copyA), z,l);
                }
            }
        }
        for(z = 0; z< copyA->rows; z++){
            for(l = 0; l< copyA->cols; l++){
                ACCESS((*copyA), z,l) = ACCESS((*copyA), z,l) / diagScale[z];
            }
        }
        if(copyB->cols>1){
            for(z = 0; z< copyA->rows; z++){
                for(l = 0; l< copyA->cols; l++){
                    ACCESS((*copyB), z,l) = ACCESS((*copyB), z,l) / diagScale[z];
                }
            }
        }else{
            for(z = 0; z< copyB->rows; z++){
                ACCESS((*copyB), z,0) = ACCESS((*copyB), z,0) / diagScale[z];
            }
        }
       // free(scatterB);
     //   free(scatterA);
     //   free(displaceB);
     //   free(displaceA);
    }

   // free(tempMatTwo.data);
   // free(tempMatOne.data);
    return copyB->data;
}