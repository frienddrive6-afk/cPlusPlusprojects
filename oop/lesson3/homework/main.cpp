#include <iostream>
// #include <fstream>
#include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>


using namespace std;


class Unit
{

public:
    string name;
    int unitType;//1-игрок,2-Враг,3-NPC
    int level = 1;
    int currentExp;
    int expToNextLevel;
    int health;
    int maxHealth;
    int mana;
    int maxMana;
    int damege;
    int uvorotlivost;
    int attakPower;//damage + атака оружия
    float defendered = 1.0; //В процентах защиты от 0 до 1 чем число меньше тем лучше

    bool isLive = true;

    int Xpos;
    int Ypos;


    void move(int newX,int newY)
    {
        Xpos = newX;
        Ypos = newY;
    }

    void attack(Unit &vrag,int damewOfSword)
    {

        vrag.health -= (damege + damewOfSword) * defendered;
    }

    void mag_attack(Unit &vrag,int trebovanaaMana,int nanosDamage)
    {
        if(trebovanaaMana < mana)
        {
            vrag.health -= nanosDamage;
            mana -=trebovanaaMana;
        }
    }

    void takeDamege(int gamege_on_this_unit)
    {
        health -= gamege_on_this_unit;

        if(health <= 0)
        {
            isLive = false;
        }
    }

    void full_health()
    {
        health = maxHealth;
        mana = maxMana;
        if(isLive == false)
        {
            isLive = true;
        }
    }

    void addExp(int exp)
    {
        currentExp += exp;
        if(currentExp >= expToNextLevel)
        {
            level++;
            currentExp -= expToNextLevel;
        }

    }




};

struct Items
    {
        string itemName;
        int type;//1 еда 2 не живое,3 живое,4 жидкость
        int weight;
        int price;
    };

class Backpack
{
public:

    

    const int maxSlots = 10;
    int currenWeight = 0;
    int maxWeight;

    vector<Items> array;

    void addItem(const Items item)
    {
        if(array.size() <= maxSlots-1)
        {
            array.push_back(item);
        }else
        {
            cout<<"В рюкзаке нет места"<<endl;
        }
    }

    void remove(int elementOfMassive)
    {
        array.erase(array.begin() + elementOfMassive);
    }

    void remove(string nameOfElement) {
        for (int i = 0; i < array.size(); ++i) {
            if (array[i].itemName == nameOfElement) {
                currenWeight -= array[i].weight;
                array.erase(array.begin() + i);
                cout << "'" << nameOfElement << "' удалено" << endl;
                return; 
            }
        }
        cout << "Предмет '" << nameOfElement << "' не найдено" << endl;
    }

    void hasItem(string nameOfElement)
    {
        int index = 0;
        bool IsitemsHas = false;
        for(Items i : array)
        {
            if(i.itemName == nameOfElement)
            {
                cout<<"Такой елемент есть под индексом "<<index<<endl;
                IsitemsHas = true;
                break;
            }else
            {
                index++;
            }
        }

        if(IsitemsHas == false)
        {
            cout<<"Такого елемента нет в рюкзаке"<<endl;
        }
    }

    void sumWeightAllItems()
    {
        for(Items i : array)
        {
            currenWeight += i.weight;
        }

        cout<<"Текущий вес рюкзака "<<currenWeight <<"килограм"<<endl;

    }

    void getFreeSlots()
    {
        int freeSlots = maxSlots - array.size();
        cout<<"Свободных слоев осталось " <<freeSlots<<" штук"<<endl;
    }

    void displayFullItems()
    {
        int freeSlots = maxSlots - array.size();
        
        for(Items i : array)
        {
            cout<<i.itemName<<endl;
        }

        for(int i = 0;i <= freeSlots;++i)
        {
            cout<<"Слот пустой"<<endl;
        }
    }

};

class Map
{
public:


    int width;
    int heigh;
    string name;

    vector<Unit> units;
    int countUnitsOnMap = 0;

    vector<Items> items;
    int countItemsOnMap;


    void updateUnitsCol()
    {
        countUnitsOnMap = units.size();
    }

    void updateItemsCol()
    {
        countItemsOnMap = items.size();
    }

};


int main()
{
    

    
    return 0;
}