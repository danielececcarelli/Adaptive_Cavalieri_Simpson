#ifndef CAVALIERI_SIMPSON_MPI_HH
#define CAVALIERI_SIMPSON_MPI_HH

#include <functional>
#include <mpi.h>
#include "cavalieri_simpson_composite.hh"
//typedef long double real;

namespace numerical
{
  //compute the cavalieri_simpson_composite using MPI
  real cavalieri_simpson_MPI(const std::function<real(real)> &f, real a, real b, int n);
}

#endif //CAVALIERI_SIMPSON_HH
