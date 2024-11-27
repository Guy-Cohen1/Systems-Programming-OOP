/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#include "Account.h"

// Implementation of the print function for the Account class
void Account::print()
{
    // Display the account details: account number, account holder, and balance
    cout<<"Account Number: "<< this->accountNumber << endl;
    cout<< "Account Holder: " << this->accountHolderName << endl;
    cout << "Balance: " << this->balance << endl;
}
