#ifndef _PYCAPI_IMPLEMENTATION
#  error "this header file must not be included directly"
#endif

#define PyCAPI_NewRef Py_NewRef
#define PyCAPI_CloseRef Py_DECREF
#define PyCAPI_CloseXRef Py_XDECREF
