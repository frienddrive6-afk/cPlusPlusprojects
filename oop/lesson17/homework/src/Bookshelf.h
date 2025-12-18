#pragma once

#include <vector>
#include <algorithm>

#include "Book.h"


using namespace std;

class Bookshelf
{
public:
    vector<Book*> books;

    void addBook(Book* book)
    {
        books.push_back(book);
    }

    void removeBook(Book* book)
    {
        vector<Book*>::iterator it = find(books.begin(), books.end(), book);
        if (it != books.end()) {
            books.erase(it);
        }
    }


    ~Bookshelf()
    {
        books.clear();
    }

};