#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "MyVector.h"

MyVector<int> i1;
MyVector<std::string> s1;
MyVector<double> d1;
MyVector<bool> b1;
MyVector<char> c1;
TEST_CASE("Default Constructor"){
  //int 
  CHECK(i1.size() == 0);
  CHECK(i1.capacity() == 10);
  
  //string 
  CHECK(s1.size() == 0);
  CHECK(s1.capacity() == 10);
  
  //double
  CHECK(d1.size() == 0);
  CHECK(d1.capacity() == 10);

  //boolean
  CHECK(b1.size() == 0);
  CHECK(b1.capacity() == 10);

  //char
  CHECK(c1.size() == 0);
  CHECK(c1.capacity() == 10);
}

MyVector<int> i2 (20);
MyVector<std::string> s2 (20);
MyVector<double> d2 (20);
MyVector<bool> b2 (20);
MyVector<char> c2 (20);
TEST_CASE("Parameterized Constructor"){
  //int
  CHECK(i2.size() == 0);
  CHECK(i2.capacity() == 20);
  
  //string
  CHECK(s2.size() == 0);
  CHECK(s2.capacity() == 20);
  
  //double
  CHECK(d2.size() == 0);
  CHECK(d2.capacity() == 20);

  //boolean
  CHECK(b2.size() == 0);
  CHECK(b2.capacity() == 20);

  //char
  CHECK(c2.size() == 0);
  CHECK(c2.capacity() == 20);
}

TEST_CASE("push_back(T)"){
  //int
  i1.push_back(23);
  CHECK(i1[0] == 23);
  i1.push_back(34);
  CHECK(i1[1] == 34);
  i1.push_back(76);
  CHECK(i1[2] == 76);
  
  //string
  s1.push_back("how");
  CHECK(s1[0] == "how");
  s1.push_back("are");
  CHECK(s1[1] == "are");
  s1.push_back("you");
  CHECK(s1[2] == "you");
  
  //double
  d1.push_back(23.3);
  CHECK(d1[0] == 23.3);
  d1.push_back(.342);
  CHECK(d1[1] == .342);
  d1.push_back(-3.3);
  CHECK(d1[2] == -3.3);

  //boolean
  b1.push_back(0);
  CHECK(b1[0] == 0);
  b1.push_back(false);
  CHECK(b1[1] == false);
  b1.push_back(true);
  CHECK(b1[2] == true);

  //char
  c1.push_back(23);
  CHECK(c1[0] == 23);
  c1.push_back(34);
  CHECK(c1[1] == 34);
  c1.push_back('c');
  CHECK(c1[2] == 'c');
}

TEST_CASE("push_back over capacity"){
  //int
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
  
  //string
  for(int i=0; i<10; i++){
    s1.push_back(std::to_string(i));
  }
  item = 0;
  for(int i=3; i<13; i++){
    CHECK(s1[i] == std::to_string(item));
    item++;
  }
  CHECK(s1.size() == 13);
  CHECK(s1.capacity() == 13);
  
  //double
  for(int i=0; i<10; i++){
    d1.push_back(i+0.5);
  }
  item = 0;
  for(int i=3; i<13; i++){
    CHECK(d1[i] == item+0.5);
    item++;
  }
  CHECK(d1.size() == 13);
  CHECK(d1.capacity() == 13);

  //boolean
  for(int i=0; i<10; i++){
    if (i%2 == 0){
      b1.push_back(0);
    }
    else {
      b1.push_back(1);
    }
  }
  item = 0;
  for(int i=3; i<13; i++){
    if (item%2 == 0){
      CHECK(b1[i] == 0);
    }
    else {
      CHECK(b1[i] == 1);
    }
    item++;
  }
  CHECK(b1.size() == 13);
  CHECK(b1.capacity() == 13);

  //char
  for(int i=0; i<10; i++){
    c1.push_back(i);
  }
  item = 0;
  for(int i=3; i<13; i++){
    CHECK(c1[i] == item);
    item++;
  }
  CHECK(c1.size() == 13);
  CHECK(c1.capacity() == 13);
}

TEST_CASE("pop_back()"){
  //int
  i1.pop_back();
  CHECK(i1.size() == 12);
  CHECK(i1.capacity() == 13);
  i1.pop_back();
  CHECK(i1.size() == 11);
  CHECK(i1.capacity() == 13);
  
  //string
  s1.pop_back();
  CHECK(s1.size() == 12);
  CHECK(s1.capacity() == 13);
  s1.pop_back();
  CHECK(s1.size() == 11);
  CHECK(s1.capacity() == 13);
  
  //double
  d1.pop_back();
  CHECK(d1.size() == 12);
  CHECK(d1.capacity() == 13);
  d1.pop_back();
  CHECK(d1.size() == 11);
  CHECK(d1.capacity() == 13);

  //boolean
  b1.pop_back();
  CHECK(b1.size() == 12);
  CHECK(b1.capacity() == 13);
  b1.pop_back();
  CHECK(b1.size() == 11);
  CHECK(b1.capacity() == 13);

  //char
  c1.pop_back();
  CHECK(c1.size() == 12);
  CHECK(c1.capacity() == 13);
  c1.pop_back();
  CHECK(c1.size() == 11);
  CHECK(c1.capacity() == 13);
}

