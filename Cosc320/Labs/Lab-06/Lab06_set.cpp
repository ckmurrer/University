/*
    Name: Cody Murrer
    Lab: 06 Set & Map (create a set and map of states and cities and search for data within and print if found or else say otherwise)
    Class: 320-752
*/

#include <iostream>
#include <set>

#include "d_state.h"
int main(){

    set <stateCity> s;
    set<stateCity>:: iterator iter;

    s.insert(stateCity("Maryland","Salisbury"));
    s.insert(stateCity("Arizona","Phoenix"));
    s.insert(stateCity("Virgina","Richmond"));
    s.insert(stateCity("Colorado", "Denver"));
    s.insert(stateCity("Florida","Miami"));

    std::cout<<"Run One:"<<std::endl;

    string state;
    std::cout<<"Enter a state: ";
    std::getline(cin, state);
    iter = s.find(state);

    if(iter != s.end()){
        std::cout<<*s.find(stateCity(state,""))<<std::endl<<std::endl;
    }else{
        std::cout<<state<<" is not int the set."<<std::endl;
    }

    std::cout<<"Run Two:"<<std::endl;

    std::cout<<"Enter a state: ";
    std::getline(cin, state);
    iter = s.find(state);

    if(iter != s.end()){
        std::cout<<*s.find(stateCity(state ,""))<<std::endl<<std::endl;
    }else{
        std::cout<<state<<" is not in the set."<<std::endl;
    }
}