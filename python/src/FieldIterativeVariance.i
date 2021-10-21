// SWIG file FieldIterativeVariance.i

%{
#include "openturns/FieldIterativeVariance.hxx"
%}

//%include FieldIterativeVariance_doc.i

%include openturns/FieldIterativeVariance.hxx

namespace OT {
%extend FieldIterativeVariance {

FieldIterativeVariance(const FieldIterativeVariance & other)
{
return new OT::FieldIterativeVariance(other);
}

} // FieldIterativeVariance
} // OT

