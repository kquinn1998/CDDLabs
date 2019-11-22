/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 6 CDD Labs
 *
 * \section SafeBuffer Header
 *
 * This class demonstrates how a buffer can be created to be used with concurrency,
 * whilst implementing semaphores to control task delegation between threads.
 */

#include "Event.h"
#include <vector>
#include "Semaphore.h"

class SafeBuffer {

private:
  std::vector<Event> data;
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> sem1;

public:
  SafeBuffer();
  int push(Event);
  Event pop();
};
