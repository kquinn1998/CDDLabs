/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 4 CDD Labs
 *
 * \section Mutual Exclusion
 *
 *This lab demonstrates mutual exclusion in concurrency using semaphores.
 *We also use the clean function in the make file.
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;

/*! \fn void updateTasks(std::shared_ptr<Semaphore> firstSem, int numUpdates)
    \brief In this function we use a passed in semaphore and an integer variable to change a shared variable safely using the semaphore
    \param firstSem the initialisation of a semaphore to ensure mutual exclusion between threads
    \param numUpdates used to decide with the for loop how many times the shared variable will be updated
    \details This function safely updates a shared variable using mutual exclusion with multiple threads.
*/
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){

 
  for(int i=0;i<numUpdates;i++){
    firstSem->Wait();
    sharedVariable++;
    firstSem->Signal();
  }

}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore(1));

  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }

  std::cout << "Launched from the main\n";

  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
