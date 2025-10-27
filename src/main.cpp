#include <iostream>
#include "../include/Monomial.h"
int main()
{
    Monomial::ExpoVec expo_vec = {1,2,3};
    Monomial m = Monomial(std::move(expo_vec));
    std::cout << m;
    return 0;
}