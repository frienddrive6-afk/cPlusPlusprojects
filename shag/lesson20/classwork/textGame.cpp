#include <iostream>
#include <cstdlib>   
#include <unistd.h>  
#include <limits>    

using namespace std;

int game_title(int pl, int bot);
void dice(int r);
void pause_animation();

int textGame()
{
    srand(time(0));

    int bot = 0, pl = 0;
    int result = 0, botresult = 0;

    bool running = true;

    while (running)
    {
        int choice = game_title(pl, bot);

        if (choice == 1)
        {
            result = rand() % 6 + 1;
            cout << "\n\n\t\t\t\t";
            dice(result);

            cout << "\n\n\t\t\t\t ��� ���� ����";
            pause_animation();

            botresult = rand() % 6 + 1;
            cout << "\n\n\t\t\t\t";
            dice(botresult);

            cout << "\n\n\t\t\t\t ��������� �����";
            pause_animation();

            cout << "\n\n\t\t";
            if (result == botresult) cout << "\t\t ͳ���! ";
            else if (result > botresult) { pl++; cout << "\t\t � ������ �����! "; }
            else { bot++; cout << "\t\t � ���� �����! "; }

            cout << "\n\n\t\t\tНажмите Enter для продолжения...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();

            if (pl > 2 || bot > 2)
            {
                system("clear");
                cout << "\n\n\t\t\t\t --- ��� � ���� ---\n\n\t\t";
                if (pl > bot) cout << "\t\t������� ������!\n";
                else cout << "\t\t��� ������!\n";
                pl = 0; bot = 0;
                
                cout << "\n\n\t\t\tНажмите Enter для продолжения...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        }
        else if (choice == 2)
        {
            pl = 0;
            bot = 0;
        }
        else if (choice == 3)
        {
            running = false;
        }
        else
        {
            cin.clear();
            cin.ignore();
        }
    }

    return 0;
}

int game_title(int pl, int bot)
{
    int pos;
    system("clear");
    cout << "\n\n\t\t\t\t --- ��� � ���� ---\n\n\t\t";
    cout << "\t  ����:  ������� - " << pl << " |  ��� - " << bot << "\n\n\t\t";
    cout << "1 - ������ ����     2 - ���� ���   3 - ����� \n\n\t\t> ";
    cin >> pos;
    return pos;
}

void dice(int r)
{
    switch (r)
    {
    case 1:
        cout << "   ----------------\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |      ##      |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   ----------------\n\t\t\t\t";
        break;
    case 2:
        cout << "   ----------------\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |   ##         |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |          ##  |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   ----------------\n\t\t\t\t";
        break;
    case 3:
        cout << "   ----------------\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |   ##         |\n\t\t\t\t";
        cout << "   |      ##      |\n\t\t\t\t";
        cout << "   |          ##  |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   ----------------\n\t\t\t\t";
        break;
    case 4:
        cout << "   ----------------\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |   ##     ##  |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |   ##     ##  |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   ----------------\n\t\t\t\t";
        break;
    case 5:
        cout << "   ----------------\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |   ##     ##  |\n\t\t\t\t";
        cout << "   |      ##      |\n\t\t\t\t";
        cout << "   |   ##     ##  |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   ----------------\n\t\t\t\t";
        break;
    case 6:
        cout << "   ----------------\n\t\t\t\t";
        cout << "   |   ##    ##   |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |   ##    ##   |\n\t\t\t\t";
        cout << "   |              |\n\t\t\t\t";
        cout << "   |   ##    ##   |\n\t\t\t\t";
        cout << "   ----------------\n\t\t\t\t";
        break;
    default:
        break;
    }
}

void pause_animation() {
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush(); 
        usleep(1000 * 1000); 
    }
    cout << endl;
}

