# Introsort and Memory Management

This repository contains on an optimized sorting framework using a hybrid algorithm called IntroSort, which intelligently combines QuickSort, HeapSort, and InsertionSort to ensure fast and reliable performance across different types of input. In addition, the project introduces a custom Memory Pool for managing dynamic memory allocations efficiently.

The program supports comprehensive testing on various array configurations and sizes, while tracking execution time and memory reuse behavior to demonstrate the advantages of using a Memory Pool.

---

## 📥 Installation & Setup

Follow the steps below to clone and set up the project on your local machine using **Visual Studio Code (VS Code).**

### 1️⃣ Install Required Software

Before proceeding, ensure you have the following installed on your system:

-   [Git](https://git-scm.com/downloads) (For cloning the repository)
-   [Visual Studio Code](https://code.visualstudio.com/) (For writing and running the code)
-   [MinGW (GCC Compiler)](https://sourceforge.net/projects/mingw/) (For compiling C++ code, required if using Windows)

> 📝 **Note:** Mac and Linux users usually have `g++` pre-installed. You can verify it by running:
>
> ```sh
> g++ --version
> ```
>
> If it's not installed, use:
>
> -   **Mac:** `brew install gcc`
> -   **Ubuntu/Linux:** `sudo apt install g++`

---

### 2️⃣ Clone the Repository

-   Open the VS Code application on your device.
-   Create a new folder or navigate to an existing folder where you want to store the project.
-   Open **Command Prompt (Windows)** or **Terminal (Mac/Linux)** in VS Code and run:

```sh
git clone https://github.com/abdultamim02/Algorithm-Design-and-Programming.git
```

Navigate to the project directory:

```sh
cd Introsort\ and\ Memory\ Management/
```

---

## ▶️ Running the Program

### Windows (Using MinGW)

1. Open **Command Prompt** and navigate to the project directory:
    ```sh
    cd '.\Introsort and Memory Management\'
    ```
2. Compile `MyTest.cpp` using g++:
    ```sh
    g++ Mytest.cpp QuickSort.cpp HeapSort.cpp InsertionSort.cpp IntroSort.cpp memory_pool.cpp swap_utils.cpp -o Mytest.exe
    ```
3. Run the compiled program:
    ```sh
    .\Mytest.exe
    ```

### Mac/Linux (Using g++)

1. Open **Terminal** and navigate to the project directory:
    ```sh
    cd Introsort\ and\ Memory\ Management/
    ```
2. Compile `MyTest.cpp` using g++:
    ```sh
    g++ -std=c++11 Mytest.cpp QuickSort.cpp HeapSort.cpp InsertionSort.cpp IntroSort.cpp memory_pool.cpp swap_utils.cpp -o Mytest.exe
    ```
3. Run the compiled program:
    ```sh
    ./Mytest.exe
    ```

---

## ✅ Expected Output

When you run `MyTest.cpp`, the terminal will print the following message:

```
Test Results Written to test_results.txt
```

The output should look something like the output in the file:

```
test_results.txt
```

This output will vary every time `MyTest.cpp` file is compiled.

---
