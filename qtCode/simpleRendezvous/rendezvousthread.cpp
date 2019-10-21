#include "rendezvousthread.h"

/**
 * @brief RendezvousThread::RendezvousThread
 *
 * Constructor.
 * Initialise both semaphores and set a delay time (in seconds)
 * @param one :First Semaphore
 * @param two :Second Semaphore
 * @param delay :Time to sleep in seconds before thread prints first message
 */
RendezvousThread::RendezvousThread(std::shared_ptr<QSemaphore> one, std::shared_ptr<QSemaphore> two, int delay)
    :firstSemaphore(one),secondSemaphore(two),waitTime(delay)
{
    //NOTHING TO DO HERE
}

/**
 * @brief RendezvousThread::run
 *
 * Print a message then wait at rendezvous point until second thread reaches same point
 *
 */
void RendezvousThread::run()
{
    sleep(waitTime);
    std::cout <<"Task has arrived at rendezvous point! "<< std::endl;
    /** Rendezvous point is here - enforce with Semaphores */
    firstSemaphore->release();
    secondSemaphore->acquire();
    std::cout << "Task has passed rendezvous point!"<<std::endl;
}
