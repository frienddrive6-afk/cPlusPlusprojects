#pragma once

#include <string>

using namespace std;

class Publisher
{
public:
    string publisher_name;

    Publisher(string name) : 
        publisher_name(name) 
    {}
};