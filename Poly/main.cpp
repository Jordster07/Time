#include <iostream>
#include "term.h"
#include "poly.h"

int main() {
    Term t1(3, 2, 'x');      
    Term t2(-1, 2, 'x');     
    Term t3(4, 1, 'x');    

    std::cout << "Testing Term compatibility:\n";
    std::cout << "t1 and t2 compatible? " << (t1.compatible(t2) ? "Yes" : "No") << "\n";
    std::cout << "t1 > t3? " << (t1 > t3) << "\n\n";


    Term poly1Terms[] = { t1, t2, t3 };
    Polynomial p1(poly1Terms, 3);

    Term p2Terms[] = {
        Term(2, 1, 'x'),     
        Term(5, 0, 'x')     
    };
    Polynomial p2(p2Terms, 2);  

    std::cout << "p1 = " << p1 << "\n"; 
    std::cout << "p2 = " << p2 << "\n";  


    Polynomial sum = p1 + p2;
    std::cout << "p1 + p2 = " << sum << "\n"; 

    Polynomial diff = p1 - p2;
    std::cout << "p1 - p2 = " << diff << "\n";  


    Polynomial product = p1 * p2;
    std::cout << "p1 * p2 = " << product << "\n"; 

    return 0;
}