
#include<iostream>
#include"cRational.h"
#include<string>

using namespace OOP;
using namespace std;

bool GetInputAndParse(std::string& input, std::string& r1_input, char& oper, std::string& r2_input);

int main(void) {

    string input;
    string r1_input;
    string r2_input;
    long long x = 0;
    long long y = 0;
    long long a = 0;
    long long b = 0;
    char oper;

    bool cont = true;

    while (cont = true) {
        cout << ">";

        getline(cin, input);

        if (input.substr(0, 4) == "quit") {
            exit(0);
        }
        else {
            // Code assumes no errors in user input as detailed in question assumption

            string split_token = " ";

            // parse r1_input

            int start = 0;

            int end = input.find(split_token);

            r1_input = input.substr(start, end - start);

            // parse oper

            start = end + split_token.size();

            end = input.find(split_token, start);

            oper = input.substr(start, end - start)[0]; //switch statement below does not work on strings, only int, char, ..

            start = end + split_token.size();

            // parse r2_input

            start = end + split_token.size();

            end = input.find(split_token, start);

            r2_input = input.substr(start, end - start);
        }

        bool valid = true;

        while (valid) {
            string delim = "/";

            auto r1_start = 0U;
            auto r1_end = r1_input.find(delim);
            while (r1_end != string::npos) {
                cout << "x = " << r1_input.substr(r1_start, r1_end - r1_start) << endl;
                x = stoll(r1_input.substr(r1_start, r1_end - r1_start));
                r1_start = r1_end + delim.length();
                r1_end = r1_input.find(delim, r1_start);
            }

            cout << "y = " << r1_input.substr(r1_start, r1_end) << endl;

            y = stoll(r1_input.substr(r1_start, r1_end));

            auto r2_start = 0U;
            auto r2_end = r2_input.find(delim);
            while (r2_end != string::npos) {
                cout << "a = " << r2_input.substr(r2_start, r2_end - r2_start) << endl;
                a = stoll(r2_input.substr(r2_start, r2_end - r2_start));
                r2_start = r2_end + delim.length();
                r2_end = r2_input.find(delim, r2_start);
            }

            cout << "b = " << r2_input.substr(r2_start, r2_end) << endl;

            b = stoll(r2_input.substr(r2_start, r2_end));

            if (y == 0) {
                cout << "Denominator of the first rational is invalid. Please enter a valid input" << endl << endl;
                cout << ">";
                cin >> r1_input >> oper >> r2_input;
            }
            else if (b == 0) {
                cout << "Denominator of the second rational is invalid. Please enter a valid input" << endl << endl;
                cout << ">";
                cin >> r1_input >> oper >> r2_input;
            }
            else {
                valid = false;
            }
        }

        cRational r1(x, y);
        cRational r2(a, b);
        cRational r3;

        switch (oper) {
        case '+':
            cout << r1 << " + " << r2 << " = " << r1 + r2 << endl << endl;
            break;

        case '-':
            cout << r1 << " - " << r2 << " = " << r1 - r2 << endl << endl;
            break;

        case '*':
            cout << r1 << " * " << r2 << " = " << r1 * r2 << endl << endl;
            break;

        case '/':
            if (r2.Numerator() == 0) {
                cout << "Invalid calculation" << endl << endl;
                break;
            }
            else {
                cout << r1 << " / " << r2 << " = " << r1 / r2 << endl << endl;
                break;
            }

        default:
            cout << "Operation not recognised" << endl << endl;
            break;
        }

        r1.~cRational();
        r2.~cRational();
        r3.~cRational();
    }

}