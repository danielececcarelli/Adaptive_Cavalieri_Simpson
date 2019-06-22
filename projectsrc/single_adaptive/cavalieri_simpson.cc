#include "cavalieri_simpson.hh"

#include <iostream>

namespace numerical
{
  real cavalieri_simpson(const std::function<real(real)> &f, real a, real b)
  {
    real result = 0.0;

    real medium = (b+a)/2;      // compute middle point
    result = (b-a) * (f(a) + 4*f(medium) + f(b)) /6;   //compute cav_simp integral

    return result;
  }
}
