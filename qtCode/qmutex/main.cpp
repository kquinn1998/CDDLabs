#include <QCoreApplication>
#include <vector>
#include <memory>
#include <iostream>
#include <QMutex>
#include "sumthread.h"


int main(int argc, char *argv[])
{
    const int num_threads=100;
    std::shared_ptr<int> sharedVariable =std::make_shared<int> (0);
    std::vector<std::shared_ptr<SumThread>> vt(num_threads);
    std::shared_ptr<QMutex> theMutex( new QMutex);
    /** Create the Threads */
    for(std::shared_ptr<SumThread>& thread: vt)
    {
        thread=std::make_shared<SumThread> (sharedVariable,theMutex);
    }
    std::cout << "Threads created " << std::endl;
    /** Launch the threads  */
    for(std::shared_ptr<SumThread>& t: vt){
      t->start();
    }
    std::cout << "Launched from the main\n";
    /**  Join the threads with the main thread */
    for (auto& v :vt){
        v->wait();
    }
    std::cout << *sharedVariable << std::endl;
    return 0;
}
