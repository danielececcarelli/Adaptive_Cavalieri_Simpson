#include "interval_helper.hh"
#include <iostream>

namespace numerical
{

  void interval_helper::divide_interval()
  {
    beta = (beta+alpha)/2;
  }


  void interval_helper::update_extremes()
  {
    nodes.push_back(beta);
    alpha = beta;
    beta = b;
  }


  void interval_helper::print_intervals() const
  {
    for(const real &value : nodes)
      std::cout<<value<<std::endl;
  }

}
