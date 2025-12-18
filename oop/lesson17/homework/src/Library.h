#pragma once

#include <vector>
#include <algorithm>
#include "Bookshelf.h"


using namespace std;

class Library
{
public:
    vector<Bookshelf*> bookshelves;

    void addBookshelf(Bookshelf* bookshelf)
    {
        bookshelves.push_back(bookshelf);
    }

    void removeBookshelf(Bookshelf* shelf)
    {
        vector<Bookshelf*>::iterator it = find(bookshelves.begin(), bookshelves.end(), shelf);
        if (it != bookshelves.end()) {
            bookshelves.erase(it);
        }
    }

    ~Library()
    {
        for(int i{}; i < bookshelves.size(); ++i)
        {
            delete bookshelves[i];
        }
    }

};