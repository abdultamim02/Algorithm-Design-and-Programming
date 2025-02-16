# Fundamental Data Structures and Programming in C++

This repository contains a project on fundamental data structures and programming concepts: arrays, linked lists, stacks, queues, and binary trees. 
Additionally, it includes a simple calculator program in C++ that evaluates mathematical expressions in both Reverse Polish Notation (RPN) and infix notation using various data structures.

---

## 📥 Installation & Setup

Follow the steps below to clone and set up the project on your local machine using **Visual Studio Code (VS Code).**

### 1️⃣ Install Required Software

Before proceeding, ensure you have the following installed on your system:

- [Git](https://git-scm.com/downloads) (For cloning the repository)
- [Visual Studio Code](https://code.visualstudio.com/) (For writing and running the code)
- [MinGW (GCC Compiler)](https://sourceforge.net/projects/mingw/) (For compiling C++ code, required if using Windows)

> 📝 **Note:** Mac and Linux users usually have `g++` pre-installed. You can verify it by running:
> ```sh
> g++ --version
> ```
> If it's not installed, use:
> - **Mac:** `brew install gcc`
> - **Ubuntu/Linux:** `sudo apt install g++`

---

### 2️⃣ Clone the Repository

* Open the VS Code application on your device.
* Create a new folder or navigate to an existing folder where you want to store the project.
* Open **Command Prompt (Windows)** or **Terminal (Mac/Linux)** in VS Code and run:

```sh
git clone https://github.com/abdultamim02/Algorithm-Design-and-Programming.git
```

Navigate to the project directory:

```sh
cd Data\ Structures\ Fundamentals/
```

---

## ▶️ Running the Program

### Windows (Using MinGW)

1. Open **Command Prompt** and navigate to the project directory:
   ```sh
   cd "Data Structures Fundamentals"
   ```
2. Compile `MyTest.cpp` using g++:
   ```sh
   g++ -o MyTest MyTest.cpp -std=c++11
   ```
3. Run the compiled program:
   ```sh
   MyTest.exe
   ```

### Mac/Linux (Using g++)

1. Open **Terminal** and navigate to the project directory:
   ```sh
   cd Data\ Structures\ Fundamentals/
   ```
2. Compile `MyTest.cpp` using g++:
   ```sh
   g++ -o MyTest MyTest.cpp -std=c++11
   ```
3. Run the compiled program:
   ```sh
   ./MyTest
   ```

---

## ✅ Expected Output

When you run `MyTest.cpp`, the output should look something like this:

```
==========================================================================================
======================================== Stack.h =========================================
==========================================================================================
------> MyStackArrayType <-------
MyStackArray.is_empty(): 1 (True)
MyStackArray.pop(): Stack Underflow -1
MyStackArray.top(): Stack Underflow -1
Stack: [2, 4, 6, 8, 10]
MyStackArray.is_empty(): 0 (False)
MyStackArray.top(): 10
MyStackArray.size(): 5
MyStackArray.pop(): 10
MyStackArray.top(): 8
Stack: [2, 4, 6, 8]
MyStackArray.size(): 4
MyStackArray.pop(): 8
MyStackArray.top(): 6
Stack: [2, 4, 6]
MyStackArray.size(): 3
MyStackArray.pop(): 6
MyStackArray.top(): 4
Stack: [2, 4]
MyStackArray.size(): 2
MyStackArray.size(): 102
-------------------------------------------
------> MyStackLinkedListType <-------
MyStackLinkedList.is_empty(): 1 (True)
MyStackLinkedList.pop(): Stack Underflow -1
MyStackLinkedList.top(): Stack Underflow -1
Stack: [10 -> 8 -> 6 -> 4 -> 2]
MyStackLinkedList.is_empty(): 0 (False)
MyStackLinkedList.top(): 10
MyStackLinkedList.size(): 5
MyStackLinkedList.pop(): 10
MyStackLinkedList.top(): 8
Stack: [8 -> 6 -> 4 -> 2]
MyStackLinkedList.size(): 4
MyStackLinkedList.pop(): 8
MyStackLinkedList.top(): 6
Stack: [6 -> 4 -> 2]
MyStackLinkedList.size(): 3
MyStackLinkedList.pop(): 6
MyStackLinkedList.top(): 4
Stack: [4 -> 2]
MyStackLinkedList.size(): 2
MyStackLinkedList.size(): 102
==========================================================================================
======================================== Queue.h =========================================
==========================================================================================
------> MyQueueArrayType <-------
MyQueueArray.is_empty(): 1 (True)
MyQueueArray.dequeue(): Queue Underflow -1
MyQueueArray.front(): Queue Underflow -1
Queue: [2, 4, 6, 8, 10]
MyQueueArray.is_empty(): 0 (False)
MyQueueArray.front(): 2
MyQueueArray.size(): 5
MyQueueArray.dequeue(): 2
MyQueueArray.front(): 4
Queue: [4, 6, 8, 10]
MyQueueArray.size(): 4
MyQueueArray.dequeue(): 4
MyQueueArray.front(): 6
Queue: [6, 8, 10]
MyQueueArray.size(): 3
MyQueueArray.dequeue(): 6
MyQueueArray.front(): 8
Queue: [8, 10]
MyQueueArray.size(): 2
MyQueueArray.size(): 102
-------------------------------------------
------> MyQueueLinkedListType <-------
MyQueueLinkedList.is_empty(): 1 (True)
MyQueueLinkedList.dequeue(): Queue Underflow -1
MyQueueLinkedList.front(): Queue Underflow -1
Queue: [2 -> 4 -> 6 -> 8 -> 10]
MyQueueLinkedList.is_empty(): 0 (False)
MyQueueLinkedList.front(): 2
MyQueueLinkedList.size(): 5
MyQueueLinkedList.dequeue(): 2
MyQueueLinkedList.front(): 4
Queue: [4 -> 6 -> 8 -> 10]
MyQueueLinkedList.size(): 4
MyQueueLinkedList.dequeue(): 4
MyQueueLinkedList.front(): 6
Queue: [6 -> 8 -> 10]
MyQueueLinkedList.size(): 3
MyQueueLinkedList.dequeue(): 6
MyQueueLinkedList.front(): 8
Queue: [8 -> 10]
MyQueueLinkedList.size(): 2
MyQueueLinkedList.size(): 102
==========================================================================================
===================================== BinaryTree.h =======================================
==========================================================================================
------> MyBinaryTreeType <-------
BinaryTree.find(110): 1 (True)
BinaryTree.find(20): 0 (False)
In-Order Traversal: [30, 40, 45, 50, 55, 60, 70, 100, 104, 105, 106, 110, 110, 120, 125]
Pre-Order Traversal: [100, 50, 40, 30, 45, 60, 55, 70, 110, 105, 104, 106, 120, 110, 125]
Post-Order Traversal: [30, 45, 40, 55, 70, 60, 50, 104, 106, 105, 110, 125, 120, 110, 100]
==========================================================================================
======================================= Calculator.h =====================================
==========================================================================================
------> CalculatorFunction <-------
RPN Result 1 For Expression "3 4 +": 7
RPN Result 2 For Expression "7 2 -": 5
RPN Result 3 For Expression "3 5 *": 15
RPN Result 4 For Expression "10 2 /": 5
RPN Result 5 For Expression "3 4 + 2 *": 14
RPN Result 6 For Expression "-3 4 +": 1
Infix Result 1 For Expression "3 + 2 * 5": 13
Infix Result 2 For Expression "3 + 4 * 2 / (1 - 5)^2^3": 3
Infix Result 3 For Expression "(1 + 2) * (3 + 4)": 21
```

This output will vary depending on the test cases you add in `MyTest.cpp`.

---
