#include "Time.h"
#include <iostream>
using namespace std;


void assignmentTest() {
    Time t1(1, 2, 3, 4);
    Time t2;
    t2 = t1;

    cout << "t1: " << t1 << "\n";
    cout << "t2: " << t2 << "\n";
    cout << ((t1 == t2) ? "PASS: Assignment successful\n" : "FAIL: Assignment incorrect\n\n");
}

void testTimeAddition() {
    Time t1(0, 23, 59, 50);
    Time t2(0, 0, 0, 15);
    Time result = t1 + t2;

    cout << t1 << " + " << t2 << " = " << result << endl;
}

void testTimeSubtraction() {
    Time t1(1, 0, 0, 0);
    Time t2(0, 1, 30, 30);
    Time result = t1 - t2;

    cout << t1 << " - " << t2 << " = " << result << endl;
}

void testTimeRelationalOperators() {
    Time a(0, 12, 30, 0);
    Time b(0, 12, 30, 0);
    Time c(0, 14, 0, 0);

    cout << a << " == " << b << "? " << (a == b ? "true" : "false") << endl;
    cout << a << " != " << c << "? " << (a != c ? "true" : "false") << endl;
    cout << a << " < "  << c << "? " << (a <  c ? "true" : "false") << endl;
    cout << c << " > "  << a << "? " << (c >  a ? "true" : "false") << endl;
    cout << a << " <= " << b << "? " << (a <= b ? "true" : "false") << endl;
    cout << c << " >= " << a << "? " << (c >= a ? "true" : "false") << endl;
}

void testTimeOutStreamOperator() {
    Time t(3, 7, 5, 2);
    cout << "Time object printed: " << t << endl;
}

void testTimeIntegerConversion() {
    Time t(1, 2, 3, 4);
    int totalSeconds = t.toSeconds();

    cout << "Time: " << t << "\n";
    cout << "Total seconds: " << totalSeconds << "\n\n";
}

int main(){
    assignmentTest();
    testTimeAddition();
    testTimeSubtraction();
    testTimeRelationalOperators();
    testTimeOutStreamOperator();
    testTimeIntegerConversion();

    return 0;
}
