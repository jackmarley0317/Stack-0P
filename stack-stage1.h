/*
 * stack-stage1.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Jack Marley
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t
#include <string>  // for stage 1

using namespace std;

class stack {

  private:
    string* dataOfArray; // string variable that points to data within array

    int sizeOfStack; // this is the current size of the stack 

    int capacityOfArray; // this is the current capacity of the array
    //string _data[4]; old code given

  public:


    string top(); // non-inline, implemented in stack-stage1.cpp

    // inline definitions
    /*
    * This function is assigning variables from the private declaration class actual
    * values in order so that they can be used. This then assigns them to the 'stack'
    * 
    * Parameters:
    * - None
    *
    * Returns:
    * -None
    */

    stack() 
    { 
      dataOfArray = new string[1]; // intializing the string with an array of 1 character (im assuming)

      sizeOfStack = 0; // The size of the stack needs to start at 0 so that way we can fill our array intially before growing it

      capacityOfArray = 1; // this is the current capacity of the array, just starting it one since that is the most trivial processs
    } 

    /*
    * This function utulizes the 'push' method in order to push new values
    * into the array when necessary. This method will allow for a dynamically
    * allocated array that is able to grow and shrink at the users discretion
    * 
    * Parameters:
    * - int newValue: we are passing by reference a string of 'newValue' into the array.
    *
    * Returns:
    * - Void function has no return
    */
    void push(const string & newValue) 
    { 
      if (capacityOfArray == sizeOfStack) // checking to see if the capacity of the array == the stack, if it does we need to grow the array
      {
        // creating a new array of capacity [2*current capacity]
        // How to do this -> data_type* array_name = new data_type[array_size];
        string* newDataOfArray = new string[2 * capacityOfArray];

        // copy the old contents of array into the new array
        // clearly use a for loop..... very basic

        for (int i =0; i < sizeOfStack; i++)
        {
          // dataOfArray[i] = newDataOfArray[i]; was assigning old data to an empty that was 2 * capacity
          newDataOfArray[i] = dataOfArray[i];
        }


        // Dellocate both arrays now
        // This frees dynamic memory
        delete[] dataOfArray;

        // replace the old array pointer with new array pointer
        dataOfArray = newDataOfArray;

        // update array capacity variable
        // worded weirdly... what it means is that we have to tell the array to update its current capacity
        // we do this by simpling taking it multiplying it by two

        capacityOfArray = capacityOfArray * 2;
      
      }
      dataOfArray[sizeOfStack] = newValue; // assign the current value of the stack with in the data of the array the new value passed by reference

      sizeOfStack++; // increment the current size of the stack to the next value to repeat this process until completed 
      
      return; 
    }
        /*
    * This function utulizes the 'pop' method in order to pop values
    *  the array when necessary. All it does is a simply check by seeing 
    * if the array is empty or not by using the 'is_empty()' function
    * 
    * Parameters:
    * - None
    *
    * Returns:
    * - Void function has no return
    */

    void pop() 
    { 
      if (is_empty() == false) // of the stack is not empty
      {
        sizeOfStack--; // decrement value being popped
      }
      else 
      {
        return;
      }
    }

    size_t size() 
    { 
      return sizeOfStack; // return current size of the stack
    }

    bool is_empty() 
    { 
      if (sizeOfStack == 0) return true; // if the stack is sized to 0 return a true to indicate it is empty
      else return false; // else indicate it is not
    }

};

#endif
