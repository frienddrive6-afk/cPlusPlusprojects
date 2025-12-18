#pragma once

#include "Publisher.h"
#include "Autor.h"

using namespace std;

class Book
{
public:
    string title;
    Autor* autor;
    Publisher* publisher;

    Book() :
        autor{ nullptr },
        publisher{ nullptr }
    {}

    Book(string title, Autor* autor, Publisher* publisher) :
        title{ title },
        autor{ autor },
        publisher{ publisher }
    {}

};