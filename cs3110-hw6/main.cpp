#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

    string inputFileName;
    string outputFileName;
    char ch;

    string sentence;

    ofstream outputFile;
    cout << "Enter output filename: ";
    cin >> outputFileName;
    cout << endl;

    ifstream inputFile;
    cout << "Enter input filename: ";
    cin >> inputFileName;

    inputFile.open(inputFileName.c_str(), ios::in);
    outputFile.open(outputFileName.c_str(), ios::out);

    if (inputFile) // if file open successful
    {
        //getline(inputFile, sentence);

        inputFile.get(ch); // get sentence one character at a time

        while(inputFile) // while file open, continue
        {
            //cout << sentence << endl;
            if (isupper(ch))
            {
                ch = tolower(ch);

            }

            if (ch == '.')
            {
                cout << ch;
                outputFile.put(ch);
                inputFile.get(ch); // get the next character
                if (isspace(ch))
                {
                    outputFile.put(ch);
                    inputFile.get(ch);
                }
                if (isalpha(ch))
                {
                    ch = toupper(ch);
                    outputFile.put(ch);
                }


            }
            else
            {
                cout << ch; // output the character
                outputFile.put(ch); // write to second file

            }

            //outputFile.put(ch); // write to second file

            //getline(inputFile, sentence);

            inputFile.get(ch); // get more characters
        }

        inputFile.close();
        outputFile.close();

    }
    else
    {
        cout << "Cannot open file.\n";
    }






    return 0;
}
