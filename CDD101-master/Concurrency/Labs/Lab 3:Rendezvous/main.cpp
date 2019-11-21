/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 3 CDD Labs
 *
 * \section Rondevoux
 *
 *This lab demonstrated rondevoux's.
 *This is done by having the two threads sync up at a
 *certain point before continuing.  
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! \fn void taskOne(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay)
    \brief IN this function the second sem will signal the first too run if it is waiting
    \param firstSem the first initialisation of a semaphore
    \param secondSem the second initialisation of a semaphore
    \param delay used for sleep() function
    \details This task runs first
*/

void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task One has arrived! "<< std::endl;

  /*! if secondSem is waiting signal to run and tell firstSem to wait till secondSem is done*/
  secondSem->Signal();
  firstSem->Wait();

  std::cout << "Task One has left!"<<std::endl;
}
/*! \fn void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay)
    \brief IN this function the first sem will signal the second too run if it is waiting
    \param firstSem the first initialisation of a semaphore
    \param secondSem the second initialisation of a semaphore
    \param delay used for sleep() function
    \details This task runs first
*/
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task Two has arrived "<<std::endl;

  /*! if firstSem is waiting signal to run and tell secondSem to wait till firstSem is done*/
  firstSem->Signal();
  secondSem->Wait();

  std::cout << "Task Two has left "<<std::endl;
}

/*! \fn int main(void)
    \brief Description of main functionality
    \details This is the driver for the demonstration of a semaphore, it creates two threads and two semaphores and the runs the two threads
*/

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2,taskTwoDelay);
  threadTwo=std::thread(taskOne,sem1,sem2,taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
