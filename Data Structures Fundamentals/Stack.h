#include <iostream>
#pragma once

using namespace std;

class MyStackArrayType{
    private:
        // Private Attributes
        int *array;         // Array pointer
        int length;         // Size of the array stack
        int topIndex;       // index of the top element

        // Dynamically Allocate memory for elemnets in the array
        void DynamicAllocation(int size){
            int *newArray = new int[size];
            for (int i = 0; i <= topIndex; i++){
                newArray[i] = array[i];     // Copy old elements to new array
            }
            delete[] array;         // Free old array memory
            array = newArray;       // Update array pointer to new array
            length = size;          // Update size
        }
    public:
        // Constructor for initialization
        MyStackArrayType (){
            length = 1;                 // Initialize length to 1 (default array size)
            array = new int[length];    // Dynamic array alocation
            topIndex = -1;              // Stack is initially empty
        }

        // Push method to push (add) an element into the stack
        void push(int item){
            // If the stack is full, dynamically allocate new memory for the element
            if (topIndex + 1 == length){
                DynamicAllocation(length + 1);
            }
            array[++topIndex] = item;       // Increment topIndex and add element
        }

        // Pop method to pop (remove) and return the popped elemnet from the stack
        int pop(){
            // If stack is empty, print underflow error
            if (is_empty()){
                cout << "Stack Underflow ";
                return -1;
            }
            return array[topIndex--];       // return element at topIndex then decrement topIndex
        }

        // Top method to return the top element without removing it
        int top(){
            // If stack is empty, print underflow error
            if (is_empty()){
                cout << "Stack Underflow ";
                return -1;
            }
            return array[topIndex];
        }

        // Is Empty method to chech if the stack if empty or not
        bool is_empty(){
            return topIndex == -1;
        }

        // Size method to return the current size of the stack
        int size(){
            return topIndex + 1;
        }

        // PrintStack method to print the stack elemnts
        void PrintStack(){
            cout << "Stack: [";
            for (int i = 0; i <= topIndex; i++){
                cout << array[i];
                if (i < topIndex) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }

        // Destructor to Free allocated memory from stack
        ~MyStackArrayType(){
            delete[] array;
        }
};

// Node class representing each element in the stack
class StackNode{
    public:
        int data;       // Holds data value
        StackNode* next;     // Pointer to new node

        // Constructor for initialization
        StackNode(int initialData, StackNode* nextNode = nullptr){
            data = initialData;
            next = nextNode;
        }
};

class MyStackLinkedListType{
    private:
        StackNode* head;     // Pointer to the head (too) element of the stack
        int count;      // Counter to count number of element in the stack

    public:
        // Constructor for initialization
        MyStackLinkedListType(){
            head = nullptr;         // Stack is initially empty
            count = 0;              // Count is 0 (no elements)
        }

        // Push method to push an element into the stack
        void push(int data){
            StackNode* newNode = new StackNode(data, head);       // Create new node and pass data and next pointer
            head = newNode;                         // Update head to the new node
            count++;                            // Increment counter
        }

        // Pop method to pop and return the popped elemnet from the stack
        int pop(){
            // If stack is empty, print underflow error
            if (is_empty()){
                cout << "Stack Underflow ";
                return -1;
            }
            int value = head->data;     // Save the head data value
            StackNode* temp = head;          // Store top element
            head = head->next;          // Move head (top) element to next element
            delete temp;                // Free memory for top element
            count--;                    // Decrement counter
            return value;               // Return saved value of popped element
        }

        // Is Empty method to chech if the stack if empty or not
        bool is_empty(){
            return head ==  nullptr;
        }

        // Top method to return the top element without removing it
        int top(){
            // If stack is empty, print underflow error
            if (is_empty()){
                cout << "Stack Underflow ";
                return -1;
            }
            return head->data;
        }

        // Size method to return the current size of the stack
        int size(){
            return count;
        }

        // Print Stack to print the stack elemnts
        void PrintStack(){
            StackNode* temp = head;
            cout << "Stack: [";
            while (temp){
                cout << temp->data;
                if (temp->next != nullptr){
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << "]" << endl;
        }

        // Destructor to Free allocated memory from stack
        ~MyStackLinkedListType(){
            while (head)
            {
                pop();
            }
        }
};