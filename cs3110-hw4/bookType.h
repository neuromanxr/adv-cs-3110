#ifndef BOOKTYPE_H_INCLUDED
#define BOOKTYPE_H_INCLUDED
#include <string>
using std::string;

class bookType
{
private:
    std::string* title;
    std::string authorsArray[4];
    std::string* publisher;

    double* price;
    int* isbn;
    int* numberOfCopies;
    int* numberOfAuthors;
public:
    bookType();
    bookType(string pTitle);
    bookType(string pTitle, std::string pAuthorsArray[], int pNumberOfAuthors, string pPublisher, double pPrice, int pIsbn, int pNumberOfCopies);
    ~bookType();

    void setPrice(double* );
    double* getPrice() const;

    void setPublisher(string* );
    std::string* getPublisher() const;

    void setIsbn(int *);
    int* getIsbn() const;

    void setNumberOfAuthors(int *);
    int* getNumberOfAuthors() const;

    void setNumberOfCopies(int *);
    int* getNumberOfCopies() const;

    void setTitle(string* );
    std::string* getTitle() const;

    void setAuthors(string [], int numberOfAuthors);
    void getAuthors(int numberOfAuthors) const;


};

#endif // BOOKTYPE_H_INCLUDED
