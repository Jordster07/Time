#include "poly.h"
#include <cmath>
#include <algorithm> 

Polynomial::Polynomial(){
    terms = nullptr;
    numTerms = 0;
}

Polynomial::Polynomial(Term* terms, int numTerms) {
    this->numTerms = numTerms;
    this->terms = new Term[numTerms];
    for (int i = 0; i < numTerms; ++i) {
        this->terms[i] = terms[i];
    }
    simplify();
}

Polynomial::Polynomial(const Polynomial& poly) {
    numTerms = poly.numTerms;
    terms = new Term[numTerms];
    for (int i = 0; i < numTerms; ++i) {
        terms[i] = poly.terms[i];
    }
}

Polynomial::~Polynomial() {
    delete[] terms;
}

Term* Polynomial::getTerms() const {
    return terms;
}

int Polynomial::getNumTerms() const {
    return numTerms;
}

void Polynomial::setTerms(Term* newTerms, int count) {
    delete[] terms;
    numTerms = count;
    terms = new Term[numTerms];
    for (int i = 0; i < count; ++i) {
        terms[i] = newTerms[i];
    }
    simplify();
}

Polynomial& Polynomial::operator=(const Polynomial& right) {
    if (this != &right) {
        delete[] terms;
        numTerms = right.numTerms;
        terms = new Term[numTerms];
        for (int i = 0; i < numTerms; ++i) {
            terms[i] = right.terms[i];
        }
    }
    return *this;
}

void Polynomial::simplify() {
    for (int i = 0; i < numTerms; ++i) {
        for (int j = i + 1; j < numTerms; ++j) {
            if (terms[i].compatible(terms[j])) {
                terms[i].setCoefficient(terms[i].getCoefficient() + terms[j].getCoefficient());

                for (int k = j; k < numTerms - 1; ++k) {
                    terms[k] = terms[k + 1];
                }
                --numTerms;
                --j; 
            }
        }
    }
}

Polynomial Polynomial::operator+(const Polynomial& right) const {
    Term* combined = new Term[numTerms + right.numTerms];
    for (int i = 0; i < numTerms; ++i) {
        combined[i] = terms[i];
    }
    for (int j = 0; j < right.numTerms; ++j) {
        combined[numTerms + j] = right.terms[j];
    }
    Polynomial result(combined, numTerms + right.numTerms);
    delete[] combined;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& right) const {
    Term* combined = new Term[numTerms + right.numTerms];
    for (int i = 0; i < numTerms; ++i) {
        combined[i] = terms[i];
    }
    for (int j = 0; j < right.numTerms; ++j) {
        Term negated = right.terms[j];
        negated.setCoefficient(-negated.getCoefficient());
        combined[numTerms + j] = negated;
    }
    Polynomial result(combined, numTerms + right.numTerms);
    delete[] combined;
    return result;
}

Polynomial Polynomial::operator*(const Polynomial& right) const {
    Term* resultTerms = new Term[numTerms * right.numTerms];
    int count = 0;

    for (int i = 0; i < numTerms; ++i) {
        for (int j = 0; j < right.numTerms; ++j) {
            double newCoef = terms[i].getCoefficient() * right.terms[j].getCoefficient();
            int newExp = terms[i].getExponent() + right.terms[j].getExponent();
            char var = terms[i].getVariable();
            resultTerms[count++] = Term(newCoef, newExp, var);
        }
    }

    Polynomial result(resultTerms, count);
    delete[] resultTerms;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
    if (poly.getNumTerms() == 0) {
        out << "0";
        return out;
    }

    for (int i = 0; i < poly.getNumTerms(); ++i) {
        Term term = poly.getTerms()[i];
        double coef = term.getCoefficient();
        int exp = term.getExponent();
        char var = term.getVariable();

        if (coef == 0) continue; 

        if (i > 0 && coef > 0)
            out << " + ";
        else if (coef < 0)
            out << " - ";

        if (std::abs(coef) != 1 || exp == 0) {
            out << std::abs(coef);
        }

        if (exp != 0) {
            out << var;
            if (exp != 1) {
                out << "^" << exp;
            }
        }
    }

    return out;
}