++++++++++
PyCAPI API
++++++++++

PyCAPI Ref
==========

.. c:function:: PyObject* PyCAPI_NewRef(PyObject *obj)

   Create a new strong reference to *obj*.

.. c:function:: void PyCAPI_CloseRef(PyObject *ref)

   Close a reference.

.. c:function:: void PyCAPI_CloseXRef(PyObject *ref)

   Similar to :c:func:`PyCAPI_CloseRef`, but do nothing if *ref* is ``NULL``.


PyCAPI Str
==========

.. c:function:: PyObject* PyCAPI_Str_FromString(const char *str)

   Create a new str object: decode *str* byte string from UTF-8.

   Raise an exception and return ``NULL`` on error.


PyCAPI Dict
===========

.. c:function:: PyObject* PyCAPI_Dict_New(void)

   Create a dictionary.

.. c:function:: int PyCAPI_Dict_GetItem(PyObject *dict, PyObject *key, PyObject **pvalue)

   Get a strong reference to a dictionary value.

   * If the key is present, return ``1`` on set *\*pvalue* to a new strong
     reference to the value.
   * If the key is missing, return ``0`` and set *\*pvalue* to ``NULL``.
   * On error, raise an exception and return ``-1``.

.. c:function:: int PyCAPI_Dict_SetItem(PyObject *dict, PyObject *key, PyObject *value)

   Set a dictionary item.

   * On success, return ``0``.
   * On error, raise an exception and return ``-1``.
