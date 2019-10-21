#include "secondthread.h"

/**
 * @brief SecondThread::SecondThread
 *
 * Creates Thread object with a shared Semaphore
 * @param theSem (QSemaphore) :The Shared Semaphore
 */
SecondThread::SecondThread(std::shared_ptr<QSemaphore> &theSem)
    :theSemaphore(theSem)
{

}

/**
 * @brief SecondThread::run
 *
 * Prints a message to console after acquiring semaphore
 */
void SecondThread::run(){
    theSemaphore->acquire();
    std::cout <<"We ";
    std::cout << "will ";
    std::cout << "show ";
    std::cout << "second"<<std::endl;

}
