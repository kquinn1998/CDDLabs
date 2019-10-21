#include <QCoreApplication>
#include <vector>
#include <memory>
#include "producerthread.h"
#include "consumerthread.h"
#include "mybuffer.h"
#include "myevent.h"



int main(int argc, char *argv[])
{
      int numProducers =5;
      int numConsumers=5;
      int bufferSize=10;
      std::vector<std::shared_ptr<ProducerThread>> ptv;
      std::vector<std::shared_ptr<ConsumerThread>> ctv;
      std::shared_ptr<myBuffer<myEvent>> theSafeBuffer
              =std::make_shared<myBuffer<myEvent>>(bufferSize);
      /** Create the producers */
    for(int i=0;i<numProducers;++i)
    {
        std::shared_ptr<ProducerThread> newProducer = std::make_shared<ProducerThread>(theSafeBuffer);
        ptv.push_back(newProducer);
    }
    /** Create the consumers */
    for(int i=0;i<numConsumers;++i)
    {
        std::shared_ptr<ConsumerThread> newConsumer = std::make_shared<ConsumerThread>(theSafeBuffer);
        ctv.push_back(newConsumer);
    }
      /** Launch the threads  */
      for(std::shared_ptr<ProducerThread> t: ptv){
        t->run();
      }
      for(std::shared_ptr<ConsumerThread> t: ctv){
        t->run();
      }
      /**< Join the threads with the main thread */
      for (auto v :ptv){
          v->wait();
      }
      for (auto& v :ctv){
          v->wait();
      }
      return 0;
}
