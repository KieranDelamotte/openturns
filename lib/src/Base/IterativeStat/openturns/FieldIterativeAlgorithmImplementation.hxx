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

#ifndef OPENTURNS_FIELDITERATIVEALGORITHMIMPLEMENTATION_HXX
#define OPENTURNS_FIELDITERATIVEALGORITHMIMPLEMENTATION_HXX

#include "openturns/OSS.hxx"
#include "openturns/PersistentObject.hxx"
#include "openturns/Sample.hxx"
#include "openturns/ProcessSample.hxx"

BEGIN_NAMESPACE_OPENTURNS


class OT_API FieldIterativeAlgorithmImplementation
  : public PersistentObject
{
  CLASSNAME

public:

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

  /** Default constructor */
  FieldIterativeAlgorithmImplementation();

  /** Parameter constructor */
  FieldIterativeAlgorithmImplementation(const UnsignedInteger verticeNumber,
                                        const UnsignedInteger dimension);

  /**
   * Virtual constructor
   *
   * @warning This method MUST be overloaded in derived classes.
   * @return A pointer to a newly allocated object similar to this one
   */
  virtual FieldIterativeAlgorithmImplementation * clone() const override;

  /**
   * Increment methods
   *
   * @warning These methods MUST be overloaded in derived classes.
   */

  virtual void increment(const Sample & /*newData*/);

  virtual void increment(const ProcessSample & newData);

  /**
   * Iteration accessor
   *
   * This method returns the current iteration number of the algorithm.
   */
  virtual UnsignedInteger getIteration() const;

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
  virtual
  String __repr__() const override;

  /** String converter */
  virtual
  String __str__(const String & offset = "") const override;

  /** Method save() stores the object through the StorageManager
   *
   * @warning This method MUST be overloaded in derived classes.
   * @internal
   */
  virtual void save(Advocate & adv) const override;

  /** Method load() reloads the object from the StorageManager
   *
   * @warning This method MUST be overloaded in derived classes.
   * @internal
   */
  virtual void load(Advocate & adv) override;

protected:
  /** Number of vertices of the underlying mesh */
  UnsignedInteger              verticesNumber_;

  /** Dimension of the field */
  UnsignedInteger              dimension_;

}; /* class FieldIterativeAlgorithmImplementation */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_FIELDITERATIVEALGORITHMIMPLEMENTATION_HXX */
