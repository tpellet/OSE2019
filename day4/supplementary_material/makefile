
### Fortran compiler wrapper
FC=mpif90

### CPP compiler wrapper
CXX=mpicxx

### Optimization flags
FFLAGS=-O3 -fopenmp

#######################################################################	

all: pi_openmp_parallel.exec 
 
#######################################################################	


## Example 1a
pi_openmp_parallel.exec: pi_openmp_parallel.cpp
	$(CXX) $(FFLAGS) pi_openmp_parallel.cpp -o pi_openmp_parallel.exec	
	

#######################################################################	

clean :
	rm -f *.exec

#######################################################################	

