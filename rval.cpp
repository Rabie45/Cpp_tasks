#include <iostream>
int &fun() {
  int val = 10;
  return val;
}
int main() {

    int val=fun();
//    int &f=fun();
    const int &d=fun();
    fun()=12;
}