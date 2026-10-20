#ifndef RAREBOOK_H
#define RAREBOOK_H
#include <string>
#include "book.h"

class RareBook : public Book
{
public:
    RareBook(string title, string author, int year, int pages, double estimated_value);

    double estimatedValue() const;
    void applyDiscount(double percent);
    string description() const;

private:
    double estimated_value_;
};
#endif