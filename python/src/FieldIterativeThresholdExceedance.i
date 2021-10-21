// SWIG file FieldIterativeThresholdExceedance.i

%{
#include "openturns/FieldIterativeThresholdExceedance.hxx"
%}

//%include FieldIterativeThresholdExceedance_doc.i

%include openturns/FieldIterativeThresholdExceedance.hxx

namespace OT {
%extend FieldIterativeThresholdExceedance {

FieldIterativeThresholdExceedance(const FieldIterativeThresholdExceedance & other)
{
return new OT::FieldIterativeThresholdExceedance(other);
}

} // FieldIterativeThresholdExceedance
} // OT

