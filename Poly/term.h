#ifndef TERM
#define TERM
#include<iostream>
/*
Create a class called Term that represents a single variable term in a polynomial. 
coefficient: double
exponent: int     // make it int for simplicity
char: variable
Term()                // default constructor
Term(coef: double, exp: int, var: char)
Term(Term& term)                // copy constructor
getters and setters....
Term& operator=(Term& right)
bool operator<=(Term& right)      // compares the exponent of the terms and returns true if this's exponent is less than/equal to right's
bool operator>=(Term& right)      // compares the exponent of the terms and returns true if this's exponent is greater than/equal to right's
bool operator<(Term& right)         // compares the exponent of the terms and returns true if this's exponent is less than right's
bool operator>(Term& right)         // compares the exponent of the terms and returns true if this's exponent is greater than right's
bool operator==(Term& right)       // compares the exponent of the terms and returns true if this's exponent is equal to right's
bool compatible(Term& term)    // tests whether the incoming term's variable and exponent match this term's exponent and variable (i.e. the two terms can be combined)
*/

class Term{
private:
    double coefficient;
    int exponent;
    char variable;

public:
    Term();
    Term(double coef, int exp, char var);
    Term(const Term& term);
    double getCoefficient() const;
    int getExponent() const;
    char getVariable() const;
    void setCoefficient(double coef);
    void setExponent(int exp);
    void setVariable(char var);
    Term& operator=(const Term& right);

    bool operator<=(const Term& right) const;
    bool operator>=(const Term& right) const;
    bool operator<(const Term& right) const;
    bool operator>(const Term& right) const;
    bool operator==(const Term& right) const;

    bool compatible(const Term& term) const;
};


#endif
