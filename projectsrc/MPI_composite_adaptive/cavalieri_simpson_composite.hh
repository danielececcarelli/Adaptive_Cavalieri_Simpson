#ifndef CAVALIERI_SIMPSON_COMPOSITE_HH
#define CAVALIERI_SIMPSON_COMPOSITE_HH

#include <functional>

typedef long double real;

namespace numerical
{
  //compute the integral of f between a and b using the formula of cavalieri_simpson composite
  real cavalieri_simpson_composite(const std::function<real(real)> &f, real a, real b, int n);
}

#endif //CAVALIERI_SIMPSON_COMPOSITE_HH
