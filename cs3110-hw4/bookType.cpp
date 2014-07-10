#include <iostream>
#include <string>
#include "bookType.h"
using namespace std;

bookType::bookType()
{
    // default constructor
    // initialized with a string
    title = new string;
    *title = "name";
}

bookType::bookType(string pTitle, std::string pAuthorsArray[], int pNumberOfAuthors, string pPublisher, double pPrice, int pIsbn, int pNumberOfCopies)
{
    title = new string;
    numberOfAuthors = new int;
    publisher = new string;
    price = new double;
    isbn = new int;
    numberOfCopies = new int;

    *title = pTitle;
    *numberOfAuthors = pNumberOfAuthors;

    for (int i = 0; i < *numberOfAuthors; i++)
    {
        authorsArray[i] = pAuthorsArray[i];
//        cout << "private array: " << authorsArray[i] << '\n';
//        cout << "authors : " << pAuthorsArray[i] << '\n';
    }

    *publisher = pPublisher;
    *price = pPrice;
    *isbn = pIsbn;
    *numberOfCopies = pNumberOfCopies;

}

bookType::bookType(string pTitle)
{
    title = new string;
    *title = pTitle;

}

bookType::~bookType()
{
    delete title;
}

void bookType::setPrice(double* bookPrice)
{
    price = bookPrice;
}

double* bookType::getPrice() const
{
    return price;
}

void bookType::setPublisher(string* publisherName)
{
    publisher = publisherName;
}

string* bookType::getPublisher() const
{
    return publisher;
}

void bookType::setNumberOfAuthors(int* numberAuthors)
{
    numberOfAuthors = numberAuthors;
}

int* bookType::getNumberOfAuthors() const
{
    return numberOfAuthors;
}

void bookType::setIsbn(int* isbnNumber)
{
    isbn = isbnNumber;
}

int* bookType::getIsbn() const
{
    return isbn;
}

void bookType::setNumberOfCopies(int* copies)
{
    numberOfCopies = copies;
}

int* bookType::getNumberOfCopies() const
{
    return numberOfCopies;
}

void bookType::setTitle(string* bookTitle)
{
    title = bookTitle;
}

string* bookType::getTitle() const
{
    return title;
}

void bookType::setAuthors(string author [], int numberOfAuthors)
{
    for (int i = 0; i < numberOfAuthors; i++)
    {
        authorsArray[i] = author[i];
//        cout << "in set " << authorsArray[i] << '\n';
//        cout << "in set *authorsArray " << *authorsArray << '\n';
//        cout << "in set *authorsArray " << *(authorsArray + 1) << '\n';
    }
}

void bookType::getAuthors(int numberOfAuthors) const
{
    for (int i = 0; i < numberOfAuthors; i++)
    {
        cout << "Authors: " << authorsArray[i] << '\n';

    }
}
