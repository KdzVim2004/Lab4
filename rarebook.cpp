#include "rarebook.h"
#include <stdexcept>
#include <string>

RareBook::RareBook(string title, string author, int year, int pages, double estimated_value)
        : Book(title, author, year, pages), estimated_value_(estimated_value) {
    if (estimated_value_ < 0) {
        throw invalid_argument( "ќценочна€ стоимость не может быть отрицательной");
    }
}

double RareBook::estimatedValue() const
{
    return estimated_value_;
}

void RareBook::applyDiscount(double percent)
{
    if (percent < 0 || percent > 100)
    {
        throw invalid_argument( "—кидка должна быть от 0 до 100");
    }
    estimated_value_ *= (1.0 - percent / 100.0);
}

string RareBook::description() const
{
    return Book::description()
        + " [ќценочна€ стоимость: "
        + to_string(estimated_value_) + " руб.]";
}