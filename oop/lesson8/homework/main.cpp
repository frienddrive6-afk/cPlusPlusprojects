#include <iostream>
// #include <filesystem>
// #include <cstdlib> // Для getenv 
// #include <fstream>
#include<string>
#include <cstring>
// #include<cstdarg> //для безконечных аргументов функции
// #include <vector>
// #include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>
// #include <sstream>
// #include <ncurses.h>

#include <chrono> 
#include <random>

using namespace std;







class PasswordGenerator
{
private:
    long long seed;
    std::mt19937 engine;
    int length;
    bool use_digits;
    bool use_specials;

    static constexpr const char* LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static constexpr const char* DIGITS = "012-987+654*321/=";
    static constexpr const char* SPECIALS = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    

    static long count;


    std::string buildAlphabet() const
    {
        std::string alphabet = LETTERS;
        if (use_digits) {
            alphabet += DIGITS;
        }
        if (use_specials) {
            alphabet += SPECIALS;
        }
        return alphabet;
    }

public:
    PasswordGenerator(int len, bool use_num, bool use_spec) :
        length{len},
        use_digits{use_num},
        use_specials{use_spec}
    {
        auto nanoseconds = std::chrono::high_resolution_clock::now().time_since_epoch();
        seed = std::chrono::duration_cast<std::chrono::nanoseconds>(nanoseconds).count();
        engine.seed(seed);
    }

    string generate()
    {
        string alphabet = buildAlphabet();
        string password = ""; 
        std::uniform_int_distribution<int> distribution(0, alphabet.length() - 1);

        for (int i = 0; i < length; ++i)
        {
            password += alphabet[distribution(engine)];
        }
        count++;
        return password;
    }

    std::string generateFromSeed(long long custom_seed)
    {
        engine.seed(custom_seed); 
        return generate(); 
    }

    static long getCount()
    {
        return count;
    }

};
long PasswordGenerator::count{0};


PasswordGenerator setupGeneratorFromUser()
{
    int len;
    short use_num_choice, use_spec_choice;
    
    cout << "Введите длину пароля: ";
    cin >> len;

    cout << "Вы хотите использовать цифры в пароле (1-Да / 2-Нет): ";
    cin >> use_num_choice;

    cout << "Вы хотите использовать спецсимволы в пароле (1-Да / 2-Нет): ";
    cin >> use_spec_choice;
    
    cin.ignore(1000, '\n');
    
    return PasswordGenerator(len, (use_num_choice == 1), (use_spec_choice == 1));
}


int main()
{
    
    cout << "--- Создаем генератор на основе вашего ввода ---" << endl;
    PasswordGenerator my_gen = setupGeneratorFromUser();

    cout << "\nСлучайный пароль: " << my_gen.generate() << endl;
    cout << "Еще один случайный: " << my_gen.generate() << endl;

    cout << "\n--- Проверка генерации по сиду ---" << endl;
    long long my_seed = 123456789;
    cout << "Пароль из сида " << my_seed << ": " << my_gen.generateFromSeed(my_seed) << endl;
    cout << "Тот же пароль из того же сида: " << my_gen.generateFromSeed(my_seed) << endl;

    cout << "\nВсего сгенерировано паролей: " << PasswordGenerator::getCount() << endl;


    
    return 0;
}




