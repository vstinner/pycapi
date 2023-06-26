#ifndef PYCAPI_H
#define PYCAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#define _PYCAPI_IMPLEMENTATION

#include "pythoncapi_compat.h"
#include "_pycapi_ref.h"
#include "_pycapi_dict.h"
#include "_pycapi_str.h"

#undef _PYCAPI_IMPLEMENTATION

#ifdef __cplusplus
}
#endif
#endif
