#======================================================================
#
#     This routine interfaces with the TASMANIAN Sparse grid
#     The crucial part is 
#
#     aVals[iI]=solveriter.iterate(aPoints[iI], n_agents)[0]  
#     => at every gridpoint, we solve an optimization problem
#
#     Simon Scheidegger, 11/16 ; 07/17
#======================================================================

import TasmanianSG
import numpy as np
from parameters import *
import nonlinear_solver_iterate as solveriter

#======================================================================

def sparse_grid_iter(n_agents, iDepth, iG, Lvalold):
    
    grid  = TasmanianSG.TasmanianSparseGrid()

    k_range=np.array([k_bar, k_up])

    ranges=np.empty((n_agents, 2))


    for i in range(n_agents):
        ranges[i]=k_range

    iDim=n_agents

    grid.makeLocalPolynomialGrid(iDim, iOut, iDepth, which_basis, "localp")
    grid.setDomainTransform(ranges)

    aPoints=grid.getPoints()
    iNumP1=aPoints.shape[0]
    aVals=np.empty([iNumP1, iOut])

    
    #print(phi[iG])
    for iI in range(aPoints.shape[0]): 
        # Solve the value function problem for all grid points

        X = solveriter.iterate(aPoints[iI], n_agents, Lvalold, phi[iG])
        aVals[iI] = X[0]

    print("aValsI ", aVals) 
    
    # Update interpolant
    grid.loadNeededPoints(aVals)


    #print(" {0:9d} {1:9d}  {2:1.2e}".format(iK+1, grid.getNumPoints()))
    #grid2 = TasmanianSG.TasmanianSparseGrid()
    #grid2.makeLocalPolynomialGrid(iDim, iOut, refinement_level+iDepth, which_basis, "localp")
    #print("Max Number of Points",grid2.getNumPoints())
    
    #f=open("grid_iter.txt", 'w')
    #np.savetxt(f, aPoints, fmt='% 2.16f')
    #f.close()
    #print("C shape ", cVals.shape)
    #print("Value Function Shape ",aVals.shape)
    return grid

#======================================================================
