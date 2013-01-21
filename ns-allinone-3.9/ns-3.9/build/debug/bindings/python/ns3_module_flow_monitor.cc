#include "ns3module.h"

std::map<void*, PyObject*> PyNs3Histogram_wrapper_registry;


static int
_wrap_PyNs3Histogram__tp_init__0(PyNs3Histogram *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Histogram *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Histogram_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Histogram(*((PyNs3Histogram *) arg0)->obj);
    return 0;
}

static int
_wrap_PyNs3Histogram__tp_init__1(PyNs3Histogram *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    double binWidth;
    const char *keywords[] = {"binWidth", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &binWidth)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Histogram(binWidth);
    return 0;
}

static int
_wrap_PyNs3Histogram__tp_init__2(PyNs3Histogram *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Histogram();
    return 0;
}

int _wrap_PyNs3Histogram__tp_init(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Histogram__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Histogram__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Histogram__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3Histogram_SerializeToXmlStream(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    int indent;
    const char *elementName;
    Py_ssize_t elementName_len;
    const char *keywords[] = {"os", "indent", "elementName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!is#", (char **) keywords, &PyStdOstream_Type, &os, &indent, &elementName, &elementName_len)) {
        return NULL;
    }
    self->obj->SerializeToXmlStream(*((PyStdOstream *) os)->obj, indent, std::string(elementName, elementName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinCount(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinCount(index);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinWidth(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinWidth(index);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetNBins(PyNs3Histogram *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNBins();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinEnd(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinEnd(index);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_AddValue(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &value)) {
        return NULL;
    }
    self->obj->AddValue(value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_SetDefaultBinWidth(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double binWidth;
    const char *keywords[] = {"binWidth", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &binWidth)) {
        return NULL;
    }
    self->obj->SetDefaultBinWidth(binWidth);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinStart(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinStart(index);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Histogram__copy__(PyNs3Histogram *self)
{

    PyNs3Histogram *py_copy;
    py_copy = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_copy->obj = new ns3::Histogram(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Histogram_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Histogram_methods[] = {
    {(char *) "SerializeToXmlStream", (PyCFunction) _wrap_PyNs3Histogram_SerializeToXmlStream, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBinCount", (PyCFunction) _wrap_PyNs3Histogram_GetBinCount, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBinWidth", (PyCFunction) _wrap_PyNs3Histogram_GetBinWidth, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNBins", (PyCFunction) _wrap_PyNs3Histogram_GetNBins, METH_NOARGS, NULL },
    {(char *) "GetBinEnd", (PyCFunction) _wrap_PyNs3Histogram_GetBinEnd, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddValue", (PyCFunction) _wrap_PyNs3Histogram_AddValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultBinWidth", (PyCFunction) _wrap_PyNs3Histogram_SetDefaultBinWidth, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBinStart", (PyCFunction) _wrap_PyNs3Histogram_GetBinStart, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Histogram__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Histogram__tp_dealloc(PyNs3Histogram *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Histogram_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Histogram_wrapper_registry.end()) {
        PyNs3Histogram_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Histogram *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Histogram__tp_richcompare (PyNs3Histogram *PYBINDGEN_UNUSED(self), PyNs3Histogram *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Histogram_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3Histogram_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Histogram",            /* tp_name */
    sizeof(PyNs3Histogram),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Histogram__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Histogram__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Histogram_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Histogram__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




pybindgen::TypeMap PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map;



static int
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__0(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >();
    return 0;
}

static int
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__1(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >(*((PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *) o)->obj);
    return 0;
}

int _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Cleanup(void)
{
    PyObject *py_retval;
    
    ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >::Cleanup();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____copy__(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self)
{

    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *py_copy;
    py_copy = PyObject_New(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__, &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type);
    py_copy->obj = new ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___methods[] = {
    {(char *) "Cleanup", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Cleanup, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_dealloc(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> > *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_richcompare (PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *PYBINDGEN_UNUSED(self), PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__",            /* tp_name */
    sizeof(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




pybindgen::TypeMap PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____typeid_map;



static int
_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_init__0(PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::FlowProbe, ns3::empty, ns3::DefaultDeleter<ns3::FlowProbe> >();
    return 0;
}

static int
_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_init__1(PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::FlowProbe, ns3::empty, ns3::DefaultDeleter<ns3::FlowProbe> >(*((PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *) o)->obj);
    return 0;
}

int _wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_init(PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___Cleanup(void)
{
    PyObject *py_retval;
    
    ns3::SimpleRefCount< ns3::FlowProbe, ns3::empty, ns3::DefaultDeleter<ns3::FlowProbe> >::Cleanup();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____copy__(PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *self)
{

    PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *py_copy;
    py_copy = PyObject_New(PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__, &PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___Type);
    py_copy->obj = new ns3::SimpleRefCount< ns3::FlowProbe, ns3::empty, ns3::DefaultDeleter<ns3::FlowProbe> >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___methods[] = {
    {(char *) "Cleanup", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___Cleanup, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_dealloc(PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::SimpleRefCount< ns3::FlowProbe, ns3::empty, ns3::DefaultDeleter<ns3::FlowProbe> > *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_richcompare (PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *PYBINDGEN_UNUSED(self), PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__ *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__",            /* tp_name */
    sizeof(PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt___methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SimpleRefCount__Ns3FlowProbe_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowProbe__gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static int
_wrap_PyNs3FlowClassifier__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'FlowClassifier' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}


PyObject *
_wrap_PyNs3FlowClassifier_SerializeToXmlStream(PyNs3FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    int indent;
    const char *keywords[] = {"os", "indent", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyStdOstream_Type, &os, &indent)) {
        return NULL;
    }
    self->obj->SerializeToXmlStream(*((PyStdOstream *) os)->obj, indent);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3FlowClassifier_methods[] = {
    {(char *) "SerializeToXmlStream", (PyCFunction) _wrap_PyNs3FlowClassifier_SerializeToXmlStream, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowClassifier__tp_dealloc(PyNs3FlowClassifier *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::FlowClassifier *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowClassifier__tp_richcompare (PyNs3FlowClassifier *PYBINDGEN_UNUSED(self), PyNs3FlowClassifier *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowClassifier_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3FlowClassifier_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.FlowClassifier",            /* tp_name */
    sizeof(PyNs3FlowClassifier),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowClassifier__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FlowClassifier__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowClassifier_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowClassifier__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3FlowMonitor__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class FlowMonitor is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3FlowMonitor__PythonHelper::_wrap_NotifyNewAggregate(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3FlowMonitor__PythonHelper::_wrap_DoStart(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoStart of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoStart__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3FlowMonitor__PythonHelper::_wrap_DoDispose(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::TypeId
PyNs3FlowMonitor__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FlowMonitor *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::FlowMonitor::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = const_cast< ns3::FlowMonitor* >((const ns3::FlowMonitor*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::FlowMonitor::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::FlowMonitor::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3FlowMonitor__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FlowMonitor *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::FlowMonitor::NotifyConstructionCompleted();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = (ns3::FlowMonitor*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FlowMonitor__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::Object::DoDispose();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FlowMonitor__PythonHelper::DoStart()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoStart"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::Object::DoStart();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoStart", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FlowMonitor__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3FlowMonitor__tp_init__0(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FlowMonitor *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowMonitor_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (self->ob_type != &PyNs3FlowMonitor_Type)
    {
        self->obj = new PyNs3FlowMonitor__PythonHelper(*((PyNs3FlowMonitor *) arg0)->obj);
        self->obj->Ref ();
        ((PyNs3FlowMonitor__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::FlowMonitor(*((PyNs3FlowMonitor *) arg0)->obj);
        self->obj->Ref ();
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3FlowMonitor__tp_init__1(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (self->ob_type != &PyNs3FlowMonitor_Type)
    {
        self->obj = new PyNs3FlowMonitor__PythonHelper();
        self->obj->Ref ();
        ((PyNs3FlowMonitor__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::FlowMonitor();
        self->obj->Ref ();
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3FlowMonitor__tp_init(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowMonitor__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowMonitor__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3FlowMonitor_ReportLastRx(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!III", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportLastRx(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_StopRightNow(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    
    self->obj->StopRightNow();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_ReportFirstTx(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!III", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportFirstTx(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_SerializeToXmlStream(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    int indent;
    bool enableHistograms;
    PyObject *py_enableHistograms;
    bool enableProbes;
    PyObject *py_enableProbes;
    const char *keywords[] = {"os", "indent", "enableHistograms", "enableProbes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!iOO", (char **) keywords, &PyStdOstream_Type, &os, &indent, &py_enableHistograms, &py_enableProbes)) {
        return NULL;
    }
    enableHistograms = (bool) PyObject_IsTrue(py_enableHistograms);
    enableProbes = (bool) PyObject_IsTrue(py_enableProbes);
    self->obj->SerializeToXmlStream(*((PyStdOstream *) os)->obj, indent, enableHistograms, enableProbes);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_AddProbe(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    const char *keywords[] = {"probe", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowProbe_Type, &probe)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->AddProbe(ns3::Ptr< ns3::FlowProbe  > (probe_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_SerializeToXmlString(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    int indent;
    bool enableHistograms;
    PyObject *py_enableHistograms;
    bool enableProbes;
    PyObject *py_enableProbes;
    const char *keywords[] = {"indent", "enableHistograms", "enableProbes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iOO", (char **) keywords, &indent, &py_enableHistograms, &py_enableProbes)) {
        return NULL;
    }
    enableHistograms = (bool) PyObject_IsTrue(py_enableHistograms);
    enableProbes = (bool) PyObject_IsTrue(py_enableProbes);
    retval = self->obj->SerializeToXmlString(indent, enableHistograms, enableProbes);
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}



PyObject *
_wrap_PyNs3FlowMonitor_CheckForLostPackets__0(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->CheckForLostPackets();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3FlowMonitor_CheckForLostPackets__1(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyObject *maxDelay;
    ns3::Time maxDelay2;
    const char *keywords[] = {"maxDelay", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &maxDelay)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (PyObject_IsInstance(maxDelay, (PyObject*) &PyNs3Time_Type)) {
        maxDelay2 = *((PyNs3Time *) maxDelay)->obj;
    } else if (PyObject_IsInstance(maxDelay, (PyObject*) &PyNs3Scalar_Type)) {
        maxDelay2 = *((PyNs3Scalar *) maxDelay)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, Scalar), not %s", maxDelay->ob_type->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->CheckForLostPackets(maxDelay2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3FlowMonitor_CheckForLostPackets(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowMonitor_CheckForLostPackets__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowMonitor_CheckForLostPackets__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3FlowMonitor_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::FlowMonitor::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_Stop(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *time;
    ns3::Time time2;
    const char *keywords[] = {"time", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &time)) {
        return NULL;
    }
    if (PyObject_IsInstance(time, (PyObject*) &PyNs3Time_Type)) {
        time2 = *((PyNs3Time *) time)->obj;
    } else if (PyObject_IsInstance(time, (PyObject*) &PyNs3Scalar_Type)) {
        time2 = *((PyNs3Scalar *) time)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, Scalar), not %s", time->ob_type->tp_name);
        return NULL;
    }
    self->obj->Stop(time2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_StartRightNow(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    
    self->obj->StartRightNow();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_SerializeToXmlFile(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *fileName;
    Py_ssize_t fileName_len;
    bool enableHistograms;
    PyObject *py_enableHistograms;
    bool enableProbes;
    PyObject *py_enableProbes;
    const char *keywords[] = {"fileName", "enableHistograms", "enableProbes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#OO", (char **) keywords, &fileName, &fileName_len, &py_enableHistograms, &py_enableProbes)) {
        return NULL;
    }
    enableHistograms = (bool) PyObject_IsTrue(py_enableHistograms);
    enableProbes = (bool) PyObject_IsTrue(py_enableProbes);
    self->obj->SerializeToXmlFile(std::string(fileName, fileName_len), enableHistograms, enableProbes);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_Start(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *time;
    ns3::Time time2;
    const char *keywords[] = {"time", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &time)) {
        return NULL;
    }
    if (PyObject_IsInstance(time, (PyObject*) &PyNs3Time_Type)) {
        time2 = *((PyNs3Time *) time)->obj;
    } else if (PyObject_IsInstance(time, (PyObject*) &PyNs3Scalar_Type)) {
        time2 = *((PyNs3Scalar *) time)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, Scalar), not %s", time->ob_type->tp_name);
        return NULL;
    }
    self->obj->Start(time2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_GetFlowStats(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowMonitor::FlowStats > retval;
    Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__;
    
    retval = self->obj->GetFlowStats();
    py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ = PyObject_New(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__, &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type);
    py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__->obj = new std::map< unsigned int, ns3::FlowMonitor::FlowStats >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_GetInstanceTypeId(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper_class = dynamic_cast<PyNs3FlowMonitor__PythonHelper*> (self->obj);
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = (helper_class == NULL)? (self->obj->GetInstanceTypeId()) : (self->obj->ns3::FlowMonitor::GetInstanceTypeId());
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_ReportForwarding(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!III", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportForwarding(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_SetFlowClassifier(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowClassifier *classifier;
    ns3::FlowClassifier *classifier_ptr;
    const char *keywords[] = {"classifier", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowClassifier_Type, &classifier)) {
        return NULL;
    }
    classifier_ptr = (classifier ? classifier->obj : NULL);
    self->obj->SetFlowClassifier(ns3::Ptr< ns3::FlowClassifier  > (classifier_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_ReportDrop(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    unsigned int reasonCode;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", "reasonCode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!IIII", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize, &reasonCode)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportDrop(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize, reasonCode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3FlowMonitor__copy__(PyNs3FlowMonitor *self)
{

    PyNs3FlowMonitor *py_copy;
    py_copy = PyObject_GC_New(PyNs3FlowMonitor, &PyNs3FlowMonitor_Type);
    py_copy->obj = new ns3::FlowMonitor(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3FlowMonitor_methods[] = {
    {(char *) "ReportLastRx", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportLastRx, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "StopRightNow", (PyCFunction) _wrap_PyNs3FlowMonitor_StopRightNow, METH_NOARGS, NULL },
    {(char *) "ReportFirstTx", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportFirstTx, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SerializeToXmlStream", (PyCFunction) _wrap_PyNs3FlowMonitor_SerializeToXmlStream, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddProbe", (PyCFunction) _wrap_PyNs3FlowMonitor_AddProbe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SerializeToXmlString", (PyCFunction) _wrap_PyNs3FlowMonitor_SerializeToXmlString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "CheckForLostPackets", (PyCFunction) _wrap_PyNs3FlowMonitor_CheckForLostPackets, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3FlowMonitor_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Stop", (PyCFunction) _wrap_PyNs3FlowMonitor_Stop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "StartRightNow", (PyCFunction) _wrap_PyNs3FlowMonitor_StartRightNow, METH_NOARGS, NULL },
    {(char *) "SerializeToXmlFile", (PyCFunction) _wrap_PyNs3FlowMonitor_SerializeToXmlFile, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Start", (PyCFunction) _wrap_PyNs3FlowMonitor_Start, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFlowStats", (PyCFunction) _wrap_PyNs3FlowMonitor_GetFlowStats, METH_NOARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3FlowMonitor_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "ReportForwarding", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportForwarding, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFlowClassifier", (PyCFunction) _wrap_PyNs3FlowMonitor_SetFlowClassifier, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ReportDrop", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportDrop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoStart", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_DoStart, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3FlowMonitor__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3FlowMonitor__tp_clear(PyNs3FlowMonitor *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::FlowMonitor *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3FlowMonitor__tp_traverse(PyNs3FlowMonitor *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj) == typeid(PyNs3FlowMonitor__PythonHelper)  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3FlowMonitor__tp_dealloc(PyNs3FlowMonitor *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3FlowMonitor__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowMonitor__tp_richcompare (PyNs3FlowMonitor *PYBINDGEN_UNUSED(self), PyNs3FlowMonitor *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowMonitor_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3FlowMonitor_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.FlowMonitor",            /* tp_name */
    sizeof(PyNs3FlowMonitor),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowMonitor__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3FlowMonitor__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3FlowMonitor__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FlowMonitor__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowMonitor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3FlowMonitor, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowMonitor__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3FlowMonitorFlowStats_wrapper_registry;
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_bytesDropped(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___unsigned_long_long___gt__ *py_std__vector__lt___unsigned_long_long___gt__;
    
    py_std__vector__lt___unsigned_long_long___gt__ = PyObject_New(Pystd__vector__lt___unsigned_long_long___gt__, &Pystd__vector__lt___unsigned_long_long___gt___Type);
    py_std__vector__lt___unsigned_long_long___gt__->obj = new std::vector< unsigned long long >(self->obj->bytesDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_long_long___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_bytesDropped(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_long_long___gt__, &self->obj->bytesDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_delayHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->delayHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_delayHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->delayHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_delaySum(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->delaySum);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_delaySum(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->delaySum = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_flowInterruptionsHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->flowInterruptionsHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_flowInterruptionsHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->flowInterruptionsHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_jitterHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->jitterHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_jitterHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->jitterHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_jitterSum(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->jitterSum);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_jitterSum(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->jitterSum = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_lastDelay(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->lastDelay);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_lastDelay(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->lastDelay = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_lostPackets(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->lostPackets));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_lostPackets(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->lostPackets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_packetSizeHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->packetSizeHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_packetSizeHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->packetSizeHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_packetsDropped(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___unsigned_int___gt__ *py_std__vector__lt___unsigned_int___gt__;
    
    py_std__vector__lt___unsigned_int___gt__ = PyObject_New(Pystd__vector__lt___unsigned_int___gt__, &Pystd__vector__lt___unsigned_int___gt___Type);
    py_std__vector__lt___unsigned_int___gt__->obj = new std::vector< unsigned int >(self->obj->packetsDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_int___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_packetsDropped(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &self->obj->packetsDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_rxBytes(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->rxBytes);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_rxBytes(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->rxBytes)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_rxPackets(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->rxPackets));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_rxPackets(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->rxPackets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstRxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeFirstRxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstRxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeFirstRxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstTxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeFirstTxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstTxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeFirstTxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeLastRxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeLastRxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeLastRxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeLastRxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeLastTxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeLastTxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeLastTxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeLastTxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timesForwarded(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->timesForwarded));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timesForwarded(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->timesForwarded)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_txBytes(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->txBytes);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_txBytes(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->txBytes)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_txPackets(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->txPackets));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_txPackets(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->txPackets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3FlowMonitorFlowStats__getsets[] = {
    {
        (char*) "delayHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_delayHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_delayHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "lostPackets", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_lostPackets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_lostPackets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timesForwarded", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timesForwarded, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timesForwarded, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeLastTxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeLastTxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeLastTxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "rxPackets", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_rxPackets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_rxPackets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packetSizeHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_packetSizeHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_packetSizeHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeFirstTxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstTxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstTxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packetsDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_packetsDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_packetsDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "txPackets", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_txPackets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_txPackets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "flowInterruptionsHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_flowInterruptionsHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_flowInterruptionsHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "bytesDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_bytesDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_bytesDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "txBytes", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_txBytes, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_txBytes, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "jitterHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_jitterHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_jitterHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "rxBytes", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_rxBytes, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_rxBytes, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "delaySum", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_delaySum, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_delaySum, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeLastRxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeLastRxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeLastRxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeFirstRxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstRxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstRxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "jitterSum", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_jitterSum, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_jitterSum, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "lastDelay", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_lastDelay, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_lastDelay, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3FlowMonitorFlowStats__tp_init__0(PyNs3FlowMonitorFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::FlowMonitor::FlowStats();
    return 0;
}

static int
_wrap_PyNs3FlowMonitorFlowStats__tp_init__1(PyNs3FlowMonitorFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FlowMonitorFlowStats *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowMonitorFlowStats_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::FlowMonitor::FlowStats(*((PyNs3FlowMonitorFlowStats *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3FlowMonitorFlowStats__tp_init(PyNs3FlowMonitorFlowStats *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowMonitorFlowStats__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowMonitorFlowStats__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


static PyObject*
_wrap_PyNs3FlowMonitorFlowStats__copy__(PyNs3FlowMonitorFlowStats *self)
{

    PyNs3FlowMonitorFlowStats *py_copy;
    py_copy = PyObject_New(PyNs3FlowMonitorFlowStats, &PyNs3FlowMonitorFlowStats_Type);
    py_copy->obj = new ns3::FlowMonitor::FlowStats(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3FlowMonitorFlowStats_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3FlowMonitorFlowStats_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3FlowMonitorFlowStats__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowMonitorFlowStats__tp_dealloc(PyNs3FlowMonitorFlowStats *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FlowMonitorFlowStats_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FlowMonitorFlowStats_wrapper_registry.end()) {
        PyNs3FlowMonitorFlowStats_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::FlowMonitor::FlowStats *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowMonitorFlowStats__tp_richcompare (PyNs3FlowMonitorFlowStats *PYBINDGEN_UNUSED(self), PyNs3FlowMonitorFlowStats *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowMonitorFlowStats_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3FlowMonitorFlowStats_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.FlowMonitor.FlowStats",            /* tp_name */
    sizeof(PyNs3FlowMonitorFlowStats),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowMonitorFlowStats__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FlowMonitorFlowStats__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowMonitorFlowStats_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3FlowMonitorFlowStats__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowMonitorFlowStats__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};





PyObject *
_wrap_PyNs3FlowProbe_AddPacketStats(PyNs3FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowId;
    unsigned int packetSize;
    PyObject *delayFromFirstProbe;
    ns3::Time delayFromFirstProbe2;
    const char *keywords[] = {"flowId", "packetSize", "delayFromFirstProbe", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IIO", (char **) keywords, &flowId, &packetSize, &delayFromFirstProbe)) {
        return NULL;
    }
    if (PyObject_IsInstance(delayFromFirstProbe, (PyObject*) &PyNs3Time_Type)) {
        delayFromFirstProbe2 = *((PyNs3Time *) delayFromFirstProbe)->obj;
    } else if (PyObject_IsInstance(delayFromFirstProbe, (PyObject*) &PyNs3Scalar_Type)) {
        delayFromFirstProbe2 = *((PyNs3Scalar *) delayFromFirstProbe)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, Scalar), not %s", delayFromFirstProbe->ob_type->tp_name);
        return NULL;
    }
    self->obj->AddPacketStats(flowId, packetSize, delayFromFirstProbe2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowProbe_SerializeToXmlStream(PyNs3FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    int indent;
    unsigned int index;
    const char *keywords[] = {"os", "indent", "index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!iI", (char **) keywords, &PyStdOstream_Type, &os, &indent, &index)) {
        return NULL;
    }
    self->obj->SerializeToXmlStream(*((PyStdOstream *) os)->obj, indent, index);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowProbe_AddPacketDropStats(PyNs3FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowId;
    unsigned int packetSize;
    unsigned int reasonCode;
    const char *keywords[] = {"flowId", "packetSize", "reasonCode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "III", (char **) keywords, &flowId, &packetSize, &reasonCode)) {
        return NULL;
    }
    self->obj->AddPacketDropStats(flowId, packetSize, reasonCode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowProbe_GetStats(PyNs3FlowProbe *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowProbe::FlowStats > retval;
    Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__;
    
    retval = self->obj->GetStats();
    py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ = PyObject_New(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__, &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type);
    py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__->obj = new std::map< unsigned int, ns3::FlowProbe::FlowStats >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__);
    return py_retval;
}

static PyMethodDef PyNs3FlowProbe_methods[] = {
    {(char *) "AddPacketStats", (PyCFunction) _wrap_PyNs3FlowProbe_AddPacketStats, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SerializeToXmlStream", (PyCFunction) _wrap_PyNs3FlowProbe_SerializeToXmlStream, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddPacketDropStats", (PyCFunction) _wrap_PyNs3FlowProbe_AddPacketDropStats, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetStats", (PyCFunction) _wrap_PyNs3FlowProbe_GetStats, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowProbe__tp_dealloc(PyNs3FlowProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::FlowProbe *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowProbe__tp_richcompare (PyNs3FlowProbe *PYBINDGEN_UNUSED(self), PyNs3FlowProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowProbe_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3FlowProbe_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.FlowProbe",            /* tp_name */
    sizeof(PyNs3FlowProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowProbe__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FlowProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3FlowProbeFlowStats_wrapper_registry;
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_bytes(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->bytes);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_bytes(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->bytes)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_bytesDropped(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___unsigned_long_long___gt__ *py_std__vector__lt___unsigned_long_long___gt__;
    
    py_std__vector__lt___unsigned_long_long___gt__ = PyObject_New(Pystd__vector__lt___unsigned_long_long___gt__, &Pystd__vector__lt___unsigned_long_long___gt___Type);
    py_std__vector__lt___unsigned_long_long___gt__->obj = new std::vector< unsigned long long >(self->obj->bytesDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_long_long___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_bytesDropped(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_long_long___gt__, &self->obj->bytesDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_delayFromFirstProbeSum(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->delayFromFirstProbeSum);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_delayFromFirstProbeSum(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->delayFromFirstProbeSum = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_packets(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->packets));
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_packets(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->packets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_packetsDropped(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___unsigned_int___gt__ *py_std__vector__lt___unsigned_int___gt__;
    
    py_std__vector__lt___unsigned_int___gt__ = PyObject_New(Pystd__vector__lt___unsigned_int___gt__, &Pystd__vector__lt___unsigned_int___gt___Type);
    py_std__vector__lt___unsigned_int___gt__->obj = new std::vector< unsigned int >(self->obj->packetsDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_int___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_packetsDropped(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &self->obj->packetsDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3FlowProbeFlowStats__getsets[] = {
    {
        (char*) "bytesDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_bytesDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_bytesDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "delayFromFirstProbeSum", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_delayFromFirstProbeSum, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_delayFromFirstProbeSum, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "bytes", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_bytes, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_bytes, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packets", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_packets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_packets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packetsDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_packetsDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_packetsDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3FlowProbeFlowStats__tp_init__0(PyNs3FlowProbeFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FlowProbeFlowStats *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowProbeFlowStats_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::FlowProbe::FlowStats(*((PyNs3FlowProbeFlowStats *) arg0)->obj);
    return 0;
}

static int
_wrap_PyNs3FlowProbeFlowStats__tp_init__1(PyNs3FlowProbeFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::FlowProbe::FlowStats();
    return 0;
}

int _wrap_PyNs3FlowProbeFlowStats__tp_init(PyNs3FlowProbeFlowStats *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowProbeFlowStats__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowProbeFlowStats__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


static PyObject*
_wrap_PyNs3FlowProbeFlowStats__copy__(PyNs3FlowProbeFlowStats *self)
{

    PyNs3FlowProbeFlowStats *py_copy;
    py_copy = PyObject_New(PyNs3FlowProbeFlowStats, &PyNs3FlowProbeFlowStats_Type);
    py_copy->obj = new ns3::FlowProbe::FlowStats(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3FlowProbeFlowStats_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3FlowProbeFlowStats_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3FlowProbeFlowStats__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowProbeFlowStats__tp_dealloc(PyNs3FlowProbeFlowStats *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FlowProbeFlowStats_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FlowProbeFlowStats_wrapper_registry.end()) {
        PyNs3FlowProbeFlowStats_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::FlowProbe::FlowStats *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowProbeFlowStats__tp_richcompare (PyNs3FlowProbeFlowStats *PYBINDGEN_UNUSED(self), PyNs3FlowProbeFlowStats *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowProbeFlowStats_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3FlowProbeFlowStats_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.FlowProbe.FlowStats",            /* tp_name */
    sizeof(PyNs3FlowProbeFlowStats),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowProbeFlowStats__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FlowProbeFlowStats__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowProbeFlowStats_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3FlowProbeFlowStats__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowProbeFlowStats__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static int
_wrap_PyNs3Ipv4FlowClassifier__tp_init(PyNs3Ipv4FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::Ipv4FlowClassifier();
    return 0;
}


PyObject *
_wrap_PyNs3Ipv4FlowClassifier_SerializeToXmlStream(PyNs3Ipv4FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    int indent;
    const char *keywords[] = {"os", "indent", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyStdOstream_Type, &os, &indent)) {
        return NULL;
    }
    self->obj->SerializeToXmlStream(*((PyStdOstream *) os)->obj, indent);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4FlowClassifier_FindFlow(PyNs3Ipv4FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowId;
    const char *keywords[] = {"flowId", NULL};
    PyNs3Ipv4FlowClassifierFiveTuple *py_FiveTuple;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &flowId)) {
        return NULL;
    }
    ns3::Ipv4FlowClassifier::FiveTuple retval = self->obj->FindFlow(flowId);
    py_FiveTuple = PyObject_New(PyNs3Ipv4FlowClassifierFiveTuple, &PyNs3Ipv4FlowClassifierFiveTuple_Type);
    py_FiveTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_FiveTuple->obj = new ns3::Ipv4FlowClassifier::FiveTuple(retval);
    PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry[(void *) py_FiveTuple->obj] = (PyObject *) py_FiveTuple;
    py_retval = Py_BuildValue((char *) "N", py_FiveTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4FlowClassifier_Classify(PyNs3Ipv4FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Header *ipHeader;
    PyNs3Packet *ipPayload;
    ns3::Packet *ipPayload_ptr;
    uint32_t out_flowId;
    uint32_t out_packetId;
    const char *keywords[] = {"ipHeader", "ipPayload", "out_flowId", "out_packetId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!II", (char **) keywords, &PyNs3Ipv4Header_Type, &ipHeader, &PyNs3Packet_Type, &ipPayload, &out_flowId, &out_packetId)) {
        return NULL;
    }
    ipPayload_ptr = (ipPayload ? ipPayload->obj : NULL);
    retval = self->obj->Classify(*((PyNs3Ipv4Header *) ipHeader)->obj, ns3::Ptr< ns3::Packet  > (ipPayload_ptr), &out_flowId, &out_packetId);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

static PyMethodDef PyNs3Ipv4FlowClassifier_methods[] = {
    {(char *) "SerializeToXmlStream", (PyCFunction) _wrap_PyNs3Ipv4FlowClassifier_SerializeToXmlStream, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindFlow", (PyCFunction) _wrap_PyNs3Ipv4FlowClassifier_FindFlow, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Classify", (PyCFunction) _wrap_PyNs3Ipv4FlowClassifier_Classify, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv4FlowClassifier__tp_dealloc(PyNs3Ipv4FlowClassifier *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::Ipv4FlowClassifier *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4FlowClassifier__tp_richcompare (PyNs3Ipv4FlowClassifier *PYBINDGEN_UNUSED(self), PyNs3Ipv4FlowClassifier *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4FlowClassifier_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3Ipv4FlowClassifier_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4FlowClassifier",            /* tp_name */
    sizeof(PyNs3Ipv4FlowClassifier),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4FlowClassifier__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4FlowClassifier__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4FlowClassifier_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4FlowClassifier__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry;
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->destinationAddress);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destinationAddress = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationPort(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->destinationPort);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationPort(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destinationPort = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_protocol(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->protocol);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_protocol(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->protocol = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourceAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->sourceAddress);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourceAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->sourceAddress = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourcePort(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->sourcePort);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourcePort(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->sourcePort = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3Ipv4FlowClassifierFiveTuple__getsets[] = {
    {
        (char*) "sourcePort", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourcePort, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourcePort, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "sourceAddress", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourceAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourceAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destinationAddress", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "protocol", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_protocol, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_protocol, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destinationPort", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationPort, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationPort, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__0(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4FlowClassifier::FiveTuple();
    return 0;
}

static int
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__1(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4FlowClassifierFiveTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4FlowClassifierFiveTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4FlowClassifier::FiveTuple(*((PyNs3Ipv4FlowClassifierFiveTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


static PyObject*
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__copy__(PyNs3Ipv4FlowClassifierFiveTuple *self)
{

    PyNs3Ipv4FlowClassifierFiveTuple *py_copy;
    py_copy = PyObject_New(PyNs3Ipv4FlowClassifierFiveTuple, &PyNs3Ipv4FlowClassifierFiveTuple_Type);
    py_copy->obj = new ns3::Ipv4FlowClassifier::FiveTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv4FlowClassifierFiveTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_dealloc(PyNs3Ipv4FlowClassifierFiveTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry.end()) {
        PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ipv4FlowClassifier::FiveTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_richcompare (PyNs3Ipv4FlowClassifierFiveTuple *PYBINDGEN_UNUSED(self), PyNs3Ipv4FlowClassifierFiveTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4FlowClassifierFiveTuple_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        if (*self->obj < *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        if (*self->obj == *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3Ipv4FlowClassifierFiveTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4FlowClassifier.FiveTuple",            /* tp_name */
    sizeof(PyNs3Ipv4FlowClassifierFiveTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4FlowClassifierFiveTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Ipv4FlowClassifierFiveTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static int
_wrap_PyNs3Ipv4FlowProbe__tp_init(PyNs3Ipv4FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyNs3FlowMonitor *monitor;
    ns3::FlowMonitor *monitor_ptr;
    PyNs3Ipv4FlowClassifier *classifier;
    ns3::Ipv4FlowClassifier *classifier_ptr;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"monitor", "classifier", "node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!", (char **) keywords, &PyNs3FlowMonitor_Type, &monitor, &PyNs3Ipv4FlowClassifier_Type, &classifier, &PyNs3Node_Type, &node)) {
        return -1;
    }
    monitor_ptr = (monitor ? monitor->obj : NULL);
    classifier_ptr = (classifier ? classifier->obj : NULL);
    node_ptr = (node ? node->obj : NULL);
    self->obj = new ns3::Ipv4FlowProbe(ns3::Ptr< ns3::FlowMonitor  > (monitor_ptr), ns3::Ptr< ns3::Ipv4FlowClassifier  > (classifier_ptr), ns3::Ptr< ns3::Node  > (node_ptr));
    return 0;
}

static PyMethodDef PyNs3Ipv4FlowProbe_methods[] = {
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv4FlowProbe__tp_dealloc(PyNs3Ipv4FlowProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::Ipv4FlowProbe *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4FlowProbe__tp_richcompare (PyNs3Ipv4FlowProbe *PYBINDGEN_UNUSED(self), PyNs3Ipv4FlowProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4FlowProbe_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3Ipv4FlowProbe_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4FlowProbe",            /* tp_name */
    sizeof(PyNs3Ipv4FlowProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4FlowProbe__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4FlowProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4FlowProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4FlowProbe__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static void
Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_clear(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_traverse(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *self)
{
    Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *iter = PyObject_GC_New(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter, &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::map< unsigned int, ns3::FlowMonitor::FlowStats >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iternext(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowMonitor::FlowStats >::iterator iter;
    PyNs3FlowMonitorFlowStats *py_FlowStats;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_FlowStats = PyObject_New(PyNs3FlowMonitorFlowStats, &PyNs3FlowMonitorFlowStats_Type);
    py_FlowStats->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_FlowStats->obj = new ns3::FlowMonitor::FlowStats(iter->second);
    PyNs3FlowMonitorFlowStats_wrapper_registry[(void *) py_FlowStats->obj] = (PyObject *) py_FlowStats;
    py_retval = Py_BuildValue((char *) "NN", PyLong_FromUnsignedLong(iter->first), py_FlowStats);
    return py_retval;
}

int _wrap_convert_py2c__ns3__FlowMonitor__FlowStats(PyObject *value, ns3::FlowMonitor::FlowStats *address)
{
    PyObject *py_retval;
    PyNs3FlowMonitorFlowStats *tmp_FlowStats;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3FlowMonitorFlowStats_Type, &tmp_FlowStats)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_FlowStats->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__(PyObject *arg, std::map< unsigned int, ns3::FlowMonitor::FlowStats > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type)) {
        *container = *((Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *tup = PyList_GET_ITEM(arg, i);
            if (!PyTuple_Check(tup) || PyTuple_Size(tup) != 2) {
                PyErr_SetString(PyExc_TypeError, "items must be tuples with two elements");
                return 0;
            }
            std::pair<unsigned int, ns3::FlowMonitor::FlowStats> item;
            if (!_wrap_convert_py2c__unsigned_int(PyTuple_GET_ITEM(tup, 0), &item.first)) {
                return 0;
            }
            if (!_wrap_convert_py2c__ns3__FlowMonitor__FlowStats(PyTuple_GET_ITEM(tup, 1), &item.second)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ instance, or a list of ns3::FlowMonitor::FlowStats");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_init(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::map< unsigned int, ns3::FlowMonitor::FlowStats >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static void
Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_clear(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_traverse(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *self)
{
    Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *iter = PyObject_GC_New(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter, &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::map< unsigned int, ns3::FlowProbe::FlowStats >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iternext(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowProbe::FlowStats >::iterator iter;
    PyNs3FlowProbeFlowStats *py_FlowStats;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_FlowStats = PyObject_New(PyNs3FlowProbeFlowStats, &PyNs3FlowProbeFlowStats_Type);
    py_FlowStats->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_FlowStats->obj = new ns3::FlowProbe::FlowStats(iter->second);
    PyNs3FlowProbeFlowStats_wrapper_registry[(void *) py_FlowStats->obj] = (PyObject *) py_FlowStats;
    py_retval = Py_BuildValue((char *) "NN", PyLong_FromUnsignedLong(iter->first), py_FlowStats);
    return py_retval;
}

int _wrap_convert_py2c__ns3__FlowProbe__FlowStats(PyObject *value, ns3::FlowProbe::FlowStats *address)
{
    PyObject *py_retval;
    PyNs3FlowProbeFlowStats *tmp_FlowStats;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3FlowProbeFlowStats_Type, &tmp_FlowStats)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_FlowStats->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__(PyObject *arg, std::map< unsigned int, ns3::FlowProbe::FlowStats > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type)) {
        *container = *((Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *tup = PyList_GET_ITEM(arg, i);
            if (!PyTuple_Check(tup) || PyTuple_Size(tup) != 2) {
                PyErr_SetString(PyExc_TypeError, "items must be tuples with two elements");
                return 0;
            }
            std::pair<unsigned int, ns3::FlowProbe::FlowStats> item;
            if (!_wrap_convert_py2c__unsigned_int(PyTuple_GET_ITEM(tup, 0), &item.first)) {
                return 0;
            }
            if (!_wrap_convert_py2c__ns3__FlowProbe__FlowStats(PyTuple_GET_ITEM(tup, 1), &item.second)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ instance, or a list of ns3::FlowProbe::FlowStats");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_init(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::map< unsigned int, ns3::FlowProbe::FlowStats >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




