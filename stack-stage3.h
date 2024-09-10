/*
 * stack-stage3.h
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

// To start stage 2, you probably want to copy all of your code from
// stack-stage1.h and stack-stage1.cpp in place of this comment.
#include <iostream>
using namespace std;

template<class T>

class stack {

  private:
    T* dataOfArray; // string variable that points to data within array

    int sizeOfStack; // this is the current size of the stack 

    int capacityOfArray; // this is the current capacity of the array
    //string _data[4]; old code given

  public:
     // inline definitions
    void deepCopy(const stack<T> & assignedOrCopiedStack); // refactored code calling
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
      dataOfArray = new T[1]; // intializing the string with an array of 1 character (im assuming)

      sizeOfStack = 0; // The size of the stack needs to start at 0 so that way we can fill our array intially before growing it

      capacityOfArray = 1; // this is the current capacity of the array, just starting it one since that is the most trivial processs
    } 

    T top() {return dataOfArray[sizeOfStack-1];} ; // non-inline, implemented in stack-stage1.cpp

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
    void push(const T & newValueOfArray) 
    { 
      if (capacityOfArray == sizeOfStack) // checking to see if the capacity of the array == the stack, if it does we need to grow the array
      {
        // creating a new array of capacity [2*current capacity]
        // How to do this -> data_type* array_name = new data_type[array_size];
        T* newDataOfArray = new T[2 * capacityOfArray];

        // copy the old contents of array into the new array
        // clearly use a for loop..... very basic

        for (int i =0; i < sizeOfStack; i++)
        {
          // dataOfArray[i] = newDataOfArray[i]; was assigning old data to an empty that was 2 * capacity
          newDataOfArray[i] = dataOfArray[i];
        }
        // Dellocate old array now
            // note: if you dellocating the new data of the array, it will cause a memory segmentation fault.
        // This frees dynamic memory
        delete[] dataOfArray;

        // replace the old array pointer with new array pointer
        dataOfArray = newDataOfArray;

        // update array capacity variable
        // worded weirdly... what it means is that we have to tell the array to update its current capacity
        // we do this by simpling taking it multiplying it by two
        capacityOfArray = capacityOfArray * 2;
      }

      dataOfArray[sizeOfStack] = newValueOfArray; // assign the current value of the stack with in the data of the array the new value passed by reference
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
    /*
    * This function returns the current size of the array
    * 
    * Parameters:
    * - None
    *
    * Returns:
    * - Void function has no return
    */
    size_t size() 
    { 
      return sizeOfStack; // return current size of the stack
    }
    /*
    * This function checks to see if the current stack is empty.
    * If the size of the stack is == 0, then the stack is clearly empty
    * and returns a true. If it is != 0, the  the stack is not empty 
    * and returns a false
    * 
    * Parameters:
    * - None
    *
    * Returns:
    * - Void function has no return
    */
    bool is_empty() 
    { 
      if (sizeOfStack == 0) return true; // if the stack is sized to 0 return a true to indicate it is empty
      else return false; // else indicate it is not
    }
    // calling the big 3
        // destructor calling
    ~stack();
        // copy constructor calling
            // note: make a deep copy of the stack
    stack(const stack<T>& copiedStack);  // Copy constructor
    // assignment constructor calling
            // note: making a deep copy of the stack as well
    stack<T>& operator=(const stack<T>& assignedStack);
};
/*
* This function creates the deep copy for the assignment and copy constructor.
* 
* 
* Parameters:
* - None
*
* Returns:
* - Void function has no return
*/
template <typename T>
void stack<T>::deepCopy(const stack<T>& assignedOrCopiedStack) 
    {
      sizeOfStack = assignedOrCopiedStack.sizeOfStack; // line copies the size of the stack from the source object "assignedOrCopiedStack" to the current object
      dataOfArray = new T[assignedOrCopiedStack.capacityOfArray]; // lines allocates an array of type 'T' with the same capacity as the sources stacks array. Ensures that there is enough space to store all the elements in the sources stack
      // copy values
      capacityOfArray = assignedOrCopiedStack.capacityOfArray; 
      // deep copy creation
      for (int i = 0; i < sizeOfStack; i++)
      {
          dataOfArray[i] = assignedOrCopiedStack.dataOfArray[i]; // 'assignedOrCopiedStack.dataOfArray[i]' is copied into the new array of 'dataArray[i]' into its corresponding position. 
      }
    }
// body for destructor class
template <typename T>
stack<T>::~stack() 
    {
        delete[] dataOfArray; // free up dynamically allocated memory
    }

// body for copy constructor
template <typename T>
stack<T>::stack(const stack<T>& copiedStack) 
    {
        deepCopy(copiedStack); // calls function that creates a deep copy using the copy method
    }

// body for assignment constructor
template <typename T>
stack<T>& stack<T>::operator=(const stack<T>& assignedStack) 
    {
        if (this == &assignedStack) return *this; // handle self assignment
        delete[] dataOfArray; // deallocate array
        deepCopy(assignedStack); // calls function that creates a deep copy using the assignment operator
        return *this; 
    }
    


#endif