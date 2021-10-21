import openturns as ot
from math import sin

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
algoMean = ot.FieldIterativeMean(mesh.getVerticesNumber(), 1)
g = ot.Graph()
g.setAxes(True)
g.setGrid(True)

for n in range(nMax):
    v = model(RI.getRealization())
    algoMean.increment(v)
    g.add(ot.Field(mesh, v).drawMarginal(0))

g.setColors(["lightgrey"])
g.add(ot.Field(mesh, algoMean.getMean()).drawMarginal(0))
g.setTitle("iter=" + str(n))
#ot.Show(g)
print("Mean field=", algoMean.getMean())
