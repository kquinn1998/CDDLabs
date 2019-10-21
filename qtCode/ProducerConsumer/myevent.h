#ifndef MYEVENT_H
#define MYEVENT_H

/**
 * @brief The myEvent class
 * A simple event class.
 *
 * On creation creates a token (a random uppercase letter) and stores it
 * Upon being consumed prints out the token in lower case!
 */
class myEvent
{
    char token;
public:
    myEvent();
    void consume();
};

#endif // MYEVENT_H
