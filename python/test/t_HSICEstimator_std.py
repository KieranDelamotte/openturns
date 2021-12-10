#! /usr/bin/env python

from __future__ import print_function
from openturns import *
import openturns.testing as ott
import math as m

TESTPREAMBLE()
RandomGenerator.SetSeed(0)


# Definition of the marginals
X1 = Uniform(-m.pi, m.pi)
X2 = Uniform(-m.pi, m.pi)
X3 = Uniform(-m.pi, m.pi)

# 3d distribution made with independent marginals
distX = ComposedDistribution([X1, X2, X3])

# Get a sample of it
size = 100
X = distX.getSample(size)


# The Ishigami model
modelIshigami = SymbolicFunction(
    ["X1", "X2", "X3"], ["sin(X1) + 5.0 * (sin(X2))^2 + 0.1 * X3^4 * sin(X1)"])

# Apply model: Y = m(X)
Y = modelIshigami(X)

# We define the covariance models for the HSIC indices.
# For the input, we consider a SquaredExponential covariance model.
covarianceList = CovarianceModelCollection()

# Input sample
for i in range(3):
    Xi = X.getMarginal(i)
    Cov = SquaredExponential(1)
    Cov.setScale(Xi.computeStandardDeviation())
    covarianceList.add(Cov)

# Output sample with squared exponential covariance
Cov2 = SquaredExponential(1)
Cov2.setScale(Y.computeStandardDeviation())
covarianceList.add(Cov2)

# We choose an estimator type :
#  - unbiased: HSICUStat;
#  - biased: HSICVStat.
#
estimatorType = HSICVStat()

# We define a distance function for the weights
#  For the TSA, the critical domain is [5,+inf].
interval = Interval(5, float('inf'))
g = DistanceToDomainFunction(interval)

stdDev = Y.computeStandardDeviation()[0]
foo = SymbolicFunction(["x", "s"], ["exp(-x/s)"])
g2 = ParametricFunction(foo, [1], [0.1*stdDev])

# The weight function
weight = ComposedFunction(g2, g)

# We eventually build the HSIC object!
hsic = HSICEstimator(covarianceList, X, Y, estimatorType, weight)

# We get the R2-HSIC
R2HSIC = hsic.getR2HSICIndices()
ott.assert_almost_equal(R2HSIC, [0.03717355, 0.00524130, 0.23551919])

# and the HSIC indices
HSICIndices = hsic.getHSICIndices()
ott.assert_almost_equal(HSICIndices, [0.00064033, 0.00025769, 0.01105157])

# We set the number of permutations for the pvalue estimate
b = 1000
hsic.setPermutationSize(b)

# We get the pvalue estimate by permutations
pvaluesPerm = hsic.getPValuesPermutation()
ott.assert_almost_equal(pvaluesPerm, [0.77722278, 0.95404595, 0.00099900])