#ifndef INTERVAL_HELPER_CC
#define INTERVAL_HELPER_CC

#include "interval_helper.hh"
#include <iostream>

namespace numerical
{
  void interval_helper::divide_interval()
  {
    beta = (beta+alpha)/2;    //new beta is the mid_point od alpha and beta
  }

  void interval_helper::extremes_update()
  {
    nodes.push_back(beta);    //store the old beta for the mesh
    alpha = beta;             //update alpha and beta
    beta = b;
  }

  void interval_helper::print_intervals() const
  {
    for(const real &value : nodes)
      std::cout<<value<<std::endl;
  }
}

#endif //INTERVAL_HELPER_CC
