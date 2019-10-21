#ifndef FIRSTTHREAD_H
#define FIRSTTHREAD_H

#include <QSemaphore>
#include <QThread>
/** required headers for using shared_ptr follow */
#include <iostream>
#include <memory>

/**
 * @brief The FirstThread class
 *
 * Sub class of QThread
 * @see QThread
 */
class FirstThread: public QThread
{
    std::shared_ptr<QSemaphore> theSemaphore;
public:
    FirstThread(std::shared_ptr<QSemaphore>&);
    void run ();
};

#endif // FIRSTTHREAD_H
