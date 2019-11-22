/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Barriers Header
 *
 * \section Barriers
 *
 * This class is used to create a Barrier instance throught the implementation of semaphores to control
 * the output of threads.
 */

/* Code: */
#include "Semaphore.h"
#pragma once
class Barrier{
    int numThreads;

    std::shared_ptr<Semaphore> sem1 ;
    std::shared_ptr<Semaphore> sem2 ;
    std::shared_ptr<Semaphore> mutex1 ;

  int i=0;
 public:
  Barrier(int numThreads);
  virtual ~Barrier();
  void wait();  
};

/* Barrier.h ends here */
