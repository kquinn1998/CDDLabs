/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 6 CDD Labs
 *
 * \section Producers and Consumers
 *
 * This lab demonstartes Producers and Consumers using a buffer.
 * A producer creates an event or process which it then places on a buffer.
 * the consumer then takes a process from a given buffer when triggered to.
 */

#include "SafeBuffer.h"
#include "Event.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
const int size=20;


/*! \fn void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
    \brief In this function we use a passed in Buffer and an integer variable to control the amount of tasks to be added to the buffer.
    \param theBuffer this is the implementation of the SafeBuffer which tasks are stored onto by producers and taken from by consumers
    \param numLoops used to decide with the for loop how many times it will increment
    \details This function creates an event in which it places on to the buffer.
*/
void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    Event e;
    theBuffer->push(e);
  }
}

/*! \fn void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
    \brief In this function we use a passed in Buffer and an integer variable to control the amount of tasks to be taken from the buffer and processed.
    \param theBuffer this is the implementation of the SafeBuffer which tasks are stored onto by producers and taken from by consumers
    \param numLoops used to decide with the for loop how many times it will increment
    \details This function takes an event from the buffer and processes it.
*/
void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    Event e= theBuffer->pop();
    e.consume();
  }
}

int main(void){

  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer( new SafeBuffer());
  /**< Launch the threads  */
  for(std::thread& p: producers){
    p=std::thread(producer,aBuffer,10);
  }

  for(std::thread& c: consumers){
    c=std::thread(consumer,aBuffer,10);
  }

  /**< Join the threads with the main thread */
  for (auto& p :producers){
      p.join();
  }
  for (auto& c :consumers){
      c.join();
  }

  std::cout  << std::endl;
  return 0;
}
