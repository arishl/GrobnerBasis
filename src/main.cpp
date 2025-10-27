#include <iostream>
#include "../include/Monomial.h"
#include "../include/Polynomial.h"
int main()
{
    Monomial::ExpoVec expo_vec = {1,2,3,2};
    Monomial m = Monomial(std::move(expo_vec));
    Monomial x = Monomial(std::move(expo_vec));
    Polynomial<int>::MonoVec mv = {m,m,m};
    Polynomial<int>::CoefVec cv = {12,2,7};
    //std::cout << m;
    Polynomial<int> p = Polynomial<int>(4, mv,cv);
    std::cout << p.stringify();
    return 0;
}