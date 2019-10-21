#include "consumerthread.h"

ConsumerThread::ConsumerThread(std::shared_ptr<myBuffer<myEvent>> aBuffer)
    :theBuffer(aBuffer)
{
//NOTHING TO DO HERE
}

void ConsumerThread::run()
{
    for(int i=0;i<10;++i){
       //get event from buffer and consume
       myEvent e= theBuffer->get();
       e.consume();
     }
}
