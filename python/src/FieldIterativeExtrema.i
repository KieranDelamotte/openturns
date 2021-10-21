// SWIG file FieldIterativeExtrema.i

%{
#include "openturns/FieldIterativeExtrema.hxx"
%}

//%include FieldIterativeExtrema_doc.i

%include openturns/FieldIterativeExtrema.hxx

namespace OT {
%extend FieldIterativeExtrema {

FieldIterativeExtrema(const FieldIterativeExtrema & other)
{
return new OT::FieldIterativeExtrema(other);
}

} // FieldIterativeExtrema
} // OT

