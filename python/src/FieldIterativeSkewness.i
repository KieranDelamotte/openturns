// SWIG file FieldIterativeSkewness.i

%{
#include "openturns/FieldIterativeSkewness.hxx"
%}

//%include FieldIterativeSkewness_doc.i

%include openturns/FieldIterativeSkewness.hxx

namespace OT {
%extend FieldIterativeSkewness {

FieldIterativeSkewness(const FieldIterativeSkewness & other)
{
return new OT::FieldIterativeSkewness(other);
}

} // FieldIterativeSkewness
} // OT

