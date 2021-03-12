/*
    Name: Cody Murrer
    Lab: 09 Graphs (build a graph from the graphA.dat)
    Class: 320-752
*/

#include "d_graph.h"
#include <iostream>
#include <fstream>
#include <set>

int main(){

    graph<string> g;

    std::ifstream graphFile;
    graphFile.open("graphA.dat",ios::in);
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
    
    g.insertEdge("F","D",1);
    g.eraseVertex("B");
    g.eraseEdge("A","D");
    
    std::cout<<"Enter a vertex you wish to view: ";
    string input;
    std::cin>>input;
    set<string> neighbor = g.getNeighbors(input);
    if(neighbor.size()==0){
        std::cout<<"There is no neighbor of this vertex"<<std::endl;
    }else{
        std::cout<<"The neighbors of vertex "<<input<<" are: ";
        for(auto itter = neighbor.begin(); itter != neighbor.end();itter++){
            std::cout<<*itter<<" ";
        }
        std::cout<<std::endl;
    }
    
    g.insertVertex("G");
    g.insertEdge("G","C",1);
    g.insertEdge("G","F",1);
    g.insertEdge("D","G",1);

    std::cout<<g;
}