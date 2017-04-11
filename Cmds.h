#include <tcl.h>

extern "C" {
int Matrix_RegisterCmds(Tcl_Interp* interp);
int Matrixd_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]);
int Madd_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]);
int Msub_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]);
int Mmul_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]);
int Minv_Cmd(ClientData cdata, Tcl_Interp* interp, int objc, Tcl_Obj* const objv[]);
}