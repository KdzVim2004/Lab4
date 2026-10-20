#include "book.h"
#include <stdexcept>
#include <utility>
using namespace std;
setlocale(LC_ALL, "Russian");
bool Book::isValidData(string title, string author, int year, int pages) const
{
    if (title.empty() || author.empty())
    {
        return false;
    }
    if (year < 1450 || year > 2025)
    {
        return false;
    }
    if (pages <= 0)
    {
        return false;
    }

    return true;
}

Book::Book(string title, string author, int year, int pages)
    : title_(title), author_(author), year_(year), pages_(pages), is_available_(true) {
    if (!isValidData(title_, author_, year_, pages_))
    {
        throw invalid_argument("Íåêîððåêòíûå äàííûå êíèãè");
    }
}

//Ãåòòåðû
string Book::title() const
{
    return title_;
}

string Book::author() const
{
    return author_;
}

int Book::year() const
{
    return year_;
}

int Book::pages() const
{
    return pages_;
}

bool Book::isAvailable() const
{
    return is_available_;
}

//Ñåòòåðû
void Book::updateTitle(string new_title) {
    if (!isValidData(new_title, author_, year_, pages_))
    {
        throw invalid_argument("Íàçâàíèå íå ìîæåò áûòü ïóñòûì");
    }
    title_ = new_title;
}

void Book::updateAuthor(string new_author) {
    if (!isValidData(title_, new_author, year_, pages_))
    {
        throw invalid_argument("Àâòîð íå ìîæåò áûòü ïóñòûì");
    }
    author_ = new_author;
}

void Book::updateYear(int new_year) {
    if (!isValidData(title_, author_, new_year, pages_))
    {
        throw invalid_argument("Ãîä äîëæåí áûòü îò 1450 äî 2025");
    }
    year_ = new_year;
}

void Book::updatePages(int new_pages) {
    if (!isValidData(title_, author_, year_, new_pages))
    {
        throw invalid_argument("Ñòðàíèö äîëæíî áûòü áîëüøå 0");
    }
    pages_ = new_pages;
}

void Book::checkout()
{
    is_available_ = false;
}

void Book::returnBook()
{
    is_available_ = true;
}

string Book::description() const
{
    return title_ + " îò " + author_ + " (" + to_string(year_) + ")";
}
