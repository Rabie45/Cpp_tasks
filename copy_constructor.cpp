#include <cstddef>
#include <cstring>
#include <iostream>

class String {

private:
  int size;
  char *chr;

public:
  String(char *chr) : chr(chr) { std::cout << &chr << std::endl; }
  //   String(String &obj) { // copy data with reff
  //     this->size = obj.size;
  //     this->chr = obj.chr;
  //     std::cout << " String(String   &obj)" << std::endl;
  //   }
  String(const String &obj) { // copy data with reff
    this->size = obj.size;
    this->chr = new char(size + 1);
    strcpy(this->chr, obj.chr);
    std::cout << " String(String   &obj)" << std::endl;
  }
  void fun() { std::cout << chr << std::endl; }
  void changeIndexChar(int val, char ch) { chr[val] = ch; }
  void change1stchar(char value) { *chr = value; }
  String() : chr(nullptr), size(0) { // copy data with reff
  }
  String &operator=(String &&obj) {
    if (this != &obj) {
      this->size = obj.size;
      this->size=0;
      this->chr= new char(size+1);
      obj.chr=nullptr;
    }

    return *this;
  }
  String &operator<(String &obj) {
    if (&obj != this) {
      this->size = obj.size;
      if (this->chr) {
        delete[] this->chr;
      }
      this->chr = obj.chr;
      obj.chr = nullptr;
    }
    return *this;
  }
};

int main() {
  char ch[] = "Rabie";
  String str{ch};
  String t2(str);
  String t3;
  t3 = std::move(t2);
  str.change1stchar('A');
  str.fun();
  t2.change1stchar('S');
  t2.fun();
  t3.fun();
  String t4;
  t4 < t2;

  t4.fun();
  t2.fun();
  return 0;
}