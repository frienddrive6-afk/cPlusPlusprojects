#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
// #include<string>
// #include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include<math.h>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>
// #include <chrono> 
// #include <random>


using namespace std;


class Object
{
private:
    string name;
    int size;                    //место занимаемое в инвенторе измеряется в ячейках не может быть дробным

public:
    Object(string name = "NonName",int size = 1):
        name{name},
        size{size}
    {}

    string getname() const
    {
        return this->name;
    }

    int getSize() const
    {
        return this->size;
    }

    void setName(const string name)
    {
        this->name = name;
    }

    void setSize(const int size)
    {
        this->size = size;
    }

};


class Unit
{
private:
    string name;
    int hp_max;
    int hp_current;
    int level;
    bool isLive;
    Object* inventory;
    int max_count_objects;
    int count_objects;
    int inventory_size;
    int inventory_current_fill;

    static int unit_count;
    static int copy_operations_count;

public:
    Unit(string name= "Defult Unit",int hp = 100,int level = 0,int max_count_objects = 10,bool isLive = true,int inv_size = 20) :
        name{ name },
        hp_max{ hp },
        hp_current{ hp },
        level{ level },
        isLive{isLive},
        inventory{nullptr},
        max_count_objects{max_count_objects},
        count_objects{ 0 },
        inventory_size{ inv_size },
        inventory_current_fill{0}
    {
        ++unit_count;
    }

    Unit(const Unit& obj)
    {
        this->name = obj.name + "_Copy";
        this->hp_max = obj.hp_max;
        this->hp_current = obj.hp_current;
        this->level = obj.level;
        

        this->count_objects = obj.count_objects;
        this->inventory_size = obj.inventory_size;
        this->max_count_objects = obj.max_count_objects;
        this->inventory_current_fill = obj.inventory_current_fill;

        if (obj.inventory != nullptr && obj.count_objects > 0)
        {
            this->inventory = new Object[obj.count_objects];

            for(int i = 0; i < obj.count_objects; ++i)
            {
                *(this->inventory + i) = *(obj.inventory + i);
            }
        }
        else
        {
            this->inventory = nullptr;
        }

        ++copy_operations_count;
    }

    string getName() const
    {
        return this->name;
    }

    int getCurrentHP() const
    {
        return this->hp_current;
    }

    int getLevel() const
    {
        return this->level;
    }

    int colObjInInventory() const
    {
        return this->count_objects;
    }

    void printInventory()
    {
        for(int i{};i < this->count_objects;++i)
        {
            cout<< (inventory + i)->getname() <<" ";
        }
        cout<<endl;
    }

    void addAttack(int damege)
    {
        if(this->hp_current <= 0)
        {
            //дебаг
            cout<<"Персонаж мертв у него нельзя убавить жизни"<<endl;
            return;
        }
        if( (this->hp_current - damege) <= 0)
        {
            this->isLive = false;
            this->hp_current = 0;
            //дебаг
            cout<<"У персонажа принижен лимит жизней он мертв";
        }else
        {
            this->hp_current -= damege;
            //дебаг
            cout<<"У игрока осталось " <<this->hp_current <<" жизней";
        }

    }

    void hil(int addHP)
    {
        if(this->isLive == false || this->hp_current <= 0)
        {
            this->isLive = true;
        }

        this->hp_current += addHP;
    }

    void addObjectInInventory(Object& newObj)
    {
        if( (this->count_objects + 1) > this->max_count_objects || (this->inventory_current_fill + newObj.getSize()) > this->inventory_size )
        {
            //дебаг
            cout<<"Нет возможности добавить обьект в инвентарь"<<endl;

            return;
        }
        int new_count = this->count_objects + 1;

        Object* newArray = new Object[new_count];


        for(int i{};i < this->count_objects;++i)
        {
            *(newArray + i) = *(this->inventory + i);
        }

        *(newArray + this->count_objects) = newObj;

        delete[] this->inventory;
        this->inventory = newArray;

        count_objects = new_count;
        this->inventory_current_fill += newObj.getSize();

        //дебаг
        cout << "Предмет '" << newObj.getname() << "' добавлен в инвентарь" << endl;
    }


    Unit& operator=(const Unit& obj) = delete;

    static int getTotalUnits()
    {
        return unit_count;
    }

    static int getCopyCount()
    {
        return copy_operations_count;
    }

    ~Unit()
    {
        --unit_count;
        delete[] this->inventory;
    }

};
int Unit::unit_count{ 0 };
int Unit::copy_operations_count{ 0 };


void printStats()
{
    cout << "\n================ STATS ================" << endl;
    cout << "Текущее количество юнитов: " << Unit::getTotalUnits() << endl;
    cout << "Всего было вызовов конструктора копирования: " << Unit::getCopyCount() << endl;
    cout << "=====================================\n" << endl;
}

int main()
{
    printStats(); 

    cout << "--- Создаем Героя ---" << endl;
    Unit hero("Герой", 150, 1, 5, true, 50); 
    
    Object sword("Меч", 10);
    Object shield("Щит", 15);
    Object potion("Зелье", 2);

    hero.addObjectInInventory(sword);
    hero.addObjectInInventory(shield);
    hero.addObjectInInventory(potion);
    
    cout << "\nИнвентарь Героя:" << endl;
    hero.printInventory();
    printStats(); 

    cout << "\n--- Создаем копию Героя ---" << endl;
    Unit hero_copy = hero; 
    
    cout << "Имя оригинала: " << hero.getName() << endl;
    cout << "Имя копии: " << hero_copy.getName() << endl;
    
    cout << "\nИнвентарь Копии:" << endl;
    hero_copy.printInventory();
    printStats(); 

    cout << "\n--- Изменяем инвентарь копии ---" << endl;
    Object helmet("Шлем", 8);
    hero_copy.addObjectInInventory(helmet);
    
    cout << "Инвентарь Оригинала после изменения копии:" << endl;
    hero.printInventory(); 
    cout << "Инвентарь Копии после изменения:" << endl;
    hero_copy.printInventory(); 
    
    cout << "\n--- Симуляция боя ---" << endl;
    cout << "Герой получает 80 урона: ";
    hero.addAttack(80);
    cout << endl;

    cout << "Герой лечится на 30 HP: ";
    hero.hil(30);
    cout << "Текущее HP: " << hero.getCurrentHP() << endl;

    cout << "Герой получает 120 урона: ";
    hero.addAttack(120);
    cout << endl;
    
    cout << "Попытка нанести урон мертвому герою: ";
    hero.addAttack(10);
    
    cout << "Лечим мертвого героя на 50 HP: ";
    hero.hil(50);
    cout << "Текущее HP после лечения: " << hero.getCurrentHP() << endl;

    printStats(); 






    return 0;
}

