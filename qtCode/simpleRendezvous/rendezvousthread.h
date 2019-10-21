#ifndef RENDEZVOUSTHREAD_H
#define RENDEZVOUSTHREAD_H
#include <QSemaphore>
#include <QThread>
#include <memory>
#include <iostream>
class RendezvousThread : public QThread
{
    std::shared_ptr<QSemaphore> firstSemaphore;
    std::shared_ptr<QSemaphore> secondSemaphore;
    int waitTime;
public:
    RendezvousThread(std::shared_ptr<QSemaphore>, std::shared_ptr<QSemaphore>, int);
    void run();
};

#endif // RENDEZVOUSTHREAD_H
