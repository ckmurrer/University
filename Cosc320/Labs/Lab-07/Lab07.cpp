/*
    Name: Cody Murrer
    Lab: 07 Hash Table (create a hash table and populate it with a dictionary then search for misspelled words from a user inputed txt file)
    Class: 320-752
*/

#include "d_hash.h"
#include "d_hashf.h"

#include <iostream> 
#include <fstream>

//extract a word from fin
ifstream& getWord(ifstream& fin, string& w)
{
	char c;
    
	w = "";	// clear the string of characters
    
	while (fin.get(c) && !isalpha(c))
		;	// do nothing. just ignore c

	// return on end-of-file
	if (fin.eof())
		return fin;
    
	// record first letter of the word
	w += tolower(c);
	// collect letters and digits
	while (fin.get(c) && (isalpha(c) || isdigit(c)))
		w += tolower(c);
           
	return fin;
}

int main(){

    myhash<string,hFstring> hashTable(1373); 
    myhash<string,hFstring>:: iterator iter;

    // open and read the dict.dat file
    std::ifstream dictionary;
    dictionary.open("dict.dat",ios::in);
    if(dictionary.is_open()){
        string dict;
        while(dictionary>>dict){
            hashTable.insert(dict);
        }
    }
    dictionary.close();

    std::cout<<"Enter the document name:";
    string docName;
    std::cin>>docName;
// open and read user text file then call getWord to search the hashtable
    std::ifstream spellCheck;
    spellCheck.open(docName,ios::in);
    if(spellCheck.is_open()){
        string check;
        std::cout<<"Misspelled words: "<<std::endl<<std::endl;
        while(getWord(spellCheck,check)){

            iter = hashTable.find(check);
            
            if(iter == hashTable.end()){
              std::cout<<check<<std::endl;   
            }
        }
    }
    spellCheck.close();
    hashTable.empty();
}