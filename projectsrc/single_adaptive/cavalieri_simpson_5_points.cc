#include "cavalieri_simpson_5_points.hh"
#include <iostream>

namespace numerical
{
  real cavalieri_simpson_5_points(const std::function<real(real)> &f, real a, real b)
  {
    real result = 0.0;      //initalize result

    real medium = (b+a)/2;                    // compute middle point
    real first_medium = (medium+a)/2;         // compute middle point of the 1st half of the interval
    real second_medium = (medium+b)/2;        // compute middle point of the 2nd half of the interval

    result = (b-a)/12 * (f(a) + 4*f(first_medium) + 2*f(medium) + 4*f(second_medium) + f(b)); //cav_simp with 5 points calculation

    return result;
  }
}
