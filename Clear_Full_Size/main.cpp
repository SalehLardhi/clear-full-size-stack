#include <iostream>
#include <cstdlib>
using namespace std;

// Define the default capacity of the stack
#define SIZE 10

// A class to represent a stack
class Stack
{
    int *arr;
    int top;
    int capacity;
    int counter=SIZE;

public:
    Stack(int size = SIZE){ // Constructor to initialize the stack
    arr = new int[size];
    capacity = size;
    top = -1;
};
   ~Stack() { // Destructor to free memory allocated to the stack
    delete[] arr;
}

    void push(int x)
{
    if (isFull())
    {
        cout << "Overflow"<<endl<<"Program Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting ..." << x << endl;
    arr[++top] = x;
    counter++;
}
    int pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;
    counter--;

    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}
    int peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
    int size() {
    return top + 1;
}

    bool isFull() {
    return top == capacity - 1;     // or return size() == capacity;
}
void Clear (){
    for (int i=0; i< counter; i++){
        pop();
        counter=0;
    }
}
bool isEmpty() {
    return top == -1;               // or return size() == 0;
}
};


int main()
{
    int StackSize;
    cout<<"Enter the size of Stack"<<endl;
    cin>>StackSize;
    Stack test(StackSize);

    cout<<"pushing some elements 1,2,3,4,5 ."<<endl;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);

    cout<<"Removing last 2 elements..."<<endl;
    test.pop();
    test.pop();

    cout << "The top element is " << test.peek() << endl;
    cout << "The stack size is " << test.size() << endl;

    if (test.isFull()) {
        cout << "True, The stack is Full\n";
    }
    else {
        cout << "False, The stack is not Full\n";
    }
    cout<<"Clear or Reset the whole stack..."<<endl;
    test.Clear();

    return 0;
}
