/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Barriers Class
 *
 * \section Barriers
 *
 * This class is used to create a Barrier instance throught the implementation of semaphores to control
 * the output of threads.
 */

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>
Barrier::~Barrier() {}

Barrier::Barrier(int numThreads) :numThreads(numThreads),
sem1(std::shared_ptr<Semaphore>(new Semaphore(0))),
sem2(std::shared_ptr<Semaphore>(new Semaphore(1))),
mutex1(std::shared_ptr<Semaphore>(new Semaphore(1))){
}


void Barrier::wait() {

    mutex1->Wait();
    i++;

    if(i == numThreads){
        sem2->Wait();
        sem1->Signal();
    }
    mutex1->Signal();


    sem1->Wait();
    sem1->Signal();

    mutex1->Wait();

    i--;

    if (i == 0){
        sem1->Wait();
        sem2->Signal();
    }

    mutex1->Signal();

    sem2->Wait();
    sem2->Signal();

}


