#pragma once

#include <string>

using namespace std;


class Autor
{
public:
    string name;
    string firstname;

    Autor(string name, string firstname) :
        name{ name },
        firstname{ firstname } 
    {}

};