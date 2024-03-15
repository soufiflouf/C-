#include <valarray> 
#include "energy.hpp"
template <typename T> class tridiag {
    public:
        tridiag (size_t n=0, const T& a=0, const T& b=0); 
        tridiag (const tridiag <T>&);
        tridiag <T>& operator= (const tridiag <T>&); 
        std::valarray <T>
            operator* (const std::valarray <T>& x) const ;
        template <class U>
        friend void energy (std::valarray <U>& x, tridiag <U>& A);
    protected:
        std::valarray <T> D, L;
 };


template <class U>
void energy (std::valarray <U>& x, tridiag <U>& A) {
energy (x, A.D, A.L); 
}

template <typename T>
std::valarray <T>
tridiag<T>::operator* (const std::valarray<T>& x) const {
    return L.shift(-1)*x.shift(-1) + D*x + L*x.shift(1); 
}



template <typename T>
tridiag<T>::tridiag (size_t n, const T& a, const T& b)
    : D(a,n), L(b,n)
{
    if (n > 0) L[n-1] = 0; 
}
template <typename T>
tridiag<T>::tridiag (const tridiag<T>& A)
    : D(A.D), L(A.L) 
{
}
template <typename T>
tridiag<T>& tridiag<T>::operator= (const tridiag<T>& A) {
    D.resize (A.D.size()); 
    L.resize (A.L.size()); 
    D = A.D;
    L = A.L;
    return *this; 
}