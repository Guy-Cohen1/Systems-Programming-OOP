/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#include "SavingsAccount.h"

// Parameterized constructor for SavingsAccount class
SavingsAccount::SavingsAccount(const string &number, const string &holder, double initialBalance, double annualRate)
        : Account(number, holder, initialBalance), annualInterestRate(annualRate)
{
    // Initialize the last transaction time to the current time
    lastTransactionTime = chrono::steady_clock::now();
}

// Overridden function to print savings account details
void SavingsAccount::print()
{
    // Update the balance before printing
    this->update_balance();
    // Display the account details: account number, account holder, and balance
    cout << "Account Number: " << this->get_account_num() << endl;
    cout << "Account Holder: " << this->get_holder_name() << endl;
    cout << "Balance: " << this->get_balance() << endl;
}

// Function to update the balance based on the annual interest rate
void SavingsAccount::update_balance()
{
    // Calculate the duration since the last transaction
    auto t = chrono::steady_clock::now() - lastTransactionTime;
    // Convert the duration to seconds
    auto t_s = chrono::duration_cast<chrono::seconds>(t);
    // Update the balance using the compound interest formula
    this->set_balance(this->get_balance() * pow(1 + this->annualInterestRate, t_s.count()));
    // Update the last transaction time to the current time
    lastTransactionTime = chrono::steady_clock::now();
}

// Overridden function to deposit money into the savings account
void SavingsAccount::deposit(double amount)
{
    // Update the balance before depositing
    this->update_balance();
    // Deposit the specified amount
    this->set_balance(this->get_balance() + amount);
}

// Overridden function to withdraw money from the savings account
void SavingsAccount::withdraw(double amount)
{
    // Update the balance before withdrawing
    this->update_balance();
    // Withdraw the specified amount
    this->set_balance(this->get_balance() - 1);  // Note: There might be an error here, consider using 'amount' instead of '1'
}
