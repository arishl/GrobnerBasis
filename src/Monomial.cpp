//
// Created by Aris Lemmenes on 10/26/25.
//

#include "../include/Monomial.h"

Monomial::Monomial(ExpoVec&& expo_vec) noexcept
    : expo_vec_ {std::move(expo_vec)}
{

}

Monomial::Monomial(std::initializer_list<int> init_list)
    : expo_vec_(init_list)
{
}

void Monomial::print_monomial() const
{
    std::cout << "(";
    for (size_t i = 0; i < expo_vec_.size(); ++i)
    {
        std::cout << expo_vec_[i];
        if (i + 1 < expo_vec_.size())
            std::cout << ", ";
    }
    std::cout << ")";
}

std::ostream& operator<<(std::ostream& os, const Monomial& monomial)
{
    os << "(";
    for (size_t i = 0; i < monomial.expo_vec_.size(); ++i)
    {
        os << monomial.expo_vec_[i];
        if (i + 1 < monomial.expo_vec_.size())
            os << ", ";
    }
    os << ")";
    return os;
}
