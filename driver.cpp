#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

template <typename T>
void testRotate(ArrayStack<T>& stack, typename Stack<T>::Direction dir) {
    cout << "Testing rotate with direction: ";
    if (dir == Stack<T>::RIGHT) {
        cout << "RIGHT" << endl;
    } else {
        cout << "LEFT" << endl;
    }
    
    try {
        stack.rotate(dir);
        cout << "After rotation: " << stack << endl;
    }
    catch (const char* e) {
        cout << "Exception caught: " << e << endl;
    }
    catch (const string& e) {
        cout << "Exception caught: " << e << endl;
    }
}

void testStringStack() {
    ArrayStack<string> stringStack(3);
    stringStack.push("apple");
    stringStack.push("banana");
    stringStack.push("cherry");
    cout << "String stack: " << stringStack << endl;
    cout << "Peek: " << stringStack.peek() << endl;
    stringStack.pop();
    cout << "After pop: " << stringStack << endl;
}

void testDoubleStack() {
    ArrayStack<double> doubleStack(4);
    doubleStack.push(3.14);
    doubleStack.push(2.718);
    doubleStack.push(1.618);
    cout << "Double stack: " << doubleStack << endl;
}

int main()
{   
    ArrayStack<int> stack(5);
    cout << "Empty stack: " << stack << endl;
    cout << "Is empty? " << stack.isEmpty() << endl;
    cout << "Max size: " << stack.getMaxSize() << endl;
    
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.push(400);
    stack.push(500);
    cout << "After pushes: " << stack << endl;
    cout << "Length: " << stack.getLength() << endl;
    cout << "Is full? " << stack.isFull() << endl;
    
    cout << "Top element: " << stack.peek() << endl;
    
    stack.pop();
    cout << "After pop: " << stack << endl;
    
    stack.rotate(Stack<int>::RIGHT);
    cout << "After right rotate: " << stack << endl;
    
    stack.rotate(Stack<int>::LEFT);
    cout << "After left rotate: " << stack << endl;
    
    ArrayStack<int> copy(stack);
    cout << "Copied stack: " << copy << endl;
    
    ArrayStack<int> assigned(10);
    assigned = stack;
    cout << "Assigned stack: " << assigned << endl;
    
    stack.clear();
    cout << "After clear: " << stack << endl;
    
    cout << "Pop from empty: ";
    try {
        stack.pop();
    }
    catch (const char* e) {
        cout << e << endl;
    }
    catch (const string& e) {
        cout << e << endl;
    }
    
    cout << "Peek from empty: ";
    try {
        stack.peek();
    }
    catch (const char* e) {
        cout << e << endl;
    }
    catch (const string& e) {
        cout << e << endl;
    }
    
    testRotate(stack, Stack<int>::RIGHT);
    
    ArrayStack<int> smallStack(2);
    smallStack.push(1);
    smallStack.push(2);
    cout << "Small stack: " << smallStack << endl;
    
    cout << "Push to full: ";
    try {
        smallStack.push(3);
    }
    catch (const char* e) {
        cout << e << endl;
    }
    catch (const string& e) {
        cout << e << endl;
    }
    
    ArrayStack<int> singleStack(3);
    singleStack.push(42);
    cout << "Single elem before rotate: " << singleStack << endl;
    singleStack.rotate(Stack<int>::RIGHT);
    cout << "Single elem after rotate: " << singleStack << endl;
    
    ArrayStack<int> selfTest(3);
    selfTest.push(10);
    selfTest.push(20);
    cout << "Before self-assignment: " << selfTest << endl;
    selfTest = selfTest;
    cout << "After self-assignment: " << selfTest << endl;
    
    testStringStack();
    testDoubleStack();
    
    ArrayStack<int> largeStack(1000);
    for (int i = 0; i < 500; i++) {
        largeStack.push(i);
    }
    cout << "Large stack size: " << largeStack.getLength() << endl;
    
    for (int i = 0; i < 250; i++) {
        largeStack.pop();
    }
    cout << "After 250 pops: " << largeStack.getLength() << endl;
    
    return 0;
}