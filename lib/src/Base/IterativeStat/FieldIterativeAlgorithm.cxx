//                                               -*- C++ -*-
/**
 *  @brief The field iterative algorithm
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

#include "openturns/FieldIterativeAlgorithm.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FieldIterativeAlgorithm)

/*
 * Default constructor
 *
 * The constructor sets a new Id to the object,
 * so it can be later referenced by a Study object.
 * It is also declared visible if member of a study.
 *
 * The object has the default name but it does not
 * use storage for it.
 */
FieldIterativeAlgorithm::FieldIterativeAlgorithm()
  : TypedInterfaceObject<FieldIterativeAlgorithmImplementation>(new FieldIterativeAlgorithmImplementation())
{
  // Nothing to do
}

/* Parameter constructor */
FieldIterativeAlgorithm::FieldIterativeAlgorithm(const UnsignedInteger verticesNumber,
    const UnsignedInteger dimension)
  : TypedInterfaceObject<FieldIterativeAlgorithmImplementation>(new FieldIterativeAlgorithmImplementation(verticesNumber, dimension))
{
  // Nothing to do
}

/* Constructor based on implementation */
FieldIterativeAlgorithm::FieldIterativeAlgorithm(const FieldIterativeAlgorithmImplementation & implementation)
  : TypedInterfaceObject<FieldIterativeAlgorithmImplementation>(implementation.clone())
{
  // Nothing to do
}

/* Constructor based on implementation smart pointer */
FieldIterativeAlgorithm::FieldIterativeAlgorithm(const Implementation & p_implementation)
  : TypedInterfaceObject<FieldIterativeAlgorithmImplementation>(p_implementation)
{
  // Nothing to do
}

#ifndef SWIG
/* Constructor based on implementation raw pointer */
FieldIterativeAlgorithm::FieldIterativeAlgorithm(FieldIterativeAlgorithmImplementation * p_implementation)
  : TypedInterfaceObject<FieldIterativeAlgorithmImplementation>(p_implementation)
{
  // Nothing to do
}
#endif

/* Return a pointer to the underlying implementation object viewed as a PersistentObject */
Pointer<FieldIterativeAlgorithmImplementation> FieldIterativeAlgorithm::getImplementationAsFieldIterativeAlgorithm() const
{
  return p_implementation_;
}

/* Set the pointer to the underlying implementation object */
void FieldIterativeAlgorithm::setImplementationAsFieldIterativeAlgorithm(const Pointer<FieldIterativeAlgorithmImplementation> & obj)
{
  p_implementation_.assign(obj);
}

/*
 * Increment methods
 *
 * @warning These methods MUST be overloaded in derived classes.
 */

void FieldIterativeAlgorithm::increment(const Sample & newData)
{
  return getImplementation()->increment(newData);
}

void FieldIterativeAlgorithm::increment(const ProcessSample & newData)
{
  return getImplementation()->increment(newData);
}

/*
 * Iteration accessor
 *
 * This method returns the current iteration number of the algorithm.
 */
UnsignedInteger FieldIterativeAlgorithm::getIteration() const
{
  return getImplementation()->getIteration();
}

/*
 * Vertices number accessor
 *
 * This method returns the number of vertices of the underlying mesh.
 */
UnsignedInteger FieldIterativeAlgorithm::getVerticesNumber() const
{
  return getImplementation()->getVerticesNumber();
}

/*
 * Dimension accessor
 *
 * This method returns the dimension of the object.
 */
UnsignedInteger FieldIterativeAlgorithm::getDimension() const
{
  return getImplementation()->getDimension();
}

/* String converter */
String FieldIterativeAlgorithm::__repr__() const
{
  return getImplementation()->__repr__();
}

/* String converter */
String FieldIterativeAlgorithm::__str__(const String & offset) const
{
  return getImplementation()->__str__(offset);
}

END_NAMESPACE_OPENTURNS
