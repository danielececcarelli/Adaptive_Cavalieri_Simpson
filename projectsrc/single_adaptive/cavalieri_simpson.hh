#ifndef CAVALIERI_SIMPSON_HH
#define CAVALIERI_SIMPSON_HH

#include <functional>

typedef long double real;

namespace numerical
{
  //compute Cavalieri Simpson classical approximation
  real cavalieri_simpson(const std::function<real(real)> &f, real a, real b);
}

#endif //CAVALIERI_SIMPSON_HH
