#ifndef CAVALIERI_SIMPSON_5_POINTS_HH
#define CAVALIERI_SIMPSON_5_POINTS_HH

#include <functional>

typedef long double real;

namespace numerical
{
  //compute the integral of f between a and b using the formula of Cavalieri Simpson on 5 steps
  real cavalieri_simpson_5_points(const std::function<real(real)> &f, real a, real b);
}

#endif //CAVALIERI_SIMPSON_5_POINTS_HH
