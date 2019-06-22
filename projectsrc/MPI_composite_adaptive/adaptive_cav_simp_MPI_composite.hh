#ifndef ADAPTIVE_CAV_SIMP_MPI_COMPOSITE_HH
#define ADAPTIVE_CAV_SIMP_MPI_COMPOSITE_HH

#include "cavalieri_simpson_MPI.hh"

#include "interval_helper.hh"

//typedef long double real;

namespace numerical
{
  class adaptive_cav_simp_MPI_composite       //a support for the adaptive_cav_simp algorithm
  {
    private:
      interval_helper I;       //an object of the class interval_helper to manage the dynamical intervals

      const real tol;          //tolerance error
      const real h_min;        //min length of interval

      int iter = 0;
      int iter_final = 0;

      const std::function<real(real)> &f;  //function to integrate
      int n;           //number of subinterval for the composite cavalieri_simpson method

      void divide_interval_adapt();     //to call interval_helper.divide_interval()
      void extremes_update_adapt();     //to call interval_helper.extremes_update()

      bool tol_control(const real value1, const real value2) const;     //compute the control of tollerance

    public:
      adaptive_cav_simp_MPI_composite(real a, real b, real tol_, real h_min_, int n_, const std::function<real(real)> &f_) :
                              I(a,b), tol(tol_), h_min(h_min_), f(f_), n(n_) {}   //constructor

      real solve();           //adaptive_cav_simp algorithm, compute the integral

      bool finish_computation() const;    //change_finish_flag in interval_helper
      void print_intervals() const;        //print the mesh
      int get_iter() {return iter;};
      int get_iter_final() {return iter_final;};
  };
}

#endif //ADAPTIVE_CAV_SIMP_MPI_COMPOSITE_HH
