/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#ifndef ARRAY_H
#define ARRAY_H
#include "SavingsAccount.h"
#include "Account.h"
#include <iostream>
using namespace std;

// Template class for a dynamic array
template <typename T>
class Array {
    int size;   // Current size of the array
    T* elements;  // Pointer to the array elements

public:
    // Default constructor
    Array(): elements(nullptr), size(0){}

    // Destructor to free allocated memory
    ~Array(){delete[] elements;}

    // Add an element to the end of the array
    void add(const T element)
    {
        T* new_arr = new T[size+1];  // Create a new array with increased size
        new_arr[size] = element;  // Add the new element to the end
        for (int i = 0; i < size ; i++)
        {
            new_arr[i] = this->elements[i];  // Copy existing elements to the new array
        }
        this->size++;
        delete [] elements;  // Deallocate memory of the old array
        this->elements = new_arr;  // Update the array pointer
    }

    // Remove an element at a specified index and return its value
    T remove(int index)
    {
        T* new_arr = new T[size-1];  // Create a new array with decreased size
        T value = elements[index];  // Store the value of the removed element
        for (int i = 0; i < size-1 ; i++)
        {
            if(i < index)
            {
                new_arr[i] = this->elements[i];  // Copy elements before the removed index
            }
            else
            {
                new_arr[i] = this->elements[i+1];  // Skip the element at the removed index
            }
        }
        delete [] elements;  // Deallocate memory of the old array
        elements = new_arr;  // Update the array pointer
        size--;
        return value;  // Return the value of the removed element
    }

    // Get the current size of the array
    int getSize() const
    {
        return this->size;
    }

    // Overloaded subscript operator to access elements by index
    T& operator[](int index)
    {
        return this->elements[index];
    }

    // Overloaded output stream operator for easy printing
    friend ostream& operator<<(ostream& os,  Array& a)
    {
        int j = 0;
        for(j; a.size > j; j++)
        {
            cout<< "Array index " << j << ":" << endl;
            a[j]->print();  // Assuming elements have a 'print' method
        }
        return os;
    }
};

#endif
