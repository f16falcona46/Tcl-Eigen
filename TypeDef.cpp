#include "TypeDef.h"
#include <Eigen/Dense>
#include <sstream>
#include <string>
#include <cstdlib>

Tcl_ObjType Matrix_Tcl_ObjType;

void Matrix_RegisterObjType()
{
	Matrix_Tcl_ObjType.name = "TclEigen_Matrixd";
	Matrix_Tcl_ObjType.freeIntRepProc = &Matrix_FreeInternalRepProc;
	Matrix_Tcl_ObjType.dupIntRepProc = &Matrix_DupInternalRepProc;
	Matrix_Tcl_ObjType.updateStringProc = &Matrix_UpdateStringProc;
	Matrix_Tcl_ObjType.setFromAnyProc = &Matrix_SetFromAnyProc;
	Tcl_RegisterObjType(&Matrix_Tcl_ObjType);
}

void Matrix_FreeInternalRepProc(Tcl_Obj* objPtr)
{
	delete (Eigen::MatrixXd*)objPtr->internalRep.otherValuePtr;
}

void Matrix_DupInternalRepProc(Tcl_Obj* srcPtr, Tcl_Obj* dupPtr)
{
	Eigen::MatrixXd* mat = new (std::nothrow) Eigen::MatrixXd(*((Eigen::MatrixXd*)srcPtr->internalRep.otherValuePtr));
	dupPtr->internalRep.otherValuePtr = mat;
}

void Matrix_UpdateStringProc(Tcl_Obj* objPtr)
{
	const Eigen::MatrixXd& mat = *(Eigen::MatrixXd*)objPtr->internalRep.otherValuePtr;
	std::stringstream ss;
	ss << "{";
	for (int i = 0; i < mat.rows(); ++i) {
		ss << "{";
		for (int j = 0; j < mat.cols(); ++j) {
			ss << mat(i,j);
			if (j < mat.cols() - 1) ss << " ";
		}
		ss << "}";
		if (i < mat.rows() - 1) ss << " ";
	}
	ss << "}";
	const std::string& s = ss.str();
	char* buf = Tcl_Alloc(s.size() + 1);
	if (buf) std::strcpy(buf, &s[0]);
	objPtr->bytes = buf;
	objPtr->length = s.size() + 1;
}

int Matrix_SetFromAnyProc(Tcl_Interp* interp, Tcl_Obj* objPtr)
{
	objPtr->typePtr = &Matrix_Tcl_ObjType;
	return TCL_OK;
}