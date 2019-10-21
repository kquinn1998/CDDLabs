#include <QCoreApplication>
#include <QSemaphore>
/** Next two headers required to use shared_ptr's */
#include <iostream>
#include <memory>

/** Class headers for inclusion */
#include "Firstthread.h"
#include "secondthread.h"


/**
 * @brief main
 *
 *Hello World threads using QSemaphore and QThread.
 * QThread requires us to create a subclass of QThread that implements each thread.
 *
 * @param argc
 * @param argv
 * @return 0 on exit
 */
int main(int argc, char *argv[])
{
    std::cout << "Hello World"<<std::endl;
    std::shared_ptr<QSemaphore> sem_ptr(new QSemaphore);
    FirstThread threadOne(sem_ptr);
    SecondThread threadTwo(sem_ptr);

    /** Launch the threads  */
    int taskOneDelay=5;
    threadOne.start();
    threadTwo.start();
    std::cout << "Launched from the main\n";
     /** Wait for the threads to finish */
    threadOne.wait();
    threadTwo.wait();
    return 0;
}
