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
#include <iostream>
#include <chrono>
#include <thread>


int characterCountBuffer[26] = {0};


/*! \fn void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
    \brief In this function we use a passed in Buffer and an integer variable to control the amount of tasks to be added to the buffer.
           A random char is added to the buffer each time
    \param theBuffer this is the implementation of the SafeBuffer which tasks are stored onto by producers and taken from by consumers
    \param numLoops used to decide with the for loop how many times it will increment
    \details This function creates an event in which it places on to the buffer.
*/
void ProducerMethod(std::shared_ptr<SafeBuffer> theBuffer, int numOfLoops) {
  char c;
  int i = 0;
  do {
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
    c =  std::rand() % 26 + 97;
    if ( ++i == numOfLoops ) {
      c = 'X';
    }
    theBuffer->Add(c);
    std::cout << "Producing " << c << std::endl;
  } while ( c != 'X' );
}

/*! \fn void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops)
    \brief In this function we use a passed in Buffer and an integer variable to control the amount of tasks to be taken from the buffer 
           and then we count the occurence of the charachter.
    \param theBuffer this is the implementation of the SafeBuffer which tasks are stored onto by producers and taken from by consumers
    \details This function takes an event from the buffer and processes it.
*/
void ConsumerMethod(std::shared_ptr<SafeBuffer> theBuffer) {
  char c;
  do {
    c = theBuffer->Remove();
    std::cout << "Consuming " << c << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
    characterCountBuffer[c]++;
  } while ( c != 'X');
}

/*! \fn void PrintArray()
    \brief This is used to print out the occurence of each charachter.
*/
void PrintArray() {
  for ( char i = 97; i < 123; ++i ) {
    std::cout << i << " " << characterCountBuffer[i] << std::endl;
  }
}

int main(void) {
  int numOfLoops;
  std::shared_ptr<SafeBuffer> theBuffer(new SafeBuffer);
  std::thread producer[10];
  std::thread consumer[10];

  std::cout << "How many characters do we add?" << std::endl;
  std::cin >> numOfLoops;

  for ( int i = 0; i < 10; i++ ) {
    producer[i] = std::thread(ProducerMethod, theBuffer, numOfLoops);
    consumer[i] = std::thread(ConsumerMethod, theBuffer);
  }

  for ( int i = 0; i < 10; ++i ) {
    producer[i].join();
    consumer[i].join();
  }

  PrintArray();
  std::cout << "All Threads Finished, back in main"<< std::endl;
  return 0;
}
