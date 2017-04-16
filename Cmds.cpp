#include "Cmds.h"
#include "TypeDef.h"
#include <vector>
#include <stdexcept>
#include <Eigen/Dense>

int Matrix_RegisterCmds(Tcl_Interp* interp)
{
	if (!Tcl_CreateObjCommand(interp, "matrixd", Matrixd_Cmd, NULL, NULL)) goto error;
	if (!Tcl_CreateObjCommand(interp, "madd", Madd_Cmd, NULL, NULL)) goto error;
	if (!Tcl_CreateObjCommand(interp, "msub", Msub_Cmd, NULL, NULL)) goto error;
	if (!Tcl_CreateObjCommand(interp, "mmul", Mmul_Cmd, NULL, NULL)) goto error;
	if (!Tcl_CreateObjCommand(interp, "minv", Minv_Cmd, NULL, NULL)) goto error;
	
	return TCL_OK;
	
	error:
	return TCL_ERROR;
}

int Matrixd_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
	Tcl_Obj* obj = Tcl_NewObj();
	obj->typePtr = &Matrix_Tcl_ObjType;
	Eigen::MatrixXd* mat = new Eigen::MatrixXd();
	*mat = Eigen::MatrixXd::Random(3,3);
	obj->internalRep.otherValuePtr = mat;
	Tcl_InvalidateStringRep(obj);
	/*
	try {
		if (objc != 1) return TCL_ERROR;
		std::vector<Tcl_Obj*> mat_rows;
		for (int i = 0; i < 3; ++i) {
			std::vector<Tcl_Obj*> rowelems;
			for (int j = 0; j < 3; ++j) {
				Tcl_Obj* elem = Tcl_NewDoubleObj(i*3 + j + 1.0);
				if (!elem) return TCL_ERROR;
				rowelems.push_back(elem);
			}
			Tcl_Obj* row = Tcl_NewListObj(rowelems.size(), rowelems.data());
			if (!row) return TCL_ERROR;
			mat_rows.push_back(row);
		}
		Tcl_Obj* mat = Tcl_NewListObj(mat_rows.size(), mat_rows.data());
		if (!mat) return TCL_ERROR;
		Tcl_SetObjResult(interp, mat);
	}
	catch (const std::exception& e) {
		return TCL_ERROR;
	}
	*/
	Tcl_SetObjResult(interp, obj);
	return TCL_OK;
}

int Madd_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
	if (objc != 2) return TCL_ERROR;
	if (Tcl_ConvertToType(interp, objv[0], &Matrix_Tcl_ObjType) != TCL_OK) return TCL_ERROR;
	if (Tcl_ConvertToType(interp, objv[1], &Matrix_Tcl_ObjType) != TCL_OK) return TCL_ERROR;
	return TCL_OK;
}

int Msub_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
	return TCL_OK;
}

int Mmul_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
	return TCL_OK;
}

int Minv_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[])
{
	return TCL_OK;
}
