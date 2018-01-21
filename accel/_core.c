#include <Python.h>
#include "../src/host.hpp"

static char module_docstring[] =
    "This module provides an interface for doing vector subtraction.";
static char vector_sub_docstring[] =
    "Perform vector subtraction.";

static PyObject *core_vector_sub(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"vector_sub", core_vector_sub, METH_VARARGS, vector_sub_docstring},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef _coremodule = {
    PyModuleDef_HEAD_INIT,
    "_core",   /* name of module */
    module_docstring, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods,
};

PyMODINIT_FUNC PyInit__core(void)
{
    return PyModule_Create(&_coremodule);

}

static PyObject *core_vector_sub(PyObject *self, PyObject *args)
{
    PyObject *vector_a, *vector_b, *yerr_obj;

    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "OO", &vector_a, &vector_b, &yerr_obj))
        return NULL;

    vector<int, aligned_allocator<int>> source_a;
    vector<int, aligned_allocator<int>> source_b;
    vector<int, aligned_allocator<int>> source_results;

    PyObject* sequence_a;
    PyObject* sequence_b;
    long len;
    int i;

    sequence_a = PySequence_Fast(vector_a, "expected a sequence");
    sequence_b = PySequence_Fast(vector_b, "expected a sequence");
    len = PySequence_Size(vector_a);
    for (i = 0; i < len; i++) {
        PyObject* a_i = PySequence_Fast_GET_ITEM(sequence_a, i);
        source_a.push_back(PyLong_AsLong(a_i));
        PyObject* b_i = PySequence_Fast_GET_ITEM(sequence_b, i);
        source_b.push_back(PyLong_AsLong(b_i));
    }

    source_results = vector_sub(source_a, source_b);
    PyObject *vector = PyList_New(source_a.size());

    for (i = 0; i < len; i++) {
        PyObject *value = PyLong_FromLong( (long) source_results[i] );
        PyList_SetItem(vector, i, value);
    }

    /* Build the output tuple */
    PyObject *ret = Py_BuildValue("O", vector);
    return ret;
}