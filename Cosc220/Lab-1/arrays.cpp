#include <iostream>

double mean(int store[], int size){// double function that gets the array variable store
  int sum = 0;
  double avg = 0;

  for(int i=0; i<size; i++){// iterates through the array an adds its contents to sum
    sum += store[i];// adding stores variables into sum
  }

  avg = sum/size;//gets the avgerage of sum
  return avg;// returns the average to get printed
}

double mean2(int* store, int size){// double function that gets a pointer version of array store
  int sum = 0;
  double avg = 0;

  for(int i=0; i<size; i++){// iterates through store an adds it together to get sum
    sum += *(store + i);// adds dereferenced store to sum
  }

  avg = sum/size;// gets the avgerage of sum
  return avg;// returns the average to get printed
}

int main() {
  int size = 0;
  int store[size];//user variable to store user input

  std::cout << "Please enter how many integers: ";
  std::cin >>size;
  std::cout << "Please enter your integers: \n";

  for (int i = 0; i < size; i++) {//populates array store
    std::cin >> store[i];//populating the array with user input
  }

  std::cout << "The mean is: " << mean(store,size) << "\n";//prints out the return of mean
  std::cout << "The mean2 is: " << mean2(store,size) << "\n";//prints out the return of mean2
  return 0;
}
