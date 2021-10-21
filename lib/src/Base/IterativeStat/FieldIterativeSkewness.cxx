//                                               -*- C++ -*-
/**
 *  @brief The field skewness iterative algorithm
 *
 *  Copyright 2005-2021 Airbus-EDF-IMACS-ONERA-Phimeca
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

#include "openturns/FieldIterativeSkewness.hxx"
#include "openturns/PersistentObjectFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeSkewness)

static const Factory<FieldIterativeSkewness> Factory_FieldIterativeSkewness;

/* Parameter constructor */
FieldIterativeSkewness::FieldIterativeSkewness(const UnsignedInteger verticesNumber,
    const UnsignedInteger dimension)
  : FieldIterativeAlgorithmImplementation(verticesNumber, dimension)
  , iterativeSkewness_(verticesNumber_ * dimension_)
{
  // Nothing to do
}

/* Virtual constructor */
FieldIterativeSkewness * FieldIterativeSkewness::clone() const
{
  return new FieldIterativeSkewness(*this);
}

/* String converter */
String FieldIterativeSkewness::__repr__() const
{
  OSS oss(true);
  oss << "class=" << FieldIterativeSkewness::GetClassName()
      << " iterativeSkewness=" << iterativeSkewness_;
  return oss;
}

String FieldIterativeSkewness::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset
      << ", vertices number=" << verticesNumber_
      << ", field dimension=" << dimension_
      << iterativeSkewness_.__str__(offset);
  return oss;
}

/* Return the accumulated skewness */
Sample FieldIterativeSkewness::getSkewness() const
{
  SampleImplementation skewness(verticesNumber_, dimension_);
  skewness.setData(iterativeSkewness_.getStandardDeviation());
  return skewness;
}

/* Return the accumulated variance */
Sample FieldIterativeSkewness::getVariance() const
{
  SampleImplementation variance(verticesNumber_, dimension_);
  variance.setData(iterativeSkewness_.getVariance());
  return variance;
}

/* Return the accumulated coefficient of variation */
Sample FieldIterativeSkewness::getCoeficientOfVariation() const
{
  SampleImplementation coefficientOfVariation(verticesNumber_, dimension_);
  coefficientOfVariation.setData(iterativeSkewness_.getCoefficientOfVariation());
  return coefficientOfVariation;
}

/* Return the accumulated standard deviation */
Sample FieldIterativeSkewness::getStandardDeviation() const
{
  SampleImplementation standardDeviation(verticesNumber_, dimension_);
  standardDeviation.setData(iterativeSkewness_.getStandardDeviation());
  return standardDeviation;
}

/* Return the accumulated mean */
Sample FieldIterativeSkewness::getMean() const
{
  SampleImplementation mean(verticesNumber_, dimension_);
  mean.setData(iterativeSkewness_.getMean());
  return mean;
}

/* Increment the statistics by one new data */
void FieldIterativeSkewness::increment(const Sample & newData)
{
  iterativeSkewness_.increment(newData.getImplementation()->getData());
}

/* Method save() stores the object through the StorageManager */
void FieldIterativeSkewness::save(Advocate & adv) const
{
  FieldIterativeAlgorithmImplementation::save(adv);
  adv.saveAttribute( "iterativeSkewness_", iterativeSkewness_);
}


/* Method load() reloads the object from the StorageManager */
void FieldIterativeSkewness::load(Advocate & adv)
{
  FieldIterativeAlgorithmImplementation::load(adv);
  adv.loadAttribute( "iterativeSkewness_", iterativeSkewness_);
}

END_NAMESPACE_OPENTURNS
