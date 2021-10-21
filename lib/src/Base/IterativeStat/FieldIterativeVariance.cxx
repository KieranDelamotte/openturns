//                                               -*- C++ -*-
/**
 *  @brief The field variance iterative algorithm
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

#include "openturns/PersistentObjectFactory.hxx"
#include "openturns/FieldIterativeVariance.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeVariance)

static const Factory<FieldIterativeVariance> Factory_FieldIterativeVariance;

/* Parameter constructor */
FieldIterativeVariance::FieldIterativeVariance(const UnsignedInteger verticesNumber,
    const UnsignedInteger dimension)
  : FieldIterativeAlgorithmImplementation(verticesNumber, dimension)
  , iterativeVariance_(verticesNumber * dimension)
{
  // Nothing to do
}

/* Virtual constructor */
FieldIterativeVariance * FieldIterativeVariance::clone() const
{
  return new FieldIterativeVariance(*this);
}

/* String converter */
String FieldIterativeVariance::__repr__() const
{
  OSS oss(true);
  oss << "class=" << FieldIterativeVariance::GetClassName()
      << " iterativeVariance=" << iterativeVariance_;
  return oss;
}

String FieldIterativeVariance::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset
      << ", vertices number=" << verticesNumber_
      << ", field dimension=" << dimension_
      << iterativeVariance_.__str__(offset);
  return oss;
}

/* Return the number of iterations */
UnsignedInteger FieldIterativeVariance::getIteration() const
{
  return iterativeVariance_.getIteration();
}

/* Return the accumulated variance */
Sample FieldIterativeVariance::getVariance() const
{
  SampleImplementation variance(verticesNumber_, dimension_);
  variance.setData(iterativeVariance_.getVariance());
  return variance;
}

/* Return the accumulated coefficient of variation */
Sample FieldIterativeVariance::getCoeficientOfVariation() const
{
  SampleImplementation coefficientOfVariation(verticesNumber_, dimension_);
  coefficientOfVariation.setData(iterativeVariance_.getCoefficientOfVariation());
  return coefficientOfVariation;
}

/* Return the accumulated standard error of the mean */
Sample FieldIterativeVariance::getStandardErrorOfTheMean() const
{
  SampleImplementation standardErrorOfTheMean(verticesNumber_, dimension_);
  standardErrorOfTheMean.setData(iterativeVariance_.getStandardErrorOfTheMean());
  return standardErrorOfTheMean;
}

/* Return the accumulated standard deviation */
Sample FieldIterativeVariance::getStandardDeviation() const
{
  SampleImplementation standardDeviationData(verticesNumber_, dimension_);
  standardDeviationData.setData(iterativeVariance_.getStandardDeviation());
  return standardDeviationData;
}

/* Return the accumulated mean */
Sample FieldIterativeVariance::getMean() const
{
  SampleImplementation mean(verticesNumber_, dimension_);
  mean.setData(iterativeVariance_.getMean());
  return mean;
}

/* Increment the statistics by one new data */
void FieldIterativeVariance::increment(const Sample & newData)
{
  iterativeVariance_.increment(newData.getImplementation()->getData());
}

/* Method save() stores the object through the StorageManager */
void FieldIterativeVariance::save(Advocate & adv) const
{
  FieldIterativeAlgorithmImplementation::save(adv);
  adv.saveAttribute( "iterativeVariance_", iterativeVariance_);
}


/* Method load() reloads the object from the StorageManager */
void FieldIterativeVariance::load(Advocate & adv)
{
  FieldIterativeAlgorithmImplementation::load(adv);
  adv.loadAttribute( "iterativeVariance_", iterativeVariance_);
}

END_NAMESPACE_OPENTURNS
