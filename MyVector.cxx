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




