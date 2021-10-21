//                                               -*- C++ -*-
/**
 *  @brief The field threshold exceedance iterative algorithm
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

#include "openturns/FieldIterativeThresholdExceedance.hxx"
#include "openturns/PersistentObjectFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeThresholdExceedance)

static const Factory<FieldIterativeThresholdExceedance> Factory_FieldIterativeThresholdExceedance;

/* Parameter constructor */
FieldIterativeThresholdExceedance::FieldIterativeThresholdExceedance(const UnsignedInteger verticesNumber,
    const UnsignedInteger dimension,
    const Scalar thresholdValue)
  : FieldIterativeAlgorithmImplementation(verticesNumber, dimension)
  , iterativeThresholdExceedance_(verticesNumber * dimension, thresholdValue)
{
  // Nothing to do
}

/* Virtual constructor */
FieldIterativeThresholdExceedance * FieldIterativeThresholdExceedance::clone() const
{
  return new FieldIterativeThresholdExceedance(*this);
}

/* String converter */
String FieldIterativeThresholdExceedance::__repr__() const
{
  OSS oss(true);
  oss << "class=" << FieldIterativeThresholdExceedance::GetClassName()
      << " iterativeThresholdExceedance=" << iterativeThresholdExceedance_;
  return oss;
}

String FieldIterativeThresholdExceedance::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset
      << "vertices number=" << verticesNumber_
      << ", field dimension=" << dimension_
      << iterativeThresholdExceedance_.__str__(offset);
  return oss;
}

/* Return the number of iterations */
UnsignedInteger FieldIterativeThresholdExceedance::getIteration() const
{
  return iterativeThresholdExceedance_.getIteration();
}

/* Threshold value accessor */
Scalar FieldIterativeThresholdExceedance::getThresholdValue() const
{
  return iterativeThresholdExceedance_.getThresholdValue();
}

/* Return the accumulated threshold exceedance */
Sample FieldIterativeThresholdExceedance::getThresholdExceedance() const
{
  SampleImplementation thresholdExceedance(verticesNumber_, dimension_);
  thresholdExceedance.setData(iterativeThresholdExceedance_.getThresholdExceedance());
  return thresholdExceedance;
}

/* Increment the statistics by one new data */
void FieldIterativeThresholdExceedance::increment(const Sample & newData)
{
  iterativeThresholdExceedance_.increment(newData.getImplementation()->getData());
}

/* Method save() stores the object through the StorageManager */
void FieldIterativeThresholdExceedance::save(Advocate & adv) const
{
  FieldIterativeAlgorithmImplementation::save(adv);
  adv.saveAttribute( "iterativeThresholdExceedance_", iterativeThresholdExceedance_);
}


/* Method load() reloads the object from the StorageManager */
void FieldIterativeThresholdExceedance::load(Advocate & adv)
{
  FieldIterativeAlgorithmImplementation::load(adv);
  adv.loadAttribute( "iterativeThresholdExceedance_", iterativeThresholdExceedance_);
}

END_NAMESPACE_OPENTURNS
