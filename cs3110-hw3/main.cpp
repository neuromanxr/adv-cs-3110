/* CS3110 - Homework #3

   Kelvin Lee

   Payroll program

*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void readFile();

double calculateBasePay(int counter, double arrHours[], double arrPayRate[]);

double calculateTax(int counter, double basePay, double arrAge[]);

void sortNames(int numberOfElements, string arrLastName[], string arrFirstName[]);

void sortNetPay(int numberOfElements, string arrLastName[], string arrFirstName[], double arrNetPay[]);


int main()
{

    readFile();


    return 0;
}

void readFile()
{
    string arrLastName[50];
    string arrFirstName[50];
    double arrHours[50];
    double arrPayRate[50];
    double arrAge[50];
    int numberOfElements = 0;

    double basePay = 0.0;
    double taxPaid = 0.0;
    double netPay = 0.0;

    double arrNetPay[50];

//    vector <string> nameOld;
//    vector <string> nameYoung;
//    vector <int> ageOld;
//    vector <int> ageYoung;

    string nameOld = "";
    string nameYoung = "";
    int ageOld = 0;
    int ageYoung = 0;

    ifstream myfile ("file.txt");
    if (myfile.is_open())
    {
        cout << "MISER CORPORATION PAYROLL" << '\n';
        cout << "---------------------------------------------" << '\n';

        // pulls data from data file and populates the arrays

        for (int i = 0; myfile >> arrLastName[i] >> arrFirstName[i] >> arrHours[i] >> arrPayRate[i] >> arrAge[i]; ++i) {numberOfElements = i;};

        // prints out the categories

        cout << setw(15) << left << "Name" << setw(14) << left << "Hours worked" << setw(10) << left << "Pay rate" << setw(5) << left \
        << "Age" << setw(10) << left << "Base Pay" << setw(7) << right << "Tax" << setw(11) << right << "Net Pay" << '\n';

        cout << "---------------------------------------------" << '\n';

//        vector <int> ageOld (arrAge, arrAge + sizeof(arrAge) / sizeof(arrAge[0]));
//        cout << "Vector: " << ageOld.at(0);

        // variable declarations for the young and old check
        ageOld = arrAge[0];
        nameOld = arrLastName[0] + arrFirstName[0];
        ageYoung = arrAge[0];
        nameYoung = arrLastName[0] + arrFirstName[0];

        // variable declarations for the most tax paid
        double mostTaxPaid = 0.0;
        string nameMostTax = "";

        for (int i = 0; i <= numberOfElements; i++)
        {
            basePay = calculateBasePay(i, arrHours, arrPayRate);
            taxPaid = calculateTax(i, basePay, arrAge);
            netPay = basePay - taxPaid;
            arrNetPay[i] = netPay;

            cout << setw(7) << left << arrLastName[i] << " " << setw(8) << left << arrFirstName[i] << setw(7) << right << arrHours[i] << setw(10) << right << arrPayRate[i] << \
            setw(8) << right << arrAge[i] << setw(10) << right << basePay << setw(10) << right << taxPaid << setw(10) << right << netPay << '\n';

            // check and store young and oldest employee

            if (arrAge[i] > ageOld)
            {
                ageOld = arrAge[i];
                nameOld = arrLastName[i] + arrFirstName[i];
            }
            if (arrAge[i] < ageYoung)
            {
                ageYoung = arrAge[i];
                nameYoung = arrLastName[i] + arrFirstName[i];
            }

            // check and store employee who paid the most taxes

            if (taxPaid > mostTaxPaid)
            {
                mostTaxPaid = taxPaid;
                nameMostTax = arrLastName[i] + arrFirstName[i];
            }

        }
        myfile.close();
        cout << "---------------------------------------------" << '\n';
        cout << "The oldest employee is: " << nameOld << "   Age: " << ageOld << '\n';
        cout << "The youngest employee is: " << nameYoung << "   Age: " << ageYoung << '\n';
        cout << "The employee who paid the most tax is: " << nameMostTax << "   Tax paid: " << mostTaxPaid << '\n';
        cout << "-----------------------------------" << '\n';
    }
    else
        cout << "Unable to open file" << '\n';

    // runs the sort functions
    sortNames(numberOfElements, arrLastName, arrFirstName);
    sortNetPay(numberOfElements, arrLastName, arrFirstName, arrNetPay);

    cout << '\n';
    cout << "-----------------------------------" << '\n';
    cout << "Payroll program is complete" << '\n';

}

void sortNames(int numberOfElements, string arrLastName[], string arrFirstName[])
{
    vector <string> sortedNames;
    string name = arrLastName[0] + arrFirstName[0];

    for (int i = 0; i <= numberOfElements; i++)
    {
        //cout << name << '\n';
        name = arrLastName[i] + arrFirstName[i];
        sortedNames.push_back(name);
    }

    sort(sortedNames.begin(), sortedNames.end());

//    for (vector<string>::iterator it=sortedNames.begin(); it!=sortedNames.end(); ++it)
//        cout << "::" << *it << '\n';

    cout << "Sort names by alphabetical order: " << '\n';
    cout << "--------------------------" << '\n';
    for (int i = 0; i <= numberOfElements; i++) {cout << sortedNames[i] << '\n';}
    cout << "--------------------------" << '\n';

}

void sortNetPay(int numberOfElements, string arrLastName[], string arrFirstName[], double arrNetPay[])
{
    // sorted with bubble sort

    string name;
    vector<string>sortedNetPayNames;

    bool finishSort = false;

    while (!finishSort)
    {
        finishSort = true;
        for (int i = 0; i <= numberOfElements - 1; i++)
        {

            if (arrNetPay[i] > arrNetPay[i + 1])
                {
                    string tempLName = arrLastName[i];
                    string tempFName = arrFirstName[i];
                    double temp = arrNetPay[i];

                    arrLastName[i] = arrLastName[i + 1];
                    arrFirstName[i] = arrFirstName[i + 1];
                    arrNetPay[i] = arrNetPay[i + 1];

                    arrLastName[i + 1] = tempLName;
                    arrFirstName[i + 1] = tempFName;
                    arrNetPay[i + 1] = temp;
                    finishSort = false;
                }
        }
    }
    for (int i = 0; i <= numberOfElements; i++)
    {
        name = arrLastName[i] + arrFirstName[i];
        sortedNetPayNames.push_back(name);
    }

    cout << "Sorted by net pay: " << '\n';
    cout << "--------------------------" << '\n';
    for (int i = 0; i <= numberOfElements; i++) {cout << "Employee: " << setw(15) << left << sortedNetPayNames[i] \
        << setw(15) << right << " Net Pay: " << setw(5) << left << arrNetPay[i] << '\n';}


}

double calculateBasePay(int counter, double arrHours[], double arrPayRate[])
{
    double basePay = 0.0;
    const double OVER = 1.5;
    basePay = (arrHours[counter] * arrPayRate[counter]);

    if (arrHours[counter] > 40)
    {
        double overtimeHours = arrHours[counter] - 40;
        double difference = overtimeHours * arrPayRate[counter];
        double overtime = overtimeHours * (arrPayRate[counter] * OVER);
        basePay = basePay + overtime - difference;
    }

    return basePay;
}

double calculateTax(int counter, double basePay, double arrAge[])
{
    double taxPaid = 0.0;
    const double HITAXRATE = .50;
    const double LOTAXRATE = .10;

    if (arrAge[counter] >= 55)
    {
        taxPaid = basePay * HITAXRATE;
    }
    else
        taxPaid = basePay * LOTAXRATE;

    return taxPaid;
}
