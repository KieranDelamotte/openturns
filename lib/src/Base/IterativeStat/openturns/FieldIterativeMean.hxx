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

#ifndef OPENTURNS_FIELDITERATIVEMEAN_HXX
#define OPENTURNS_FIELDITERATIVEMEAN_HXX

#include "openturns/FieldIterativeAlgorithmImplementation.hxx"
#include "openturns/IterativeMean.hxx"

BEGIN_NAMESPACE_OPENTURNS

class OT_API FieldIterativeMean
  : public FieldIterativeAlgorithmImplementation
{
  CLASSNAME

public:

  /** Parameter constructor */
  explicit FieldIterativeMean(const UnsignedInteger verticesNumber = 1,
                              const UnsignedInteger dimension = 1);

  /** Virtual constructor */
  FieldIterativeMean * clone() const override;

  /** Increment the statistics by one new data */
  using FieldIterativeAlgorithmImplementation::increment;
  void increment(const Sample & newData) override;

  /**
   * Comparison operator
   *
   * This method compares objects based on their content.
   */
  inline
  Bool operator ==(const FieldIterativeMean & other) const
  {
    return this == &other;
  }

  /**
   * Comparison operator
   *
   * This method compares objects based on their content.
   */
  inline
  Bool operator !=(const FieldIterativeMean & other) const
  {
    return !(operator == (other));
  }

  /** String converter */
  String __repr__() const override;

  /** String converter */
  String __str__(const String & offset = "") const override;

  /** Return the accumulated mean */
  Sample getMean() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const override;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv) override;

private:
  /** The iterative mean algorithm doing the actual work */
  IterativeMean iterativeMean_;
};

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_FIELDITERATIVEMEAN_HXX */
