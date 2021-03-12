/*
    Name: Cody Murrer
    Lab: 11 Graph Minimization (build a graph from the graphB.dat file then find the min path the min path value and its vertex)
    Class: 320-752
*/
#include "d_graph.h" 
#include "d_util.h"

#include <iostream>
#include <fstream>
#include <set>
#include <queue>

int main(){
// creates a graph g then populates it with the dat file 
    graph<string> g;
    std::ifstream graphFile;
    graphFile.open("graphB.dat",ios::in);
    if(graphFile.is_open()){
        int count;
        graphFile>>count;
        string vertex;
        string vertex2;
        int weight;
        while(count !=0){
            graphFile>>vertex;    
            g.insertVertex(vertex);
            count--;
        }
        graphFile>>count;
        while(count !=0){
            graphFile>>vertex>>vertex2>>weight;    
            g.insertEdge(vertex,vertex2,weight);
            count--;
        }
    }
    graphFile.close();
// user input for desired vertex
    string input;
    std::cout<<"Enter a vertex: ";
    std::cin>>input;
// list for the min path as well as the min path value and vertices 
// used to find the largest min path vertex
    std::list<string> path;
    int minPathVal = 0;
    string vertex3;
    string mVertex;
    int count = 0;
// reopens the .dat file to start at the beginning of the file
    graphFile.open("graphB.dat",ios::in);
    graphFile >> count;
// loops through the file and calls min path and compares it to the min path value
// if its larger then it sets min path value equal to the return and the vertex to the one from the .dat file during that iteration    
    while(count!=0){
        graphFile>>vertex3;
        if(minimumPath(g,vertex3,input,path)>minPathVal){
            minPathVal = minimumPath(g,vertex3,input,path);
            mVertex = vertex3;
        }
        count--;
    }
// calls min path again this time using the largest min path value to allow full iteration through the path list
    minimumPath(g,mVertex,input,path);
    std::cout<<"Vertex with largest minimum-path value = "<<mVertex<<std::endl;
    std::cout<<"Minimum-path value = "<<minPathVal<<std::endl;
    std::cout<<"Minimum-path = ";
    writeContainer(path.begin(),path.end()," ");
    std::cout<<std::endl;
    graphFile.close();
}