#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
#include<string>
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


using namespace std;

class GameItem
{
private:
    string name;
    int value;
    float weight;

public:

    GameItem(string name = "noname", int value = 1, float weight = 1.0) :
        name{name},
        value{value},
        weight{weight}
    {}

    string getName() const
    {
        return name;
    }

    int getValue() const
    {
        return value;
    }

    float getWeight() const
    {
        return weight;
    }

    bool operator==(const GameItem& obj)
    {
        if(this->value == obj.value)
        {
            return true;
        }else
        {
            return false;
        }
    }

    bool operator!=(const GameItem& obj)
    {
        if(operator==(obj) == true)
        {
            return false;
        }else
        {
            return true;
        }
    }

    bool operator<(const GameItem& obj)
    {
        if(this->value < obj.value)
        {
            return true;
        }else
        {
            return false;
        }
    }

    bool operator>(const GameItem& obj)
    {
        if(this->value > obj.value)
        {
            return true;
        }else
        {
            return false;
        }
    }

};



class GameInventory
{
private:
    GameItem* inventory;
    int maxCountItems;
    int countItems;
    int allValue;
    float allWeight;

    static int GameInventory_count;

public:
    GameInventory(int maxItems = 10) :
        inventory{ nullptr },
        maxCountItems{maxItems},
        countItems{ 0 },
        allValue{ 0 },
        allWeight{ 0 }
    {
        ++GameInventory_count;
    }

    int getValue() const
    {
        return allValue;
    }

    float getWeight() const
    {
        return allWeight;
    }

    int getCountItems() const
    {
        return countItems;
    }

    GameItem* getInventory() const
    {
        return inventory;
    }

    int getMaxCount() const
    {
        return maxCountItems;
    }

    GameInventory(const GameInventory& obj) :
        inventory{nullptr}, 
        countItems{obj.countItems},
        allValue{obj.allValue},
        allWeight{obj.allWeight},
        maxCountItems{obj.maxCountItems}
    {
        if (countItems > 0) {
            inventory = new GameItem[countItems];
            for (int i = 0; i < countItems; ++i) {
                *(inventory + i) = *(obj.inventory + i);
            }
        }

        ++GameInventory_count;
    }

    void addItem(const GameItem& obj)
    {
        int new_countItems = countItems + 1;

        if(new_countItems > this->maxCountItems)
        {
            //debug
            cout<<"В инвенторе нет свободного места для добавления нового элемента"<<endl;
            return;
        }

        GameItem* newArray = new GameItem[new_countItems];

        for (int i = 0; i < countItems; ++i) {
            newArray[i] = inventory[i];
        }
        
        newArray[countItems] = obj;

        delete[] inventory;
        
        inventory = newArray;
        countItems = new_countItems;
        allValue += obj.getValue();
        allWeight += obj.getWeight();

    }

    GameInventory& operator= (const GameInventory& obj)
    {
        if (this == &obj) {
            return *this;
        }

        GameItem* new_inventory = nullptr;
        if (obj.countItems > 0) {
            new_inventory = new GameItem[obj.countItems];
            for (int i = 0; i < obj.countItems; ++i) {
                *(new_inventory + i) = *(obj.inventory + i);
            }
        }

        delete[] inventory;
        this->inventory = new_inventory; 

        this->countItems = obj.getCountItems();
        this->allValue = obj.getValue();
        this->allWeight = obj.getWeight();
        
        this->maxCountItems = obj.maxCountItems;

        // if(this->getMaxCount() < obj.getMaxCount())
        // {
        //     this->maxCountItems = obj.getMaxCount();
        // }

        return *this;

    }

    void operator+=(const GameItem& obj)
    {  
        this->addItem(obj);
    }


    void operator-=(const string& item_name)
{  
    if (inventory == nullptr) return;
    
    int index_to_delete = -1;
    for (int i = 0; i < countItems; ++i) {
        if (inventory[i].getName() == item_name) {
            index_to_delete = i;
            break;
        }
    }

    if (index_to_delete == -1) {
        cout << "Предмет '" << item_name << "' не найден в инвентаре." << endl;
        return;
    }

    // Сохраняем удаляемый объект, чтобы вычесть его характеристики
    GameItem item_to_remove = inventory[index_to_delete];

    int newCount = countItems - 1;
    GameItem* newInventory = nullptr;
    if (newCount > 0) {
        newInventory = new GameItem[newCount];
        int new_idx = 0;
        for (int old_idx = 0; old_idx < countItems; ++old_idx) {
            if (old_idx == index_to_delete) continue;
            newInventory[new_idx] = inventory[old_idx];
            new_idx++;
        }
    }

    delete[] inventory;
    inventory = newInventory;
    countItems = newCount;
    allValue -= item_to_remove.getValue();
    allWeight -= item_to_remove.getWeight();
}



