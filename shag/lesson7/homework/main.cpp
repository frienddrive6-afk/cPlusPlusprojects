#include <iostream>
#include <vector> 
#include <algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int User_col()
{
    short players_col = 0;

    do
    {
        cout<<"Введите количество учасников >1 и <7: ";
        cin>>players_col;   
    } while (players_col < 1 || players_col > 7);

    return players_col;
}


vector<string> Dia(short players_col,vector<string> deck)
{
    for(int i = 0;i < players_col;i++)
    {
        int player_coloda[6];
        // for(int j = 0; j < 6; j++)
        // {
            cout<<"Карты игрока №"<<i+1<<": ";
            for(int l = 0; l < 6;l++)
            {
                // int card_id = rand() % 36;
                int card_id = rand() % deck.size();
                cout<<deck[card_id]<<" ";
                deck.erase(deck.begin() + card_id);
                
            }

        // }
        cout<<endl;
    }

    return deck;
}


void SeeRes(vector<string> deck)
{
    for(int i = 0;i < deck.size();i++)
    {
        cout<<deck[i]<<" ";
    }
    cout<<endl;
}


int main() {

    srand(time(NULL));

    vector<string> deck = {
    // Бубни (♦)
    "6♦", "7♦", "8♦", "9♦", "10♦", "J♦", "Q♦", "K♦", "A♦",
    // Хрести (♣)
    "6♣", "7♣", "8♣", "9♣", "10♣", "J♣", "Q♣", "K♣", "A♣",
    // Піки (♠)
    "6♠", "7♠", "8♠", "9♠", "10♠", "J♠", "Q♠", "K♠", "A♠",
    // Чирви (♥)
    "6♥", "7♥", "8♥", "9♥", "10♥", "J♥", "Q♥", "K♥", "A♥"
    };


    short players_col = User_col();

    deck = Dia(players_col,deck);
    




    SeeRes(deck);



    return 0;
}