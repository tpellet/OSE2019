#include <iostream>
#include <cmath>
#include <mpi.h>
#include <omp.h>

#define _USE_MATH_DEFINES

const int num_steps = 500000000;

int main( int argc, char *argv[] ){
    int i, Trank, Tsum, rank, my_rank, loop, numprocs;
    double sum = 0.0;
    double pi  = 0.0;
    double w;
    double x;
    std::cout << "using " << omp_get_max_threads() << " OpenMP threads" << std::endl;


    double time = -omp_get_wtime();
  
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    my_rank = 1;
    MPI_Reduce(&my_rank, &Trank, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank==0){
        printf("Number of clusters is %i\n", Trank);
	loop = round(num_steps/Trank);          //p = 4(m/n)
        printf("Loop size: %i\n", loop);
        w = 1.0/((double)loop*(double)Trank);
	printf("W is equal to %e\n",w);
        
    }

    MPI_Bcast(&loop, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&w, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    printf("I am node %i and the number of loops to do is %i\n", rank, loop);
    printf("I am node %i and w is equal to %f\n", rank, w);
    
    #pragma omp parallel for private(rank,x,i) reduction(+:sum)
    for(int i=rank; i<loop*(1+rank); ++i) {
        double x = (i+0.5)*w;
        sum += 4.0/(1.0+x*x);
        // intf("The sum within a cluster is %i\n", sum);
    }
    printf("The sum within a cluster is %i\n", sum);
    MPI_Reduce(&sum, &Tsum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank==0){
	printf("The total sum across nodes and threads is %i\n", Tsum);
    	pi = (double)Tsum*(double)w;          //p = 4(m/n)
      	printf("Pi: %f\n", pi);
   
    	time += omp_get_wtime();

    	std::cout << num_steps
              << " steps approximates pi as : "
              << pi
              << ", with relative error "
              << std::fabs(M_PI-pi)/M_PI
              << std::endl;
    	std::cout << "the solution took " << time << " seconds" <<std::endl;
    }
    MPI_Finalize();
}
