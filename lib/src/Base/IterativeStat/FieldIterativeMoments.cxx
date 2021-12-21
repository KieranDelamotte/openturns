//                                               -*- C++ -*-
/**
 *  @brief The field moments iterative algorithm
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

#include "openturns/FieldIterativeMoments.hxx"
#include "openturns/PersistentObjectFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeMoments)

static const Factory<FieldIterativeMoments> Factory_FieldIterativeMoments;

/* Parameter constructor */
FieldIterativeMoments::FieldIterativeMoments(const UnsignedInteger verticesNumber,
    const UnsignedInteger order,
    const UnsignedInteger dimension)
  : FieldIterativeAlgorithmImplementation(verticesNumber, dimension)
  , iterativeMoments_(order, verticesNumber * dimension)
{
  // Nothing
}

/* Virtual constructor */
FieldIterativeMoments * FieldIterativeMoments::clone() const
{
  return new FieldIterativeMoments(*this);
}

/* String converter */
String FieldIterativeMoments::__repr__() const
{
  OSS oss(true);
  oss << "class=" << FieldIterativeMoments::GetClassName()
      << " iterativeMoments=" << iterativeMoments_;
  return oss;
}

String FieldIterativeMoments::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset
      << ", vertices number=" << verticesNumber_
      << ", field dimension=" << dimension_
      << ", order=" << iterativeMoments_.getOrder()
      << iterativeMoments_.__str__(offset);
  return oss;
}

/* Return the accumulated kurtosis */
Sample FieldIterativeMoments::getKurtosis() const
{
  SampleImplementation kurtosis(verticesNumber_, dimension_);
  kurtosis.setData(iterativeMoments_.getKurtosis());
  return kurtosis;
}

/* Return the accumulated skewness */
Sample FieldIterativeMoments::getSkewness() const
{
  SampleImplementation skewness(verticesNumber_, dimension_);
  skewness.setData(iterativeMoments_.getSkewness());
  return skewness;
}

/* Return the accumulated variance */
Sample FieldIterativeMoments::getVariance() const
{
  SampleImplementation variance(verticesNumber_, dimension_);
  variance.setData(iterativeMoments_.getVariance());
  return variance;
}

/* Return the accumulated coefficient of variation */
Sample FieldIterativeMoments::getCoefficientOfVariation() const
{
  SampleImplementation coefficientOfVariation(verticesNumber_, dimension_);
  coefficientOfVariation.setData(iterativeMoments_.getCoefficientOfVariation());
  return coefficientOfVariation;
}

/* Return the accumulated standard deviation */
Sample FieldIterativeMoments::getStandardDeviation() const
{
  SampleImplementation standardDeviation(verticesNumber_, dimension_);
  standardDeviation.setData(iterativeMoments_.getStandardDeviation());
  return standardDeviation;
}

/* Return the accumulated mean */
Sample FieldIterativeMoments::getMean() const
{
  SampleImplementation mean(verticesNumber_, dimension_);
  mean.setData(iterativeMoments_.getMean());
  return mean;
}

/* Increment the statistics by one new data */
void FieldIterativeMoments::increment(const Sample & newData)
{
  iterativeMoments_.increment(newData.getImplementation()->getData());
}

/* Method save() stores the object through the StorageManager */
void FieldIterativeMoments::save(Advocate & adv) const
{
  FieldIterativeAlgorithmImplementation::save(adv);
  adv.saveAttribute( "iterativeMoments_", iterativeMoments_);
}


/* Method load() reloads the object from the StorageManager */
void FieldIterativeMoments::load(Advocate & adv)
{
  FieldIterativeAlgorithmImplementation::load(adv);
  adv.loadAttribute( "iterativeMoments_", iterativeMoments_);
}

END_NAMESPACE_OPENTURNS
