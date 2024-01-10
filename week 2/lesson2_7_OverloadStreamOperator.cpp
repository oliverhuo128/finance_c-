// lesson2_7_OverloadStreamOperator.cpp 
#include <iostream>
using namespace std;
// ew class
class Date{
    int month, day, year;
public:
    Date(int dd, int mm, int yyyy){
        day = dd; month = mm; year = yyyy;
    }
    friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt){
    os << dt.day << '/' << dt.month << '/' << dt.year;
    return os;
}

int main(){
    Date dt(25, 12, 92);
    cout << dt;             // stream with our operator
}