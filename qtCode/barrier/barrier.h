#ifndef BARRIER_H
#define BARRIER_H
#include <QMutex>
#include <QSemaphore>
#include <memory>

class Barrier
{
    int threadCount;
    int threadTotal;
    QMutex theLock;
    QSemaphore turnstileOne;
    QSemaphore turnstileTwo;

public:
    Barrier(int numThreads);
    virtual ~Barrier();
    void wait();
    void phaseOne();
    void phaseTwo();
};

#endif // BARRIER_H

