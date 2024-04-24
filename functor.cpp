#include <iostream>
#include <ostream>
class Complex {
  int real;
  float img;

public:
  Complex() = default;
  Complex(int real, float img) : real(real), img(img) {}
  int operator+(int num) {
    std::cout << "real" << std::endl;
    return this->real + num;
  }
  float operator+(float img) {
    std::cout << "img" << std::endl;
    return this->img + img;
  }
  Complex operator+(const Complex &temp) {
    std::cout << "complex" << std::endl;
    Complex result;
    result.img = this->img + temp.img;
    result.real = this->real + temp.real;
    return result;
  }
  int getReal(){
    return this->real;
  }
   float getImg(){
    return this->img;
  }
  operator int(){
    return real;
  }
  operator float(){
    return img;
  }
};

int main() {
Complex a(1,2.3);
Complex b( 2,3.3);
int real=a+3;
float img=a+1.5f;
Complex c=a+b;
std::cout<<c.getImg()<<" "<<c.getReal()<<std::endl;
int x=a;
float y=a;
std::cout<<x<<" "<<y<<std::endl;




}