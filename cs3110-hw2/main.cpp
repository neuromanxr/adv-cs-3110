// CS3110 Homework # 2
//
// Kelvin Lee
//
// Borough with the fewest accidents

#include <iostream>
#include <string>

using namespace std;

int getNumAccidents(string);

int findLowest(int arr[]);


int main()
{
    string boroughNames[] = {"Bronx", "Queens", "Brooklyn", "Staten Island", "Manhattan"};
    int accidentNumbers[5];

    for (int i = 0; i < 5; i++)
    {
        accidentNumbers[i] = getNumAccidents(boroughNames[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << boroughNames[i] << " accidents: " << accidentNumbers[i] << endl;
    }

    int lowIndex = findLowest(accidentNumbers);
    cout << "The borough with the fewest accidents is: " << boroughNames[lowIndex] << " with: " << accidentNumbers[lowIndex] << " accidents.";

    return 0;
}


int getNumAccidents(string borough)
{
    int input = 0;
    bool incorrectInput = true;
    cout << "Enter the number of automobile accidents for: " << borough << endl;

    // validate input
    while (incorrectInput)
    {
        cin >> input;
        if (input < 0)
        {
            cout << "That is not a valid input (zero or greater is acceptable) Try again: " << endl;
            incorrectInput = true;
        }
        else
            break;
    }
    return input;
}


int findLowest(int arr[])
{
    int index = 0;
    int small = arr[0];
    for (int i = 1; i < 5; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
            index = i;
        }
    }
    return index;
}
