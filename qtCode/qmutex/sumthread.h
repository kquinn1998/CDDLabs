#ifndef SUMTHREAD_H
#define SUMTHREAD_H
#include <QThread>
#include <memory>
#include  <QMutex>

class SumThread: public QThread
{
    std::shared_ptr<int> count;
    std::shared_ptr<QMutex> theMutex;
public:
    SumThread(std::shared_ptr<int>, std::shared_ptr<QMutex>);
    void run();
};

#endif // SUMTHREAD_H
