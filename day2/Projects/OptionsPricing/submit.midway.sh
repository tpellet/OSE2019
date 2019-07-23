#!/bin/bash -l

#SBATCH --ntasks=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1

#SBATCH --time=00:01:00


#SBATCH --job-name=Optionpricing
#SBATCH --output=OptionPricing.out
#SBATCH --error=OptionPricing.err



### openmp executable 
./BS.cpp.exec

