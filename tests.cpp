#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "MyVector.h"

MyVector<int> i1;
TEST_CASE("Default Constructor"){
  CHECK(i1.size() == 0);
  CHECK(i1.capacity() == 10);
}

MyVector<int> i2 (20);
TEST_CASE("Parameterized Constructor"){
  CHECK(i2.size() == 0);
  CHECK(i2.capacity() == 20);
}

TEST_CASE("push_back(T)"){
  i1.push_back(23);
  CHECK(i1[0] == 23);
  i1.push_back(34);
  CHECK(i1[1] == 34);
  i1.push_back(76);
  CHECK(i1[2] == 76);
}

TEST_CASE("push_back over capacity"){
  for(int i=0; i<10; i++){
    i1.push_back(i);
  }
  int item = 0;
  for(int i=3; i<13; i++){
    CHECK(i1[i] == item);
    item++;
  }
  CHECK(i1.size() == 13);
  CHECK(i1.capacity() == 13);
}

TEST_CASE("pop_back()"){
  i1.pop_back();
  CHECK(i1.size() == 12);
  CHECK(i1.capacity() == 13);
  CHECK(i1[12] == 0);
  i1.pop_back();
  CHECK(i1.size() == 11);
  CHECK(i1.capacity() == 13);
  CHECK(i1[11] == 0);
}

TEST_CASE("pop_back(n)"){
  i1.pop_back(0);
  i1.pop_back(0);
  i1.pop_back(0);
  for (int i=0; i<8; i++){
    CHECK(i1[i] == i);
  }
  i1.pop_back(5);
  for(int i=0; i<7; i++){
    if (i < 5){
      CHECK(i1[i] == i);
    }
    else {
      CHECK(i1[i] == i+1);
    }
  }
  i1.pop_back(2);
  for(int i=0; i<6; i++){
    if (i > 3){
      CHECK(i1[i] == i+2);
    }
    else if(i > 1){
      CHECK(i1[i] == i+1);
    }
    else{
      CHECK(i1[i] == i);
    }
  }
}

TEST_CASE("clear()"){
  i2.push_back(21);
  i2.push_back(4);
  i2.push_back(64);
  i2.clear();
  for (int i=0; i<3; i++){
    CHECK(i2[i] == 0);
  }
  CHECK(i2.size() == 0);
  CHECK(i2.capacity() == 10);
  CHECK(i2.empty() == true);
}

TEST_CASE("empty()"){
  CHECK(i1.empty() == false);
  CHECK(i2.empty() == true);
  i2.push_back(56);
  CHECK(i2.empty() == false);
  i2.clear();
  CHECK(i2.empty() == true);
}
