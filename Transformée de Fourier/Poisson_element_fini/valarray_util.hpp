#include<iostream>
#include <valarray>

//on définit ici dot et norm car elles ne font pas partie de la libraire standard

template <typename Vec1 , typename Vec2 > typename Vec1::value_type
dot (const Vec1& x, const Vec2& y) {
    typename Vec1::value_type sum = 0; 
    for (size_t i = 0; i < x.size(); i++)
        sum += x[i]*y[i]; 
    return sum;
}
template <typename Vec> typename Vec::value_type 
norm (const Vec& x) {
return sqrt(dot(x,x)); 
}
//on spécifie notre template value_type
// on utilise value_type pour pouvoir utiliser n'importe quel type de donnée dans notre template