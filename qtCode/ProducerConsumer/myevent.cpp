#include "myevent.h"
#include <iostream>
#include <QString>

myEvent::myEvent()
{
    token=97+qrand() % 26;//QString::number(97+qrand() % 26);
    std::cout<<token;
}

void myEvent::consume()
{
    token=token-32;
    std::cout << token;
}
