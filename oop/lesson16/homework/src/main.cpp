#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
// #include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>


#include "Person.h"
#include "Queue.h"

using namespace std;




int main()
{
    Queue q;

    q.addPerson(Person("Vasya", 20, 1));
    q.addPerson(Person("Petya", 25, 5));
    q.addPerson(Person("Boss", 40, 100));
    
    for(int i=0; i<7; ++i) {
        q.addPerson(Person("Worker", 18, 2));
    }
    
    q.Show(); 

    cout << "\nПопытка добавить слабого:" << endl;
    q.addPerson(Person("WeakGuy", 15, 0)); 

 
    cout << "\nПопытка добавить VIP:" << endl;
    q.addPerson(Person("SuperStar", 22, 50)); 
    
    q.Show();

    cout << "\nPull:" << endl;
    q.Pull();

    q.Show();

    return 0;
}