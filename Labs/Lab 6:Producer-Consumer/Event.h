/*
 *Project: CDD Labs
 *Author: Kevin Quinn C00216607
 *License: GNU
 *Description: A group of labs demonstrating concurrency.
 */

/*! \mainpage Lab 6 CDD Labs
 *
 * \section Event Header
 *
 * This Header is used to create an event / task, which can be added to a buffer and then
 * consumed by a thread.
 */

#pragma once
//no matter how many time it is included, it will only compile it once. To avoid errors.

class Event{
 private:
  char myChar;
 public:
  Event();
  bool consume(); //true if consumes, false if something goes wrong  
};

