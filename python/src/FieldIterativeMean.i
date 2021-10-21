// SWIG file FieldIterativeMean.i

%{
#include "openturns/FieldIterativeMean.hxx"
%}

//%include FieldIterativeMean_doc.i

%include openturns/FieldIterativeMean.hxx

namespace OT {
%extend FieldIterativeMean {

FieldIterativeMean(const FieldIterativeMean & other)
{
return new OT::FieldIterativeMean(other);
}

} // FieldIterativeMean
} // OT

