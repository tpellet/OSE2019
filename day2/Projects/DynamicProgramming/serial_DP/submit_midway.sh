#!/bin/bash -l

#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1

#SBATCH --time=00:01:00


#SBATCH --job-name=DP
#SBATCH --output=DP.out
#SBATCH --error=DP.err



### openmp executable 
./VFI

