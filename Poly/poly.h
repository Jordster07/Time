#ifndef POLY
#define POLY
#include<iostream>
#include"term.h"
/*
Create a class called Polynomial.  This version will be simplified to only include a single variable and will be a series of Terms as defined above.
-Term* terms
-int numTerms
-void simplify()      // goes through the Polynomial and compares the terms looking for and simplifying compatible terms.
Polynomial()
Polynomial(Term* terms, int numTerms)
Polynomial(Polynomial& poly)
getters and setters
Polynomial& operator=(Polynomial& right)         // assignment overload
Polynomial& operator+(Polynomial& right)        // + overload
Polynomial& operator-(Polynomial& right)       // - overload
Polynomial& operator*(Polynomial& right)      // * overload
Polynomial& operator<<(Polynomial& right)     // insertion operator--sends a formatted version of the polynomial to an output stream

Test the functions of both Term and Polynomial.
*/
class Polynomial{
private:
    Term* terms;
    int numTerms;

    void simplify();

public:
    Polynomial();
    Polynomial(Term* terms, int numTerms);
    Polynomial(const Polynomial& poly);
    ~Polynomial();
    Term* getTerms() const;
    int getNumTerms() const;
    void setTerms(Term* terms, int numTerms);
    
    Polynomial& operator=(const Polynomial& right);
    Polynomial operator+(const Polynomial& right) const;
    Polynomial operator-(const Polynomial& right) const;
    Polynomial operator*(const Polynomial& right) const;

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly);
};


#endif