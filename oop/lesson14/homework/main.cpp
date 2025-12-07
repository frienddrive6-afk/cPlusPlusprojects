#include <iostream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

template<typename T>
class SmartCell
{
private:
    T value;
    int history_size_max;
    vector<T> history;

    static int count;

public:
    SmartCell() :
        value{},
        history_size_max{ 3 },
        history{}
    {}

    SmartCell(const T& val, int hit = 3) :
        value{ val },
        history_size_max{ hit },
        history{}
    {
        history.push_back(val);
    }

    T getValue() const
    {
        return value;
    }

    void setValue(const T& val)
    {
        value = val;
        count++;

        if (history.size() < history_size_max)
        {
            history.push_back(val);
        }
        else
        {
            history.erase(history.begin()); 
            history.push_back(val);
        }
    }

    string toString() const
    {
        stringstream ss;
        ss << value;
        return ss.str();
    }
    
    void printHistory() const {
        cout << " [History: ";
        for(const auto& item : history) {
            cout << item << " ";
        }
        cout << "]" << endl;
    }

    static int getStats() {
        return count;
    }

    SmartCell<T> operator+(const SmartCell<T>& other) const
    {
        return SmartCell<T>(this->value + other.value);
    }

    SmartCell<T> operator-(const SmartCell<T>& other) const
    {
        return SmartCell<T>(this->value - other.value);
    }

    SmartCell<T> operator*(const SmartCell<T>& other) const
    {
        return SmartCell<T>(this->value * other.value);
    }

    SmartCell<T> operator/(const SmartCell<T>& other) const
    {
        if (other.value == T{}) {
            return SmartCell<T>{};
        }
        return SmartCell<T>(this->value / other.value);
    }
};
template<typename T>
int SmartCell<T>::count = 0;


int main()
{    
    SmartCell<int> numCell(10, 3); 
    
    cout << numCell.toString() << endl;
    
    numCell.setValue(20);
    cout << "20"; numCell.printHistory();
    
    numCell.setValue(30);
    cout << "30"; numCell.printHistory();
    
    numCell.setValue(40); 
    cout << "40"; numCell.printHistory();

    cout << numCell.getValue() << endl;
    
    SmartCell<string> textCell("Hello"); 
    textCell.setValue("World");
    textCell.setValue("C++");
    
    cout<< textCell.toString() << endl;
    textCell.printHistory();

    SmartCell<int> a{100}; 
    SmartCell<int> b{50};
    SmartCell<int> c = a + b; 
    
    cout << "100 + 50 = " << c.toString() << endl;

    cout<< SmartCell<int>::getStats() << endl;
    
    cout<< SmartCell<string>::getStats() << endl;

    return 0;
}