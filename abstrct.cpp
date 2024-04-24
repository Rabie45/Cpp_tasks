#include <iostream>
#include <ostream>

class A {
private:
public:
   virtual void printMembers() {  std::cout << " Class A " << std::endl;}
};
class B : private A {
private:
  int x;
  int y;

public:
  B(int x, int y) : x(x), y(y) { std::cout << " Class B Cons" << std::endl; }
  void printMembers() override {
    std::cout << " Class B " << x << " " << y << " " << std::endl;
  }
};

class C: private A {
public:
  C(int x, int y) : x(x), y(y) { std::cout << " Class C Cons" << std::endl; }
  void printMembers() {
    std::cout << " Class C " << x << " " << y << " " << std::endl;
  }

private:
  int x;
  int y;
};


int main() {
    A *a;
  B b(10, 11);

  b.printMembers();
  C c(10,11);
  c.printMembers();
  return 0;
}