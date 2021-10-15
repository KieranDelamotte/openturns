//                                               -*- C++ -*-
/**
 *  @brief The test file of class IterativeExtrema for standard methods
 *
 *  Copyright 2005-2019 Airbus-EDF-IMACS-ONERA-Phimeca
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

// Check if bool is true
void assertTrue(bool condition)
{
  if (!condition) throw TestFailed("Boolean is not true");
}

// Check if bool is false
void assertFalse(bool condition)
{
  if (condition) throw TestFailed("Boolean is not false");
}

// Check if two int are equal
void assertEqual(UnsignedInteger value1, UnsignedInteger value2)
{
  if (value1 != value2)
  {
    throw TestFailed(OSS() << "Value " << value1 << " is not equal to " << value2);
  }
}

int main(int, char *[])
{
  TESTPREAMBLE;
  OStream fullprint(std::cout);
  setRandomGenerator();

  try
  {
    // We create three points
    const UnsignedInteger dimension = 2;
    Point point1(dimension);
    point1[0] = 10.;
    point1[1] = 20.;
    Point point2(dimension);
    point2[0] = 11.;
    point2[1] = 21.;
    Point point3(dimension);
    point3[0] = 12.;
    point3[1] = 22.;

    // We create a Sample
    Sample sample1(0, 2);
    sample1.add(point1);
    sample1.add(point2);
    sample1.add(point3);
    fullprint << "sample1=" << sample1 << std::endl;
    Point referencemin = point1;
    fullprint << "referencemin=" << referencemin << std::endl;
    Point referencemax = point3;
    fullprint << "referencemax=" << referencemax << std::endl;

    // Iterative extrema, one point at a time
    fullprint << "Iterative extrema, one point at a time" << std::endl;
    IterativeExtrema iterextremaPoint(dimension);
    iterextremaPoint.increment(point1);
    iterextremaPoint.increment(point2);
    iterextremaPoint.increment(point3);
    Point computedmin = iterextremaPoint.getMin();
    assert_almost_equal(referencemin, computedmin, 0, 0);
    Point computedmax = iterextremaPoint.getMax();
    assert_almost_equal(referencemax, computedmax, 0, 0);
    UnsignedInteger iteration = iterextremaPoint.getIteration();
    assertEqual(iteration, 3);

    // Iterative extrema, one single sample
    fullprint << "Iterative extrema, one single sample" << std::endl;
    IterativeExtrema iterextremaSample(dimension);
    iterextremaSample.increment(sample1);
    computedmin = iterextremaSample.getMin();
    assert_almost_equal(referencemin, computedmin, 1e-8, 0);
    computedmax = iterextremaSample.getMax();
    assert_almost_equal(referencemax, computedmax, 1e-8, 0);
    iteration = iterextremaSample.getIteration();
    assertEqual(iteration, 3);

    // Iterative extrema, one single sample, then one point at a time
    fullprint << "Iterative extrema, one single sample, then one point at a time" << std::endl;
    IterativeExtrema iterextremaMixed(dimension);
    iterextremaMixed.increment(sample1);
    iterextremaMixed.increment(point1);
    iterextremaMixed.increment(point2);
    iterextremaMixed.increment(point3);
    computedmin = iterextremaMixed.getMin();
    assert_almost_equal(referencemin, computedmin, 1e-8, 0);
    computedmax = iterextremaMixed.getMax();
    assert_almost_equal(referencemax, computedmax, 1e-8, 0);
    iteration = iterextremaMixed.getIteration();
    assertEqual(iteration, 6);
  }
  catch (TestFailed & ex)
  {
    std::cerr << ex << std::endl;
    return ExitCode::Error;
  }


  return ExitCode::Success;
}
