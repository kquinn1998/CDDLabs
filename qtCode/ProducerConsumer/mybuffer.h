#ifndef MYBUFFER_H
#define MYBUFFER_H
#include <vector>
#include <QMutex>
#include <QSemaphore>


/**
 * @brief The myBuffer class
 * A simple shared buffer class.
 *
 * A buffer that can be shared between threads.
 * Only one thread at a time can add or remove from thread
 * (We can improve on this! how?)
 * Does not allow anyone to try take item from empty buffer
 */
template <class T>
class myBuffer{
    int size;
    int count;
    std::vector<T> elems;
    QMutex theLock;
    QSemaphore sentinel;
public:
    myBuffer<T>(int aSize);
    T get();
    void put(T);
};

template <class T>
myBuffer<T>::myBuffer(int aSize)
    :size(aSize),count(0)
{

}

template <class T>
T myBuffer<T>:: get()
{
    sentinel.acquire();
    theLock.lock();
    T item = elems.back();
    elems.pop_back();
    --count;
    theLock.unlock();
    return item;
}

template <class T>
void myBuffer<T>::put(T newElem)
{
    theLock.lock();
    elems.push_back(newElem);
    ++count;
    theLock.unlock();
    sentinel.release();
}

#endif // MYBUFFER_H
