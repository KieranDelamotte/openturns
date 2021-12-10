
//                                               -*- C++ -*-
/**
 * @brief HSICESTIMATORGLOBALSENSITIVITY implements the sensivity analysis method based on HSIC indices
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
#ifndef OPENTURNS_HSICESTIMATORGLOBALSENSITIVITY_HXX
#define OPENTURNS_HSICESTIMATORGLOBALSENSITIVITY_HXX

#include "openturns/TypedInterfaceObject.hxx"
#include "openturns/HSICEstimatorImplementation.hxx"
#include "openturns/HSICEstimator.hxx"
#include "openturns/ResourceMap.hxx"
#include "openturns/CovarianceModel.hxx"
#include "openturns/Sample.hxx"
#include "openturns/Graph.hxx"
#include "openturns/Pointer.hxx"
#include "openturns/Function.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class HSICEstimatorGlobalSensitivity
 *
 */
class OT_API HSICEstimatorGlobalSensitivity
  : public HSICEstimatorImplementation
{
  CLASSNAME

public:

  typedef Collection<CovarianceModel> CovarianceModelCollection;

public:

  /** Default */
  HSICEstimatorGlobalSensitivity();

  /** Constructor */
  HSICEstimatorGlobalSensitivity(const CovarianceModelCollection & covarianceList,  const Sample & X,  const Sample & Y, const HSICStat & estimatorType);

  /** Virtual constructor */
  HSICEstimatorGlobalSensitivity* clone() const override;

private:
  /** Compute the weight matrix from the weight function */
  virtual SquareMatrix computeWeightMatrix(const Sample & Y) const override;

private:

  /** Compute the p-values with asymptotic formula */
  void computePValuesAsymptotic();

public:

  /** Get the asymptotic p-values */
  Point getPValuesAsymptotic();

  /** Draw the asymptotic p-values */
  Graph drawPValuesAsymptotic();

private:
  /** data */
  Point PValuesAsymptotic_ ;

};


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_HSICESTIMATORGLOBALSENSITIVITY_HXX */