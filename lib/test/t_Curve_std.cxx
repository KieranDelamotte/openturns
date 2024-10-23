//                                               -*- C++ -*-
/**
 *  @brief The test file of class Curve for standard methods
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

    // Generate the data for the curves to be drawn
    UnsignedInteger size = 50;
    Point cursor(2);

    Sample data1(size, 2); //curve y = 2x for x in [-2;5]
    Sample data2(size, 2); //curve y = x*x for x in [-1;1]

    Scalar tmp;
    for(UnsignedInteger i = 0; i < size; i++)
    {
      tmp = 7.*i / size + 2;
      cursor[0] = tmp;
      cursor[1] = 2 * tmp;
      data1[i] = cursor;

      tmp = 9.*i / size + 1;
      cursor[0] = tmp;
      cursor[1] = tmp * tmp;
      data2[i] = cursor;
    }

    // Create an empty graph
    Graph myGraph("Some curves", "x1", "x2", true, "topright", 1.0, GraphImplementation::NONE);

    // Create the first curve
    Curve myCurve1(data1, "blue", "dashed", 2, "linear function");

    // Then, draw it
    myGraph.add(myCurve1);

    // Check that the correct files have been generated by computing their checksum

    // Create the second cloud
    Curve myCurve2(data2, "red", "solid", 2, "polynomial function");

    // Add it to the graph and draw everything
    myGraph.add(myCurve2);
    for (UnsignedInteger i = 0; i < 4; ++i)
    {
      myGraph.setLogScale(static_cast<GraphImplementation::LogScale>(i));
    }
  }
  catch (TestFailed & ex)
  {
    std::cerr << ex << std::endl;
    return ExitCode::Error;
  }


  return ExitCode::Success;
}
