//                                               -*- C++ -*-
/**
 *  @brief The field extrema iterative algorithm
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

#include "openturns/FieldIterativeExtrema.hxx"
#include "openturns/PersistentObjectFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeExtrema)

static const Factory<FieldIterativeExtrema> Factory_FieldIterativeExtrema;

/* Parameter constructor */
FieldIterativeExtrema::FieldIterativeExtrema(const UnsignedInteger verticesNumber,
    const UnsignedInteger dimension)
  : FieldIterativeAlgorithmImplementation(verticesNumber, dimension)
  , iterativeExtrema_(dimension)
{
  // Nothing to do
}

/* Virtual constructor */
FieldIterativeExtrema * FieldIterativeExtrema::clone() const
{
  return new FieldIterativeExtrema(*this);
}

/* String converter */
String FieldIterativeExtrema::__repr__() const
{
  OSS oss(true);
  oss << "class=" << FieldIterativeExtrema::GetClassName()
      << " iterativeExtrema=" << iterativeExtrema_;
  return oss;
}

String FieldIterativeExtrema::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset
      << "vertices number=" << verticesNumber_
      << ", field dimension=" << dimension_
      << iterativeExtrema_.__str__(offset);
  return oss;
}

/* Return the accumulated min */
Sample FieldIterativeExtrema::getMin() const
{
  SampleImplementation min(verticesNumber_, dimension_);
  min.setData(iterativeExtrema_.getMin());
  return min;
}

/* Return the accumulated max */
Sample FieldIterativeExtrema::getMax() const
{
  SampleImplementation max(verticesNumber_, dimension_);
  std::cout << iterativeExtrema_.getMax() << std::endl;
  max.setData(iterativeExtrema_.getMax());
  return max;
}

/* Increment the statistics by one new data */
void FieldIterativeExtrema::increment(const Sample & newData)
{
  iterativeExtrema_.increment(newData.getImplementation()->getData());
}

/* Method save() stores the object through the StorageManager */
void FieldIterativeExtrema::save(Advocate & adv) const
{
  FieldIterativeAlgorithmImplementation::save(adv);
  adv.saveAttribute( "iterativeExtrema_", iterativeExtrema_);
}


/* Method load() reloads the object from the StorageManager */
void FieldIterativeExtrema::load(Advocate & adv)
{
  FieldIterativeAlgorithmImplementation::load(adv);
  adv.loadAttribute( "iterativeExtrema_", iterativeExtrema_);
}

END_NAMESPACE_OPENTURNS
