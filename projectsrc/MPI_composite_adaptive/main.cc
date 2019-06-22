#include <iostream>
#include <cmath>
#include "adaptive_cav_simp_MPI_composite.hh"
#include <mpi.h>
//typedef long double real;
//mpiexec -np 4 cav_simp_MPI_composite 2> /dev/null

real my_fun1(real x)             //test function 1
  {return (x<=0.4) ? 1 : 0;}    //a = 0, b = 1, integral_correct = 0.400

real my_fun2(real x)             //test function 2
    {return powl(x,10);}        //a = -2, b = 2, integral_correct = 372.3636363636363636

real my_fun3(real x)             //test function 3
      {return 20*(1-x*x)*(1-x*x)*(1-x*x);}  //a = -1, b = 1, integral_correct = 18.2857142857143


int main(int argc, char* argv[])
{
  MPI_Init (&argc, &argv);        //MPI INIT
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  std::function<real(real)> f = my_fun2;     //define a function

  real a = -2;          //define all the inputs for adaptive_cav_simp class
  real b = 2;
  real tol = 0.0001;
  real h_min = 0.001;
  int n = 10;

  numerical::adaptive_cav_simp_MPI_composite adap_MPI_composite(a, b, tol, h_min, n, f); //create an object of class adaptive_cav_simp

  if(rank == 0)
  {
  std::cout << "------- COMPUTING ---------" << std::endl << std::endl;
  }

  real result = adap_MPI_composite.solve();     //call to solve();

  if(rank == 0)
  {
  real integral_correct = 372.3636363636363636;     //correct integral

  std::cout.precision(17);
  std::cout << "------- RESULT ---------" << std::endl;
  std::cout<< result <<std::endl<< std::endl;         //print the result

  std::cout << "------- ERROR ---------" << std::endl;
  std::cout<< std::abs(result-integral_correct) <<std::endl <<std::endl;      //print the error

  std::cout << "------- INTERVAL ---------" << std::endl;         //print all the mesh extremes
  adap_MPI_composite.print_intervals();

  std::cout << std::endl << "------- FINISH ---------" << std::endl;
  }

  MPI_Finalize();       //MPI FINALIZE
  return 0;
}
