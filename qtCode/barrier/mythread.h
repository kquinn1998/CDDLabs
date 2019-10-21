#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <memory>
#include  <QMutex>
#include "barrier.h"

class myThread: public QThread
{
    std::shared_ptr<Barrier> theBarrier;
    int numLoops;
public:
    myThread(std::shared_ptr<Barrier>, int);
    void run();
};

#endif // MYTHREAD_H
