/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Jack Marley
 */

#include "stack-stage1.h"

string stack::top() {return dataOfArray[sizeOfStack-1];}