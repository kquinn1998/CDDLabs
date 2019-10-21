#include <QCoreApplication>
#include <QSemaphore>
/** Required includes for use of shared pointers*/
#include <memory>
#include <iostream>
/** Our new thread class*/
#include "rendezvousthread.h"

/**
 * @brief main
 *
 * Create and run two threads with a rendezvous point.
 * Semaphores are used to enforce Rendezvous point
 * @param argc: unused
 * @param argv :unused
 * @return: 0 on exit
 */
int main(int argc, char *argv[])
{

    std::shared_ptr<QSemaphore> sem1( new QSemaphore);
    std::shared_ptr<QSemaphore> sem2( new QSemaphore);
    int taskOneDelay=5;
    int taskTwoDelay=1;
    /** Create the threads  */
    RendezvousThread threadOne(sem1,sem2,taskOneDelay);
    RendezvousThread threadTwo(sem2,sem1,taskTwoDelay);
    threadOne.start();
    threadTwo.start();
    std::cout << "Hello from the main thread" <<std::endl;
    threadOne.wait();
    threadTwo.wait();
    return 0;
}
