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

#ifndef OPENTURNS_FIELDITERATIVEALGORITHM_HXX
#define OPENTURNS_FIELDITERATIVEALGORITHM_HXX

#include "openturns/TypedInterfaceObject.hxx"
#include "openturns/FieldIterativeAlgorithmImplementation.hxx"

BEGIN_NAMESPACE_OPENTURNS

class FieldIterativeAlgorithmImplementation;

class OT_API FieldIterativeAlgorithm
  : public TypedInterfaceObject<FieldIterativeAlgorithmImplementation>
{
  CLASSNAME

public:

  typedef TypedInterfaceObject<FieldIterativeAlgorithmImplementation>::Implementation Implementation;

  /**
   * Default constructor
   *
   * The constructor sets a new Id to the object,
   * so it can be later referenced by a Study object.
   * It is also declared visible if member of a study.
   *
   * The object has the default name but it does not
   * use storage for it.
   */
  FieldIterativeAlgorithm();

  /** Parameter constructor */
  FieldIterativeAlgorithm(const UnsignedInteger verticesNumber,
                          const UnsignedInteger dimension);

  /** Constructor based on implementation */
  FieldIterativeAlgorithm(const FieldIterativeAlgorithmImplementation & implementation);

  /** Constructor based on implementation smart pointer */
  FieldIterativeAlgorithm(const Implementation & p_implementation);

#ifndef SWIG
  /** Constructor based on implementation raw pointer */
  FieldIterativeAlgorithm(FieldIterativeAlgorithmImplementation * p_implementation);
#endif

  /** Return a pointer to the underlying implementation object viewed as a PersistentObject */
  Pointer<FieldIterativeAlgorithmImplementation> getImplementationAsFieldIterativeAlgorithm() const;

  /** Set the pointer to the underlying implementation object */
  void setImplementationAsFieldIterativeAlgorithm(const Pointer<FieldIterativeAlgorithmImplementation> & obj);

  /**
   * Increment methods
   *
   * @warning These methods MUST be overloaded in derived classes.
   */

  virtual void increment(const Sample & newData);

  virtual void increment(const ProcessSample & newData);

  /**
   * Iteration accessor
   *
   * This method returns the current iteration number of the algorithm.
   */
  UnsignedInteger getIteration() const;

  /**
   * Vertices number accessor
   *
   * This method returns the number of vertices of the underlying mesh.
   */
  UnsignedInteger getVerticesNumber() const;

  /**
   * Dimension accessor
   *
   * This method returns the dimension of the object.
   */
  UnsignedInteger getDimension() const;

  /** String converter */
  virtual String __repr__() const override;

  /** String converter */
  virtual String __str__(const String & offset = "") const override;

}; /* class FieldIterativeAlgorithm */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_FIELDITERATIVEALGORITHM_HXX */
