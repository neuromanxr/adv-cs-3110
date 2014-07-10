#include "bankAccount.h"
#include <string>
#include <fstream>

using namespace std;

// reads in initial database of 3 objects

int read_accts(bankAccount account[], int max_accts)
{
    int num_accts = 3;
    string fName[3] = {"Sally", "Thomas", "George"};
    string lName[3] = {"Anderson", "Lee", "Lopez"};
    int SSNumber[3] = {256252121, 652521212, 121252652};
    int accountNumb[3] = {1005820, 1005821, 1005822};
    string accountTyp[3] = {"Checking", "Savings", "CD"};
    double accountBalance[3] = {10212.50, 9523.25, 26545.75};


    for (int i = 0; i < max_accts; i++)
    {
        if (i == num_accts)
            break;
        account[i].nameAndNumber.firstAndLast.firstName = fName[i];
        account[i].nameAndNumber.firstAndLast.lastName = lName[i];
        account[i].nameAndNumber.SSNumber = SSNumber[i];
        account[i].accountNumber = accountNumb[i];
        account[i].accountType = accountTyp[i];
        account[i].balance = accountBalance[i];

    }
    return num_accts;
}

void menuDisplay()
{
    cout << '\n';
    cout << "MENU" << '\n';
    cout << "W) Withdrawal\n";
    cout << "D) Deposit\n";
    cout << "N) New Account\n";
    cout << "B) Balance\n";
    cout << "I) Account Info\n";
    cout << "C) Close Account\n";
    cout << "Enter choice: ";
}

//void menu()
//{
//    char choice;
//
//    do
//    {
//        menuDisplay();
//        cin >> choice;
//        while (toupper(choice) != 'W' || toupper(choice) != 'D' || toupper(choice) != 'N' \
//               || toupper(choice) != 'B' || toupper(choice) != 'I' || toupper(choice) != 'C')
//        {
//            cout << "Make a choice of either 'w', 'd', 'n', 'b', 'i', 'c': " << '\n';
//            cin >> choice;
//
//        }
//}

// finds the requested account by going through account array

int findacct(const bankAccount account[], int num_accts, int requested_account)
{
//cout << "num_accts " << num_accts << '\n';
    for (int i = 0; i < num_accts; i++)
    {
    //cout << "findacct: " << account[i].accountNumber << " " << requested_account << '\n';
        if (account[i].accountNumber == requested_account)
        {
        //cout << "findacct match: " << account[i].accountNumber << " " << requested_account << '\n';
            return i;
        }

    }
    return -1;
}

void withdrawal(bankAccount account[], int num_accts)
{
//cout << "num_accts " << num_accts << '\n';

    int input = 0;
    int withdrawAmount = 0;
//bool confirm = false;
    cout << "Enter Account Number: ";
    cin >> input;
    int findAccount = findacct(account, num_accts, input);
    if (findAccount == -1)
    {
        cout << "Account Number: " << input << " doesn't exist." << '\n';
    }
    else
    {
        cout << "How much do you want to withdraw? : ";
        cin >> withdrawAmount;
        if (withdrawAmount > account[findAccount].balance)
            cout << "Insufficient funds." << '\n';
        else
        {
            cout << "Withdrawing: " << withdrawAmount << " dollars" << '\n';
            account[findAccount].balance = account[findAccount].balance - withdrawAmount;
            cout << "New Balance: " << account[findAccount].balance << '\n';
        }
    }

}

void deposit(bankAccount account[], int num_accts)
{
    int input = 0;
    int depositAmount = 0;
//bool confirm = false;
    cout << "Enter Account Number: ";
    cin >> input;
    int findAccount = findacct(account, num_accts, input);
    if (findAccount == -1)
    {
        cout << "Account Number: " << input << " doesn't exist." << '\n';
    }
    else
    {
        cout << "How much do you want to deposit? : ";
        cin >> depositAmount;
        if (depositAmount > account[findAccount].balance)
            cout << "Insufficient funds." << '\n';
        else
        {
            cout << "Depositing: " << depositAmount << " dollars" << '\n';
            account[findAccount].balance = account[findAccount].balance + depositAmount;
            cout << "New Balance: " << account[findAccount].balance << '\n';
        }
    }
}

// creates new account, increments num_accts after creating new account and returns new num_accts

