// SWIG file FieldIterativeMoments.i

%{
#include "openturns/FieldIterativeMoments.hxx"
%}

//%include FieldIterativeMoments_doc.i

%include openturns/FieldIterativeMoments.hxx

namespace OT {
%extend FieldIterativeMoments {

FieldIterativeMoments(const FieldIterativeMoments & other)
{
return new OT::FieldIterativeMoments(other);
}

} // FieldIterativeMoments
} // OT

