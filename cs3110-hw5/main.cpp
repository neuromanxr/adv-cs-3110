#include <iostream>
#include "bankAccount.h"


/*
CS3110 - Assignment 5

Kelvin Lee

*/


using namespace std;

int main()
{
    const int MAX_NUM = 100;
    bankAccount accounts[MAX_NUM];

    int numberOfAccounts = read_accts(accounts, MAX_NUM);
//cout << "Number of accounts " << numberOfAccounts << '\n';

    print_accts(accounts, numberOfAccounts);

    char choice;

    do
    {
        menuDisplay();
    //cout << "Number of accounts " << numberOfAccounts << '\n';
        cin >> choice;

        switch (choice)
        {
            case 'W':
            case 'w': cout << "Withdrawal" << '\n';
                      withdrawal(accounts, numberOfAccounts);
                      break;
            case 'D':
            case 'd': cout << "Deposit" << '\n';
                      deposit(accounts, numberOfAccounts);
                      break;
            case 'N':
            case 'n': cout << "New Account" << '\n';
                      //cout << "Number of accounts " << numberOfAccounts << '\n';
                      numberOfAccounts = new_acct(accounts, numberOfAccounts);
                      //cout << "Number of accounts " << numberOfAccounts << '\n';
                      break;
            case 'B':
            case 'b': cout << "Balance Inquiry" << '\n';
                      balance(accounts, numberOfAccounts);
                      break;
            case 'I':
            case 'i': cout << "Account Info" << '\n';
                      account_info(accounts, numberOfAccounts);
                      break;
            case 'C':
            case 'c': cout << "Close Account" << '\n';
                      close_acct(accounts, numberOfAccounts);
                      break;

        }
    }while (toupper(choice) != 'Q');




    return 0;
}
