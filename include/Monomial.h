//
// Created by Aris Lemmenes on 10/26/25.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H

#include <vector>
#include <iostream>


//A Monomial defines one term of a polynomial i.e. x^2y^3x^1w^0
class Monomial
{
public:
    using ExpoVec = std::vector<int>;

    Monomial() = default;
    Monomial(const ExpoVec& expo);
    Monomial(ExpoVec&& expo_vec) noexcept;
    Monomial(std::initializer_list<int> init_list);
    Monomial(const Monomial& other) = default;
    Monomial(Monomial&& other) = default;
    Monomial& operator=(const Monomial& other) = default;
    Monomial& operator=(Monomial&& other) = default;
    ~Monomial() = default;

    void print_monomial() const;
    friend std::ostream& operator<<(std::ostream&, const Monomial&);

private:
    ExpoVec expo_vec_;
};

#endif //GROBNERBASIS_MONOMIAL_H