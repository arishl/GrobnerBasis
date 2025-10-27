//
// Created by Aris Lemmenes on 10/26/25.
//
#include "../include/Polynomial.h"

template <typename K>
Polynomial<K>::Polynomial(const MonoVec& mono_vec, const CoefVec& coef_vec)
    : mono_vec_(mono_vec), coef_vec_(coef_vec)
{
    if (mono_vec.size() != coef_vec.size())
    {
        throw std::invalid_argument("mono_vec.size() != coef_vec.size();");
    }
}

template <typename K>
Polynomial<K>::Polynomial(MonoVec&& mono_vec, CoefVec&& coef_vec) noexcept
    :mono_vec_(std::move(mono_vec)), coef_vec_(std::move(coef_vec))
{
    if (mono_vec_.size() != coef_vec_.size())
    {
        throw std::invalid_argument("mono_vec.size() != coef_vec.size();");
    }
}

template <typename K>
std::string Polynomial<K>::stringify() const
{
    std::string hold;
    hold = hold + "(";
    for (size_t i = 0; i < coef_vec_.size(); ++i)
    {
        hold = hold + "(";
        hold = hold + std::to_string(coef_vec_[i]) + "," + mono_vec_[i].stringify();
        hold = hold + "),";
    }
    hold = hold + ")";
    return hold;
}