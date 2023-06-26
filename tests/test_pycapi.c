#undef NDEBUG

#include <pycapi.h>

// FIXME: Waiting for https://github.com/python/cpython/pull/106005
static inline int
PyDict_GetItemRef(PyObject *dict, PyObject *key, PyObject **pvalue) {
    PyObject *value;
    if (!PyDict_Check(dict)) {
        *pvalue = NULL;
        return -1;
    }
#if PY_VERSION_HEX >= 0x03000000
    value = PyDict_GetItemWithError(dict, key);
#else
    value = _PyDict_GetItemWithError(dict, key);
#endif
    if (value == NULL) {
        if (PyErr_Occurred()) {
            *pvalue = NULL;
            return -1;
        }
        *pvalue = NULL;
        return 0;
    }
    *pvalue = PyCAPI_NewRef(value);
    return 1;
}

#include <assert.h>
#include <stdio.h>

static int
test_dict(void)
{
    PyObject *dict = NULL, *key = NULL, *value = NULL;

    dict = PyCAPI_Dict_New();
    if (dict == NULL) {
        goto error;
    }

    key = PyCAPI_Str_FromString("key");
    if (key == NULL) {
        goto error;
    }

    value = PyCAPI_Str_FromString("value");
    if (value == NULL) {
        goto error;
    }

    if (PyCAPI_Dict_SetItem(dict, key, value) < 0) {
        goto error;
    }

    PyObject *get_value = Py_True;  // marker
    assert(PyCAPI_Dict_GetItem(dict, key, &get_value) == 1);
    assert(get_value == value);
    PyCAPI_CloseRef(get_value);

    PyCAPI_CloseRef(dict);
    PyCAPI_CloseRef(key);
    PyCAPI_CloseRef(value);
    return 0;

error:
    PyCAPI_CloseXRef(dict);
    PyCAPI_CloseXRef(key);
    PyCAPI_CloseXRef(value);
    return -1;
}

int main()
{
    int exitcode = 0;
    Py_Initialize();
    if (test_dict()) {
        printf("FAIL: test_dict() failed\n");
        exitcode = 1;
    }
    Py_Finalize();
    if (exitcode == 0) {
        printf("Tests succeeded\n");
    }
    return exitcode;
}
