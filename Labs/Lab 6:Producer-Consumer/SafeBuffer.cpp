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
#include "Event.h"
#include <vector>
#include "Semaphore.h"

SafeBuffer::SafeBuffer(){
  mutex = std::make_shared<Semaphore>(1);
  sem1=std::make_shared<Semaphore>(0);
}

int SafeBuffer::push(Event e){
  mutex->Wait();
  data.push_back(e);
  int s = data.size();
  sem1->Signal();
  mutex->Signal();
  return s;
}

Event SafeBuffer::pop(){
  sem1->Wait();
  mutex->Wait();
  Event e = data.back();
  data.pop_back();
  mutex->Signal();
  return e;
}