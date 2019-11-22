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


#include <mutex>
#include "Semaphore.h"
#include <queue>

class SafeBuffer {
 public:
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> items;
  std::shared_ptr<Semaphore> spaces;
  std::queue<char> safeBuffer;
  SafeBuffer();
  void Add(char);
  char Remove();
};

