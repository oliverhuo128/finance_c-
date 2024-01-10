

#include "cRational.h"
#include<string>

using namespace std;

using namespace OOP;

int main(void) {

    long long x;
    long long y;
    long long a;
    long long b;
    char slash;
    char oper;
    int n;
    string z;

    cout << "Input test:\n";

    cout << "Please input an expression" << endl;

    cin >> x >> slash >> y >> oper >> a >> slash >> b;

    cRational r1(x, y);
    cRational r2(a, b);
    cRational r3;

    // Operator Tests

    cout << "r1 = " << r1 << ", r2 = " << r2 << endl << endl;

    cout << "Operator test:\n";

    if (oper == '+') {
        cout << r1 << " + " << r2 << " = " << r1 + r2 << endl << endl;
    }
    else if (oper == '-') {
        cout << r1 << " - " << r2 << " = " << r1 - r2 << endl << endl;
    }
    else if (oper == '*') {
        cout << r1 << " * " << r2 << " = " << r1 * r2 << endl << endl;
    }
    else if (oper == '/') {
        cout << r1 << " / " << r2 << " = " << r1 / r2 << endl << endl;
    }
    else {
        cout << "Operation not recognised" << endl << endl;
    }

    cout << "< test:\n";

    if ((r1 < r2) == true) {
        z = "TRUE";
    }
    else {
        z = "FALSE";
    }

    cout << r1 << " < " << r2 << " is " << z << endl << endl;

    cout << "> test:\n";

    if ((r1 > r2) == true) {
        z = "TRUE";
    }
    else {
        z = "FALSE";
    }

    cout << r1 << " > " << r2 << " is " << z << endl << endl;

    cout << "<= test:\n";

    if ((r1 <= r2) == true) {
        z = "TRUE";
    }
    else {
        z = "FALSE";
    }

    cout << r1 << " <= " << r2 << " is " << z << endl << endl;

    cout << ">= test:\n";

    if ((r1 >= r2) == true) {
        z = "TRUE";
    }
    else {
        z = "FALSE";
    }

    cout << r1 << " >= " << r2 << " is " << z << endl << endl;

    cout << "!= test:\n";

    if ((r1 != r2) == true) {
        z = "TRUE";
    }
    else {
        z = "FALSE";
    }

    cout << r1 << " != " << r2 << " is " << z << endl << endl;

    cout << "== test:\n";

    if ((r1 == r2) == true) {
        z = "TRUE";
    }
    else {
        z = "FALSE";
    }

    cout << r1 << " == " << r2 << " is " << z << endl << endl;

    cout << "RealValue test:\n";

    cout << "r1 = " << r1 << " = " << r1.RealValue() << endl << endl;

    cout << "GCD test:\n";

    cout << "The GCD of " << r1.Numerator() << " and " << r1.Denominator() << " = " << r3.GCD(r1.Numerator(), r1.Denominator()) << endl << endl;

    cout << "Canonicalform test:\n";

    cout << "Canonical form of " << r1 << " =  ";

    r1.canonicalform();

    cout << r1 << ", the canonical form of " << r2 << " = ";

    r2.canonicalform();

    cout << r2 << endl << endl;

    cout << "Opposite test:\n";

    cout << "The opposite of " << r1 << " = " << r1.opposite() << endl << endl;

    cout << "Reciprocal test:\n";

    cout << "The reciprocal of " << r1 << " = " << r1.reciprocal() << endl << endl;

    cout << "Exp test:\n";

    cout << "Please input an integer" << endl;

    cin >> n;

    cout << r1 << " to the power " << n << " = " << r1.exp(n) << endl << endl;

}
