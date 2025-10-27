#include <iostream>
#include "../include/Monomial.h"
#include "../include/Polynomial.h"
int main()
{
    Monomial::ExpoVec expo_vec = {1,2,3};
    Monomial m = Monomial(std::move(expo_vec));
    Polynomial<int>::MonoVec mv = {m};
    Polynomial<int>::CoefVec cv = {1};
    std::cout << m;
    Polynomial<int> p = Polynomial<int>(mv,cv);
    std::cout << p.stringify();
    return 0;
}