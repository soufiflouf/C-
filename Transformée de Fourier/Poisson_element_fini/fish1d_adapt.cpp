#include<iostream>
#include"valarray_util.hpp"
#include"range.hpp"
#include"mass.hpp"
#include"tridiag_ldlt.hpp"
#include"u_alpha.hpp"
#include"f_alpha.hpp"
#include"chi_beta.hpp"
#include"interpolate_1d.hpp"




using namespace std;

int main (int argc, char** argv) {
    size_t n = (argc > 1) ? atoi(argv[1]) : 11;
    double alpha = (argc > 2) ? atof(argv[2]): 0.5,
           beta = (argc > 3) ? atof(argv[3]) : 2/alpha;

valarray <double > x (n+1);
for (size_t i = 0; i < n+1; i++) 
    x[i] = -1 + 2*chi (beta, 1.0*i/n);
valarray <double > M(n-1);
tridiag <double > A(n-1);
mass (x, M);
energy (x, A);
tridiag_ldlt <double > C(A);
valarray <double > pi_h_f = interpolate (x, f(alpha)),
                   b = M*valarray <double >(pi_h_f[range(1,n)]),
                   uh (0.0, n+1);
uh [range(1,n)] = C.solve (b);
valarray <double > pi_h_u = interpolate (x,u(alpha)),
                   u_err = (pi_h_u - uh)[range(1,n)],
                   uerr_linf = abs(u_err);
cerr << "err_l2 " << sqrt(dot (u_err, M*u_err)) << endl
     << "err_linf " << uerr_linf.max() << endl
     << "err_h1 " << sqrt(dot (u_err, A*u_err)) << endl;
}                      



