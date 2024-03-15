struct u {
    u (double a1) : a(a1) {}
    double operator() (double x) const { return pow(1-x*x,a); } 
    double a;
};