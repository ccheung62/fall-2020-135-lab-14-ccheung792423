#pragma once

template <class T>
class MyVector{
 public:
  MyVector();
  MyVector(int size);
  ~MyVector();
  int size();
  int capacity();
  bool empty();
  void push_back(T item);
  void pop_back(int n);
  void pop_back();
  void clear();
  void printStat();
  T &operator[](int i){
    return data[i];
  };
 private:
  T* data;
  int cap;
  int s;
};

#include "MyVector.cxx"
