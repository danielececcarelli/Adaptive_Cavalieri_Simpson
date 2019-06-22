#include <iostream>
#include <cmath>
#include "adaptive_cav_simp_composite.hh"
typedef long double real;

real my_fun1(real x)             //test function 1
  {return (x<=0.4) ? 1 : 0;}    //a = 0, b = 1, integral_correct = 0.400

real my_fun2(real x)             //test function 2
    {return powl(x,10);}        //a = -2, b = 2, integral_correct = 372.3636363636363636

real my_fun3(real x)             //test function 3
      {return 20*(1-x*x)*(1-x*x)*(1-x*x);}  //a = -1, b = 1, integral_correct = 18.2857142857143

int main()
{
  std::function<real(real)> f = my_fun2;

  real a = 2;
  real b = -2;
  real tol = 0.0001;
  real h_min = 0.001;
  int n = 10;

  numerical::adaptive_cav_simp_composite adap_composite(a,b,tol,h_min,n, f);
  //std::cout<< "The computation is finish: " << adap_composite.finish_computation() <<std::endl;
  std::cout << "------- COMPUTING ---------" << std::endl << std::endl;

  real result = adap_composite.solve();
  std::cout.precision(17);

  real integral_correct = -372.3636363636363636;

  std::cout << "------- RESULT ---------" << std::endl;
  std::cout<< result <<std::endl<< std::endl;

  std::cout << "------- ERROR ---------" << std::endl;
  std::cout<< std::abs(result-integral_correct) <<std::endl<<std::endl;

  //std::cout<< "The computation is finish: " << adap.finish_computation() <<std::endl;
  std::cout << "------- INTERVALS ------" << std::endl;
  adap_composite.print_intervals();

  return 0;
}
