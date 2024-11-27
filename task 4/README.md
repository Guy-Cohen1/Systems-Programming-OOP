# Banking System - C++ Assignment

## Overview
This C++ project implements a simple banking system featuring inheritance, polymorphism, and exception handling. The system is designed to manage different types of accounts, including **savings accounts** and **checking accounts**, each with its own unique behavior, while also handling operations such as deposits, withdrawals, and interest calculations.

## Project Requirements

### Key Features
- **Array Template** for managing dynamic arrays of accounts.
- **Account Class** for base functionality such as balance management, deposits, and withdrawals.
- **SavingsAccount Class** that extends Account and manages interest accumulation.
- **CheckingAccount Class** that extends Account and supports overdraft limits.
- **Menu Class** to manage the user interface and handle input/output.

### Structure
1. **Array<T> (Template Class)**  
    Manages a dynamic array of items, providing methods for adding, removing, and getting the size of the array.  
    - **add**: Adds an element to the array.
    - **remove**: Removes an element by index and returns the removed element.
    - **getSize**: Returns the size of the array.

2. **Account Class**  
    A base class representing a general bank account.  
    - Fields: `accountNumber` (string), `accountHolderName` (string), `balance` (double).
    - Methods:  
        - `getBalance()`: Returns the current balance.
        - Virtual methods:  
            - `deposit(double amount)`: Adds funds to the account.
            - `withdraw(double amount)`: Withdraws funds from the account.

3. **SavingsAccount Class** (Inherits from Account)  
    A savings account that includes interest rate calculations.  
    - Fields: `annualInterestRate` (double), `lastTransactionTime` (chrono::steady_clock::time_point).
    - Methods:  
        - `deposit(double amount)`: Adds funds and updates the interest.
        - `withdraw(double amount)`: Withdraws funds and updates the interest.

4. **CheckingAccount Class** (Inherits from Account)  
    A checking account with an overdraft limit.  
    - Fields: `overdraftLimit` (double).
    - Methods:  
        - `deposit(double amount)`: Adds funds to the account.
        - `withdraw(double amount)`: Withdraws funds, checking if overdraft is exceeded.

5. **Menu Class**  
    Manages user interaction and provides the system interface.  
    - Fields: `bankAccounts` (Array<Account*>).
    - Methods:  
        - `mainMenu()`: Displays the user menu and performs actions based on user input.

### Usage
1. **Add a new account**: Adds a new account to the system.
2. **Deposit funds**: Deposit a specified amount to an account.
3. **Withdraw funds**: Withdraw a specified amount from an account.
4. **Delete account**: Removes an account from the system by index.
5. **Display account details**: Shows details of all accounts in the system.
6. **Exit program**: Ends the program after releasing any allocated memory.

