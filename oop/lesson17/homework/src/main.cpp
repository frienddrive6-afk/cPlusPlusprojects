#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
#include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>



#include "Autor.h"
#include "Publisher.h"
#include "Book.h"
#include "Bookshelf.h"
#include "Library.h"
#include "Reader.h"




using namespace std;




int main()
{
    Autor* pushkin = new Autor{"Alexander", "Pushkin"};
    Publisher* ast = new Publisher{"AST"};

    Book* book1 = new Book{"Eugene Onegin", pushkin, ast};
    Book* book2 = new Book{"Tales", pushkin, ast};

    Library myLibrary;


    Bookshelf* shelf1 = new Bookshelf{};
    myLibrary.addBookshelf(shelf1);

    shelf1->addBook(book1);
    shelf1->addBook(book2);

    Reader reader{"Ivan"};
    reader.takeBook(book1); 
    cout << reader.name << " взял " << reader.takenBooks[0]->title << endl;


    delete book1;
    delete book2;

    delete pushkin;
    delete ast;

    return 0;
}


