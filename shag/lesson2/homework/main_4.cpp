#include <iostream>
using namespace std;

enum Pizza {
    Margherita = 1, // Ціна: 100 грн
    Pepperoni = 2,  // Ціна: 120 грн
    FourCheese = 3, // Ціна: 130 грн
    PizzaNone = 4   
};

enum Drink {
    Cola = 5,      // Ціна: 30 грн
    Juice = 6,     // Ціна: 40 грн
    DrinkNone = 7  
};

int main() {
    int vubor_pizza;
    int vubor_drink;

    int col_pizza;
    int col_drink;

    double pizze_prise_single = 0.0; 
    double drink_prise_single = 0.0; 

    double prise_za_pizza = 0.0;
    double prise_za_drink = 0.0;

    double zagal_prise = 0.0;

    cout << "Что будете брать: \n1)Margherita\n2)Pepperoni\n3)FourCheese\n4)Ничего\n";
    cin >> vubor_pizza;
    cout << "Введите количество пиц: ";
    cin >> col_pizza;

    if (col_pizza < 0) col_pizza = 0; 

    if (vubor_pizza == Margherita) {
        pizze_prise_single = 100.0;
    } else if (vubor_pizza == Pepperoni) {
        pizze_prise_single = 120.0;
    } else if (vubor_pizza == FourCheese) {
        pizze_prise_single = 130.0;
    } else if (vubor_pizza == PizzaNone) { 
        pizze_prise_single = 0.0;
        col_pizza = 0; 
    } else {
        cout << "Неверный выбор пиццы, пицца не будет учтена." << endl;
        pizze_prise_single = 0.0;
        col_pizza = 0;
    }

    prise_za_pizza = pizze_prise_single * col_pizza;
    cout << "Промежуточный расчет: Цена одной пиццы: " << pizze_prise_single << ", Количество: " << col_pizza << ", Сумма за пиццы: " << prise_za_pizza << endl;


    cout << "Что будете брать: \n5)Cola\n6)Juice\n7)Ничего\n";
    cin >> vubor_drink;
    cout << "Введите количество напитков: ";
    cin >> col_drink;

    if (col_drink < 0) col_drink = 0; 

    if (vubor_drink == Cola) {
        drink_prise_single = 30.0;
    } else if (vubor_drink == Juice) {
        drink_prise_single = 40.0;
    } else if (vubor_drink == DrinkNone) { 
        drink_prise_single = 0.0;
        col_drink = 0;
    } else {
        cout << "Неверный выбор напитка, напиток не будет учтен." << endl;
        drink_prise_single = 0.0;
        col_drink = 0;
    }

    prise_za_drink = drink_prise_single * col_drink;
    cout << "Промежуточный расчет: Цена одного напитка: " << drink_prise_single << ", Количество: " << col_drink << ", Сумма за напитки (до скидки): " << prise_za_drink << endl;


    if (col_drink > 2) {
        double drink_discount = prise_za_drink * 0.10; 
        prise_za_drink = prise_za_drink - drink_discount;
        cout << "Применена скидка на напитки: " << drink_discount << ", Сумма за напитки (после скидки): " << prise_za_drink << endl;
    }

    zagal_prise = prise_za_pizza + prise_za_drink;
    cout << "Общая сумма (до финальной скидки): " << zagal_prise << endl;


    if (zagal_prise > 300.0) {
        double overall_discount = zagal_prise * 0.20; 
        zagal_prise = zagal_prise - overall_discount;
        cout << "Применена общая скидка: " << overall_discount << endl;
    }


    cout << "С вас: " << zagal_prise << " грн" << endl;

    return 0;
}