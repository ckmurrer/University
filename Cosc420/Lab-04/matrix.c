#include "matrix.h"
// initializes the matrix
void initMatrix(matrix* A, int rows, int cols){
	A->rows = rows;
    A->cols = cols;
    A->data = malloc(A->rows*A->cols*sizeof(double));
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
           printf("%.03f | ",ACCESS((*A),i,j));
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

    double* recBufA = malloc(sendCount[rank]*sizeof(int));
    double* recBufB = malloc(sendCount[rank]*sizeof(int));

    MPI_Scatterv(
        A->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacement
        MPI_DOUBLE,            //datatype
        recBufA,            //recieve buffer
        sendCount[rank],    //recieve counter
        MPI_DOUBLE,            //recieve datatype
        0,                  //root
        world               //comm
    );
    MPI_Scatterv(
        B->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacment
        MPI_DOUBLE,            //datatype
        recBufB,            //recieve buffer
        sendCount[rank],    //recieve counter 
        MPI_DOUBLE,            //recieve datatype
        0,                  //root
        world               //comm
    );

    double* temp = malloc(matSize*sizeof(int));
    for(i=0; i<minSend; i++){
        temp[i] = recBufA[i]+recBufB[i]; // temp variable buffer to store added variables
    }
    MPI_Gatherv(
        temp,               //send buffer
        minSend,            //send count
        MPI_DOUBLE,            //send type
        addTotal.data,           //recieve buffer
        sendCount,          //recieve count
        displace,           //recieve type
        MPI_DOUBLE,            //datatype
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
double* matrixSubtraction(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank){
    matrix subTotal;
    if(A->cols!=B->cols){
       printf("Why are we here? Just to suffer?\nInvalid matrix dimensions btw.\n");
       return subTotal.data;
    }
    initMatrix(&subTotal,A->rows,A->cols);
    double* temp;
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

    double* recBufA = malloc(sendCount[rank]*sizeof(int));
    double* recBufB = malloc(sendCount[rank]*sizeof(int));

       MPI_Scatterv(
        A->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacement
        MPI_DOUBLE,            //datatype
        recBufA,            //recieve buffer
        sendCount[rank],    //recieve counter
        MPI_DOUBLE,            //recieve datatype
        0,                  //root
        world               //comm
    );
    MPI_Scatterv(
        B->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacment
        MPI_DOUBLE,            //datatype
        recBufB,            //recieve buffer
        sendCount[rank],    //recieve counter 
        MPI_DOUBLE,            //recieve datatype
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
        MPI_DOUBLE,            //send type
        subTotal.data,           //recieve buffer
        sendCount,          //recieve count
        displace,           //recieve type
        MPI_DOUBLE,            //datatype
        0,                  //root
        world               //comm
    );

    free(temp);
    free(sendCount);
    free(displace);
    free(recBufA);
    free(recBufB);    
	return subTotal.data;
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
double innerProduct(matrix* A,matrix* B, MPI_Comm world,int wSize, int rank){
    double inProd = 0.0;
    double temp = 0.0;
    int matSize = A->rows*A->cols;
    int* sendCount = malloc(wSize*sizeof(int));
    int* displace = malloc(wSize*sizeof(int));
    double* recBufA = malloc(matSize*sizeof(double));
    double* recBufB = malloc(matSize*sizeof(double));
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
        MPI_DOUBLE,            //datatype
        recBufA,            //recieve buffer
        sendCount[rank],    //recieve counter
        MPI_DOUBLE,            //recieve datatype
        0,                  //root
        world               //comm
    );
    MPI_Scatterv(
        B->data,            //send buffer
        sendCount,          //send counter
        displace,           //displacment
        MPI_DOUBLE,            //datatype
        recBufB,            //recieve buffer
        sendCount[rank],    //recieve counter 
        MPI_DOUBLE,            //recieve datatype
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
        MPI_DOUBLE,            //datatype
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

double* gaussJordan(matrix* A, matrix* B, MPI_Comm world, int wSize, int rank){
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
            MPI_DOUBLE,
            aPivot,
            scatterA[rank],
            MPI_DOUBLE,
            0,
            world
        );

        MPI_Scatterv(
            copyB->data,
            scatterB,
            displaceB,
            MPI_DOUBLE,
            bPivot,
            scatterB[rank],
            MPI_DOUBLE,
            0,
            world
        );

        MPI_Bcast(
            &scale,
            copyA->rows,
            MPI_DOUBLE,
            0,
            world
        );

        MPI_Bcast(
            &aPivot,
            copyA->rows,
            MPI_DOUBLE,
            0,
            world
        );

        MPI_Bcast(
            &bPivot,
            copyB->rows,
            MPI_DOUBLE,
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
            MPI_DOUBLE,
            copyA->data,
            scatterA,
            displaceA,
            MPI_DOUBLE,
            0,
            world            
        );
        MPI_Gatherv(
            matBScatter,
            scatterB[rank],
            MPI_DOUBLE,
            copyB->data,
            scatterB,
            displaceB,
            MPI_DOUBLE,
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

// normalize the matrix passed from main
double normalize(matrix* A, MPI_Comm world, int wSize, int rank){
    if(A->rows > 1 && A->cols != 1){
        printf("Invalid size not a vector\n");
        return 0;
    }
    if(A->cols > 1 && A->rows != 1){
        printf("Invalid size not a vector\n");
        return 0;
    }

    if(A->rows == 1){
        matrix temp;
        temp = matrixTranspose(A);
        A->data = temp.data;
    }
    int mult = A->cols*A->rows;
    int total = 0;
    double globalTotal = 0.0, localTotal = 0.0;
    int displacement[wSize];
    int sendCount[wSize];
    int i;
    for(i=0; i<wSize; i++){
        sendCount[i] = mult/wSize;
    }   
    for(i=0; i<mult%wSize; i++){
        sendCount[i] += 1;
    }
    int buff[sendCount[rank]];
    for(i=0; i<wSize; i++){
        displacement[i] = total;
        total += sendCount[i];
    }

    MPI_Scatterv(
        A->data,
        sendCount,
        displacement,
        MPI_DOUBLE,
        buff,
        sendCount[rank],
        MPI_DOUBLE,
        0,
        world
    );

    for(i=0; i<sendCount[rank]; i++){
        localTotal += pow(buff[i],2);
    }

    MPI_Reduce(
        &localTotal,
        &globalTotal,
        1,
        MPI_DOUBLE,
        MPI_SUM,
        0,
        world
    );

    return sqrt(globalTotal);
}

// find the eigenvectors of a matrix using mpi functions
double* eigenVector(char* fileName, MPI_Comm world, int dimensions, int wSize, int rank){
    MPI_File file;
    matrix* A;
    matrix temp,temp2;
    initMatrix(A,dimensions,dimensions);
    int size = temp.cols*temp.rows;
    int i;
    int counter = 0;
    int finished = 0;
    int sendCount[wSize];
    int displacement[wSize];
    int total;
    double* diff;
    double buff[size];
    double buff2[size];
    double norm;
    double tolerance = pow(10,-16);
    if(rank == 0){
        for(i=0; i<size; i++){
            buff[i] = 1;
            buff2[i] = 1;
        }
    }
    temp.rows = A->rows;
    temp.cols = 1;
    temp2.cols = 1;
    temp2.rows = A->rows;
    temp.data = buff;
    temp2.data = buff2;
    
    MPI_File_open(
        world,
        fileName,
        MPI_MODE_RDONLY,
        MPI_INFO_NULL,
        &file
    );

    if(rank = 0){
        MPI_File_read(
            file,
            A->data,
            dimensions*dimensions,
            MPI_DOUBLE,
            MPI_STATUS_IGNORE
        );
    }
    MPI_File_close(&file);
    MPI_Barrier(world);
    
    while(counter<1 && !finished ){
        free(temp2.data);
        temp2.data = temp.data;
        temp = matrixMutiplication(A,&temp,world,wSize,rank);
        norm = normalize(&temp,world,wSize,rank);

        MPI_Bcast(
            &norm,
            1,
            MPI_DOUBLE,
            0,
            world
        );
    
        for(i=0; i<wSize; i++){
            sendCount[i] = (size)/wSize;
        }
        for(i=0; i<size%wSize; i++){
            sendCount[i] += 1;
        }
        for(i=0; i<wSize; i++){
            displacement[i] = total;
            total += sendCount[i];
        }

        double buff3[sendCount[rank]];
        MPI_Scatterv(
            temp.data,
            sendCount,
            displacement,
            MPI_DOUBLE,
            buff3,
            sendCount[rank],
            MPI_DOUBLE,
            0,
            world
        );

        for(i=0; i<sendCount[rank]; i++){
            buff3[i] /= norm;
        }

        MPI_Gatherv(
            buff3,
            sendCount[rank],
            MPI_DOUBLE,
            temp.data,
            sendCount,
            displacement,
            MPI_DOUBLE,
            0,
            world
        );

        diff = matrixSubtraction(&temp, &temp2, world, wSize,rank);
        if(rank == 0){
            for(i=0; i<size; i++){
                if(diff[i]<=tolerance){
                    finished = 1;
                    break;
                }
            }
        }
        if(rank==0){
            free(diff);
        }
        MPI_Bcast(
            &finished,
            1,
            MPI_DOUBLE,
            0,
            world
        );
        counter++;
    }   
    free(A->data);
    free(temp2.data);
    
    if(rank == 0){
        return temp.data;
    }
    return NULL;
}

// find the eigenvectors of a matrix using files
double* eigenVectorFile(char* fileName, MPI_Comm world, int dimensions, int wSize, int rank){
    MPI_File file;
    matrix A;
    initMatrix(&A,dimensions,dimensions);

    int sendCounter[wSize];
    int displacement[wSize];
    int i;
    int temo = 0;
    int counter = 0;
    int finish = 0; 
    int size = dimensions*dimensions;

    double localBuff[sendCounter[rank]];

    for(i=0; i< wSize; i++){
        sendCounter[i] = size/wSize;
        displacement[i] = temo;
        temo+=size/wSize;
    }
    if(size%wSize>0){
        sendCounter[wSize-1]+=size%wSize;
    }

    MPI_Offset offset = rank*sizeof(double)*sendCounter[rank];
    MPI_File_open(
        world,
        fileName,
        MPI_MODE_RDONLY,
        MPI_INFO_NULL,
        &file
    );

    MPI_File_read_at(
        file,
        offset,
        localBuff,
        sendCounter[rank],
        MPI_DOUBLE,
        MPI_STATUS_IGNORE
    );

    MPI_File_close(&file);
    MPI_Gatherv(
        localBuff,
        sendCounter[rank],
        MPI_DOUBLE,
        A.data,
        sendCounter,
        displacement,
        MPI_DOUBLE,
        0,
        world
    );

    free(sendCounter);
    free(displacement);
    free(localBuff);
    MPI_Barrier(world);

    matrix B;
    B.data = malloc(dimensions*sizeof(double));
    B.rows = dimensions;
    B.cols = 1;

    for(i=0; i<dimensions; i++){
        B.data[i] = 1;
    }

    double toleramce = pow(10,-16);
    while(counter<1 && !finish){
        matrix plsWork;
        plsWork.rows = B.rows;
        plsWork.cols = B.cols;
        plsWork.data = B.data;

        B = matrixMutiplication(&A, &B, world, wSize, rank);
        double norm = normalize(&B,world,wSize,rank);
        B.data = &norm;
        MPI_Bcast(
            B.data,
            dimensions,
            MPI_DOUBLE,
            0,
            world
        );
        
        double whyDontYouWork[dimensions];
        int total = 0;
        int total2 = 0;

        for(i=0; i<dimensions; i++){
            whyDontYouWork[i] = plsWork.data - B.data;
        }

        MPI_Bcast(
            whyDontYouWork,
            dimensions,
            MPI_DOUBLE,
            0,
            world
        );

        for(i=0; i<dimensions; i++){
            total += whyDontYouWork[i];
            total2 += plsWork.data[i];
        }

        if(total2-total<=toleramce||total2 - total >= pow(-10,-16)){
            finish = 1;
        }
        free(plsWork.data);
        counter++;
    }
    return B.data;
}