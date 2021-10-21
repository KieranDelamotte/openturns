// SWIG file FieldIterativeAlgorithm.i

%{
#include "openturns/FieldIterativeAlgorithmImplementation.hxx"
%}

//%include FieldIterativeAlgorithmImplementation_doc.i

%include openturns/FieldIterativeAlgorithmImplementation.hxx
namespace OT {
%extend FieldIterativeAlgorithmImplementation {

FieldIterativeAlgorithmImplementation(const FieldIterativeAlgorithmImplementation & other)
{
return new OT::FieldIterativeAlgorithmImplementation(other);
}

} // FieldIterativeAlgorithmImplementation
} // OT

