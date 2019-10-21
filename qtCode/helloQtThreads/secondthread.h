#ifndef SECONDTHREAD_H
#define SECONDTHREAD_H

#include <QSemaphore>
#include <QThread>
/** required headers for using shared_ptr follow */
#include <iostream>
#include <memory>


class SecondThread: public QThread
{
    std::shared_ptr<QSemaphore> theSemaphore;
public:
    SecondThread(std::shared_ptr<QSemaphore>&);
    void run ();
};


#endif // SECONDTHREAD_H
