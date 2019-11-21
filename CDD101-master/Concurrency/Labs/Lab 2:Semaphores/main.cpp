/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: Thread processing the second task must wait for thread executing the first task.
 */

 /** @brief An implementation of a semaphore
 *
 * 
 * 
 * @return a message 
 * @param theSem shared semaphore object
 * @param delay represents the time for the thread to sleep.
 */

/*! \mainpage Lab 2 CDD Labs
 *
 * \section Semaphores
 *
 * With this lab I am demonstrating how semaphores work by creating mutual exclusion, by making task 2 wait for task 1.
 *  
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

/*! \fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay)
    \brief Description of taskOne functionality
    \param theSemaphore semaphore used to create mutual exclusion between two threads created in main
    \param delay used for sleep() function
    \details This task runs first
*/

void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal(); //signals critical section
}

/*! \fn void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
    \brief Description of taskTwo functionality
    \param theSemaphore semaphore used to create mutual exclusion between two threads created in main
    \details This task runs second following the first being complete
*/

void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait(); //waits till thread 1 is complete
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

/*! \fn int main(void)
    \brief Description of main functionality
    \details This is the driver for the demonstration of a semaphore, it creates two threads and a semaphore and the runs the two threads
*/

int main(void){
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
  /*! Final output should show taskOne's message being displayed first and taskTwo's second*/
}
