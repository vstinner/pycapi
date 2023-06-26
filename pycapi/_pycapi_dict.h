#ifndef _PYCAPI_IMPLEMENTATION
#  error "this header file must not be included directly"
#endif

#define PyCAPI_Dict_New PyDict_New
#define PyCAPI_Dict_GetItem PyDict_GetItemRef
#define PyCAPI_Dict_SetItem PyDict_SetItem
