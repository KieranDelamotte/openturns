import openturns as ot
from math import sin
ot.RandomGenerator.SetSeed(0)
import openturns.testing as ott

class FUNC(ot.OpenTURNSPythonPointToFieldFunction):

    def __init__(self, mesh):
        super(FUNC, self).__init__(2, mesh, 1)
        self.setInputDescription(['R', 'I'])
        self.setOutputDescription(['U'])
        self.mesh_ = mesh

    def _exec(self, X):
        values = [[X[0] * sin(X[1] * v[0])] for v in self.mesh_.getVertices()]
        return values


mesh = ot.IntervalMesher([10]).build(ot.Interval(0.0, 10.0))
model = ot.PointToFieldFunction(FUNC(mesh))

R = ot.Uniform(150.0, 170.0)
I = ot.Uniform(1.2, 1.4)
RI = ot.ComposedDistribution([R, I])

nMax = 100
algoMoments = ot.FieldIterativeMoments(mesh.getVerticesNumber(), 2, 1)
g = ot.Graph()
g.setAxes(True)
g.setGrid(True)

for n in range(nMax):
    v = model(RI.getRealization())
    algoMoments.increment(v)
    g.add(ot.Field(mesh, v).drawMarginal(0))

g.setColors(["lightgrey"])
g.add(ot.Field(mesh, algoMoments.getMean()).drawMarginal(0))
#g.add(ot.Field(mesh, algoMoments.getMean()+3.0*algoMoments.getStandardDeviation()).drawMarginal(0))
#g.add(ot.Field(mesh, algoMoments.getMean()-3.0*algoMoments.getStandardDeviation()).drawMarginal(0))

curveMean = ot.Curve(ot.Field(mesh, algoMoments.getMean()).getMarginal(0),"red","solid",2,"mean")
g.add(curveMean)
curvePlus = ot.Curve(ot.Field(mesh, algoMoments.getMean()+1.0*algoMoments.getStandardDeviation()).getMarginal(0),"blue","dashed",2,"mean+stdDev")
g.add(curvePlus)
curveMinus = ot.Curve(ot.Field(mesh, algoMoments.getMean()-1.0*algoMoments.getStandardDeviation()).getMarginal(0),"blue","dotdash",2,"mean-stdDev")
g.add(curveMinus)

g.setTitle("iter=" + str(n))
lgds = ["traj"]*nMax
lgds.append("1")
lgds.append("2")
lgds.append("3")
g.setLegendPosition("topright")
#ot.Show(g)

# Test the mean
referenceMean = ot.Sample([[0],[154.323],[79.5463],[-111.676],
                           [-135.38],[40.0056],[151.839],[38.3196],
                           [-126.353],[-100.04],[69.6563]])
ott.assert_almost_equal(algoMoments.getMean(), referenceMean)

# Test the standard deviation
referenceStandardDeviation = ot.Sample([[0],[6.22892],[14.8517],[19.2843],
                                        [16.9702],[41.1879],[9.929],[55.1141],
                                        [37.5694],[49.7933],[71.1115]])
ott.assert_almost_equal(algoMoments.getStandardDeviation(), referenceStandardDeviation)

