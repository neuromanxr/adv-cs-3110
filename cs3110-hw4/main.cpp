#include <iostream>
#include <string>
#include <cctype>

#include "bookType.h"
#include "memberType.h"

using namespace std;

void displayMenu();
void subMenu(bookType [], int*, int);
void searchBookTitle(bookType []);
void searchBookISBN(bookType []);

int main()
{

    // parameters for constructor
    string bookTitle = "Rich Dad Poor Dad";
    string authors[] = {"bob", "tom"};
    string authorsMore[] = {"rich", "pat", "tod"};
    string publisher = "Another Publisher";

    // for books array
    const int NUM_ITEMS = 100;

    bookType richDad(bookTitle, authors, 2, publisher, 25.99, 10023, 100);

    bookType books[NUM_ITEMS] = {bookType(bookTitle, authors, 2, publisher, 25.99, 10023, 100),
                                 bookType("Fruit Loops", authorsMore, 3, "Some Publisher", 30.99, 10025, 125)};

    char choice;

    do
    {
        displayMenu();
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'C')
        {
            cout << "Make a choice of either 'a', 'b', 'c': " << '\n';
            cin >> choice;
        }

        switch (choice)
        {
            case 'a': searchBookTitle(books);
            break;
            case 'b': searchBookISBN(books);
            break;
        }
    }while (toupper(choice) != 'C');


    // getting from books array initialized with constructor
    cout << "------------------------" << '\n';
    cout << "Array of Books " << '\n';

    for (int i = 0; i < 2; i++)
    {
        int numb = *books[i].getNumberOfAuthors();

        cout << "Title: " << *books[i].getTitle() << '\n';
        books[i].getAuthors(numb);
        cout << "Number of Authors: " << *books[i].getNumberOfAuthors() << '\n';
        cout << "Publisher: " << *books[i].getPublisher() << '\n';
        cout << "Price: " << *books[i].getPrice() << '\n';
        cout << "ISBN: " << *books[i].getIsbn() << '\n';
        cout << "Copies: " << *books[i].getNumberOfCopies() << '\n';
    }

    // getter methods for richDad object

    cout << "------------------------" << '\n';
    cout << "Rich Dad Poor Dad Book " << '\n';
    cout << "Title: " << *richDad.getTitle() << '\n';
    richDad.getAuthors(2);
    cout << "Number of Authors: " << *richDad.getNumberOfAuthors() << '\n';
    cout << "Publisher: " << *richDad.getPublisher() << '\n';
    cout << "Price: " << *richDad.getPrice() << '\n';
    cout << "ISBN: " << *richDad.getIsbn() << '\n';
    cout << "Copies: " << *richDad.getNumberOfCopies() << '\n';

    // book object Art of War
    // testing setters and getters

    bookType artOfWar;

    string* bTitle = new string;
    *bTitle = "Art of War";
    artOfWar.setTitle(bTitle);
    string* publisherSome = new string;
    *publisherSome = "Unique Publisher";
    artOfWar.setPublisher(publisherSome);
    string authorsSome[] = {"man", "ana"};
    artOfWar.setAuthors(authorsSome, 2);
    double* bPrice = new double;
    *bPrice = 23.99;
    artOfWar.setPrice(bPrice);
    int* bIsbn = new int;
    *bIsbn = 10036;
    artOfWar.setIsbn(bIsbn);
    int* bNumberCopies = new int;
    *bNumberCopies = 24;
    artOfWar.setNumberOfCopies(bNumberCopies);

    cout << "------------------------" << '\n';
    cout << "Art of War Book " << '\n';
    cout << "Title: " << *artOfWar.getTitle() << '\n';
    artOfWar.getAuthors(2);
    cout << "Publisher: " << *artOfWar.getPublisher() << '\n';
    cout << "Price: " << *artOfWar.getPrice() << '\n';
    cout << "ISBN: " << *artOfWar.getIsbn() << '\n';
    cout << "Copies: " << *artOfWar.getNumberOfCopies() << '\n';


    // setter and getter methods for firstMember object

    memberType firstMember;
    firstMember.setNameOfPerson("Kelvin");
    firstMember.setMemberID(1101);
    firstMember.setNumberOfBooksBought(5);
    firstMember.setAmountSpent(100.25);
    cout << "Name: " << firstMember.getNameOfPerson() << '\n';
    cout << "Member ID: " << firstMember.getMemberID() << '\n';
    cout << "Books Bought: " << firstMember.getNumberOfBooksBought() << '\n';
    cout << "Amount Spent: " << firstMember.getAmountSpent() << '\n';


    return 0;
}

void searchBookTitle(bookType book[])
{
    cout << "Enter a search string: " << '\n';
    char searchString[256];
    cin.ignore();
    cin.getline(searchString, 256);
    //cout << "input " << searchString << '\n';
    bool found = true;

    int* numberOfBooks = new int;
    *numberOfBooks = 100;

    for (int i = 0; i < 2; i++)
    {
        if (*book[i].getTitle() == searchString)
        {
            found = true;
            cout << "Book found" << '\n';
            subMenu(book, numberOfBooks, i);
        }
        else
            found = false;
    }
    if (found == false)
        cout << "Book not found" << '\n';

}

void searchBookISBN(bookType book[])
{
    cout << "Enter ISBN: " << '\n';
    int searchISBN;
    bool found = true;
    cin.ignore();
    cin >> searchISBN;

    for (int i = 0; i < 2; i++)
    {
        if (*book[i].getIsbn() == searchISBN)
        {
            found = true;
            cout << "Book found" << '\n';
        }
        else
            found = false;
    }
    if (found == false)
        cout << "Book not found" << '\n';
}

void displayMenu()
{
    cout << '\n';
    cout << "MENU" << '\n';
    cout << "A) Search by Title\n";
    cout << "B) Search by ISBN\n";
    cout << "C) Exit\n";
    cout << "Enter choice: ";

}

void subMenu(bookType book[], int* number, int index)
{
    cout << '\n';
    cout << "SUBMENU" << '\n';
    cout << "A) Update copies in stock\n" << '\n';

    char choice;

    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'A')
        {
            cout << "Make a choice of either 'a': " << '\n';
            cin >> choice;
        }

        switch (choice)
        {
            case 'a': book[index].setNumberOfCopies(number);
                      cout << "Number of copies: " << *book[index].getNumberOfCopies() << '\n';

            break;


        }
    }while (toupper(choice) != 'A');
}
