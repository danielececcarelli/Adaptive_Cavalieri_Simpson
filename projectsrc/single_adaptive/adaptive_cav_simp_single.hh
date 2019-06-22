#ifndef ADAPTIVE_CAV_SIMP_SINGLE_HH
#define ADAPTIVE_CAV_SIMP_SINGLE_HH

#include "cavalieri_simpson.hh"
#include "cavalieri_simpson_5_points.hh"
#include "interval_helper.hh"


typedef long double real;

namespace numerical
{

  class adaptive_cav_simp_single      //a support for the adaptive_cav_simp algorithm (single)
  {
    private:
      interval_helper I;    // helper to manage dynamical interval
      real tol;             // tolerance control
      real h_min;           // min length of interval
      int iter = 0;
      int iter_final = 0;

      const std::function<real(real)> &f;    //function to integrate

      void divide_interval_adapt();     //to call interval_helper.divide_interval()
      void update_extremes_adapt();     //to call interval_helper.extremes_update()

      bool tol_control(const real value1, const real value2) const;   //check on the tolerance

    public:
      adaptive_cav_simp_single(real a, real b, real tol_, real h_min_, const std::function<real(real)> &f_) :
                              I(a,b), tol(tol_), h_min(h_min_), f(f_) {}

      real solve();    //compute the integral
      bool finish_computation() const;    //change_finish_flag in interval_helper
      void print_intervals();     //print the mesh
      int get_iter() {return iter;};
      int get_iter_final() {return iter_final;};

  };

}
#endif  //ADAPTIVE_CAV_SIMP_SINGLE_HH
