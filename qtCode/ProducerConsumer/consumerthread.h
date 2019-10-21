#ifndef CONSUMERTHREAD_H
#define CONSUMERTHREAD_H
#include <QThread>
#include <memory>
#include "mybuffer.h"
#include "myevent.h"
/**
 * @brief The ConsumerThread class
 * A thread that takes events from the shared buffer and consumes them!
 */
class ConsumerThread: public QThread
{
    std::shared_ptr<myBuffer<myEvent>> theBuffer;
public:
    ConsumerThread(std::shared_ptr<myBuffer<myEvent>>);
    void run();
};

#endif // CONSUMERTHREAD_H
