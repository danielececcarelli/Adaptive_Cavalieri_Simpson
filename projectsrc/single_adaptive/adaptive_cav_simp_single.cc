#include "adaptive_cav_simp_single.hh"

#include <cmath>
#include <iostream>

namespace numerical
{

  real adaptive_cav_simp_single::solve()
  {
    real result = 0.0;    //initialize result

    //real a = I.get_a();     //copy a and b
    real b = I.get_b();

    if(I.get_inverted())    //interval control
    {
      std::cout<<"Warning: computing integral backward (a > b)"<<std::endl;
    }

    while(I.get_alpha() != b)       //we stop when alpha (begin of dynamical interval) is equal to b (end of fixed interval)
    {
      real alpha = I.get_alpha();   //copy of alpha and beta
      real beta = I.get_beta();

      real value1 = numerical::cavalieri_simpson(f, alpha, beta);      //compute the integral with classical cav_simp
      real value2 = numerical::cavalieri_simpson_5_points(f, alpha, beta);    //compute the integral (with 5 points cav_simp)
                                                                                        //for error control

      if(tol_control(value1, value2))       //if the tollerance control is true
      {
        result += value1;                 //sum the partial integral (value1)
        update_extremes_adapt();          //update dynamical extremes
        iter+=3;
        iter_final+=3;
      }
      else if (beta - alpha < h_min)      //if the interval is less than h_min
      {
          std::cout << "Warning, h too small in: ( " << alpha << ", " << beta << " )" << '\n';
          result += value1;               //warning, then as before
          update_extremes_adapt();
          iter+=3;
          iter_final+=3;
      }
      else        //tol_control false but the interval is larger than h_min
      {
        divide_interval_adapt();          //split the interval
        iter+=3;
      }
    }

    I.change_finish_flag();           //set finish_flag = true

    return I.get_inverted() ? -result : result;
  }


  void adaptive_cav_simp_single::divide_interval_adapt(void)
  {
    I.divide_interval();
  }


  void adaptive_cav_simp_single::update_extremes_adapt(void)
  {
    I.update_extremes();
  }


       // tollerance control: if the difference between
       // value1 (cav_simp 1 step) and value2 (cav_simp 5 steps) is small enough
  bool adaptive_cav_simp_single::tol_control(const real value1, const real value2) const
  {
    return (std::abs(value1-value2)*2*I.get_length()/15 < tol*(I.get_beta()-I.get_alpha()));
  }


  bool adaptive_cav_simp_single::finish_computation() const
  {
    return I.get_finish_flag();
  }


  void adaptive_cav_simp_single::print_intervals()
  {
    if(finish_computation())
      I.print_intervals();
  }

}
