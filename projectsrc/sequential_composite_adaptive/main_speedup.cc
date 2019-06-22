#include <iostream>
#include <fstream>
#include <cmath>
#include "adaptive_cav_simp_composite.hh"
#include <time.h>
//typedef long double real;
//mpiexec -np 4 cav_simp 2> /dev/null

real my_fun(real x)             //test function
  {return powl(x,10);}

int main()
{
  std::function<real(real)> f = my_fun;     //define a function

  real a = -2;          //define all the inputs for adaptive_cav_simp class
  real b = 2;
  real tol = 0.0000001;
  real h_min = 0.000001;

  clock_t t;
  clock_t tt;

  std::vector<clock_t>::size_type observations = 1000;
  std::vector<clock_t>::size_type iterations = 10;
  int n = 100;

  std::vector<clock_t> v;

  for(std::vector<clock_t>::size_type j=0; j<observations; j++)
  {
    int nn = n;

    for(std::vector<clock_t>::size_type i=0; i<iterations; i++)
    {

      numerical::adaptive_cav_simp_composite adap_seq_comp(a, b, tol, h_min, n, f); //create an object of class adaptive_cav_simp

      t = clock();

      real result = adap_seq_comp.solve();     //call to solve();

      tt = clock() - t;
      //std::cout <<"result = "<<  result <<std::endl;
      //std::cout <<"time with n = "<< n << " : " << tt <<std::endl;
      v.push_back(tt);

      nn += n;
    }
  }


  std::ofstream myfile;
  myfile.open ("data.csv");
  for (std::vector<clock_t>::size_type i = 0; i<observations*iterations; i++)
  {
    if(i % 10 == 0 )
      myfile << "\n";
    else
      myfile << ",";

    myfile << v[i];
  }


  return 0;
}
