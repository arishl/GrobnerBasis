//
// Created by Aris Lemmenes on 10/26/25.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include "Monomial.h"

template <typename K>
class Polynomial
{
public:
    using MonoVec = std::vector<Monomial>;
    using CoefVec = std::vector<K>;
    Polynomial() = default;
    Polynomial(const Polynomial&) = default;
    Polynomial(Polynomial&&) = default;
    Polynomial& operator=(const Polynomial&) = default;
    Polynomial& operator=(Polynomial&&) = default;
    ~Polynomial() = default;

    print_polynomial();
    Polynomial operator+(Polynomial const& p) const;
    Polynomial operator-(Polynomial const& p) const;
    Polynomial operator*(Polynomial const& p) const;
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
private:
    CoefVec coef_vec_;
    MonoVec monomial_vec_;
};

#include "../src/Polynomial.tpp"


#endif //GROBNERBASIS_POLYNOMIAL_H