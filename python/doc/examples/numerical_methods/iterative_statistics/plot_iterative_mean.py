"""
Iterative mean
==============
"""

# %%
# In this example, we show how to use the :class:`~openturns.IterativeMean` class. This algorithm computes an estimate of the mean using iterative algorithms. In other words, this algorithm can be used to iteratively update the estimate of the mean using one point at a time instead of using the full sample. 

# %%
import openturns as ot

# %%
# Create the mean object

# %%
dim = 5
myMean = ot.IterativeMean(dim)

# %%
# Perform the simulations. In the following session, we increment using the :meth:`~openturns.IterativeMean.increment` method one :class:`~openturns.Point` at a time.

# %%
n = ot.Normal(dim)
size = 50
for i in range(size):
    point = n.getRealization()
    myMean.increment(point)

# %%
# The :meth:`~openturns.IterativeMean.getMean` method returns the sample mean.

# %%
myMean.getMean()

# %%
# The :meth:`~openturns.IterativeMean.getIteration` method returns the sample size.

# %%
myMean.getIteration()

# %%
# We can also increment with a `Sample`.

# %%
sample = n.getSample(size)
myMean.increment(sample)

# %%
print ("Iteration " + str(myMean.getIteration()))
print (myMean.getMean())

