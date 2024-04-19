#include<iostream>
#include <cmath>

int main(){
    int x=0,y=0;
    std::cout << "enter x : "<<std::endl;
    std::cin>> x;
    std::cout<< x<<std::endl;
    std::cout << "enter y : "<<std::endl;
    std::cin>>y;
    std::cout<< y<<std::endl;
    std::cout << "Right angle ="<< pow(x,2) + pow(y,2) <<std::endl;

}