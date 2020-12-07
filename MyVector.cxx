#include "MyVector.h"
#include <iostream>

template<class T>
MyVector<T>::MyVector(){
  data = new T[10];
  cap = 10;
  s = 0;
}

template<class T>
MyVector<T>::MyVector(int size){
  if (size < 0){
    size = 10;
    cap = 10;
  }
  data = new T[s];
  cap = size;
  s = 0;
}

template<class T>
MyVector<T>::~MyVector(){
  delete[] data;
  data = 0;
}

template<class T>
int MyVector<T>::size(){
  return s;
}

template<class T>
int MyVector<T>::capacity(){
  return cap;
}

template<class T>
bool MyVector<T>::empty(){
  if (s == 0){
    return true;
  }
  else{
    return false;
  }
}

template<class T>
void MyVector<T>::push_back(T item){
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
void MyVector<T>::pop_back(int n){
  data[n] = 0;
  for (int i=n; i<s-1; i++){
    data[i] = data[i+1];
  }
  data[s] = 0;
  s--;
  
}

template<class T>
void MyVector<T>::pop_back(){
  data[s-1] = 0;
  s--;
}

template<class T>
void MyVector<T>::clear(){
  data = new T[10];
  cap = 10;
  s = 0;
}




