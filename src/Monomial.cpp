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

bool Monomial::operator==(const Monomial& other) const
{
    return expo_vec_ == other.expo_vec_;
}

int Monomial::get_variables() const
{
    return expo_vec_.size();
}

std::string Monomial::stringify() const
{
    std::string hold;
    hold = hold + "(";
    for (size_t i = 0; i < expo_vec_.size(); ++i)
    {
        hold = hold + std::to_string(expo_vec_[i]);
        if (i + 1 < expo_vec_.size())
            hold = hold + ", ";
    }
    hold = hold + ")";
    return hold;
}

std::ostream& operator<<(std::ostream& os, const Monomial& monomial)
{
    os << monomial.stringify();
    return os;
}
