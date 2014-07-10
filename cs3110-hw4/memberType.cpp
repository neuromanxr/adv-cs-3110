#include <iostream>
#include <string>

#include "memberType.h"

using namespace std;

memberType::memberType()
{
    nameOfPerson = "name";
}

memberType::memberType(string name)
{
    nameOfPerson = name;
}

memberType::memberType(string name, int member, int booksBought, double spent)
{
    nameOfPerson = name;
    memberID = member;
    numberOfBooksBought = booksBought;
    amountSpent = spent;
}

void memberType::setNameOfPerson(string name)
{
    nameOfPerson = name;
}

string memberType::getNameOfPerson() const
{
    return nameOfPerson;
}

void memberType::setMemberID(int member)
{
    memberID = member;
}

int memberType::getMemberID() const
{
    return memberID;
}

void memberType::setNumberOfBooksBought(int number)
{
    numberOfBooksBought = number;
}

int memberType::getNumberOfBooksBought() const
{
    return numberOfBooksBought;
}

void memberType::setAmountSpent(double spent)
{
    amountSpent = spent;
}

double memberType::getAmountSpent() const
{
    return amountSpent;
}
