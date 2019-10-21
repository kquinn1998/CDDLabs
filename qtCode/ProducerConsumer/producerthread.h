#ifndef PRODUCERTHREAD_H
#define PRODUCERTHREAD_H

#include <QThread>
#include <memory>
#include "mybuffer.h"
#include "myevent.h"
/**
 * @brief The ProducerThread class
 * A thread that creates events and puts them into theshared buffer!
 */
class ProducerThread :public QThread
{
    std::shared_ptr<myBuffer<myEvent>> theBuffer;
public:
    ProducerThread(std::shared_ptr<myBuffer<myEvent>>);
    void run();
};

#endif // PRODUCERTHREAD_H
