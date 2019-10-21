#include "Firstthread.h"

/**
 * @brief FirstThread::FirstThread
 *
 * Creates Thread object with a shared Semaphore.
 * Do this with initialisation list
 *
 * @param theSem (QSemaphore) :The Shared Semaphore
 */
FirstThread::FirstThread(std::shared_ptr<QSemaphore> &theSem)
    :theSemaphore(theSem)
{
 //Nothing to do here
}


/**
 * @brief FirstThread::run
 *
 * We must implement a run method that will run when the start() method is called.
 * all the thread work is done here.
 * Prints a message to console and then releases Semaphore
 */
void FirstThread::run(){
    sleep(2);
    std::cout <<"I ";
    std::cout << "must ";
    std::cout << "print ";
    std::cout << "first"<<std::endl;
    theSemaphore->release();
}
