#include <iostream>
#include <cstdlib>

#include "MyVector.h"

int main (){
  MyVector<int> test;
  if (test.empty()){
    std::cout << "it is empty so correct" << std::endl;
  }
  else {
    std::cout << "nope" << std::endl;
  }
  std::cout << "size is: " << test.size() << std::endl;
  std::cout << "capacity is: " << test.capacity() << std::endl;
  for (int i=0; i<20; i++){
    test.push_back(i);
  }
  for (int i=0; i<test.size(); i++){
    std::cout << test[i] << "  ";
  }
  std::cout << std::endl;
  std::cout << "size would be now: " << test.size() << std::endl;
  std::cout << "capacity would be now: " << test.capacity() << std::endl;
  if (test.empty()){
    std::cout << "it is not empty so :(" << std::endl;
  }
  else {
    std::cout << "should be filled yep" << std::endl;
  }
  std::cout << "I will clear it" << std::endl;
  test.clear();
  if (test.empty()){
    std::cout << "cool cool" << std::endl;
  }
  else {
    std::cout << "panic struggle no" << std::endl;
  }
  for (int i=0; i<test.size(); i++){
    std::cout << test[i] << "  ";
  }
  std::cout << std::endl;

  test.push_back(10);
  test.push_back(20);
  test.push_back(30);
  test.push_back(40);
  for (int i=0; i<test.size(); i++){
    std::cout << test[i] << "  ";
  }
  std::cout << std::endl;
  test.pop_back();
  test.pop_back(1);
  for (int i=0; i<test.size(); i++){
    std::cout << test[i] << "  ";
  }
  std::cout << std::endl;
  

  return 0;
}

