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
    Monomial(Monomial&&) noexcept = default;
    Monomial& operator=(const Monomial&) = default;
    Monomial& operator=(Monomial&&) noexcept = default;
    ~Monomial() = default;

    bool operator==(const Monomial& other) const;

    int get_variables() const;
    const ExpoVec& get_expo_vec() const;
    friend void swap(Monomial& a, Monomial& b) noexcept {
        using std::swap;
        swap(a.expo_vec_, b.expo_vec_);
    }

    std::string stringify() const;
    friend std::ostream& operator<<(std::ostream&, const Monomial&);

private:
    ExpoVec expo_vec_;
};

#endif //GROBNERBASIS_MONOMIAL_H