//
// Created by Aris Lemmenes on 10/26/25.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include "Monomial.h"
#include <numeric>
template <typename K>
class Polynomial
{
public:
    using MonoVec = std::vector<Monomial>;
    using CoefVec = std::vector<K>;

    Polynomial() = default;
    Polynomial(int variables, const MonoVec& mono_vec, const CoefVec& coef_vec);
    Polynomial(int variables, MonoVec&& mono_vec, CoefVec&& coef_vec) noexcept;
    Polynomial(const Polynomial&) = default;
    Polynomial(Polynomial&&) = default;
    Polynomial& operator=(const Polynomial&) = default;
    Polynomial& operator=(Polynomial&&) = default;
    ~Polynomial() = default;

    [[nodiscard]] std::string stringify() const;
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    Polynomial operator+(Polynomial const& p) const;
    Polynomial operator-(Polynomial const& p) const;
    Polynomial operator*(Polynomial const& p) const;

    void clean_polynomial();
    void order_polynomial();
    std::pair<K, Monomial> get_leading_monomial();

    Polynomial compute_s_polynomial(Polynomial const& p1, Polynomial const& p2) const;

private:
    CoefVec coef_vec_;
    MonoVec mono_vec_;
    int variables_;
};

#include "../src/Polynomial.tpp"


#endif //GROBNERBASIS_POLYNOMIAL_H