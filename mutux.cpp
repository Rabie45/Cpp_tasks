

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <ostream>
#include <thread>
std::mutex m;
int balance = 0;
std::condition_variable cv;
void addMoney(int value) {

  std::lock_guard<std::mutex> ad(m);
  balance += value;
  std::cout << "New balance=:" << balance << std::endl;
  cv.notify_one();
}
void getMoney(int value) {
  std::unique_lock<std::mutex> gm(m);
  std::cout << "I am stck here" << std::endl;

  cv.wait(gm, [] {
    if (balance)
      return true;
    else
      false;
  });
  if (balance > value) {
    std::cout << "u Have money to get" << std::endl;
    balance -= value;
  } else {
    std::cout << "the balance is low" << std::endl;
  }
  std::cout << "Current balcnce is :" << balance << std::endl;
}

int main() {
  std::thread t1(addMoney, 200);
  std::thread t2(getMoney, 200);
  t1.join();
  t2.join();

  return 0;
}