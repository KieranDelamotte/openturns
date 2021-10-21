//                                               -*- C++ -*-
/**
 *  @brief The field kurtosis iterative algorithm
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

#include "openturns/FieldIterativeKurtosis.hxx"
#include "openturns/PersistentObjectFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeKurtosis)

static const Factory<FieldIterativeKurtosis> Factory_FieldIterativeKurtosis;

/* Parameter constructor */
FieldIterativeKurtosis::FieldIterativeKurtosis(const UnsignedInteger verticesNumber,
    const UnsignedInteger dimension)
  : FieldIterativeAlgorithmImplementation(verticesNumber, dimension)
  , iterativeKurtosis_(verticesNumber * dimension)
{
  // Nothing to do
}

/* Virtual constructor */
FieldIterativeKurtosis * FieldIterativeKurtosis::clone() const
{
  return new FieldIterativeKurtosis(*this);
}

/* String converter */
String FieldIterativeKurtosis::__repr__() const
{
  OSS oss(true);
  oss << "class=" << FieldIterativeKurtosis::GetClassName()
      << " iterativeKurtosis=" << iterativeKurtosis_;
  return oss;
}

String FieldIterativeKurtosis::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset
      << ", vertices number=" << verticesNumber_
      << ", field dimension=" << dimension_
      << iterativeKurtosis_.__str__(offset);
  return oss;
}

/* Return the accumulated kurtosis */
Sample FieldIterativeKurtosis::getKurtosis() const
{
  SampleImplementation kurtosis(verticesNumber_, dimension_);
  kurtosis.setData(iterativeKurtosis_.getKurtosis());
  return kurtosis;
}

/* Return the accumulated skewness */
Sample FieldIterativeKurtosis::getSkewness() const
{
  SampleImplementation skewness(verticesNumber_, dimension_);
  skewness.setData(iterativeKurtosis_.getSkewness());
  return skewness;
}

/* Return the accumulated variance */
Sample FieldIterativeKurtosis::getVariance() const
{
  SampleImplementation variance(verticesNumber_, dimension_);
  variance.setData(iterativeKurtosis_.getVariance());
  return variance;
}

/* Return the accumulated coefficient of variation */
Sample FieldIterativeKurtosis::getCoeficientOfVariation() const
{
  SampleImplementation coefficientOfVariation(verticesNumber_, dimension_);
  coefficientOfVariation.setData(iterativeKurtosis_.getCoefficientOfVariation());
  return coefficientOfVariation;
}

/* Return the accumulated standard deviation */
Sample FieldIterativeKurtosis::getStandardDeviation() const
{
  SampleImplementation standardDeviation(verticesNumber_, dimension_);
  standardDeviation.setData(iterativeKurtosis_.getStandardDeviation());
  return standardDeviation;
}

/* Return the accumulated mean */
Sample FieldIterativeKurtosis::getMean() const
{
  SampleImplementation mean(verticesNumber_, dimension_);
  mean.setData(iterativeKurtosis_.getMean());
  return mean;
}

/* Increment the statistics by one new data */
void FieldIterativeKurtosis::increment(const Sample & newData)
{
  iterativeKurtosis_.increment(newData.getImplementation()->getData());
}

/* Method save() stores the object through the StorageManager */
void FieldIterativeKurtosis::save(Advocate & adv) const
{
  FieldIterativeAlgorithmImplementation::save(adv);
  adv.saveAttribute( "iterativeKurtosis_", iterativeKurtosis_);
}


/* Method load() reloads the object from the StorageManager */
void FieldIterativeKurtosis::load(Advocate & adv)
{
  FieldIterativeAlgorithmImplementation::load(adv);
  adv.loadAttribute( "iterativeKurtosis_", iterativeKurtosis_);
}

END_NAMESPACE_OPENTURNS
