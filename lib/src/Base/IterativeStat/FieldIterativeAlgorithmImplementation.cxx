//                                               -*- C++ -*-
/**
 *  @brief The field iterative algorithm implementation
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

#include "openturns/FieldIterativeAlgorithmImplementation.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeAlgorithmImplementation)

/* Default constructor */
FieldIterativeAlgorithmImplementation::FieldIterativeAlgorithmImplementation()
  : PersistentObject()
  , verticesNumber_(1)
  , dimension_(1)
{
  // Nothing to do
}

/* Parameter constructor */
FieldIterativeAlgorithmImplementation::FieldIterativeAlgorithmImplementation(const UnsignedInteger verticesNumber,
    const UnsignedInteger dimension)
  : PersistentObject()
  , verticesNumber_(verticesNumber)
  , dimension_(dimension)
{
  // Nothing to do
}

/* Virtual constructor */
FieldIterativeAlgorithmImplementation * FieldIterativeAlgorithmImplementation::clone() const
{
  return new FieldIterativeAlgorithmImplementation(*this);
}

/* String converter */
String FieldIterativeAlgorithmImplementation::__repr__() const
{
  return OSS(true) << "class=" << getClassName()
         << ", vertices number=" << verticesNumber_
         << ", dimension=" << dimension_;
}

/* String converter */
String FieldIterativeAlgorithmImplementation::__str__(const String &) const
{
  return __repr__();
}

/*
 * Iteration accessor
 *
 * This method returns the current iteration number of the algorithm.
 */
UnsignedInteger FieldIterativeAlgorithmImplementation::getIteration() const
{
  throw NotYetImplementedException(HERE) << "In FieldIterativeAlgorithmImplementation::getIteration()";
}

/*
 * Vertices number accessor
 *
 * This method returns the number of vertices of the underlying mesh.
 */
UnsignedInteger FieldIterativeAlgorithmImplementation::getVerticesNumber() const
{
  return verticesNumber_;
}

/*
 * Dimension accessor
 *
 * This method returns the dimension of the object.
 */
UnsignedInteger FieldIterativeAlgorithmImplementation::getDimension() const
{
  return dimension_;
}

/* Increment the statistics by one new data */
void FieldIterativeAlgorithmImplementation::increment(const Sample & /*newData*/)
{
  throw NotYetImplementedException(HERE) << "In FieldIterativeAlgorithmImplementation::increment(const Sample & newData)";
}

/* Increment the statistics by several new data */
void FieldIterativeAlgorithmImplementation::increment(const ProcessSample & newData)
{
  for (UnsignedInteger i = 0; i < newData.getSize(); ++i)
    increment(newData[i]);
}

/* Method save() stores the object through the StorageManager
 *
 * @warning This method MUST be overloaded in derived classes.
 * @internal
 */
void FieldIterativeAlgorithmImplementation::save(Advocate & adv) const
{
  PersistentObject::save(adv);
  adv.saveAttribute( "verticesNumber_", verticesNumber_);
  adv.saveAttribute( "dimension_", dimension_);
}

/* Method load() reloads the object from the StorageManager
 *
 * @warning This method MUST be overloaded in derived classes.
 * @internal
 */
void FieldIterativeAlgorithmImplementation::load(Advocate & adv)
{
  PersistentObject::load(adv);
  adv.loadAttribute( "verticesNumber_", verticesNumber_);
  adv.loadAttribute( "dimension_", dimension_);
}

END_NAMESPACE_OPENTURNS
