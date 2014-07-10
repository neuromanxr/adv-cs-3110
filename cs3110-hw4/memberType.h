#ifndef MEMBERTYPE_H_INCLUDED
#define MEMBERTYPE_H_INCLUDED
#include <string>

using std::string;

class memberType
{
private:
    string nameOfPerson;
    int memberID;
    int numberOfBooksBought;
    double amountSpent;
public:
    memberType();
    memberType(string name);
    memberType(string name, int member, int booksBought, double spent);

    void setNameOfPerson(string name);
    string getNameOfPerson() const;

    void setMemberID(int member);
    int getMemberID() const;

    void setNumberOfBooksBought(int number);
    int getNumberOfBooksBought() const;

    void setAmountSpent(double spent);
    double getAmountSpent() const;
};


#endif // MEMBERTYPE_H_INCLUDED
