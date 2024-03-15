#include <iostream>
#include <cmath>
#include <complex> 


using namespace std;

template <typename T> class complex {
public:
complex(const T& a=0, const T& b=0); // fonction membre numéro 1, constructeur
complex(const complex <T>& z); // constructeur numéro 2
complex <T>& operator= (const complex <T>& z); // opérateur de surcharge
T& real (); 
T& imag (); 
const T& real() const;
const T& imag() const;
protected: T re, im;

// les quatres dernières lignes sont des accesseurs afin d'accéder aux données protected : Im, Re
};
// on définit une classe quaternion en prenant la classe complexe comme exemple et qui soit compatible avec elle


// ma classe quaternion
template <typename T> 
class quaternion {
public:
    quaternion (const T& a=0, const T& b=0,
                const T& c=0, const T& d=0);
    quaternion (const std::complex<T>& z,
                const std::complex<T>& h);
    quaternion ( const quaternion<T>& h);
    quaternion<T>& operator= (const quaternion<T>& h );
    std::complex <T>& z();
    std::complex <T>& w();
    const std::complex<T>& z() const;
    const std::complex<T>& w() const;
 protected :
    std::complex<T> zc, wc;


};
// définition de mes constructeurs et surcharge opérateurs
template <typename T>
quaternion<T>::quaternion (
const T& a, const T& b, const T& c, const T& d)
: zc(a,b), wc(c,d) {}  
template <typename T>
quaternion<T>::quaternion (
const std::complex <T>& z, const std::complex <T>& w)
: zc(z), wc(w) {}
template <typename T>
quaternion<T>::quaternion (const quaternion<T>& h)
: zc(h.zc), wc(h.wc) {}
template <typename T>
quaternion <T>&
quaternion<T>::operator= (const quaternion<T>& h) {
zc = h.zc; wc = h.wc;
return *this; }


template <typename T>
std::complex <T>&
quaternion <T>::z() { return zc; }
template <typename T>
std::complex <T>&
quaternion <T>::w() { return wc;}
template <typename T>
const std::complex <T>&
quaternion<T>::z() const { return zc; }
template<typename T>
const std::complex<T>&
quaternion<T>::w() const { return wc;}

template <typename T>
quaternion <T>
operator+ (const quaternion <T>& h, quaternion <T> m) {
quaternion <T> r;
r.z() = h.z() + m.z(); 
r.w() = h.w() + m.w(); 
return r;
}

template <typename T>
quaternion<T>
operator - (const quaternion <T>& h, quaternion <T> m) {
quaternion <T> r;
r.z() = h.z() - m.z(); 
r.w() = h.w() - m.w();
return r;
}
template <typename T>
quaternion <T>
operator* (const quaternion <T>& h1, quaternion <T> h2) {
    quaternion <T> r;
    r.z() = h1.z()*h2.z() - h1.w()*conj(h2.w());
    r.w() = h1.z()*h2.w() + h1.w()*conj(h2.z());
    return r;
}

template <typename T>
quaternion <T> conj (const quaternion <T>& h) {
    quaternion <T> r; 
    r.z() = conj(h.z()); 
    r.w() = -h.w();    
    return r;
}

template <typename T>
T norm (const quaternion <T>& h) {
return norm(h.z()) + norm(h.w()); 
}
template <typename T>
T abs (const quaternion <T>& h) {
return sqrt(norm(h)); 
}

template <typename T>
quaternion <T>
operator/ (const quaternion <T>& h1, const quaternion <T>& h2)   {

    quaternion <T> r = h1*conj(h2);
    T deno = abs(h2.z())*abs(h2.z()) + abs(h2.w())*abs(h2.w()); 
    r.z() /= deno;
    r.w() /= deno;
    return r;
}



template <typename T>
std::ostream&
operator<< (std::ostream& out, const quaternion<T>& h) {
    out << "(" << h.z() << ", " << h.w() << ")";
    return out; }

template <typename T>
std::istream&
operator >> (std::istream& is, quaternion <T>& h) {
    std::complex <T> z, w; 
    char c; is >> c;
    if (c == '(') {
        is >> z >> c; 
        if (c == ',') { 
            is >> w >> c;
            if (c == ')') h = quaternion<T>(z, w);
            else          is.setstate(std::ios_base::failbit); 
          } else {
            if (c == ')') h = z;
            else          is.setstate(std::ios_base::failbit);
          }
} else { 
    is.putback(c); 
    is >> z;
    h = z;
}
return is; 
}


int main(int argc, char**argv) {
    quaternion <double > h1 (1, 1, 7, 9),
                         h2 (1,-1,-7,-9);
cout << "h1 = " << h1 << endl 
     << "h2 = " << h2 << endl
     << "h1+h2 = " <<  h1-h2 << endl
     << "h1*h2 = " << h1*h2  << endl
     << "h1/h2 = " << h1/h2 << endl
     << "(h1/h2)*h2 = " << (h1/h2)*h2 << endl;

}


// make quaternion
//  ./quaternion

// ou bien taper cette commande comme on le souhaite

//g++ quaternion.cpp -Wall -std=c++17
//./a.out