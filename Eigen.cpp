#include <tcl.h>
#include <Eigen/Dense>
#include <vector>

#include "Cmds.h"
#include "TypeDef.h"

extern "C" {
int DLLEXPORT Eigen_Init(Tcl_Interp *interp)
{
	if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL) {
		return TCL_ERROR;
	}
	if (Tcl_PkgProvide(interp, "Eigen", "0.1") == TCL_ERROR) {
		return TCL_ERROR;
	}
	if (Matrix_RegisterCmds(interp) != TCL_OK) return TCL_ERROR;
	Matrix_RegisterObjType();
	return TCL_OK;
}
}
