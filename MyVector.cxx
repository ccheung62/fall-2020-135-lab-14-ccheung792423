#include "MyVector.h"
#include <iostream>

template<class T>
MyVector<T>::MyVector(){  //default size of array is 10
  data = new T[10];
  cap = 10;
  s = 0;
}

template<class T>
MyVector<T>::MyVector(int size){  //set the size as parameter except for when
                                  //parameter is less than 0 which will then
                                  //be set as 10  
  if (size < 0){
    size = 10;
    cap = 10;
  }
  data = new T[size];
  cap = size;
  s = 0;
}

template<class T>
MyVector<T>::~MyVector(){
  delete[] data;
  data = nullptr;
}

template<class T>
int MyVector<T>::size(){  //return the number of elements in the array
  return s;
}

template<class T>
int MyVector<T>::capacity(){ //return the size of the array 
  return cap;
}

template<class T>
bool MyVector<T>::empty(){  //check if any element is initialized in the array
  if (s == 0){
    return true;
  }
  else{
    return false;
  }
}

template<class T>
void MyVector<T>::push_back(T item){ //add the item at the end of the array
  if (s >= cap){
    T* temp = data;
    data = new T[s+1];
    for(int i=0; i<s; i++){
      data[i] = temp[i];
    }
    delete[] temp;
    temp = 0;
    cap ++;
  }
  data[s] = item;
  s++;
}

template<class T>
void MyVector<T>::pop_back(int n){ //make the element at index n inaccesible
  if (n >= s){
    return;
  }
  for (int i=n; i<s-1; i++){
    data[i] = data[i+1];
  }
  s--;
  
}

template<class T>
void MyVector<T>::pop_back(){  //make the last element inaccesible 
  s--;
}

template<class T>
void MyVector<T>::clear(){  //allocate a new array for data
  data = new T[10];
  cap = 10;
  s = 0;
}

template<class T>
void MyVector<T>::printStat(){
  for (int i=0; i<s; i++){
    std::cout << data[i] << "  ";
  }
  std::cout << std::endl;
  if (s == 0){
    std::cout << "The MyVector is empty" << std::endl;
  }
  else {
  std::cout << "It currently contains " << s << " elements" << std::endl;
  }
  std::cout << "It's capacity is " << cap << " elements" << std::endl;
  std::cout << "--------------------------------------------" << std::endl;
}




