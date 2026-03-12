#include "ArrayStack.hpp"

template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO 
    //create Array stack of max size i 
    maxSize = i;
    buffer = new T[maxSize]; 
    this->length = 0; //empty stack 
    
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);

    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    //remove everything in stack 
    delete[] buffer; // deallocate memory
    buffer = nullptr; 
    this->length = 0; // reset length
    maxSize = 0; // reset max size

}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    for(int i = 0; i < copyObj.length; i++)
    {
        buffer[i] = copyObj.buffer[i];
    }
    this->length = copyObj.length;
    
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    // check if stack is empty
    if (isEmpty())
    {
        throw runtime_error("Stack is empty, so no elements to peek");
    }
    //return top elem
    return buffer[ this->length - 1]; 


}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    // check if stack is empty
    if (isEmpty())
    {
        throw runtime_error("Stack is empty, so no elements to pop");
    }
   
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    // check if stack is full 
    if(isFull())
    {
        throw runtime_error("Stack is full, so new element can't be pushed");
    }
    
    // add elem to the top of stack
    buffer[this->length] = elem;

    // update length
    this->length++;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (isEmpty())
    {
        throw runtime_error("Stack is empty, so no elements to rotate");
    }

   


    // right rotate (move top to bottom)
    if (dir == Stack<T>::RIGHT)
    {
        T temp = buffer[this->length - 1]; // store top element 

        for (int i = this->length - 1; i > 0; i--)
        {
            buffer[i] = buffer[i - 1]; // give elem after the value of previous elem
        }
        
        buffer[0] = temp; // give bottom element the val of top
    }

    // left rotate (move bottom to top)
    else if (dir == Stack<T>::LEFT)
    {
        T temp = buffer[0]; // store bottom element 
        for (int i = 0; i < this->length -1; i++)
        {
            buffer[i] = buffer[i + 1]; // give elem before the value of next elem
        }

        buffer[this->length - 1] = temp; // give top element the val of bottom 
    }

}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << endl << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}