    void operator+(const GameInventory& obj)
    {
        if(this == &obj)
        {
            return;
        }

        this->allValue += obj.allValue;
        this->allWeight += obj.allWeight;
        this->maxCountItems += obj.maxCountItems;
        
        int newCount = this->countItems + obj.countItems;
        GameItem* newArray = new GameItem[newCount];


        for(int i{}; i < this->countItems;++i)
        {
            *(newArray + i) = *(this->inventory + i);
        }

        for(int i{};i < obj.countItems;++i)
        {
            *(newArray + i + this->countItems) = *(obj.inventory + i);
        }

        delete[] this->inventory;
        inventory = newArray;

        this->countItems = newCount;

    }


    bool operator==(const GameInventory& obj)
    {
        if(this->countItems != obj.countItems || this->allValue != obj.allValue || this->allWeight != obj.allWeight)
        {
            return false;
        }

        if (this->countItems == 0)
        {
            return true;
        }

        for(int i{};i < this->countItems;++i)
        {
            if( *(this->inventory + i) != *(obj.inventory + i) )
            {
                return false;
            }
        }


        return true;
    }

    bool operator!=(const GameInventory& obj)
    {
        return !(this->operator==(obj));
    }

    GameInventory& operator++()
    {
        ++maxCountItems;
        return *this;
    }

    GameInventory operator++(int) 
    {
        GameInventory temp = *this; 
        ++maxCountItems;
        return temp;
    }


    GameInventory& operator--()
    {
        --maxCountItems;
        return *this;
    }

    GameInventory operator--(int) 
    {
        GameInventory temp = *this; 
        --maxCountItems;
        return temp;
    }

    void printIfo() const
    {
        cout<<"В этом инвенторе лежит "<< this->countItems <<" елементов а максимальное количество " << this->maxCountItems <<" ценность даного инвенторя состовляет " <<this->allValue <<" а его вес "<<this->allWeight<<endl;

    }


    static int getInventoryCount()
    {
        return GameInventory_count;
    }

    ~GameInventory()
    {
        delete[] inventory;
        --GameInventory_count;
    }


};
int GameInventory::GameInventory_count{ 0 };



void printInventoryDetails(const string& title, const GameInventory& inv) {
    cout << "\n--- " << title << " ---" << endl;
    inv.printIfo();
    cout << "Предметы: ";
    if (inv.getCountItems() == 0) {
        cout << "пусто";
    } else {
        for (int i = 0; i < inv.getCountItems(); ++i) {
            cout << inv.getInventory()[i].getName() << " | ";
        }
    }
    cout << endl;
}




int main()
{
    cout << "Инвентарей создано: " << GameInventory::getInventoryCount() << endl; 

    GameInventory playerInventory(5); 
    cout << "\n-> Создан инвентарь игрока (playerInventory)." << endl;
    cout << "Инвентарей создано: " << GameInventory::getInventoryCount() << endl; 

    GameItem sword("Меч", 100, 5.5);
    GameItem shield("Щит", 80, 8.0);
    GameItem potion("Зелье", 20, 0.5);
    
    cout << "\n-> Добавляем предметы..." << endl;
    playerInventory += sword;
    playerInventory += shield;
    playerInventory += potion;
    printInventoryDetails("Инвентарь игрока", playerInventory);
    
    cout << "\n-> Пытаемся добавить еще 3 предмета в инвентарь на 5 слотов..." << endl;
    playerInventory += GameItem("Шлем", 50, 3.0);
    playerInventory += GameItem("Сапоги", 30, 2.0);
    playerInventory += GameItem("Перчатки", 25, 1.0); 

    printInventoryDetails("Инвентарь игрока после попытки переполнения", playerInventory);

    cout << "\n-> Увеличиваем емкость инвентаря (постфиксный ++)..." << endl;
    playerInventory++;
    playerInventory += GameItem("Перчатки", 25, 1.0); 
    printInventoryDetails("Инвентарь после увеличения емкости", playerInventory);
    
    cout << "\n-> Удаляем 'Щит'..." << endl;
    playerInventory -= "Щит"; 
    printInventoryDetails("Инвентарь после удаления Щита", playerInventory);

    cout << "\n-> Создаем копию инвентаря (chest) и присваиваем (vendor)..." << endl;
    GameInventory chest = playerInventory;
    GameInventory vendor(2); 
    vendor = playerInventory; 
    
    cout << "Инвентарей создано: " << GameInventory::getInventoryCount() << endl; 
    printInventoryDetails("Сундук (копия)", chest);
    printInventoryDetails("Торговец (присваивание)", vendor);
    
    cout << "\n-> Создаем еще один инвентарь (loot) и объединяем с инвентарем игрока..." << endl;
    GameInventory loot(3);
    loot += GameItem("Золото", 500, 10.0);
    loot += GameItem("Кристалл", 1000, 0.1);
    
    playerInventory + loot;
    printInventoryDetails("Инвентарь игрока ПОСЛЕ ОБЪЕДИНЕНИЯ", playerInventory);
    
    cout << "\n-> Сравниваем инвентари..." << endl;
    if (chest == vendor) {
        cout << "Сундук и Торговец имеют одинаковые инвентари (по составу)." << endl;
    }
    if (playerInventory != chest) {
        cout << "Инвентарь игрока и Сундук теперь отличаются." << endl;
    }
    
    return 0; 
}