int new_acct(bankAccount account[], int num_accts)
{
    int input = 0;
    int accountType = 0;
    //bool confirm = false;
    cout << "Enter a new Account Number: ";
    cin >> input;
    int findAccount = findacct(account, num_accts, input);
    if (findAccount == -1)
    {
        account[num_accts].accountNumber = input;
        cout << "Account Number: " << account[num_accts].accountNumber << '\n';
        cout << "Enter First Name: ";
    //cout << "num_accts " << num_accts << '\n';
        cin >> account[num_accts].nameAndNumber.firstAndLast.firstName;
        cin.ignore();
    //cout << account[num_accts].nameAndNumber.firstAndLast.firstName << '\n';
        cout << "Enter Last Name: ";
        cin >> account[num_accts].nameAndNumber.firstAndLast.lastName;
        cin.ignore();
        cout << "Enter Social Security Number: ";
        cin >> account[num_accts].nameAndNumber.SSNumber;
        cout << "Enter Account Type: ";
        cin >> accountType;
        switch (accountType)
        {
            case 1: cout << "Checking" << '\n';
                      account[num_accts].accountType = "Checking";
                      break;
            case 2: cout << "Savings" << '\n';
                      account[num_accts].accountType = "Savings";
                      break;
            case 3: cout << "CD" << '\n';
                      account[num_accts].accountType = "CD";
                      break;

        }
        cout << "Enter Initial Deposit: ";
        cin >> account[num_accts].balance;

    //cout << account[num_accts].balance << '\n';
        num_accts += 1;
    }
    else
    {
        cout << "Account already exists." << '\n';

    }
    return num_accts;

}

// closes account by emptying out values of object in the array

int close_acct(bankAccount account[], int num_accts)
{
    int input = 0;
//bool confirm = false;
    cout << "Enter Account Number: " << '\n';
    cin >> input;
    int findAccount = findacct(account, num_accts, input);
    if (findAccount == -1)
    {
        cout << "Account Number: " << input << " doesn't exist." << '\n';
    }
    else if (account[findAccount].balance > 0)
    {
        cout << "There is a non-zero balance in Account Number: " << account[findAccount].accountNumber << '\n';
    }
    else if (findAccount != -1)
    {
        cout << "Closing Account: " << input << '\n';
        account[findAccount].nameAndNumber.firstAndLast.firstName = "";
        account[findAccount].nameAndNumber.firstAndLast.lastName = "";
        account[findAccount].nameAndNumber.SSNumber = 0;
        account[findAccount].accountType = "";
        account[findAccount].accountNumber = 0;
        account[findAccount].balance = 0;

    }
    return num_accts - 1;
}

void balance(const bankAccount account[], int num_accts)
{
    int input = 0;
    cout << "Enter Account Number: ";
    cin >> input;
    int findAccount = findacct(account, num_accts, input);
    if (findAccount == -1)
    {
        cout << "Account Number: " << input << " doesn't exist." << '\n';
    }
    else
    {
        cout << "Your balance is: " << account[findAccount].balance << '\n';

    }
}

void account_info(const bankAccount account[], int num_accts)
{

    int input = 0;
    bool found = true;
    cout << "Enter Social Security Number: ";
    cin >> input;
    for (int i = 0; i < num_accts; i++)
    {
        if (input == account[i].nameAndNumber.SSNumber)
        {
            found = true;
            cout << "Account Found." << '\n';
            cout << "Account Info: " << '\n';
            cout << "Name: " << account[i].nameAndNumber.firstAndLast.firstName << " ";
            cout << account[i].nameAndNumber.firstAndLast.lastName << '\n';
            cout << "SSN: " << account[i].nameAndNumber.SSNumber << '\n';
            cout << "Account Number: " << account[i].accountNumber << '\n';
            cout << "Account Type: " << account[i].accountType << '\n';
            cout << "Account Balance: " << account[i].balance << '\n';
            break;

        }
        else
        {
            found = false;

        }
    }
    if (found == false)
        cout << "Account SSN: " << input << " doesn't exist." << '\n';
}

void print_accts(const bankAccount account[], int num_accts)
{
    ofstream outfile("outfile.txt");

    for (int i = 0; i < num_accts; i++)
    {
        cout << "Account Info: " << '\n';
        cout << "Name: " << account[i].nameAndNumber.firstAndLast.firstName << " ";
        cout << account[i].nameAndNumber.firstAndLast.lastName << '\n';
        cout << "SSN: " << account[i].nameAndNumber.SSNumber << '\n';
        cout << "Account Number: " << account[i].accountNumber << '\n';
        cout << "Account Type: " << account[i].accountType << '\n';
        cout << "Account Balance: " << account[i].balance << '\n';
        cout << '\n';

        outfile << "Account Info: " << '\n';
        outfile << "Name: " << account[i].nameAndNumber.firstAndLast.firstName << " ";
        outfile << account[i].nameAndNumber.firstAndLast.lastName << '\n';
        outfile << "SSN: " << account[i].nameAndNumber.SSNumber << '\n';
        outfile << "Account Number: " << account[i].accountNumber << '\n';
        outfile << "Account Type: " << account[i].accountType << '\n';
        outfile << "Account Balance: " << account[i].balance << '\n';
        outfile << '\n';
    }
}
