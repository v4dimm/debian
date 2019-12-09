#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <unistd.h>

 
std::mutex g_lock;
 
void threadFunction()
{
     g_lock.lock();
 
     std::cout << "runner start " << std::this_thread::get_id() << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(rand()%4));
        for (int i = 0; i < 10; i++) {
        int barrier = rand() % 2;
        if (barrier != 0) {
            sleep(4);
            std::cout << "barrier " << i << std::endl;
        }
        else {
            continue;
        }
    }
    
     std::cout << "runner finishes " << std::this_thread::get_id() << std::endl;
 
     g_lock.unlock();
}
 
int main()
{
     srand((unsigned int)time(0));
     std::thread t1(threadFunction);
     std::thread t2(threadFunction);
     std::thread t3(threadFunction);
     t1.join();
     t2.join();
     t3.join();
     return 0;
}