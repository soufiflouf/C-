struct f {
    f (double a1) : a(a1) {} 
    double operator() (double x) const {
        return (x*x == 1) ? 0 : 
            2*a*(pow (1-x*x, a-1) - 2*(a-1)*x*x*pow (1-x*x, a-2));
}
double a; };