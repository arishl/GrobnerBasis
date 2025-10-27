//
// Created by Aris Lemmenes on 10/26/25.
//
#include "../include/Polynomial.h"

template <typename K>
Polynomial<K>::Polynomial(int variables, const MonoVec& mono_vec, const CoefVec& coef_vec)
    : variables_(variables), mono_vec_(mono_vec), coef_vec_(coef_vec)
{
    if (mono_vec.size() != coef_vec.size())
    {
        throw std::invalid_argument("mono_vec.size() != coef_vec.size();");
    }
    for (int i = 0; i < mono_vec.size(); ++i)
    {
        if (mono_vec_[i].get_variables() != variables)
        {
            throw std::invalid_argument("mono_vec_[i].get_variables() != variables;");
        }
    }
    this->clean_polynomial();
}

template <typename K>
Polynomial<K>::Polynomial(int variables, MonoVec&& mono_vec, CoefVec&& coef_vec) noexcept
    :variables_(variables), mono_vec_(std::move(mono_vec)), coef_vec_(std::move(coef_vec))
{
    if (mono_vec_.size() != coef_vec_.size())
    {
        throw std::invalid_argument("mono_vec.size() != coef_vec.size();");
    }
    for (int i = 0; i < mono_vec.size(); ++i)
    {
        if (mono_vec_[i].get_variables() != variables)
        {
            throw std::invalid_argument("mono_vec_[i].get_variables() != variables;");
        }
    }
    this->clean_polynomial();
}

template <typename K>
std::string Polynomial<K>::stringify() const
{
    std::string hold;
    hold = hold + "(";
    for (size_t i = 0; i < coef_vec_.size(); ++i)
    {
        hold = hold + "(";
        hold = hold + std::to_string(coef_vec_[i]) + ", " + mono_vec_[i].stringify();
        hold = hold + ")";
        if (i + 1 < coef_vec_.size())
            hold = hold + ", ";
    }
    hold = hold + ")";
    return hold;
}

template <typename K>
void Polynomial<K>::clean_polynomial()
{
    for (size_t i = 0; i < coef_vec_.size(); ++i)
    {
        for (size_t x = i+1; x < coef_vec_.size(); ++x)
        {
            if (mono_vec_[i] == mono_vec_[x])
            {
                mono_vec_.erase(mono_vec_.begin() + x);
                coef_vec_[i]+= coef_vec_[x];
                coef_vec_.erase(coef_vec_.begin() + x);
                x-=1;
            }
        }
    }
}
