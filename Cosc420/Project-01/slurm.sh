#!/bin/sh

#SBATCH --job-name=ThisIsGarbage
##SBATCH --nodes=60
#SBATCH --ntasks=50
#SBATCH --mem=5gb
#SBATCH --time=08:00:00
#SBATCH --output=out/%j.log

module load mpi/mpich-3.2-x86_64

##mpicc ~/cmurrer1/COSC/University/Cosc420/Project-1

mpirun ~/cmurrer1/COSC/University/Cosc420/Project-1/main