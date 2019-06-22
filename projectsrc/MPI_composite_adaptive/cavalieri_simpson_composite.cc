#include "cavalieri_simpson_composite.hh"

#include <iostream>
typedef long double real;

namespace numerical
{
  real cavalieri_simpson_composite(const std::function<real(real)> &f, real a, real b, int n)
  {
    real result = 0.0;      //initalize result

    real x = a;             //initalize x
    real h = (b-a) / n;     //define h where we use cavalieri_simpson single

    for(int i = 0; i < 2*n+1; i++)     //loop over all the nodes of the mesh
    {
      if(i%2 != 0)                          //assign the right coefficient
        result += 4*f(x);
      else
      {
        if(i==0 || i==2*n)
          result += f(x);
        else
          result += 2*f(x);
      }
      x += h/2;
    }
    return (h/6)*result;                    //return the result
  }
}
