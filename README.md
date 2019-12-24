# Adaptive_Cavalieri_Simpson

ADAPTIVE Cavalieri Simpson rule implementation.

The Cavalieri Simpson rule is a quadrature formula to approximate numerically the computation of an integral. 
(https://en.wikipedia.org/wiki/Simpson%27s_rule)
The most used version of this rule is Composite one (https://en.wikipedia.org/wiki/Simpson%27s_rule#Composite_Simpson's_rule)
where we subdivide our integral domain to N subintervals, where we can apply the single Cavalieri simpson rule in each of them.

The Adaptive version of this rule is an algorithm that refine the subdivision of this interval where we need it most, for example near
to some singularity or discontinuity of the function. For more detail on this algorithm, see the 
"Parallel_Adaptive_Cavalieri_Simpson.pdf" in this repository.


In project_src you can find the three different implementation of this rule:
1) Single adaptive (classical Adaptive Cavalieri Simpson)
2) Sequential composite adaptive (a mix of Composite Cavalieri Simpson with an adaptive grid, sequential implementation)
2) MPI Parallel composite adaptive (a mix of Composite Cavalieri Simpson with an adaptive grid, parallel implementation using MPI)


In speedup_data_analysis you can find the data for our speed up analysis in the pdf presentation.


This is a project for the university course "Algorithm and Parallel Computing" in Politecnico of Milano 
done by Daniele Ceccarelli and Matilde Perego.