TEST_CASE("pop_back(n)"){
  //int 
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
  
  //string
  s1.pop_back(0);
  s1.pop_back(0);
  s1.pop_back(0);
  for (int i=0; i<8; i++){
    CHECK(s1[i] == std::to_string(i));
  }
  s1.pop_back(5);
  for(int i=0; i<7; i++){
    if (i < 5){
      CHECK(s1[i] == std::to_string(i));
    }
    else {
      CHECK(s1[i] == std::to_string(i+1));
    }
  }
  s1.pop_back(2);
  for(int i=0; i<6; i++){
    if (i > 3){
      CHECK(s1[i] == std::to_string(i+2));
    }
    else if(i > 1){
      CHECK(s1[i] == std::to_string(i+1));
    }
    else{
      CHECK(s1[i] == std::to_string(i));
    }
  }
  
  //double
  d1.pop_back(0);
  d1.pop_back(0);
  d1.pop_back(0);
  for (int i=0; i<8; i++){
    CHECK(d1[i] == i+0.5);
  }
  d1.pop_back(5);
  for(int i=0; i<7; i++){
    if (i < 5){
      CHECK(d1[i] == i+0.5);
    }
    else {
      CHECK(d1[i] == i+1.5);
    }
  }
  d1.pop_back(2);
  for(int i=0; i<6; i++){
    if (i > 3){
      CHECK(d1[i] == i+2.5);
    }
    else if(i > 1){
      CHECK(d1[i] == i+1.5);
    }
    else{
      CHECK(d1[i] == i+0.5);
    }
  }

  //boolean
  b1.pop_back(0);
  b1.pop_back(0);
  b1.pop_back(0);
  for (int i=0; i<8; i++){
    if (i%2 == 0){
      CHECK(b1[i] == 0);
    }
    else {
      CHECK(b1[i] == 1);
    }
  }
  b1.pop_back(5);
  for(int i=0; i<7; i++){
    if (i < 5){
      CHECK(b1[i] == i%2);
    }
    else {
      CHECK(b1[i] == (i+1)%2);
    }
  }
  b1.pop_back(2);
  for(int i=0; i<6; i++){
    if (i > 3){
      CHECK(b1[i] == (i+2)%2);
    }
    else if(i > 1){
      CHECK(b1[i] == (i+1)%2);
    }
    else{
      CHECK(b1[i] == (i%2));
    }
  }

  //char
  c1.pop_back(0);
  c1.pop_back(0);
  c1.pop_back(0);
  for (int i=0; i<8; i++){
    CHECK(c1[i] == i);
  }
  c1.pop_back(5);
  for(int i=0; i<7; i++){
    if (i < 5){
      CHECK(c1[i] == i);
    }
    else {
      CHECK(c1[i] == i+1);
    }
  }
  c1.pop_back(2);
  for(int i=0; i<6; i++){
    if (i > 3){
      CHECK(c1[i] == i+2);
    }
    else if(i > 1){
      CHECK(c1[i] == i+1);
    }
    else{
      CHECK(c1[i] == i);
    }
  }

}

TEST_CASE("clear()"){
  //int
  i2.push_back(21);
  i2.push_back(4);
  i2.push_back(64);
  i2.clear();
  CHECK(i2.size() == 0);
  CHECK(i2.capacity() == 10);
  CHECK(i2.empty() == true);
  
  //string
  s2.push_back(std::to_string(21));
  s2.push_back(std::to_string(4));
  s2.push_back(std::to_string(64));
  s2.clear();
  CHECK(s2.size() == 0);
  CHECK(s2.capacity() == 10);
  CHECK(s2.empty() == true);
  
  //double
  d2.push_back(21.3);
  d2.push_back(4.4);
  d2.push_back(64.5);
  d2.clear();
  CHECK(d2.size() == 0);
  CHECK(d2.capacity() == 10);
  CHECK(d2.empty() == true);

  //boolean
  b2.push_back(0);
  b2.push_back(1);
  b2.push_back(1);
  b2.clear();
  CHECK(b2.size() == 0);
  CHECK(b2.capacity() == 10);
  CHECK(b2.empty() == true);
}

TEST_CASE("empty()"){
  //int 
  CHECK(i1.empty() == false);
  CHECK(i2.empty() == true);
  i2.push_back(56);
  CHECK(i2.empty() == false);
  i2.clear();
  CHECK(i2.empty() == true);
  
  //string
  CHECK(s1.empty() == false);
  CHECK(s2.empty() == true);
  s2.push_back(std::to_string(56));
  CHECK(s2.empty() == false);
  s2.clear();
  CHECK(s2.empty() == true);
  
  //double
  CHECK(d1.empty() == false);
  CHECK(d2.empty() == true);
  d2.push_back(5.42);
  CHECK(d2.empty() == false);
  d2.clear();
  CHECK(d2.empty() == true);

  //boolean
  CHECK(b1.empty() == false);
  CHECK(b2.empty() == true);
  b2.push_back(1);
  CHECK(b2.empty() == false);
  b2.clear();
  CHECK(b2.empty() == true);

  //char
  CHECK(c1.empty() == false);
  CHECK(c2.empty() == true);
  c2.push_back(56);
  CHECK(c2.empty() == false);
  c2.clear();
  CHECK(c2.empty() == true);
}





