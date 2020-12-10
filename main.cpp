#include <iostream>
#include <cstdlib>

#include "MyVector.h"

int main (){
  MyVector<int> test;
  test.printStat();
  std::cout << "After adding 0-19 into the MyVector" << std::endl;
  for (int i=0; i<20; i++){
    test.push_back(i);
  }
  test.printStat();
  test.clear();
  std::cout << "After clear() is called" << std::endl;
  test.printStat();
  std::cout << "Adding 10, 20, 30 by push_back()" << std::endl;
  test.push_back(10);
  test.push_back(20);
  test.push_back(30);
  test.printStat();
  std::cout << "Got rid of the last element and the 2nd element by pop_back()" << std::endl;
  test.pop_back();
  test.pop_back(1);
  test.printStat();
  

  return 0;
}

