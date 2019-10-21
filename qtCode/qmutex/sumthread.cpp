#include "sumthread.h"

SumThread::SumThread(std::shared_ptr<int> theSum, std::shared_ptr<QMutex> mutex)
    :count(theSum), theMutex(mutex)
{
    //NOTHING TO DO HERE
}

void SumThread::run()
{
    for(int i=0; i<100;++i)
   {
        theMutex->lock();
        *count+=1;
        theMutex->unlock();
    }
}
