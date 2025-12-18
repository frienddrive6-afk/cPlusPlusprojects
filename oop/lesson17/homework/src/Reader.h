#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;

class Reader
{
public:
    string name;
    vector<Book*> takenBooks; 

    Reader(string name) : 
        name(name) 
    {}

    void takeBook(Book* book)
    {
        takenBooks.push_back(book);
    }

    void returnBook(Book* book)
    {
        vector<Book*>::iterator it = find(takenBooks.begin(), takenBooks.end(), book);
        if (it != takenBooks.end()) {
            takenBooks.erase(it);
        }
    }
};