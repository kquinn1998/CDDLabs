#include "barrier.h"

Barrier::Barrier(int numThreads):
    threadCount(0),threadTotal(numThreads)
{

}


Barrier::~Barrier()
{
    /**NOTHING TO DO HERE*/
}
void Barrier::phaseOne()
{
    theLock.lock();
    ++threadCount;
    if (threadCount==threadTotal)
    {
        turnstileOne.release(threadTotal);
    }
    theLock.unlock();
    turnstileOne.acquire();
}

void Barrier::phaseTwo()
{
    theLock.lock();
    --threadCount;
    if(threadCount==0)
    {
        turnstileTwo.release(threadTotal);
    }
    theLock.unlock();
    turnstileTwo.acquire();
}
void Barrier::wait()
{
    phaseOne();
    phaseTwo();
}

