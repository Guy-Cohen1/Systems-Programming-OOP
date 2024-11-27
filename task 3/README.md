# Stack and Queue Implementation

## Overview

This assignment involves implementing a dynamic Stack and Queue in C++, along with handling menu interactions for a simple command-line application. The task is divided into three main components: **Stack**, **Queue**, and **Menu**. These components will help you practice class design, constructor and destructor implementation, operator overloading, and data manipulation in C++.

## Assignment Details

### 1. **Stack Implementation**

The `Stack` is implemented as a linked list with the following methods and operator overloads:

#### Private Members:
- `StackNode* top`: Pointer to the top of the stack.
- `StackNode`: Contains an integer `data` and a pointer to the next node `StackNode* next`.

#### Public Members:
- `Stack()`: Initializes `top` to `NULL`.
- `push(int val)`: Adds a new element to the top of the stack.
- `pop()`: Removes the top element. If the stack is empty, prints "Stack is empty".
- `isEmpty()`: Returns `true` if the stack is empty.
- `peek()`: Returns the top element without modifying the stack. If empty, returns `INT_MIN`.

#### Operators:
- `+`: Concatenates two `Stack` objects.
- `+`: Concatenates a `Stack` with an integer.
- `+=`: Pushes an integer onto the stack.
- `==`: Compares two stacks for equality.
- `<<`: Inserts the stack for easy printing.

### 2. **Queue Implementation**

The `Queue` is implemented using a vector with the following methods:

#### Private Members:
- `std::vector<int> queue`: Holds the elements in the queue.
- `int maxQ`: Maximum capacity of the queue.

#### Public Members:
- `MyQueue(int maxQ)`: Initializes the queue with a maximum size.
- `enQueue(int val)`: Inserts an element at the end of the queue.
- `deQueue()`: Removes the front element of the queue.
- `isEmpty()`: Returns `true` if the queue is empty.
- `peek()`: Returns the first element in the queue.

### 3. **Menu Class**

The `Menu` class handles user interactions. The main menu allows navigation to the stack or queue menu, or exiting the program. Each menu provides options to interact with the respective data structure.

#### Main Menu:
- Enter the stack menu.
- Enter the queue menu.
- Exit the program.

#### Stack Menu:
- Add an element to the stack.
- Remove an element from the stack.
- Check if the stack is empty.
- Print the stack.
- Return to the main menu.

#### Queue Menu:
- Print the queue.
- Add an element to the queue.
- Remove an element from the queue.
- Print the first element in the queue.
- Return to the main menu.

### Requirements:
- **Function Signatures**: All required methods must follow the specified function signatures. Pay attention to proper use of `const` where applicable.
- **Code Quality**: Ensure good programming practices, including meaningful variable names, reusability, proper indentation, and comments in English.
- **Error Handling**: Handle edge cases such as empty data structures appropriately.
- **Output Format**: Ensure output matches the example format provided in the `run` file, with appropriate line breaks and no extra spaces.
