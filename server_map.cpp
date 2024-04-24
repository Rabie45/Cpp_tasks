#include <chrono>
#include <cstdlib>
#include <iostream>
#include <map>
#include <thread>

/*
Confugre -> drop, connected
connected -> configure,send, drop
drop->idle
sending ->Idle,drop
idle
*/
enum class states : unsigned char { CONFIURE, CONNECTED, DROP, SENDING, IDLE };
enum class goto_states : unsigned char {
  GOTO_CONFIURE,
  GOTO_CONNECTED,
  GOTO_DROP,
  GOTO_SENDING,
  GOTO_IDLE
};
bool preform() { return true; }
int main() {
  states current = states::IDLE;
  std::map<states, std::map<goto_states, states>> mymap;
  mymap[states::CONFIURE] = {
      {goto_states::GOTO_DROP, states::DROP},
      {goto_states::GOTO_CONNECTED, states::CONNECTED},
  };
  mymap[states::CONNECTED] = {
      {goto_states::GOTO_SENDING, states::SENDING},
      {goto_states::GOTO_DROP, states::DROP},
      {goto_states::GOTO_CONFIURE, states::CONFIURE},
  };
  mymap[states::DROP] = {
      {goto_states::GOTO_IDLE, states::IDLE},
  };
  mymap[states::SENDING] = {
      {goto_states::GOTO_IDLE, states::IDLE},
      {goto_states::GOTO_DROP, states::DROP},
  };
  mymap[states::IDLE] = {
      {goto_states::GOTO_CONFIURE, states::CONFIURE},
  };
  while (1) {

    switch (current) {
    case states::IDLE:
      std::cout << "IDLE state" << std::endl;
      if (preform()) {
        current = mymap[current][goto_states::GOTO_CONFIURE];
      }
      break;
    case states::CONFIURE:
      std::cout << "CONFIUGRE state" << std::endl;
      if(!preform()){
        current = mymap[current][goto_states::GOTO_CONNECTED];
      }
      else if (preform()) {
      current=mymap[current][goto_states::GOTO_DROP];
      }

      break;
    case states::CONNECTED:
      std::cout << "CONNECTED state" << std::endl;
      if (preform()) {
        current = mymap[current][goto_states::GOTO_SENDING];
      }else if(!preform()){
        current = mymap[current][goto_states::GOTO_CONFIURE];
      }else{
        current = mymap[current][goto_states::GOTO_DROP];
      }
      break;
    case states::DROP:
      std::cout << "DROP state" << std::endl;
      exit(0);
      break;
    case states::SENDING:
      std::cout << "SENDING state" << std::endl;
      break;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}