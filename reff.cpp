#include <iostream>

void val(int &v);
void val(int &v){
v=1000;
std::cout<<v<<std::endl;
}
int main(){
int x=5;
int &y=x;
val(y);
std::cout<<y<<std::endl;
}