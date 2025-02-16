#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Calculator.h"

using namespace std;

int main(void){

    cout << "==========================================================================================" << endl;
    cout << "======================================== Stack.h =========================================" << endl;
    cout << "==========================================================================================" << endl;

    cout << "------> MyStackArrayType <-------" << endl;
    MyStackArrayType MyStackArray;

    // Test: Empty Stack Check
    cout << "MyStackArray.is_empty(): " << MyStackArray.is_empty() << (MyStackArray.is_empty() ? " (True)" : " (False)") << endl;

    // Edge Case: Pop from Empty Stack
    cout << "MyStackArray.pop(): " << MyStackArray.pop() << endl;
    
    // Edge Case: Get top from Empty Stack
    cout << "MyStackArray.top(): " << MyStackArray.top() << endl;
    
    // Test: Push Elements
    MyStackArray.push(2);
    MyStackArray.push(4);
    MyStackArray.push(6);
    MyStackArray.push(8);
    MyStackArray.push(10);
    MyStackArray.PrintStack();

    // Test: Check Empty Status
    cout << "MyStackArray.is_empty(): " << MyStackArray.is_empty() << (MyStackArray.is_empty() ? " (True)" : " (False)") << endl;

    // Test: Check Top Element
    cout << "MyStackArray.top(): " << MyStackArray.top() << endl;

    // Test: Check Size
    cout << "MyStackArray.size(): " << MyStackArray.size() << endl;

    // Test: Pop Element
    cout << "MyStackArray.pop(): " << MyStackArray.pop() << endl;
    cout << "MyStackArray.top(): " << MyStackArray.top() << endl;
    MyStackArray.PrintStack();
    cout << "MyStackArray.size(): " << MyStackArray.size() << endl;

    // Test: Pop More Elements
    cout << "MyStackArray.pop(): " << MyStackArray.pop() << endl;
    cout << "MyStackArray.top(): " << MyStackArray.top() << endl;
    MyStackArray.PrintStack();
    cout << "MyStackArray.size(): " << MyStackArray.size() << endl;

    // Test: Pop More Elements
    cout << "MyStackArray.pop(): " << MyStackArray.pop() << endl;
    cout << "MyStackArray.top(): " << MyStackArray.top() << endl;
    MyStackArray.PrintStack();
    cout << "MyStackArray.size(): " << MyStackArray.size() << endl;

    // Edge Case: Large Number of Pushes
    for (int i = 0; i < 100; i++) {
        MyStackArray.push(i);
    }
    cout << "MyStackArray.size(): " << MyStackArray.size() << endl;

    cout << "-------------------------------------------" << endl;
    cout << "------> MyStackLinkedListType <-------" << endl;
    MyStackLinkedListType MyStackLinkedList;

    // Test: Empty Stack Check
    cout << "MyStackLinkedList.is_empty(): " << MyStackLinkedList.is_empty() << (MyStackLinkedList.is_empty() ? " (True)" : " (False)") << endl;

    // Edge Case: Pop from Empty Stack
    cout << "MyStackLinkedList.pop(): " << MyStackLinkedList.pop() << endl;
    
    // Edge Case: Get top from Empty Stack
    cout << "MyStackLinkedList.top(): " << MyStackLinkedList.top() << endl;

    // Test: Push Elements
    MyStackLinkedList.push(2);
    MyStackLinkedList.push(4);
    MyStackLinkedList.push(6);
    MyStackLinkedList.push(8);
    MyStackLinkedList.push(10);
    MyStackLinkedList.PrintStack();

    // Test: Check Empty Status
    cout << "MyStackLinkedList.is_empty(): " << MyStackLinkedList.is_empty() << (MyStackLinkedList.is_empty() ? " (True)" : " (False)") << endl;

    // Test: Check Top Element
    cout << "MyStackLinkedList.top(): " << MyStackLinkedList.top() << endl;

    // Test: Check Size
    cout << "MyStackLinkedList.size(): " << MyStackLinkedList.size() << endl;

    // Test: Pop Element
    cout << "MyStackLinkedList.pop(): " << MyStackLinkedList.pop() << endl;
    cout << "MyStackLinkedList.top(): " << MyStackLinkedList.top() << endl;
    MyStackLinkedList.PrintStack();
    cout << "MyStackLinkedList.size(): " << MyStackLinkedList.size() << endl;

    // Test: Pop More Elements
    cout << "MyStackLinkedList.pop(): " << MyStackLinkedList.pop() << endl;
    cout << "MyStackLinkedList.top(): " << MyStackLinkedList.top() << endl;
    MyStackLinkedList.PrintStack();
    cout << "MyStackLinkedList.size(): " << MyStackLinkedList.size() << endl;

    // Test: Pop More Elements
    cout << "MyStackLinkedList.pop(): " << MyStackLinkedList.pop() << endl;
    cout << "MyStackLinkedList.top(): " << MyStackLinkedList.top() << endl;
    MyStackLinkedList.PrintStack();
    cout << "MyStackLinkedList.size(): " << MyStackLinkedList.size() << endl;

    // Edge Case: Large Number of Pushes
    for (int i = 0; i < 100; i++) {
        MyStackLinkedList.push(i);
    }
    cout << "MyStackLinkedList.size(): " << MyStackLinkedList.size() << endl;

    cout << "==========================================================================================" << endl;
    cout << "======================================== Queue.h =========================================" << endl;
    cout << "==========================================================================================" << endl;

    cout << "------> MyQueueArrayType <-------" << endl;
    MyQueueArrayType MyQueueArray;

    // Test: Empty Queue Check
    cout << "MyQueueArray.is_empty(): " << MyQueueArray.is_empty() << (MyQueueArray.is_empty() ? " (True)" : " (False)") << endl;

    // Edge Case: Dequeue from Empty Queue
    cout << "MyQueueArray.dequeue(): " << MyQueueArray.dequeue() << endl;

    // Edge Case: Get front from Empty Queue
    cout << "MyQueueArray.front(): " << MyQueueArray.front() << endl;

    // Test: Enqueue Elements
    MyQueueArray.enqueue(2);
    MyQueueArray.enqueue(4);
    MyQueueArray.enqueue(6);
    MyQueueArray.enqueue(8);
    MyQueueArray.enqueue(10);
    MyQueueArray.PrintQueue();

    // Test: Check Empty Status
    cout << "MyQueueArray.is_empty(): " << MyQueueArray.is_empty() << (MyQueueArray.is_empty() ? " (True)" : " (False)") << endl;

    // Test: Check Front Element
    cout << "MyQueueArray.front(): " << MyQueueArray.front() << endl;

    // Test: Check Size
    cout << "MyQueueArray.size(): " << MyQueueArray.size() << endl;

    // Test: Dequeue Element
    cout << "MyQueueArray.dequeue(): " << MyQueueArray.dequeue() << endl;
    cout << "MyQueueArray.front(): " << MyQueueArray.front() << endl;
    MyQueueArray.PrintQueue();
    cout << "MyQueueArray.size(): " << MyQueueArray.size() << endl;

    // Test: Dequeue More Elements
    cout << "MyQueueArray.dequeue(): " << MyQueueArray.dequeue() << endl;
    cout << "MyQueueArray.front(): " << MyQueueArray.front() << endl;
    MyQueueArray.PrintQueue();
    cout << "MyQueueArray.size(): " << MyQueueArray.size() << endl;

    // Test: Dequeue More Elements
    cout << "MyQueueArray.dequeue(): " << MyQueueArray.dequeue() << endl;
    cout << "MyQueueArray.front(): " << MyQueueArray.front() << endl;
    MyQueueArray.PrintQueue();
    cout << "MyQueueArray.size(): " << MyQueueArray.size() << endl;

    // Edge Case: Large Number of Enqueues
    for (int i = 0; i < 100; i++) {
        MyQueueArray.enqueue(i);
    }
    cout << "MyQueueArray.size(): " << MyQueueArray.size() << endl;

    cout << "-------------------------------------------" << endl;
    cout << "------> MyQueueLinkedListType <-------" << endl;
    MyQueueLinkedListType MyQueueLinkedList;

    // Test: Empty Queue Check
    cout << "MyQueueLinkedList.is_empty(): " << MyQueueLinkedList.is_empty() << (MyQueueLinkedList.is_empty() ? " (True)" : " (False)") << endl;

    // Edge Case: Dequeue from Empty Queue
    cout << "MyQueueLinkedList.dequeue(): " << MyQueueLinkedList.dequeue() << endl;

    // Edge Case: Get front from Empty Queue
    cout << "MyQueueLinkedList.front(): " << MyQueueLinkedList.front() << endl;

    // Test: Enqueue Elements
    MyQueueLinkedList.enqueue(2);
    MyQueueLinkedList.enqueue(4);
    MyQueueLinkedList.enqueue(6);
    MyQueueLinkedList.enqueue(8);
    MyQueueLinkedList.enqueue(10);
    MyQueueLinkedList.PrintQueue();

    // Test: Check Empty Status
    cout << "MyQueueLinkedList.is_empty(): " << MyQueueLinkedList.is_empty() << (MyQueueLinkedList.is_empty() ? " (True)" : " (False)") << endl;

    // Test: Check Front Element
    cout << "MyQueueLinkedList.front(): " << MyQueueLinkedList.front() << endl;

    // Test: Check Size
    cout << "MyQueueLinkedList.size(): " << MyQueueLinkedList.size() << endl;

    // Test: Dequeue Element
    cout << "MyQueueLinkedList.dequeue(): " << MyQueueLinkedList.dequeue() << endl;
    cout << "MyQueueLinkedList.front(): " << MyQueueLinkedList.front() << endl;
    MyQueueLinkedList.PrintQueue();
    cout << "MyQueueLinkedList.size(): " << MyQueueLinkedList.size() << endl;

    // Test: Dequeue More Elements
    cout << "MyQueueLinkedList.dequeue(): " << MyQueueLinkedList.dequeue() << endl;
    cout << "MyQueueLinkedList.front(): " << MyQueueLinkedList.front() << endl;
    MyQueueLinkedList.PrintQueue();
    cout << "MyQueueLinkedList.size(): " << MyQueueLinkedList.size() << endl;

    // Test: Dequeue More Elements
    cout << "MyQueueLinkedList.dequeue(): " << MyQueueLinkedList.dequeue() << endl;
    cout << "MyQueueLinkedList.front(): " << MyQueueLinkedList.front() << endl;
    MyQueueLinkedList.PrintQueue();
    cout << "MyQueueLinkedList.size(): " << MyQueueLinkedList.size() << endl;

    // Edge Case: Large Number of Enqueues
    for (int i = 0; i < 100; i++) {
        MyQueueLinkedList.enqueue(i);
    }
    cout << "MyQueueLinkedList.size(): " << MyQueueLinkedList.size() << endl;

    cout << "==========================================================================================" << endl;
    cout << "===================================== BinaryTree.h =======================================" << endl;
    cout << "==========================================================================================" << endl;
    
    cout << "------> MyBinaryTreeType <-------" << endl;
    MyBinaryTreeType BinaryTree;

    // Test: Insert Elements
    BinaryTree.insert(100);
    BinaryTree.insert(50);
    BinaryTree.insert(110);
    BinaryTree.insert(40);
    BinaryTree.insert(60);
    BinaryTree.insert(105);
    BinaryTree.insert(120);
    BinaryTree.insert(30);
    BinaryTree.insert(45);
    BinaryTree.insert(55);
    BinaryTree.insert(70);
    BinaryTree.insert(104);
    BinaryTree.insert(106);
    BinaryTree.insert(110);
    BinaryTree.insert(125);

    // Test: Find Element (Existing)
    cout << "BinaryTree.find(110): " << BinaryTree.find(110) << (BinaryTree.find(110) ? " (True)" : " (False)") << endl;

    // Edge Case: Find Element (Non-Existing)
    cout << "BinaryTree.find(20): " << BinaryTree.find(20) << (BinaryTree.find(20) ? " (True)" : " (False)") << endl;

    // Test: Print Binary Tree
    BinaryTree.PrintBinaryTree();

    cout << "==========================================================================================" << endl;
    cout << "======================================= Calculator.h =====================================" << endl;
    cout << "==========================================================================================" << endl;

    cout << "------> CalculatorFunction <-------" << endl;
    CalculatorFunction MyCalculator;

    // Test: Basic Addition
    string rpn_expression1 = "3 4 +";
    int rpn_result1 = MyCalculator.evaluate_rpn(rpn_expression1);
    cout << "RPN Result 1 For Expression \"3 4 +\": " << rpn_result1 << endl; // Should output 7
        
    // Test: Basic Subtraction
    string rpn_expression2 = "7 2 -";
    int rpn_result2 = MyCalculator.evaluate_rpn(rpn_expression2);
    cout << "RPN Result 2 For Expression \"7 2 -\": " << rpn_result2 << endl; // Should output 5
        
    // Test: Multiplication
    string rpn_expression3 = "3 5 *";
    int rpn_result3 = MyCalculator.evaluate_rpn(rpn_expression3);
    cout << "RPN Result 3 For Expression \"3 5 *\": " << rpn_result3 << endl; // Should output 15
        
    // Test: Division
    string rpn_expression4 = "10 2 /";
    int rpn_result4 = MyCalculator.evaluate_rpn(rpn_expression4);
    cout << "RPN Result 4 For Expression \"10 2 /\": " << rpn_result4 << endl; // Should output 5
        
    // Test: Multiple Operations
    string rpn_expression5 = "3 4 + 2 *";
    int rpn_result5 = MyCalculator.evaluate_rpn(rpn_expression5);
    cout << "RPN Result 5 For Expression \"3 4 + 2 *\": " << rpn_result5 << endl; // Should output 14
        
    // Test: Negative Numbers
    string rpn_expression6 = "-3 4 +";
    int rpn_result6 = MyCalculator.evaluate_rpn(rpn_expression6);
    cout << "RPN Result 6 For Expression \"-3 4 +\": " << rpn_result6 << endl; // Should output 1
        
    // Test: Simple Infix Expression
    string infix_expression1 = "3 + 2 * 5";
    int infix_result1 = MyCalculator.evaluate_infix(infix_expression1);
    cout << "Infix Result 1 For Expression \"3 + 2 * 5\": " << infix_result1 << endl; // Should output 13
    
    // Test: Complex Infix Expression
    string infix_expression2 = "3 + 4 * 2 / (1 - 5)^2^3";
    int infix_result2 = MyCalculator.evaluate_infix(infix_expression2);
    cout << "Infix Result 2 For Expression \"3 + 4 * 2 / (1 - 5)^2^3\": " << infix_result2 << endl; // Should output 3
        
    // Test: Nested Parentheses Infix Expression
    string infix_expression3 = "(1 + 2) * (3 + 4)";
    int infix_result3 = MyCalculator.evaluate_infix(infix_expression3);
    cout << "Infix Result 3 For Expression \"(1 + 2) * (3 + 4)\": " << infix_result3 << endl; // Should output 21    

    return 0;
}