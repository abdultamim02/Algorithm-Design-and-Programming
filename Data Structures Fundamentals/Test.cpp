#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(void){
    cout << "------> MyStackArrayType <-------" << endl;
    MyStackArrayType stack;

    cout << "stack.is_empty(): " << stack.is_empty() << (stack.is_empty() ? " (True)" : " (False)") << endl;

    stack.PrintStack();

    stack.push(2);
    stack.push(4);
    stack.push(6);
    stack.push(8);
    stack.push(10);

    stack.PrintStack();

    cout << "stack.is_empty(): " << stack.is_empty() << (stack.is_empty() ? " (True)" : " (False)") << endl;
    cout << "stack.top(): " << stack.top() << endl;
    cout << "stack.size(): " << stack.size() << endl;
    
    cout << "stack.pop(): " << stack.pop() << endl;
    cout << "stack.top(): " << stack.top() << endl;

    stack.PrintStack();
    
    cout << "stack.size(): " << stack.size() << endl;

    cout << "-------------------------------------------" << endl;

    cout << "------> MyStackLinkedListType <-------" << endl;
    MyStackLinkedListType Stack;

    cout << "Stack.size(): " << Stack.size() << endl;
    cout << "Stack.is_empty(): " << Stack.is_empty() << (Stack.is_empty() ? " (True)" : " (False)") << endl;

    Stack.PrintStack();

    Stack.push(2);
    Stack.push(4);
    Stack.push(6);
    Stack.push(8);
    Stack.push(10);

    Stack.PrintStack();

    cout << "Stack.is_empty(): " << Stack.is_empty() << (Stack.is_empty() ? " (True)" : " (False)") << endl;
    cout << "Stack.top(): " << Stack.top() << endl;
    cout << "Stack.size(): " << Stack.size() << endl;
    
    cout << "Stack.pop(): " << Stack.pop() << endl;
    cout << "Stack.top(): " << Stack.top() << endl;

    Stack.PrintStack();
    
    cout << "Stack.size(): " << Stack.size() << endl;

    cout << "-------------------------------------------" << endl;

    cout << "------> MyQueueArrayType <-------" << endl;
    MyQueueArrayType queue;

    cout << "queue.is_empty(): " << queue.is_empty() << (queue.is_empty() ? " (True)" : " (False)") << endl;

    queue.PrintQueue();

    queue.enqueue(2);
    queue.enqueue(4);
    queue.enqueue(6);
    queue.enqueue(8);
    queue.enqueue(10);

    queue.PrintQueue();

    cout << "queue.is_empty(): " << queue.is_empty() << (queue.is_empty() ? " (True)" : " (False)") << endl;
    cout << "queue.front(): " << queue.front() << endl;
    cout << "queue.size(): " << queue.size() << endl;
    
    cout << "queue.dequeue(): " << queue.dequeue() << endl;
    cout << "queue.front(): " << queue.front() << endl;

    queue.PrintQueue();
    
    cout << "queue.size(): " << queue.size() << endl;

    cout << "-------------------------------------------" << endl;

    return 0;
}