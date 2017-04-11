#include <tcl.h>

extern "C" {
extern Tcl_ObjType Matrix_Tcl_ObjType;

void Matrix_RegisterObjType();
void Matrix_FreeInternalRepProc(Tcl_Obj* objPtr);
void Matrix_DupInternalRepProc(Tcl_Obj* srcPtr, Tcl_Obj* dupPtr);
void Matrix_UpdateStringProc(Tcl_Obj* objPtr);
int Matrix_SetFromAnyProc(Tcl_Interp* interp, Tcl_Obj* objPtr);
}