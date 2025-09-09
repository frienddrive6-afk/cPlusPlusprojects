#include<iostream>
// #include<cmath>
using namespace std;


int main()
{
    const short zp_100 = 50;
    const double zp_1 = float(zp_100)/100; //за одну строчку кода
    const short zapizn_minus = 20;
    short vubor;
    // cout<<zp_1<<endl;

    cout<<"Выберете какие разщеты хотите произвести\n1)бажаний дохід Васі та кількість запізнень. Порахувати скільки рядків коду йому треба написати\n2)кількість рядків коду, написаних Васею, і бажаний обсяг зарплати. Порахувати скільки разів Вася може запізнитися\n3)кількість рядків коду і кількість запізнень. Визначити скільки грошей заплатять Васі та чи заплатять взагалі"<<endl;
    cin>>vubor;

    int gel_dohod;
    short col_zapizn;
    int col_lines_need;
    int zp_istin;

    switch (vubor)
    {
    case 1:
        cout<<"Напишите желаемый доход:";
        cin>>gel_dohod;
        cout<<"Напишите количество пропусков: ";
        cin>>col_zapizn;

        cout<<"Програмисту нужно написать строчек: "  <<(gel_dohod + (col_zapizn*20))*2 <<endl;

        break;

    case 2:
        cout<<"Введите количество строчек: ";
        cin>>col_lines_need;
        cout<<"Введите желаемый доход: ";
        cin>>gel_dohod;

        zp_istin = col_lines_need*zp_1;
        // cout<<(100 - 90)/20<<endl;
        col_zapizn = (zp_istin - gel_dohod)/zapizn_minus;
        if(col_zapizn>= 1)
        {
            cout<<"Вася может опоздать " <<col_zapizn <<" раз"<<endl;
        }else
        {
            cout<<"Вася не может опаздывать"<<endl;
        }

        break;

    case 3:
        cout<<"Введите количество строчек: ";
        cin>>col_lines_need;
        cout<<"Напишите количество пропусков: ";
        cin>>col_zapizn;

        zp_istin = col_lines_need*zp_1;
        // cout<<zp_istin<<endl;

        gel_dohod = zp_istin - (col_zapizn*20);

        if(gel_dohod>0)
        {
            cout<<"Вася заработает " <<gel_dohod <<"$"<<endl;
        }else
        {
            cout<<"Вася не заработает:("<<endl;
        }
        // cout<<gel_dohod<<endl;

        break;
    
    default:cout<<"Не правильный вариат"<<endl;break;
    }


    return 0;
}
