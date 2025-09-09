#include <iostream>
#include<algorithm>
// #include <unistd.h> //задежка
// #include<cmath>
// #include <iomanip>

using namespace std;


int main() {
    


    srand(time(NULL));
    // const int size = 10;
    int ar[] = {148,144,154,145,155,130,157,136,152,130,177,166};
    int size = sizeof(ar)/sizeof(ar[0]);

    for(int i: ar) cout<< i <<" ";
    cout<<endl<<endl;

    for(int i = 0; i<size;i++)
    {
        for(int j = 0; j<size-1;j++)
        {
            if(ar[j]<ar[j+1])
            {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j+1] = temp;
            }
        }
    }

    for(int i: ar) cout<< i <<" ";
    cout<<endl;
    
    cout<<"Ученик с ростом " <<ar[9] <<" занимал бы 10 место в списке по росту"<<endl;







    return 0;
}