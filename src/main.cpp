#include <iostream>
#include "../include/Monomial.h"
#include "../include/Polynomial.h"
int main()
{
    Monomial::ExpoVec expo_vec_1 = {1,2,3,2};
    Monomial::ExpoVec expo_vec_2 = {2,4,6,8};
    Monomial::ExpoVec expo_vec_3 = {7,1,7,9};
    Monomial high = Monomial(std::move(expo_vec_3));
    Monomial mid = Monomial(std::move(expo_vec_2));
    Monomial low = Monomial(std::move(expo_vec_1));

    Polynomial<int>::MonoVec mv = {mid,low,high};
    Polynomial<int>::CoefVec cv = {12,2,7};
    //std::cout << m;
    Polynomial<int> p = Polynomial<int>(4, mv,cv);
    std::cout << "Before ordering:\n" << p.stringify() << "\n";
    p.order_polynomial();
    std::cout << "After ordering:\n" << p.stringify() << "\n";
    return 0;
}