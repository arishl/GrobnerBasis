//
// Created by Aris Lemmenes on 10/26/25.
//

#ifndef GROBNERBASIS_IDEAL_H
#define GROBNERBASIS_IDEAL_H
#include <vector>

#include "Polynomial.h"

template<typename T>
class Ideal
{
public:
    using PolynomialVector = std::vector<Polynomial<T>>;
    Ideal() = default;
    Ideal(const PolynomialVector& generators);
    Ideal(PolynomialVector&& generators);
    Ideal(const Ideal& other) = default;
    Ideal& operator=(const Ideal) = default;
private:

};



#endif //GROBNERBASIS_IDEAL_H