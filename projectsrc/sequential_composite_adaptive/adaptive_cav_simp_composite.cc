#include "adaptive_cav_simp_composite.hh"

#include <cmath>
#include <iostream>

namespace numerical
{

  real adaptive_cav_simp_composite::solve()
  {

    real result = 0.0;    //initialize result
    real b = I.get_b();   //copy b


    if(I.get_inverted())    //interval control
    {
      std::cout<<"Warning: computing integral backward (a > b)"<<std::endl;
    }

    while(I.get_alpha() != b)       //we stop when alpha (begin of dynamical interval) is equal to b (end of fixed interval)
    {
      real alpha = I.get_alpha();   //copy of alpha and beta
      real beta = I.get_beta();

      real value1 = numerical::cavalieri_simpson_composite(f, alpha, beta, n);      //compute the integral (with n)
      real value2 = numerical::cavalieri_simpson_composite(f, alpha, beta, 2*n);    //compute the integral (with 2*n) for error control

      if (tol_control(value1, value2))       //if the tollerance control is true
      {
        result += value1;                 //sum the partial integral (value1)
        extremes_update_adapt();          //update dynamical extremes
        iter += 2*n+1;
        iter_final += 2*n+1;
      }
      else if (beta - alpha < h_min)      //if the interval is less than h_min
      {
          std::cout << "Warning, h too small in: ( " << alpha << ", " << beta << " )" << '\n';
          result += value1;               //warning, then as before
          extremes_update_adapt();
          iter_final += 2*n+1;
      }
      else        //tol_control false but the interval is larger than h_min
      {
        divide_interval_adapt();          //split the interval
        iter += 2*n+1;
      }
    }

    I.change_finish_flag();           //set finish_flag = true

    return I.get_inverted() ? -result : result;
  }

      // tollerance control: if the difference between
      // value1 (n subint) and value2 (2n subint) is small enough
  bool adaptive_cav_simp_composite::tol_control(const real value1, const real value2) const
  {
    return (std::abs(value1-value2)*2*I.get_length()/15 < tol*(I.get_beta()-I.get_alpha()));
  }

    // use all the interval_helper functions
  void adaptive_cav_simp_composite::divide_interval_adapt(void)
  {
    I.divide_interval();
  }


  void adaptive_cav_simp_composite::extremes_update_adapt(void)
  {
    I.extremes_update();
  }


  bool adaptive_cav_simp_composite::finish_computation() const
  {
    return I.get_finish_flag();
  }


  void adaptive_cav_simp_composite::print_intervals() const
  {
    if(finish_computation())
      I.print_intervals();
  }
}
