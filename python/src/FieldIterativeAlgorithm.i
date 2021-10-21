// SWIG file FieldIterativeAlgorithm.i

%{
#include "openturns/FieldIterativeAlgorithm.hxx"
%}

//%include FieldIterativeAlgorithm_doc.i

OTTypedInterfaceObjectHelper(FieldIterativeAlgorithm)

%include openturns/FieldIterativeAlgorithm.hxx
namespace OT {
%extend FieldIterativeAlgorithm {

FieldIterativeAlgorithm(const FieldIterativeAlgorithm & other)
{
return new OT::FieldIterativeAlgorithm(other);
}

} // FieldIterativeAlgorithm
} // OT

