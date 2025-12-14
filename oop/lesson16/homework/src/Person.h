#pragma once

#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;
    int status;                       //1,5,10

public:
    Person() : name("noname"), age(0), status(0) {}

    Person(string name, int age, int status) :
        name{ name },
        age{ age },
        status{ status }
    {}

    int getStatus() const
    {
        return status;
    }

    string getName() const { return name; }

    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name << " (Status: " << p.status << ")";
        return os;
    }

};