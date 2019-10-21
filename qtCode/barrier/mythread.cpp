#include "mythread.h"
#include <iostream>

myThread::myThread(std::shared_ptr<Barrier> aBarrier, int totalLoops):
    theBarrier(aBarrier),numLoops(totalLoops)
{

}

void myThread::run()
{
    for(int i=0;i<numLoops;++i){
       //Do first bit of task
       std::cout << "A"<< i;
       //Barrier
       theBarrier->wait();
       //Do second half of task
       std::cout<< "B" << i;
       theBarrier->wait();
    }
}
