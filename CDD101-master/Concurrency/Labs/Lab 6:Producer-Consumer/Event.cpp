/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 6 CDD Labs
 *
 * \section Event Class
 *
 * This class is used to create an event / task, which can be added to a buffer and then
 * consumed by a thread.
 */

#include "Event.h"
#include <iostream>
#include <stdlib.h>


/*! \fn Event Constructor
    \brief  this constructor is used to create an event / task containng a random alpha charachter between a and z
            to be added top a buffer.
*/
Event::Event(){
  myChar = 'a'+rand()%26;
  std::cout<<myChar<<std::endl;
}

/*! \fn Event Consumer
    \brief  This method is used to consume a task when triggered by the buffer.
            This includes printing out the char of the designated task
*/
bool Event::consume(){
  char c=myChar-32;
  std::cout<<c;
}