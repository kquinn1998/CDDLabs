#include <QCoreApplication>
#include <memory>
#include <vector>
#include <iostream>

#include "barrier.h"
#include "mythread.h"


int main(int argc, char *argv[])
{

    const int num_threads = 50;
    std::vector<std::shared_ptr<myThread>> vt(num_threads);
    std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
    /** Create the Threads */
    for(std::shared_ptr<myThread>& thread: vt)
    {
        thread=std::make_shared<myThread> (aBarrier,10);
    }
    std::cout << "Threads created " << std::endl;
    /** Launch the threads  */
    for(std::shared_ptr<myThread>& t: vt){
      t->start();
    }
    /**< Wait for all threads to finish */
    for (auto& v :vt){
        v->wait();
    }
    std::cout << std::endl << "*FINISHED*" << std::endl;
    return 0;
}
