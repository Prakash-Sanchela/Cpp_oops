# create two threads which prints odd and even number one by one

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int number = 0;
std::mutex mt;
void print_even()
{
    while(number < 20){
        std::lock_guard<std::mutex> lock(mt);
        //std::unique_lock<std::mutex> lock(mt);
        if (number%2 == 0)
            cout << "even : " <<number++ <<endl;
        //lock.unlock();
    }
    return;
}

void print_odd()
{
    while(number < 20) {
        std::lock_guard<std::mutex> lock(mt);
        //std::unique_lock<std::mutex> lock(mt);
        if (number %2 != 0)
            cout << "Odd : " <<number++ <<endl;
        //lock.unlock();
    }
    return;
}
int main()
{
    std::cout<<"Hello World"<<endl;
    std::thread t1(print_even);
    std::thread t2(print_odd);
    
    t1.join();
    t2.join();
    return 0;
}
