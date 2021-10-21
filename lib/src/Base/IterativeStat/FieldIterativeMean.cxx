//                                               -*- C++ -*-
/**
 *  @brief The field mean iterative algorithm
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

#include "openturns/FieldIterativeMean.hxx"
#include "openturns/PersistentObjectFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeMean)

static const Factory<FieldIterativeMean> Factory_FieldIterativeMean;

/* Parameter constructor */
FieldIterativeMean::FieldIterativeMean(const UnsignedInteger verticesNumber,
                                       const UnsignedInteger dimension)
  : FieldIterativeAlgorithmImplementation(verticesNumber, dimension)
  , iterativeMean_(verticesNumber * dimension)
{
  // Nothing to do
}

/* Virtual constructor */
FieldIterativeMean * FieldIterativeMean::clone() const
{
  return new FieldIterativeMean(*this);
}

/* String converter */
String FieldIterativeMean::__repr__() const
{
  OSS oss(true);
  oss << "class=" << FieldIterativeMean::GetClassName()
      << " iterativeMean=" << iterativeMean_;
  return oss;
}

String FieldIterativeMean::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset
      << ", vertices number=" << verticesNumber_
      << ", field dimension=" << dimension_
      << iterativeMean_.__str__(offset);
  return oss;
}

/* Return the accumulated mean */
Sample FieldIterativeMean::getMean() const
{
  SampleImplementation mean(verticesNumber_, dimension_);
  mean.setData(iterativeMean_.getMean());
  return mean;
}

/* Increment the statistics by one new data */
void FieldIterativeMean::increment(const Sample & newData)
{
  iterativeMean_.increment(newData.getImplementation()->getData());
}

/* Method save() stores the object through the StorageManager */
void FieldIterativeMean::save(Advocate & adv) const
{
  FieldIterativeAlgorithmImplementation::save(adv);
  adv.saveAttribute( "iterativeMean_", iterativeMean_);
}

/* Method load() reloads the object from the StorageManager */
void FieldIterativeMean::load(Advocate & adv)
{
  FieldIterativeAlgorithmImplementation::load(adv);
  adv.loadAttribute( "iterativeMean_", iterativeMean_);
}

END_NAMESPACE_OPENTURNS
