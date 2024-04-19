#include <iostream>

int main(){
    unsigned char i=0;
    int a=0;
    std::cout << "|-------|---------------|" << std::endl;
    std::cout << "|-------|---------------|" << std::endl;
for ( i = 0; i <= 128; i++,a++)
{
    std::cout <<"  " <<a <<"      " << i <<"             " << std::endl;
    std::cout << "|-----------------------|" << std::endl;
}
}