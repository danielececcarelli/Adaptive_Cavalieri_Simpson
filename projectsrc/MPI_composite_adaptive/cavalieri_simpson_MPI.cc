#include "cavalieri_simpson_MPI.hh"

#include <iostream>
//typedef long double real;

namespace numerical
{
  real cavalieri_simpson_MPI(const std::function<real(real)> &f, real a, real b, int n)
  {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    real result = 0.0;          //initialize result

    int local_n = n/size;       //define the number of subinterval
    int remaining = n%size;

    real local_h = (b-a)/n;

    if(rank < remaining) //take care of remaining
    {
            //we use the cavalieri_simpson_composite function with the
                //right interval and the right number of points
      real first = a + rank*(local_n+1)*local_h;
      real last = first + (local_n+1)*(local_h);
      result = cavalieri_simpson_composite(f, first, last, local_n+1);
    }
    else
    {
      real first = a + remaining*(local_n+1)*local_h + (rank-remaining)*(local_n)*local_h;
      real last = first + local_n*local_h;
      result = cavalieri_simpson_composite(f, first, last, local_n);
    }

    //we use MPI_Allreduce to sum all the result computed in the ranks (result available in all ranks)
    MPI_Allreduce(MPI_IN_PLACE, &result, 1, MPI_LONG_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    return result;
  }
}
