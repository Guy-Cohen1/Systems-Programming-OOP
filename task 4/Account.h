/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "iostream"
using namespace std;

// Base class representing a generic bank account
class Account
{
    string accountNumber;         // Account number
    string accountHolderName;     // Account holder's name
    double balance;               // Account balance

public:

    // Default constructor
    Account(){};

    // Parameterized constructor to initialize account details
    Account(const string& number, const string& holder, double initialBalance): accountNumber(number), accountHolderName(holder), balance(initialBalance){}

    // Get the current balance of the account
    double getBalance() const {return balance;}

    // Virtual function to deposit money into the account
    virtual void deposit(const double amount){balance+=amount;}

    // Virtual function to withdraw money from the account
    virtual void withdraw(const double amount){balance-=amount;}

    // Virtual function to print account details (to be overridden by derived classes)
    virtual void print() ;

    // Setter function to set the balance of the account
    void set_balance(const double balance){this->balance = balance;}

    // Getter function to get the balance of the account
    double get_balance() const {return balance;}

    // Getter function to get the account number
    string get_account_num() const {return accountNumber;};

    // Getter function to get the account holder's name
    string get_holder_name() const {return accountHolderName;};

    // Virtual destructor (default implementation)
    virtual ~Account() = default;
};

#endif // ACCOUNT_H
