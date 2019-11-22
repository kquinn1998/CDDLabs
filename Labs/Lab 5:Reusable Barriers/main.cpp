/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 5 CDD Labs
 *
 * \section Barriers
 *
 * This lab employs the use of reusable barriers to show how it can be used
 * to aid concurrency by making one section of threads run first then the second.
 * 
 * With the output we will see that all the A's will be printed first with an integer attached,
 * then all the B's with the integer attached, the for loop then incremenets and the same happens
 * again with a new integer.
 */

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;

/*! \fn void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops)
    \brief In this function we use a passed in Barrier and an integer variable to control the amount of interation occurs.
    \param theBarrier this is the implementation of the barrier class which which will control the output of the threads
    \param numLoops used to decide with the for loop how many times it will increment
    \details This function demonstrates how you can use a barrier to control the output of multiple threads in stages.
*/

void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    theBarrier->wait();
    std::cout << "A"<< i;
    theBarrier->wait();
    std::cout<< "B" << i;
  }
  

}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));

  int i=0;
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
