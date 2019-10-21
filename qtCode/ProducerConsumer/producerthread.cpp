#include "producerthread.h"

ProducerThread::ProducerThread(std::shared_ptr<myBuffer<myEvent>> aBuffer)
    :theBuffer(aBuffer)
{
//NOTHING TO DO HERE
}


void ProducerThread::run()
{
    for(int i=0;i<10;++i){
       //Produce event and add to buffer
        myEvent e;
        theBuffer->put(e);
    }
}
