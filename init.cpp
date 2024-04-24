#include <iostream>
class LED{
public:
int val;
LED(int val) : val(val), x(5),y(6){
std::cout<< "constructor "<<val<<std::endl;
}
void turnLedON(){
   std::cout<< "LED ON"<<val<<std::endl;

}
void turnLedOFF(){
   std::cout<< "LED OFF"<<std::endl;
}
void acess(LED e){
std::cout<<e.x<< e.y<<std::endl;
}
private:
int y;
int x;

};

int main(){

LED led(3);
led.val=5;
led.turnLedON();
led.turnLedOFF();
led.acess(led);
}