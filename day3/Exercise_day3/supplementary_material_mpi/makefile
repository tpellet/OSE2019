### Fortran compiler wrapper
FC=mpif90

### CPP compiler wrapper
CXX=mpicxx

### Optimization flags
FFLAGS=-O3

#######################################################################	

all: broadcast_mpi.exec allreduce_mpi.exec scatter_mpi.exec

#######################################################################	



## Example 1a
broadcast_mpi.exec: broadcast.cpp
	$(CXX) $(FFLAGS) broadcast.cpp -o broadcast_mpi.exec
	
## Example 2
allreduce_mpi.exec: allreduce.cpp
	$(CXX) $(FFLAGS) allreduce.cpp -o allreduce_mpi.exec

## Example 3
scatter_mpi.exec: scatter.cpp
	$(CXX) $(FFLAGS) scatter.cpp -o scatter_mpi.exec


clean :
	rm -f *.exec

#######################################################################	
