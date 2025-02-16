#include <iostream>
#pragma once

using namespace std;

class MyQueueArrayType{
    private:
        int *array;         // Array pointer
        int length;         // Size of the array queue
        int frontIndex;     // Index of front element
        int rearIndex;      // Index of rear element
        int count;          // Counter to count number of element in the queue

        // Dynamically Allocate memory for elemnets in the array
        void DynamicAllocation(int size){
            int *newArray = new int[size];
            for (int i = 0; i < count; i++){
                newArray[i] = array[((frontIndex + i) % length)];     // Copy old elements to new array
            }
            delete[] array;             // Free old array memory
            array = newArray;           // Update array pointer to new array
            length = size;              // Update size
            frontIndex = 0;             // Update frontIndex
            rearIndex = count - 1;      // Update rearIndex
        }

    public:
        // Constructor for initialization
        MyQueueArrayType(){
            length = 1;                 // Initialize length to 1 (default array size)
            array = new int[length];    // Dynamic array alocation
            frontIndex = -1;            // Initialize frontIndex to -1
            rearIndex = -1;             // Initialize rearIndex to -1
            count = 0;                  // Count is 0 (no elements)
        }

        // Enqeueu method to enqueue (add) an element into the queue
        void enqueue(int item){
            // If the queue is full, dynamically allocate new memory for the element
            if (count == length){
                DynamicAllocation(length + 1);
            }
            
            // If the queue is empty, update frontIndex and rearIndex to the first index
            if (is_empty()){
                frontIndex = 0;
                rearIndex = 0;
            }
            else {
                rearIndex = (rearIndex + 1) % length;       // else just update and increment rearIndex to the next index
            }
            array[rearIndex] = item;        // Add element
            count++;                        // Increment counter
        }

        // Dequeue method to dequeue (remove) and return the dequeued elemnet from the stack
        int dequeue(){
            // If queue is empty, print underflow error
            if (is_empty()){
                cout << "Queue Underflow ";
                return -1;
            }
            
            // Initialize item to the elemnt at frontIndex of the array (aka the element to be dequeued (removed))
            int item = array[frontIndex];

            // If the frontIndex and rearIndex are the same decrment both
            if (frontIndex == rearIndex){
                frontIndex = -1;
                rearIndex = -1;
            }
            else {
                frontIndex = (frontIndex + 1) % length;     // else increment only the frontIndex to the next index
            }
            count--;            // decrement counter
            return item;        // return dequeued item
        }

        // front method to return the front (top) element without removing it
        int front(){
            // If queue is empty, print underflow error
            if (is_empty()){
                cout << "Queue Underflow ";
                return -1;
            }
            return array[frontIndex];
        }

        // Is Empty method to chech if the queue if empty or not
        bool is_empty(){
            return count == 0;
        }

        // Size method to return the current size of the queue
        int size(){
            return count;
        }

        // PrintQueue method to print the queue elemnts
        void PrintQueue(){
            cout << "Queue: [";
            for (int i = 0; i < count; i++){
                cout << array[((frontIndex + i) % length)];
                if (i < count - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }

        // Destructor to Free allocated memory from queue
        ~MyQueueArrayType(){
            delete[] array;
        }
};

// Node class representing each element in the queue
class QueueNode{
    public:
        int data;       // Holds data value
        QueueNode* next;     // Pointer to new node

        // Constructor for initialization
        QueueNode(int initialData, QueueNode* nextNode = nullptr){
            data = initialData;
            next = nextNode;
        }
};

class MyQueueLinkedListType{
    private:
        QueueNode* frontNode;
        QueueNode* rearNode;
        int count;

    public:
        MyQueueLinkedListType(){
            frontNode = nullptr;
            rearNode = nullptr;
            count = 0;
        }

        // Enqeueu method to enqueue (add) an element into the queue
        void enqueue(int item){
            QueueNode* newNode = new QueueNode(item, nullptr);
            if (frontNode == nullptr && rearNode == nullptr){
                frontNode = newNode;
                rearNode = newNode;
            }
            else{
                rearNode->next = newNode;
                rearNode = newNode;
            }
            count++;
        }

        // Dequeue method to dequeue (remove) and return the dequeued elemnet from the stack
        int dequeue(){
            if (is_empty()){
                cout << "Queue Underflow ";
                return -1;
            }
            QueueNode* temp = frontNode;
            int value = temp->data;
            frontNode = frontNode->next;

            if (frontNode == nullptr){
                rearNode = nullptr;
            }

            delete temp;
            count--;
            return value;
        }

        // front method to return the front (top) element without removing it
        int front(){
            // If queue is empty, print underflow error
            if (is_empty()){
                cout << "Queue Underflow ";
                return -1;
            }
            return frontNode->data;
        }

        // Is Empty method to chech if the queue if empty or not
        bool is_empty(){
            return frontNode == nullptr;
        }

        // Size method to return the current size of the queue
        int size(){
            return count;
        }

        // PrintQueue method to print the queue elemnts
        void PrintQueue(){
            QueueNode* temp = frontNode;
            cout << "Queue: [";
            while (temp){
                cout << temp->data;
                if (temp->next != nullptr){
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << "]" << endl;
        }

        // Destructor to Free allocated memory from queue
        ~MyQueueLinkedListType(){
            while (!is_empty())
            {
                dequeue();
            }
        }
};