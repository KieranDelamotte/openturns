//                                               -*- C++ -*-
/**
 *  @brief The test file of class Contour for standard methods
 *
 *  Copyright 2005-2025 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "openturns/OT.hxx"
#include "openturns/OTtestcode.hxx"

using namespace OT;
using namespace OT::Test;

int main(int, char *[])
{
  TESTPREAMBLE;
  OStream fullprint(std::cout);

  try
  {
    // Create a function
    Description inputVar(2);
    inputVar[0] = "x";
    inputVar[1] = "y";
    Description formula(1);
    formula[0] = "exp(-sin(cos(y)^2*x^2+sin(x)^2*y^2))";
    SymbolicFunction f(inputVar, formula);

    // Generate the data for the curver to be drawn
    Point discretization(2);
    UnsignedInteger nX = 75;
    UnsignedInteger nY = 75;
    discretization[0] = nX;
    discretization[1] = nY;
    Sample inputData(Box(discretization).generate());
    inputData *= Point(2, 10.0);
    inputData += Point(2, -5.0);
    Sample data(f(inputData));
    UnsignedInteger size = 7;
    Point levels(size);
    for (UnsignedInteger i = 0; i < size; i++)
    {
      levels[i] = (0.5 + i) / size;
    }

    // Create an empty graph
    Graph myGraph("Complex iso lines", "u1", "u2", true, "topright");

    // Create the first contour
    Contour myContour(nX + 2, nY + 2, data);
    myContour.setLevels(levels);
    myContour.setColor("red");
    fullprint << "contour=" << myContour << std::endl;

    // Modify it to filled Contour
    myContour.setColorMap("inferno");
    myContour.setAlpha(0.5);
    myContour.setExtend("min");
    myContour.setColorBarPosition("left");
    myContour.setColorMapNorm("symlog");
    myContour.setHatches(Description({ "/", "\\", "+/", "*" }));
    myContour.setIsFilled(true);
    fullprint << "filled contour=" << myContour << std::endl;

    // Then, draw it
    myGraph.add(Drawable(myContour));

    // Check that the correct files have been generated by computing their checksum
  }
  catch (TestFailed & ex)
  {
    std::cerr << ex << std::endl;
    return ExitCode::Error;
  }


  return ExitCode::Success;
}
