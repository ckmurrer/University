/*
    Name: Cody Murrer
    Lab: 06 Set & Map (create a set and map of states and cities and search for data within and print if found or else say otherwise)
    Class: 320-752
*/

#include <iostream>
#include <map>
#include <string>
#include "d_state.h"

int main(){
    map<string,string> m;
    map<string,string>:: iterator iter;

    m.insert({"Maryland","Salisbury"});
    m.insert({"Arizona","Phoenix"});
    m.insert({"Virgina","Richmond"});
    m.insert({"Colorado", "Denver"});
    m.insert({"Florida","Miami"});
    
    std::cout<<"Run One:"<<std::endl;

    string state;
    std::cout<<"Enter a state: ";
    std::getline(cin, state);
    iter = m.find(state);

    if(m.find(state) != m.end()){
        std::cout<<iter->second<<", "<<iter->first<<std::endl<<std::endl;
    }else{
        std::cout<<state<<" is in the map."<<std::endl<<std::endl;
    }

    std::cout<<"Run Two:"<<std::endl;

    std::cout<<"Enter a state: ";
    std::getline(cin, state);
    iter = m.find(state);

    if(m.find(state) != m.end()){
        std::cout<<iter->second<<", "<<iter->first<<std::endl;
    }else{
        std::cout<<state<<" is not in the map."<<std::endl;
    }
}