#include <iostream>
#include <ostream>

class A {
private:
public:
  A() { std::cout << " Class A Cons" << std::endl; }
  void printMembers() { std::cout << " Class A" << std::endl; }
};
class B : public A {
private:
  int x;
  int y;

public:
  B(int x, int y) : x(x), y(y) { std::cout << " Class B Cons" << std::endl; }
  void printMembers() {
    std::cout << " Class B" << x << " " << y << " " << std::endl;
  }
};
int main() {
  B b(10, 11);
  b.printMembers();
  return 0;
}