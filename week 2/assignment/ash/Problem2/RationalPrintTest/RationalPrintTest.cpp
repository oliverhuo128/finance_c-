
#include<iostream>
#include"FunctionUtils.h"
#include"cRational.h"

using namespace OOP;
using namespace std;

int main(void) {

    string r1_input;
    string r2_input;
    long long x = 0;
    long long y = 0;
    long long a = 0;
    long long b = 0;
    char slash;
    char oper;
    string z;
    int n;

    cout << ">";

    cin >> r1_input >> oper >> r2_input;

    string delim = "/";

    auto r1_start = 0U;
    auto r1_end = r1_input.find(delim);
    while (r1_end != string::npos) {
        x = stoll(r1_input.substr(r1_start, r1_end - r1_start));
        r1_start = r1_end + delim.length();
        r1_end = r1_input.find(delim, r1_start);
    }

    y = stoll(r1_input.substr(r1_start, r1_end));

    auto r2_start = 0U;
    auto r2_end = r2_input.find(delim);
    while (r2_end != string::npos) {
        a = stoll(r2_input.substr(r2_start, r2_end - r2_start));
        r2_start = r2_end + delim.length();
        r2_end = r2_input.find(delim, r2_start);
    }

    b = stoll(r2_input.substr(r2_start, r2_end));

    cout << "r1 = " << x << "/" << y << ", r2 = " << a << "/" << b << endl;

    cRational r1(x, y);
    cRational r2(a, b);

    cout << "PrintcRational test:\n";

    PrintcRational(r1);

    cout << "" << endl;

    cout << "PrintMixedRational test:\n";

    PrintMixedRational(r1);
}