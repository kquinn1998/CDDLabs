#include <iostream>
#include <thread>
#include <unistd.h>
#include "semaphore.h"

using namespace std;
/**
 * @brief taskOne
 *
 * This prints out a message before the second thread does any work
 * @param theSemaphore
 * @param delay
 */
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}


/*! displays a message second*/
/**
 * @brief taskTwo
 *
 * This prints out a message  after the first thread has finished
 * @param theSemaphore
 */
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
    theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}


/**
 * @brief main
 *
 * We launch two threads using the built-in std::pthread
 * and a custom Semaphore class
 * @return 0 on success
 */
int main()
{
    std::thread threadOne, threadTwo;
    std::shared_ptr<Semaphore> sem( new Semaphore);
    /**< Launch the threads  */
    int taskOneDelay=5;
    threadOne=std::thread(taskTwo,sem);
    threadTwo=std::thread(taskOne,sem,taskOneDelay);
    std::cout << "Launched from the main\n";
     /**< Wait for the threads to finish */
    threadOne.join();
    threadTwo.join();
    return 0;
}
