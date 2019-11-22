/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 6 CDD Labs
 *
 * \section SafeBuffer Class
 *
 * This class demonstrates how a buffer can be created to be used with concurrency,
 * whilst implementing semaphores to control task delegation between threads.
 */

#include "SafeBuffer.h"
#include <iostream>

SafeBuffer::SafeBuffer() {
  items = std::make_shared<Semaphore>(0);
  mutex = std::make_shared<Semaphore>(1);
  spaces = std::make_shared<Semaphore>(100);
}

/*! \fn void SafeBuffer::Add(char c)
    \brief With this function we begin by checking if the buffer is full then we mutex it to make it safe the add the char to the buffer
    \param c this is the char to be added to the buffer.
*/

void SafeBuffer::Add(char c) {
  spaces->Wait();
  mutex->Wait();
  safeBuffer.push(c);
  mutex->Signal();
  items->Signal();
}

/*! \fn void SafeBuffer::Remove()
    \brief This first checks if there are items to be consumed, it then locks the mutex and removes the item.
    \param c this is the char to be added to the buffer.
*/
char SafeBuffer::Remove() {
  char c;
  items->Wait();
  mutex->Wait();
  c = safeBuffer.front();
  safeBuffer.pop();
  mutex->Signal();
  spaces->Signal();
  return c;
}