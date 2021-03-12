/*
    Name: Cody Murrer
    Lab: 10 Graph Traversal (build a graph from the graphB.dat file then traverse it by some vertex using BFS and DFS)
    Class: 320-752
*/
#include "d_graph.h" 
#include "d_util.h"

#include <iostream>
#include <fstream>
#include <set>
#include <queue>

int main(){
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

        string input;
        std::cout<<"What vertex A-F do you wish to search for: ";
        std::cin>>input;
        
        set<string> userBFS = bfs(g,input);
        writeContainer(userBFS.begin(),userBFS.end()," ");
        std::cout<<std::endl;

        list<string> userDFS;
        dfs(g,userDFS);
        writeContainer(userDFS.begin(), userDFS.end(), " ");
        std::cout<<std::endl;
}