To run the algorithm choose the data on main.cc and then: mpiexec -np 4 cav_simp_MPI_composite 2> /dev/null
(where 4 is a number of cores used)

To run the speedup: mpiexec -np 4 speedup_MPI_composite 2> /dev/null
(data produced in "data.csv)  