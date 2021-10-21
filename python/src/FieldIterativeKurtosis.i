// SWIG file FieldIterativeKurtosis.i

%{
#include "openturns/FieldIterativeKurtosis.hxx"
%}

//%include FieldIterativeKurtosis_doc.i

%include openturns/FieldIterativeKurtosis.hxx

namespace OT {
%extend FieldIterativeKurtosis {

FieldIterativeKurtosis(const FieldIterativeKurtosis & other)
{
return new OT::FieldIterativeKurtosis(other);
}

} // FieldIterativeKurtosis
} // OT

