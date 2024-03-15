#include<iostream>
#include"tridiag.hpp"
#include "inplace_factorize.hpp"
#include "inplace_solve.hpp"

template<typename T>
class tridiag_ldlt : protected tridiag <T> {
    public:
        tridiag_ldlt (const tridiag <T>& A);
        std::valarray <T> solve (const std::valarray <T>& b) const;
};


template <typename T>
tridiag_ldlt<T>::tridiag_ldlt (const tridiag<T>& A)
    : tridiag <T>(A) 
{
inplace_factorize (tridiag <T>::D, tridiag <T>::L);
}



template <typename T>
std::valarray <T>
tridiag_ldlt<T>::solve (const std::valarray<T>& b) const {
    std::valarray <T> x = b;
    inplace_solve (tridiag <T>::D, tridiag <T>::L, x); 
    return x;
}