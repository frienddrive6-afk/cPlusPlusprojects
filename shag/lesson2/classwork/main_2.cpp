#include<iostream>
// #include<cmath>
using namespace std;


enum Day
    {
        mn=5,
        ts,
        wn,
        thu=10,
        fr,
        sn=100,
        st=202
    };


enum UkrainianMpney {
    MykhailoHrushevsky = 50,  
    arasShevchenko = 100,   
    LesyaUkrainka = 200,     
    HryhoriiSkovoroda = 500, 
    VolodymyrVernadsky = 1000 
};

int main()
{
    // Day d=mn;
    // cout<<d <<" " <<thu <<" " <<sn <<" " <<st <<" "<<endl;
    

    //пример
    // short num;
    // cout<<"Введите число: ";
    // cin>>num;
    // if(num<1 && num>7)
    // {
    //     cout<<"err";
    //     return 1;
    // }

    // Day d;
    // switch (num)
    // {
    //     case 5:d = mn;break;
    //     case 6:d = ts;break;
    //     case 7:d = wn;break;
    //     case 10:d = thu;break;

    // }
    
    // cout<<d<<endl;




    //Задание 1
    // short num;
    // cout<<"numb: ";
    // cin>>num;

    // UkrainianMpney M;
    // switch (num)
    // {
    // case 50:M=MykhailoHrushevsky;break;
    // case 100:M=arasShevchenko;break;
    // case 200:M=LesyaUkrainka;break;
    // case 500:M=HryhoriiSkovoroda;break;
    // case 1000:M=VolodymyrVernadsky;break;
    // }

    // switch (M)
    // {
    // case MykhailoHrushevsky:cout<<"MykhailoHrushevsky"<<endl;break;
    // case arasShevchenko:cout<<"arasShevchenko"<<endl;break;
    // case LesyaUkrainka:cout<<"LesyaUkrainka"<<endl;break;
    // case HryhoriiSkovoroda:cout<<"HryhoriiSkovoroda"<<endl;break;
    // case VolodymyrVernadsky:cout<<"VolodymyrVernadsky"<<endl;break;
    // }



    //Задание 2
    cout<<"Введите текст: "<<endl;
    string txt;
    cin>>txt;
    UkrainianMpney m;

    if(txt=="MykhailoHrushevsky") m=MykhailoHrushevsky;
    if(txt=="arasShevchenko") m=arasShevchenko;
    if(txt=="LesyaUkrainka") m=LesyaUkrainka;
    if(txt=="HryhoriiSkovoroda") m=HryhoriiSkovoroda;
    if(txt=="VolodymyrVernadsky") m=VolodymyrVernadsky;


    cout<<m<<endl;


    return 0;
}
