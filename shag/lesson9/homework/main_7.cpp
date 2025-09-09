#include <iostream>
#include<string>
// #include<cstdarg> //для безконечных аргументов функции
#include <vector> 
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


string Sled_Byckva(vector<string> alphabet,string user_letter)
{
    for (int i = 0; i < alphabet.size(); ++i)
    {
        if (alphabet[i] == user_letter)
        {
            if (i == alphabet.size() - 1)
            {
                return "!"; 
            }
            else
            {
                return alphabet[i + 1];
            }
        }
    }

    return "";
}

int main() {

    vector<string> ukrainian_alphabet = {
        "А", "Б", "В", "Г", "Ґ", "Д", "Е", "Є", "Ж", "З", "И",
        "І", "Ї", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С",
        "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ь", "Ю", "Я"
    };

    string user_input;

    cout << "Введіть українську літеру у верхньому регістрі: ";
    cin >> user_input;

    string result = Sled_Byckva(ukrainian_alphabet, user_input);

    if (result == "!")
    {
        cout << "Далі літер немає" << endl;
    }
    else if (result.empty())
    {
        cout << "Ви ввели не українську літеру або ввели її в неправильному регістрі." << endl;
    }
    else
    {
        cout << "Наступна літера - це \"" << result << "\"" << endl;
    }

    return 0;
}