#include "ns3module.h"

PyObject *
_wrap_ns3_olsrSecondsToEmf(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint8_t retval;
    double seconds;
    const char *keywords[] = {"seconds", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &seconds)) {
        return NULL;
    }
    retval = ns3::olsr::SecondsToEmf(seconds);
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_ns3_olsrEmfToSeconds(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    int emf;
    const char *keywords[] = {"emf", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &emf)) {
        return NULL;
    }
    if (emf > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    retval = ns3::olsr::EmfToSeconds(emf);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


std::map<void*, PyObject*> PyNs3OlsrAssociation_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrAssociation__get_netmask(PyNs3OlsrAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(self->obj->netmask);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociation__set_netmask(PyNs3OlsrAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *tmp_Ipv4Mask;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Mask_Type, &tmp_Ipv4Mask)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->netmask = *tmp_Ipv4Mask->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociation__get_networkAddr(PyNs3OlsrAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->networkAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociation__set_networkAddr(PyNs3OlsrAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->networkAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrAssociation__getsets[] = {
    {
        (char*) "netmask", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociation__get_netmask, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociation__set_netmask, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "networkAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociation__get_networkAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociation__set_networkAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrAssociation__tp_init__0(PyNs3OlsrAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::Association();
    return 0;
}

static int
_wrap_PyNs3OlsrAssociation__tp_init__1(PyNs3OlsrAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrAssociation *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociation_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::Association(*((PyNs3OlsrAssociation *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrAssociation__tp_init(PyNs3OlsrAssociation *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrAssociation__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrAssociation__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrAssociation__copy__(PyNs3OlsrAssociation *self)
{

    PyNs3OlsrAssociation *py_copy;
    py_copy = PyObject_New(PyNs3OlsrAssociation, &PyNs3OlsrAssociation_Type);
    py_copy->obj = new ns3::olsr::Association(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrAssociation_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrAssociation_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrAssociation__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrAssociation__tp_dealloc(PyNs3OlsrAssociation *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrAssociation_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrAssociation_wrapper_registry.end()) {
        PyNs3OlsrAssociation_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::Association *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrAssociation__tp_str(PyNs3OlsrAssociation *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrAssociation__tp_richcompare (PyNs3OlsrAssociation *PYBINDGEN_UNUSED(self), PyNs3OlsrAssociation *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrAssociation_Type)) {
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

PyTypeObject PyNs3OlsrAssociation_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.Association",            /* tp_name */
    sizeof(PyNs3OlsrAssociation),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrAssociation__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrAssociation__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrAssociation__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrAssociation_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrAssociation__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrAssociation__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrAssociationTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_expirationTime(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_expirationTime(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_gatewayAddr(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->gatewayAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_gatewayAddr(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->gatewayAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_netmask(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(self->obj->netmask);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_netmask(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *tmp_Ipv4Mask;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Mask_Type, &tmp_Ipv4Mask)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->netmask = *tmp_Ipv4Mask->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_networkAddr(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->networkAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_networkAddr(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->networkAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrAssociationTuple__getsets[] = {
    {
        (char*) "networkAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_networkAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_networkAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "gatewayAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_gatewayAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_gatewayAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "netmask", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_netmask, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_netmask, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrAssociationTuple__tp_init__0(PyNs3OlsrAssociationTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::AssociationTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrAssociationTuple__tp_init__1(PyNs3OlsrAssociationTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrAssociationTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociationTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::AssociationTuple(*((PyNs3OlsrAssociationTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrAssociationTuple__tp_init(PyNs3OlsrAssociationTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrAssociationTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrAssociationTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrAssociationTuple__copy__(PyNs3OlsrAssociationTuple *self)
{

    PyNs3OlsrAssociationTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrAssociationTuple, &PyNs3OlsrAssociationTuple_Type);
    py_copy->obj = new ns3::olsr::AssociationTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrAssociationTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrAssociationTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrAssociationTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrAssociationTuple__tp_dealloc(PyNs3OlsrAssociationTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrAssociationTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrAssociationTuple_wrapper_registry.end()) {
        PyNs3OlsrAssociationTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::AssociationTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrAssociationTuple__tp_str(PyNs3OlsrAssociationTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrAssociationTuple__tp_richcompare (PyNs3OlsrAssociationTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrAssociationTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrAssociationTuple_Type)) {
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

PyTypeObject PyNs3OlsrAssociationTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.AssociationTuple",            /* tp_name */
    sizeof(PyNs3OlsrAssociationTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrAssociationTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrAssociationTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrAssociationTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrAssociationTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrAssociationTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrAssociationTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrDuplicateTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_address(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->address);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_address(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->address = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_expirationTime(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_expirationTime(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_ifaceList(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->ifaceList);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_ifaceList(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->ifaceList)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_retransmitted(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(self->obj->retransmitted));
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_retransmitted(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyObject *py_boolretval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->retransmitted = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_sequenceNumber(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->sequenceNumber);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_sequenceNumber(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->sequenceNumber = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrDuplicateTuple__getsets[] = {
    {
        (char*) "retransmitted", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_retransmitted, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_retransmitted, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "ifaceList", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_ifaceList, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_ifaceList, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "sequenceNumber", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_sequenceNumber, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_sequenceNumber, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "address", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_address, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_address, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrDuplicateTuple__tp_init__0(PyNs3OlsrDuplicateTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::DuplicateTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrDuplicateTuple__tp_init__1(PyNs3OlsrDuplicateTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrDuplicateTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrDuplicateTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::DuplicateTuple(*((PyNs3OlsrDuplicateTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrDuplicateTuple__tp_init(PyNs3OlsrDuplicateTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrDuplicateTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrDuplicateTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrDuplicateTuple__copy__(PyNs3OlsrDuplicateTuple *self)
{

    PyNs3OlsrDuplicateTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrDuplicateTuple, &PyNs3OlsrDuplicateTuple_Type);
    py_copy->obj = new ns3::olsr::DuplicateTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrDuplicateTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrDuplicateTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrDuplicateTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrDuplicateTuple__tp_dealloc(PyNs3OlsrDuplicateTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrDuplicateTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrDuplicateTuple_wrapper_registry.end()) {
        PyNs3OlsrDuplicateTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::DuplicateTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrDuplicateTuple__tp_richcompare (PyNs3OlsrDuplicateTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrDuplicateTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrDuplicateTuple_Type)) {
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

PyTypeObject PyNs3OlsrDuplicateTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.DuplicateTuple",            /* tp_name */
    sizeof(PyNs3OlsrDuplicateTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrDuplicateTuple__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrDuplicateTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrDuplicateTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrDuplicateTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrDuplicateTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrIfaceAssocTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrIfaceAssocTuple__get_ifaceAddr(PyNs3OlsrIfaceAssocTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->ifaceAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrIfaceAssocTuple__set_ifaceAddr(PyNs3OlsrIfaceAssocTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->ifaceAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrIfaceAssocTuple__get_mainAddr(PyNs3OlsrIfaceAssocTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->mainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrIfaceAssocTuple__set_mainAddr(PyNs3OlsrIfaceAssocTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->mainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrIfaceAssocTuple__get_time(PyNs3OlsrIfaceAssocTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->time);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrIfaceAssocTuple__set_time(PyNs3OlsrIfaceAssocTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->time = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrIfaceAssocTuple__getsets[] = {
    {
        (char*) "ifaceAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrIfaceAssocTuple__get_ifaceAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrIfaceAssocTuple__set_ifaceAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "mainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrIfaceAssocTuple__get_mainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrIfaceAssocTuple__set_mainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "time", /* attribute name */
        (getter) _wrap_PyNs3OlsrIfaceAssocTuple__get_time, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrIfaceAssocTuple__set_time, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrIfaceAssocTuple__tp_init__0(PyNs3OlsrIfaceAssocTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::IfaceAssocTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrIfaceAssocTuple__tp_init__1(PyNs3OlsrIfaceAssocTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrIfaceAssocTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrIfaceAssocTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::IfaceAssocTuple(*((PyNs3OlsrIfaceAssocTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrIfaceAssocTuple__tp_init(PyNs3OlsrIfaceAssocTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrIfaceAssocTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrIfaceAssocTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrIfaceAssocTuple__copy__(PyNs3OlsrIfaceAssocTuple *self)
{

    PyNs3OlsrIfaceAssocTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrIfaceAssocTuple, &PyNs3OlsrIfaceAssocTuple_Type);
    py_copy->obj = new ns3::olsr::IfaceAssocTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrIfaceAssocTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrIfaceAssocTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrIfaceAssocTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrIfaceAssocTuple__tp_dealloc(PyNs3OlsrIfaceAssocTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrIfaceAssocTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrIfaceAssocTuple_wrapper_registry.end()) {
        PyNs3OlsrIfaceAssocTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::IfaceAssocTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrIfaceAssocTuple__tp_str(PyNs3OlsrIfaceAssocTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrIfaceAssocTuple__tp_richcompare (PyNs3OlsrIfaceAssocTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrIfaceAssocTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrIfaceAssocTuple_Type)) {
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

PyTypeObject PyNs3OlsrIfaceAssocTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.IfaceAssocTuple",            /* tp_name */
    sizeof(PyNs3OlsrIfaceAssocTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrIfaceAssocTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrIfaceAssocTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrIfaceAssocTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrIfaceAssocTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrIfaceAssocTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrIfaceAssocTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrLinkTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_asymTime(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->asymTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_asymTime(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->asymTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_localIfaceAddr(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->localIfaceAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_localIfaceAddr(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->localIfaceAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_neighborIfaceAddr(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->neighborIfaceAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_neighborIfaceAddr(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->neighborIfaceAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_symTime(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->symTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_symTime(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->symTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_time(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->time);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_time(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->time = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrLinkTuple__getsets[] = {
    {
        (char*) "neighborIfaceAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_neighborIfaceAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_neighborIfaceAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "asymTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_asymTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_asymTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "symTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_symTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_symTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "localIfaceAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_localIfaceAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_localIfaceAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "time", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_time, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_time, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrLinkTuple__tp_init__0(PyNs3OlsrLinkTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::LinkTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrLinkTuple__tp_init__1(PyNs3OlsrLinkTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrLinkTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrLinkTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::LinkTuple(*((PyNs3OlsrLinkTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrLinkTuple__tp_init(PyNs3OlsrLinkTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrLinkTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrLinkTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrLinkTuple__copy__(PyNs3OlsrLinkTuple *self)
{

    PyNs3OlsrLinkTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrLinkTuple, &PyNs3OlsrLinkTuple_Type);
    py_copy->obj = new ns3::olsr::LinkTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrLinkTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrLinkTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrLinkTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrLinkTuple__tp_dealloc(PyNs3OlsrLinkTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrLinkTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrLinkTuple_wrapper_registry.end()) {
        PyNs3OlsrLinkTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::LinkTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrLinkTuple__tp_str(PyNs3OlsrLinkTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrLinkTuple__tp_richcompare (PyNs3OlsrLinkTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrLinkTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrLinkTuple_Type)) {
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

PyTypeObject PyNs3OlsrLinkTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.LinkTuple",            /* tp_name */
    sizeof(PyNs3OlsrLinkTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrLinkTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrLinkTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrLinkTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrLinkTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrLinkTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrLinkTuple__tp_init,             /* tp_init */
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
PyNs3OlsrMessageHeader__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    PyNs3OlsrMessageHeader__PythonHelper *helper = dynamic_cast< PyNs3OlsrMessageHeader__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

uint32_t
PyNs3OlsrMessageHeader__PythonHelper::Deserialize(ns3::Buffer::Iterator start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::MessageHeader *self_obj_before;
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *py_Iterator;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Deserialize"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::Deserialize(start);
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = (ns3::olsr::MessageHeader*) this;
    py_Iterator = PyObject_New(PyNs3BufferIterator, &PyNs3BufferIterator_Type);
    py_Iterator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Iterator->obj = new ns3::Buffer::Iterator(start);
    PyNs3BufferIterator_wrapper_registry[(void *) py_Iterator->obj] = (PyObject *) py_Iterator;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Deserialize", (char *) "N", py_Iterator);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::Deserialize(start);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::Deserialize(start);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3OlsrMessageHeader__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::MessageHeader *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = const_cast< ns3::olsr::MessageHeader* >((const ns3::olsr::MessageHeader*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

uint32_t
PyNs3OlsrMessageHeader__PythonHelper::GetSerializedSize() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::MessageHeader *self_obj_before;
    PyObject *py_retval;
    uint32_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetSerializedSize"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::GetSerializedSize();
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = const_cast< ns3::olsr::MessageHeader* >((const ns3::olsr::MessageHeader*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetSerializedSize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::GetSerializedSize();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::MessageHeader::GetSerializedSize();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}


void
PyNs3OlsrMessageHeader__PythonHelper::Serialize(ns3::Buffer::Iterator start) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::MessageHeader *self_obj_before;
    PyObject *py_retval;
    PyNs3BufferIterator *py_Iterator;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Serialize"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::olsr::MessageHeader::Serialize(start);
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = const_cast< ns3::olsr::MessageHeader* >((const ns3::olsr::MessageHeader*) this);
    py_Iterator = PyObject_New(PyNs3BufferIterator, &PyNs3BufferIterator_Type);
    py_Iterator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Iterator->obj = new ns3::Buffer::Iterator(start);
    PyNs3BufferIterator_wrapper_registry[(void *) py_Iterator->obj] = (PyObject *) py_Iterator;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Serialize", (char *) "N", py_Iterator);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrMessageHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrMessageHeader__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3OlsrMessageHeader__tp_init__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (self->ob_type != &PyNs3OlsrMessageHeader_Type)
    {
        self->obj = new PyNs3OlsrMessageHeader__PythonHelper(*((PyNs3OlsrMessageHeader *) arg0)->obj);
        ((PyNs3OlsrMessageHeader__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::olsr::MessageHeader(*((PyNs3OlsrMessageHeader *) arg0)->obj);
    }
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeader__tp_init__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (self->ob_type != &PyNs3OlsrMessageHeader_Type)
    {
        self->obj = new PyNs3OlsrMessageHeader__PythonHelper();
        ((PyNs3OlsrMessageHeader__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::olsr::MessageHeader();
    }
    return 0;
}

int _wrap_PyNs3OlsrMessageHeader__tp_init(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_SetVTime(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
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
    self->obj->SetVTime(time2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::olsr::MessageHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetMessageType(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::MessageHeader::MessageType messageType;
    const char *keywords[] = {"messageType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &messageType)) {
        return NULL;
    }
    self->obj->SetMessageType(messageType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetMessageSequenceNumber(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int messageSequenceNumber;
    const char *keywords[] = {"messageSequenceNumber", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &messageSequenceNumber)) {
        return NULL;
    }
    if (messageSequenceNumber > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMessageSequenceNumber(messageSequenceNumber);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_Print(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    PyNs3OlsrMessageHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrMessageHeader__PythonHelper*> (self->obj);
    const char *keywords[] = {"os", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyStdOstream_Type, &os)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Print(*((PyStdOstream *) os)->obj)) : (self->obj->ns3::olsr::MessageHeader::Print(*((PyStdOstream *) os)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHopCount(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetHopCount();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetMessageSequenceNumber(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetMessageSequenceNumber();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetOriginatorAddress(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *originatorAddress;
    const char *keywords[] = {"originatorAddress", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &originatorAddress)) {
        return NULL;
    }
    self->obj->SetOriginatorAddress(*((PyNs3Ipv4Address *) originatorAddress)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3OlsrMessageHeader_GetMid__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderMid *py_Mid;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Mid & retval = self->obj->GetMid();
    py_Mid = PyObject_New(PyNs3OlsrMessageHeaderMid, &PyNs3OlsrMessageHeaderMid_Type);
    py_Mid->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mid->obj = new ns3::olsr::MessageHeader::Mid(retval);
    PyNs3OlsrMessageHeaderMid_wrapper_registry[(void *) py_Mid->obj] = (PyObject *) py_Mid;
    py_retval = Py_BuildValue((char *) "N", py_Mid);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetMid__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderMid *py_Mid;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Mid const & retval = self->obj->GetMid();
    py_Mid = PyObject_New(PyNs3OlsrMessageHeaderMid, &PyNs3OlsrMessageHeaderMid_Type);
    py_Mid->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mid->obj = new ns3::olsr::MessageHeader::Mid(retval);
    PyNs3OlsrMessageHeaderMid_wrapper_registry[(void *) py_Mid->obj] = (PyObject *) py_Mid;
    py_retval = Py_BuildValue((char *) "N", py_Mid);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetMid(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetMid__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetMid__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetVTime(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetVTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_Deserialize(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    PyNs3OlsrMessageHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrMessageHeader__PythonHelper*> (self->obj);
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj)) : (self->obj->ns3::olsr::MessageHeader::Deserialize(*((PyNs3BufferIterator *) start)->obj));
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}



PyObject *
_wrap_PyNs3OlsrMessageHeader_GetTc__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderTc *py_Tc;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Tc & retval = self->obj->GetTc();
    py_Tc = PyObject_New(PyNs3OlsrMessageHeaderTc, &PyNs3OlsrMessageHeaderTc_Type);
    py_Tc->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Tc->obj = new ns3::olsr::MessageHeader::Tc(retval);
    PyNs3OlsrMessageHeaderTc_wrapper_registry[(void *) py_Tc->obj] = (PyObject *) py_Tc;
    py_retval = Py_BuildValue((char *) "N", py_Tc);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetTc__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderTc *py_Tc;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Tc const & retval = self->obj->GetTc();
    py_Tc = PyObject_New(PyNs3OlsrMessageHeaderTc, &PyNs3OlsrMessageHeaderTc_Type);
    py_Tc->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Tc->obj = new ns3::olsr::MessageHeader::Tc(retval);
    PyNs3OlsrMessageHeaderTc_wrapper_registry[(void *) py_Tc->obj] = (PyObject *) py_Tc;
    py_retval = Py_BuildValue((char *) "N", py_Tc);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetTc(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetTc__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetTc__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetInstanceTypeId(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    PyNs3OlsrMessageHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrMessageHeader__PythonHelper*> (self->obj);
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = (helper_class == NULL)? (self->obj->GetInstanceTypeId()) : (self->obj->ns3::olsr::MessageHeader::GetInstanceTypeId());
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetSerializedSize(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3OlsrMessageHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrMessageHeader__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetSerializedSize()) : (self->obj->ns3::olsr::MessageHeader::GetSerializedSize());
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetHopCount(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int hopCount;
    const char *keywords[] = {"hopCount", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &hopCount)) {
        return NULL;
    }
    if (hopCount > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetHopCount(hopCount);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHna__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHna *py_Hna;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hna & retval = self->obj->GetHna();
    py_Hna = PyObject_New(PyNs3OlsrMessageHeaderHna, &PyNs3OlsrMessageHeaderHna_Type);
    py_Hna->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hna->obj = new ns3::olsr::MessageHeader::Hna(retval);
    PyNs3OlsrMessageHeaderHna_wrapper_registry[(void *) py_Hna->obj] = (PyObject *) py_Hna;
    py_retval = Py_BuildValue((char *) "N", py_Hna);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHna__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHna *py_Hna;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hna const & retval = self->obj->GetHna();
    py_Hna = PyObject_New(PyNs3OlsrMessageHeaderHna, &PyNs3OlsrMessageHeaderHna_Type);
    py_Hna->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hna->obj = new ns3::olsr::MessageHeader::Hna(retval);
    PyNs3OlsrMessageHeaderHna_wrapper_registry[(void *) py_Hna->obj] = (PyObject *) py_Hna;
    py_retval = Py_BuildValue((char *) "N", py_Hna);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetHna(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetHna__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetHna__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetHello__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHello *py_Hello;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hello & retval = self->obj->GetHello();
    py_Hello = PyObject_New(PyNs3OlsrMessageHeaderHello, &PyNs3OlsrMessageHeaderHello_Type);
    py_Hello->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hello->obj = new ns3::olsr::MessageHeader::Hello(retval);
    PyNs3OlsrMessageHeaderHello_wrapper_registry[(void *) py_Hello->obj] = (PyObject *) py_Hello;
    py_retval = Py_BuildValue((char *) "N", py_Hello);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHello__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHello *py_Hello;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hello const & retval = self->obj->GetHello();
    py_Hello = PyObject_New(PyNs3OlsrMessageHeaderHello, &PyNs3OlsrMessageHeaderHello_Type);
    py_Hello->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hello->obj = new ns3::olsr::MessageHeader::Hello(retval);
    PyNs3OlsrMessageHeaderHello_wrapper_registry[(void *) py_Hello->obj] = (PyObject *) py_Hello;
    py_retval = Py_BuildValue((char *) "N", py_Hello);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetHello(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetHello__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetHello__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetOriginatorAddress(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetOriginatorAddress();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_Serialize(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *start;
    PyNs3OlsrMessageHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrMessageHeader__PythonHelper*> (self->obj);
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Serialize(*((PyNs3BufferIterator *) start)->obj)) : (self->obj->ns3::olsr::MessageHeader::Serialize(*((PyNs3BufferIterator *) start)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetTimeToLive(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetTimeToLive();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetTimeToLive(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int timeToLive;
    const char *keywords[] = {"timeToLive", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &timeToLive)) {
        return NULL;
    }
    if (timeToLive > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetTimeToLive(timeToLive);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetMessageType(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    ns3::olsr::MessageHeader::MessageType retval;
    
    retval = self->obj->GetMessageType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeader__copy__(PyNs3OlsrMessageHeader *self)
{

    PyNs3OlsrMessageHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3OlsrMessageHeader, &PyNs3OlsrMessageHeader_Type);
    py_copy->obj = new ns3::olsr::MessageHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeader_methods[] = {
    {(char *) "SetVTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetVTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetMessageType", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetMessageType, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMessageSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetMessageSequenceNumber, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHopCount", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetHopCount, METH_NOARGS, NULL },
    {(char *) "GetMessageSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetMessageSequenceNumber, METH_NOARGS, NULL },
    {(char *) "SetOriginatorAddress", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetOriginatorAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMid", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetMid, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetVTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetVTime, METH_NOARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTc", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetTc, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetHopCount", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetHopCount, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHna", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetHna, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHello", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetHello, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetOriginatorAddress", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetOriginatorAddress, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTimeToLive", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetTimeToLive, METH_NOARGS, NULL },
    {(char *) "SetTimeToLive", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetTimeToLive, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMessageType", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetMessageType, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3OlsrMessageHeader__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrMessageHeader__tp_clear(PyNs3OlsrMessageHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::olsr::MessageHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3OlsrMessageHeader__tp_traverse(PyNs3OlsrMessageHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj) == typeid(PyNs3OlsrMessageHeader__PythonHelper) )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3OlsrMessageHeader__tp_dealloc(PyNs3OlsrMessageHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrMessageHeader__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrMessageHeader__tp_str(PyNs3OlsrMessageHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrMessageHeader__tp_richcompare (PyNs3OlsrMessageHeader *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeader_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeader_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MessageHeader",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrMessageHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3OlsrMessageHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrMessageHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrMessageHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeader__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHello_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHello__get_hTime(PyNs3OlsrMessageHeaderHello *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->hTime);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHello__set_hTime(PyNs3OlsrMessageHeaderHello *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->hTime = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHello__get_linkMessages(PyNs3OlsrMessageHeaderHello *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__;
    
    py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ = PyObject_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type);
    py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__->obj = new std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >(self->obj->linkMessages);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHello__set_linkMessages(PyNs3OlsrMessageHeaderHello *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__, &self->obj->linkMessages)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHello__get_willingness(PyNs3OlsrMessageHeaderHello *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->willingness);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHello__set_willingness(PyNs3OlsrMessageHeaderHello *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->willingness = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHello__getsets[] = {
    {
        (char*) "linkMessages", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHello__get_linkMessages, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHello__set_linkMessages, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "willingness", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHello__get_willingness, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHello__set_willingness, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "hTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHello__get_hTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHello__set_hTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHello__tp_init__0(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hello();
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHello__tp_init__1(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHello *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHello_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hello(*((PyNs3OlsrMessageHeaderHello *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHello__tp_init(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHello__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHello__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHello_Deserialize(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_GetHTime(PyNs3OlsrMessageHeaderHello *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetHTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_Serialize(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *start;
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    self->obj->Serialize(*((PyNs3BufferIterator *) start)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_Print(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    const char *keywords[] = {"os", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyStdOstream_Type, &os)) {
        return NULL;
    }
    self->obj->Print(*((PyStdOstream *) os)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_SetHTime(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
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
    self->obj->SetHTime(time2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_GetSerializedSize(PyNs3OlsrMessageHeaderHello *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderHello__copy__(PyNs3OlsrMessageHeaderHello *self)
{

    PyNs3OlsrMessageHeaderHello *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHello, &PyNs3OlsrMessageHeaderHello_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hello(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHello_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHello_methods[] = {
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_GetHTime, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_SetHTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHello__tp_dealloc(PyNs3OlsrMessageHeaderHello *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHello_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHello_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHello_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hello *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHello__tp_richcompare (PyNs3OlsrMessageHeaderHello *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHello *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHello_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHello_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MessageHeader.Hello",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHello),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHello__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHello__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHello_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHello__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHello__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_linkCode(PyNs3OlsrMessageHeaderHelloLinkMessage *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->linkCode);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_linkCode(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->linkCode = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_neighborInterfaceAddresses(PyNs3OlsrMessageHeaderHelloLinkMessage *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->neighborInterfaceAddresses);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_neighborInterfaceAddresses(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->neighborInterfaceAddresses)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHelloLinkMessage__getsets[] = {
    {
        (char*) "neighborInterfaceAddresses", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_neighborInterfaceAddresses, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_neighborInterfaceAddresses, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "linkCode", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_linkCode, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_linkCode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__0(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage();
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__1(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHelloLinkMessage *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHelloLinkMessage_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage(*((PyNs3OlsrMessageHeaderHelloLinkMessage *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__copy__(PyNs3OlsrMessageHeaderHelloLinkMessage *self)
{

    PyNs3OlsrMessageHeaderHelloLinkMessage *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHelloLinkMessage, &PyNs3OlsrMessageHeaderHelloLinkMessage_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHelloLinkMessage_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_dealloc(PyNs3OlsrMessageHeaderHelloLinkMessage *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hello::LinkMessage *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_richcompare (PyNs3OlsrMessageHeaderHelloLinkMessage *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHelloLinkMessage *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHelloLinkMessage_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHelloLinkMessage_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MessageHeader.Hello.LinkMessage",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHelloLinkMessage),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHelloLinkMessage_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHelloLinkMessage__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHna_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHna__get_associations(PyNs3OlsrMessageHeaderHna *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__;
    
    py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ = PyObject_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type);
    py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__->obj = new std::vector< ns3::olsr::MessageHeader::Hna::Association >(self->obj->associations);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHna__set_associations(PyNs3OlsrMessageHeaderHna *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__, &self->obj->associations)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHna__getsets[] = {
    {
        (char*) "associations", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHna__get_associations, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHna__set_associations, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHna__tp_init__0(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hna();
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHna__tp_init__1(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHna *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHna_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hna(*((PyNs3OlsrMessageHeaderHna *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHna__tp_init(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHna__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHna__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHna_GetSerializedSize(PyNs3OlsrMessageHeaderHna *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHna_Print(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    const char *keywords[] = {"os", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyStdOstream_Type, &os)) {
        return NULL;
    }
    self->obj->Print(*((PyStdOstream *) os)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHna_Serialize(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *start;
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    self->obj->Serialize(*((PyNs3BufferIterator *) start)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHna_Deserialize(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderHna__copy__(PyNs3OlsrMessageHeaderHna *self)
{

    PyNs3OlsrMessageHeaderHna *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHna, &PyNs3OlsrMessageHeaderHna_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hna(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHna_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHna_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHna__tp_dealloc(PyNs3OlsrMessageHeaderHna *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHna_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHna_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHna_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hna *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHna__tp_richcompare (PyNs3OlsrMessageHeaderHna *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHna *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHna_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHna_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MessageHeader.Hna",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHna),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHna__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHna__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHna_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHna__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHna__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_address(PyNs3OlsrMessageHeaderHnaAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->address);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_address(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->address = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_mask(PyNs3OlsrMessageHeaderHnaAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(self->obj->mask);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_mask(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *tmp_Ipv4Mask;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Mask_Type, &tmp_Ipv4Mask)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->mask = *tmp_Ipv4Mask->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHnaAssociation__getsets[] = {
    {
        (char*) "mask", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_mask, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_mask, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "address", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_address, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_address, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__0(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hna::Association();
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__1(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHnaAssociation *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHnaAssociation_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hna::Association(*((PyNs3OlsrMessageHeaderHnaAssociation *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__copy__(PyNs3OlsrMessageHeaderHnaAssociation *self)
{

    PyNs3OlsrMessageHeaderHnaAssociation *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHnaAssociation, &PyNs3OlsrMessageHeaderHnaAssociation_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hna::Association(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHnaAssociation_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_dealloc(PyNs3OlsrMessageHeaderHnaAssociation *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hna::Association *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_richcompare (PyNs3OlsrMessageHeaderHnaAssociation *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHnaAssociation *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHnaAssociation_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHnaAssociation_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MessageHeader.Hna.Association",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHnaAssociation),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHnaAssociation_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHnaAssociation__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderMid_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderMid__get_interfaceAddresses(PyNs3OlsrMessageHeaderMid *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->interfaceAddresses);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderMid__set_interfaceAddresses(PyNs3OlsrMessageHeaderMid *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->interfaceAddresses)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderMid__getsets[] = {
    {
        (char*) "interfaceAddresses", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderMid__get_interfaceAddresses, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderMid__set_interfaceAddresses, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderMid__tp_init__0(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Mid();
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderMid__tp_init__1(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderMid *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderMid_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Mid(*((PyNs3OlsrMessageHeaderMid *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderMid__tp_init(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderMid__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderMid__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderMid_GetSerializedSize(PyNs3OlsrMessageHeaderMid *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderMid_Print(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    const char *keywords[] = {"os", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyStdOstream_Type, &os)) {
        return NULL;
    }
    self->obj->Print(*((PyStdOstream *) os)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderMid_Serialize(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *start;
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    self->obj->Serialize(*((PyNs3BufferIterator *) start)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderMid_Deserialize(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderMid__copy__(PyNs3OlsrMessageHeaderMid *self)
{

    PyNs3OlsrMessageHeaderMid *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderMid, &PyNs3OlsrMessageHeaderMid_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Mid(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderMid_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderMid_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderMid__tp_dealloc(PyNs3OlsrMessageHeaderMid *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderMid_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderMid_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderMid_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Mid *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderMid__tp_richcompare (PyNs3OlsrMessageHeaderMid *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderMid *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderMid_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderMid_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MessageHeader.Mid",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderMid),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderMid__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderMid__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderMid_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderMid__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderMid__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderTc_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderTc__get_ansn(PyNs3OlsrMessageHeaderTc *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->ansn);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderTc__set_ansn(PyNs3OlsrMessageHeaderTc *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->ansn = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderTc__get_neighborAddresses(PyNs3OlsrMessageHeaderTc *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->neighborAddresses);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderTc__set_neighborAddresses(PyNs3OlsrMessageHeaderTc *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->neighborAddresses)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderTc__getsets[] = {
    {
        (char*) "ansn", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderTc__get_ansn, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderTc__set_ansn, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "neighborAddresses", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderTc__get_neighborAddresses, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderTc__set_neighborAddresses, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderTc__tp_init__0(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Tc();
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderTc__tp_init__1(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderTc *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderTc_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Tc(*((PyNs3OlsrMessageHeaderTc *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderTc__tp_init(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderTc__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderTc__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderTc_GetSerializedSize(PyNs3OlsrMessageHeaderTc *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderTc_Print(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    const char *keywords[] = {"os", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyStdOstream_Type, &os)) {
        return NULL;
    }
    self->obj->Print(*((PyStdOstream *) os)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderTc_Serialize(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *start;
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    self->obj->Serialize(*((PyNs3BufferIterator *) start)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderTc_Deserialize(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderTc__copy__(PyNs3OlsrMessageHeaderTc *self)
{

    PyNs3OlsrMessageHeaderTc *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderTc, &PyNs3OlsrMessageHeaderTc_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Tc(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderTc_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderTc_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderTc__tp_dealloc(PyNs3OlsrMessageHeaderTc *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderTc_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderTc_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderTc_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Tc *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderTc__tp_richcompare (PyNs3OlsrMessageHeaderTc *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderTc *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderTc_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderTc_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MessageHeader.Tc",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderTc),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderTc__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderTc__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderTc_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderTc__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderTc__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMprSelectorTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMprSelectorTuple__get_expirationTime(PyNs3OlsrMprSelectorTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrMprSelectorTuple__set_expirationTime(PyNs3OlsrMprSelectorTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMprSelectorTuple__get_mainAddr(PyNs3OlsrMprSelectorTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->mainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrMprSelectorTuple__set_mainAddr(PyNs3OlsrMprSelectorTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->mainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMprSelectorTuple__getsets[] = {
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrMprSelectorTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMprSelectorTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "mainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrMprSelectorTuple__get_mainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMprSelectorTuple__set_mainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMprSelectorTuple__tp_init__0(PyNs3OlsrMprSelectorTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MprSelectorTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrMprSelectorTuple__tp_init__1(PyNs3OlsrMprSelectorTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMprSelectorTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMprSelectorTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MprSelectorTuple(*((PyNs3OlsrMprSelectorTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrMprSelectorTuple__tp_init(PyNs3OlsrMprSelectorTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMprSelectorTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMprSelectorTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMprSelectorTuple__copy__(PyNs3OlsrMprSelectorTuple *self)
{

    PyNs3OlsrMprSelectorTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMprSelectorTuple, &PyNs3OlsrMprSelectorTuple_Type);
    py_copy->obj = new ns3::olsr::MprSelectorTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMprSelectorTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMprSelectorTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMprSelectorTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMprSelectorTuple__tp_dealloc(PyNs3OlsrMprSelectorTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMprSelectorTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMprSelectorTuple_wrapper_registry.end()) {
        PyNs3OlsrMprSelectorTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MprSelectorTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMprSelectorTuple__tp_richcompare (PyNs3OlsrMprSelectorTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrMprSelectorTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMprSelectorTuple_Type)) {
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

PyTypeObject PyNs3OlsrMprSelectorTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.MprSelectorTuple",            /* tp_name */
    sizeof(PyNs3OlsrMprSelectorTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMprSelectorTuple__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMprSelectorTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMprSelectorTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMprSelectorTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMprSelectorTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrNeighborTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrNeighborTuple__get_neighborMainAddr(PyNs3OlsrNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->neighborMainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrNeighborTuple__set_neighborMainAddr(PyNs3OlsrNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->neighborMainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrNeighborTuple__get_status(PyNs3OlsrNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->status);
    return py_retval;
}
static int _wrap_PyNs3OlsrNeighborTuple__set_status(PyNs3OlsrNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &self->obj->status)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrNeighborTuple__get_willingness(PyNs3OlsrNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->willingness);
    return py_retval;
}
static int _wrap_PyNs3OlsrNeighborTuple__set_willingness(PyNs3OlsrNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->willingness = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrNeighborTuple__getsets[] = {
    {
        (char*) "status", /* attribute name */
        (getter) _wrap_PyNs3OlsrNeighborTuple__get_status, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrNeighborTuple__set_status, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "neighborMainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrNeighborTuple__get_neighborMainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrNeighborTuple__set_neighborMainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "willingness", /* attribute name */
        (getter) _wrap_PyNs3OlsrNeighborTuple__get_willingness, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrNeighborTuple__set_willingness, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrNeighborTuple__tp_init__0(PyNs3OlsrNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::NeighborTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrNeighborTuple__tp_init__1(PyNs3OlsrNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrNeighborTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrNeighborTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::NeighborTuple(*((PyNs3OlsrNeighborTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrNeighborTuple__tp_init(PyNs3OlsrNeighborTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrNeighborTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrNeighborTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrNeighborTuple__copy__(PyNs3OlsrNeighborTuple *self)
{

    PyNs3OlsrNeighborTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrNeighborTuple, &PyNs3OlsrNeighborTuple_Type);
    py_copy->obj = new ns3::olsr::NeighborTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrNeighborTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrNeighborTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrNeighborTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrNeighborTuple__tp_dealloc(PyNs3OlsrNeighborTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrNeighborTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrNeighborTuple_wrapper_registry.end()) {
        PyNs3OlsrNeighborTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::NeighborTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrNeighborTuple__tp_str(PyNs3OlsrNeighborTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrNeighborTuple__tp_richcompare (PyNs3OlsrNeighborTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrNeighborTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrNeighborTuple_Type)) {
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

PyTypeObject PyNs3OlsrNeighborTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.NeighborTuple",            /* tp_name */
    sizeof(PyNs3OlsrNeighborTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrNeighborTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrNeighborTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrNeighborTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrNeighborTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrNeighborTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrNeighborTuple__tp_init,             /* tp_init */
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
PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportTestFailure(PyNs3OlsrOlsrMprTestCase *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *cond;
    Py_ssize_t cond_len;
    const char *actual;
    Py_ssize_t actual_len;
    const char *limit;
    Py_ssize_t limit_len;
    const char *message;
    Py_ssize_t message_len;
    const char *file;
    Py_ssize_t file_len;
    int32_t line;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper = dynamic_cast< PyNs3OlsrOlsrMprTestCase__PythonHelper* >(self->obj);
    const char *keywords[] = {"cond", "actual", "limit", "message", "file", "line", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#s#s#i", (char **) keywords, &cond, &cond_len, &actual, &actual_len, &limit, &limit_len, &message, &message_len, &file, &file_len, &line)) {
        return NULL;
    }
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoReportTestFailure of class TestCase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoReportTestFailure__parent_caller(std::string(cond, cond_len), std::string(actual, actual_len), std::string(limit, limit_len), std::string(message, message_len), std::string(file, file_len), line);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoSetup(PyNs3OlsrOlsrMprTestCase *self)
{
    PyObject *py_retval;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper = dynamic_cast< PyNs3OlsrOlsrMprTestCase__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoSetup of class TestCase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoSetup__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportCaseFailure(PyNs3OlsrOlsrMprTestCase *self)
{
    PyObject *py_retval;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper = dynamic_cast< PyNs3OlsrOlsrMprTestCase__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoReportCaseFailure of class TestCase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoReportCaseFailure__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportCaseSuccess(PyNs3OlsrOlsrMprTestCase *self)
{
    PyObject *py_retval;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper = dynamic_cast< PyNs3OlsrOlsrMprTestCase__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoReportCaseSuccess of class TestCase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoReportCaseSuccess__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportStart(PyNs3OlsrOlsrMprTestCase *self)
{
    PyObject *py_retval;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper = dynamic_cast< PyNs3OlsrOlsrMprTestCase__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoReportStart of class TestCase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoReportStart__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportEnd(PyNs3OlsrOlsrMprTestCase *self)
{
    PyObject *py_retval;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper = dynamic_cast< PyNs3OlsrOlsrMprTestCase__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoReportEnd of class TestCase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoReportEnd__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoTeardown(PyNs3OlsrOlsrMprTestCase *self)
{
    PyObject *py_retval;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper = dynamic_cast< PyNs3OlsrOlsrMprTestCase__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoTeardown of class TestCase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoTeardown__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

bool
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoRun()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::OlsrMprTestCase *self_obj_before;
    PyObject *py_retval;
    bool retval;
    PyObject *py_boolretval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoRun"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::OlsrMprTestCase::DoRun();
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrOlsrMprTestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrOlsrMprTestCase* >(m_pyself)->obj = (ns3::olsr::OlsrMprTestCase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoRun", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrOlsrMprTestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::OlsrMprTestCase::DoRun();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrOlsrMprTestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::OlsrMprTestCase::DoRun();
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrOlsrMprTestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoReportStart()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TestCase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoReportStart"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::TestCase::DoReportStart();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = (ns3::TestCase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoReportStart", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoReportCaseSuccess()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TestCase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoReportCaseSuccess"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::TestCase::DoReportCaseSuccess();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = (ns3::TestCase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoReportCaseSuccess", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoReportCaseFailure()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TestCase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoReportCaseFailure"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::TestCase::DoReportCaseFailure();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = (ns3::TestCase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoReportCaseFailure", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoReportTestFailure(std::string cond, std::string actual, std::string limit, std::string message, std::string file, int32_t line)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TestCase *self_obj_before;
    PyObject *py_retval;
    const char *cond_ptr;
    Py_ssize_t cond_len;
    const char *actual_ptr;
    Py_ssize_t actual_len;
    const char *limit_ptr;
    Py_ssize_t limit_len;
    const char *message_ptr;
    Py_ssize_t message_len;
    const char *file_ptr;
    Py_ssize_t file_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoReportTestFailure"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::TestCase::DoReportTestFailure(cond, actual, limit, message, file, line);
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = (ns3::TestCase*) this;
    cond_ptr = (cond).c_str();
    cond_len = (cond).size();
    actual_ptr = (actual).c_str();
    actual_len = (actual).size();
    limit_ptr = (limit).c_str();
    limit_len = (limit).size();
    message_ptr = (message).c_str();
    message_len = (message).size();
    file_ptr = (file).c_str();
    file_len = (file).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoReportTestFailure", (char *) "s#s#s#s#s#i", cond_ptr, cond_len, actual_ptr, actual_len, limit_ptr, limit_len, message_ptr, message_len, file_ptr, file_len, line);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoReportEnd()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TestCase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoReportEnd"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::TestCase::DoReportEnd();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = (ns3::TestCase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoReportEnd", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoSetup()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TestCase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetup"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::TestCase::DoSetup();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = (ns3::TestCase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetup", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrOlsrMprTestCase__PythonHelper::DoTeardown()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TestCase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoTeardown"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::TestCase::DoTeardown();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = (ns3::TestCase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoTeardown", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TestCase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

static int
_wrap_PyNs3OlsrOlsrMprTestCase__tp_init(PyNs3OlsrOlsrMprTestCase *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (self->ob_type != &PyNs3OlsrOlsrMprTestCase_Type)
    {
        self->obj = new PyNs3OlsrOlsrMprTestCase__PythonHelper();
        ((PyNs3OlsrOlsrMprTestCase__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::olsr::OlsrMprTestCase();
    }
    return 0;
}


PyObject *
_wrap_PyNs3OlsrOlsrMprTestCase_DoRun(PyNs3OlsrOlsrMprTestCase *self)
{
    PyObject *py_retval;
    bool retval;
    PyNs3OlsrOlsrMprTestCase__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrOlsrMprTestCase__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->DoRun()) : (self->obj->ns3::olsr::OlsrMprTestCase::DoRun());
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

static PyMethodDef PyNs3OlsrOlsrMprTestCase_methods[] = {
    {(char *) "DoRun", (PyCFunction) _wrap_PyNs3OlsrOlsrMprTestCase_DoRun, METH_NOARGS, NULL },
    {(char *) "DoReportTestFailure", (PyCFunction) PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportTestFailure, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DoSetup", (PyCFunction) PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoSetup, METH_NOARGS, NULL },
    {(char *) "DoReportCaseFailure", (PyCFunction) PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportCaseFailure, METH_NOARGS, NULL },
    {(char *) "DoReportCaseSuccess", (PyCFunction) PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportCaseSuccess, METH_NOARGS, NULL },
    {(char *) "DoReportStart", (PyCFunction) PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportStart, METH_NOARGS, NULL },
    {(char *) "DoReportEnd", (PyCFunction) PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoReportEnd, METH_NOARGS, NULL },
    {(char *) "DoTeardown", (PyCFunction) PyNs3OlsrOlsrMprTestCase__PythonHelper::_wrap_DoTeardown, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrOlsrMprTestCase__tp_clear(PyNs3OlsrOlsrMprTestCase *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::olsr::OlsrMprTestCase *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3OlsrOlsrMprTestCase__tp_traverse(PyNs3OlsrOlsrMprTestCase *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj) == typeid(PyNs3OlsrOlsrMprTestCase__PythonHelper) )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3OlsrOlsrMprTestCase__tp_dealloc(PyNs3OlsrOlsrMprTestCase *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3TestCase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3TestCase_wrapper_registry.end()) {
        PyNs3TestCase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrOlsrMprTestCase__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrOlsrMprTestCase__tp_richcompare (PyNs3OlsrOlsrMprTestCase *PYBINDGEN_UNUSED(self), PyNs3OlsrOlsrMprTestCase *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrOlsrMprTestCase_Type)) {
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

PyTypeObject PyNs3OlsrOlsrMprTestCase_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.OlsrMprTestCase",            /* tp_name */
    sizeof(PyNs3OlsrOlsrMprTestCase),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrOlsrMprTestCase__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3OlsrOlsrMprTestCase__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrOlsrMprTestCase__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrOlsrMprTestCase__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrOlsrMprTestCase_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrOlsrMprTestCase, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrOlsrMprTestCase__tp_init,             /* tp_init */
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
PyNs3OlsrPacketHeader__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    PyNs3OlsrPacketHeader__PythonHelper *helper = dynamic_cast< PyNs3OlsrPacketHeader__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

uint32_t
PyNs3OlsrPacketHeader__PythonHelper::Deserialize(ns3::Buffer::Iterator start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::PacketHeader *self_obj_before;
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *py_Iterator;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Deserialize"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::Deserialize(start);
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = (ns3::olsr::PacketHeader*) this;
    py_Iterator = PyObject_New(PyNs3BufferIterator, &PyNs3BufferIterator_Type);
    py_Iterator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Iterator->obj = new ns3::Buffer::Iterator(start);
    PyNs3BufferIterator_wrapper_registry[(void *) py_Iterator->obj] = (PyObject *) py_Iterator;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Deserialize", (char *) "N", py_Iterator);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::Deserialize(start);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::Deserialize(start);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3OlsrPacketHeader__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::PacketHeader *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = const_cast< ns3::olsr::PacketHeader* >((const ns3::olsr::PacketHeader*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

uint32_t
PyNs3OlsrPacketHeader__PythonHelper::GetSerializedSize() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::PacketHeader *self_obj_before;
    PyObject *py_retval;
    uint32_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetSerializedSize"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::GetSerializedSize();
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = const_cast< ns3::olsr::PacketHeader* >((const ns3::olsr::PacketHeader*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetSerializedSize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::GetSerializedSize();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::olsr::PacketHeader::GetSerializedSize();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}


void
PyNs3OlsrPacketHeader__PythonHelper::Serialize(ns3::Buffer::Iterator start) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::olsr::PacketHeader *self_obj_before;
    PyObject *py_retval;
    PyNs3BufferIterator *py_Iterator;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Serialize"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::olsr::PacketHeader::Serialize(start);
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = const_cast< ns3::olsr::PacketHeader* >((const ns3::olsr::PacketHeader*) this);
    py_Iterator = PyObject_New(PyNs3BufferIterator, &PyNs3BufferIterator_Type);
    py_Iterator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Iterator->obj = new ns3::Buffer::Iterator(start);
    PyNs3BufferIterator_wrapper_registry[(void *) py_Iterator->obj] = (PyObject *) py_Iterator;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Serialize", (char *) "N", py_Iterator);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OlsrPacketHeader* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OlsrPacketHeader__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || py_method->ob_type == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3OlsrPacketHeader__tp_init__0(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrPacketHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrPacketHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (self->ob_type != &PyNs3OlsrPacketHeader_Type)
    {
        self->obj = new PyNs3OlsrPacketHeader__PythonHelper(*((PyNs3OlsrPacketHeader *) arg0)->obj);
        ((PyNs3OlsrPacketHeader__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::olsr::PacketHeader(*((PyNs3OlsrPacketHeader *) arg0)->obj);
    }
    return 0;
}

static int
_wrap_PyNs3OlsrPacketHeader__tp_init__1(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (self->ob_type != &PyNs3OlsrPacketHeader_Type)
    {
        self->obj = new PyNs3OlsrPacketHeader__PythonHelper();
        ((PyNs3OlsrPacketHeader__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::olsr::PacketHeader();
    }
    return 0;
}

int _wrap_PyNs3OlsrPacketHeader__tp_init(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrPacketHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrPacketHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrPacketHeader_Serialize(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *start;
    PyNs3OlsrPacketHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrPacketHeader__PythonHelper*> (self->obj);
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Serialize(*((PyNs3BufferIterator *) start)->obj)) : (self->obj->ns3::olsr::PacketHeader::Serialize(*((PyNs3BufferIterator *) start)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_Deserialize(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    PyNs3OlsrPacketHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrPacketHeader__PythonHelper*> (self->obj);
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj)) : (self->obj->ns3::olsr::PacketHeader::Deserialize(*((PyNs3BufferIterator *) start)->obj));
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetPacketLength(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetPacketLength();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::olsr::PacketHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetPacketSequenceNumber(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetPacketSequenceNumber();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_SetPacketSequenceNumber(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int seqnum;
    const char *keywords[] = {"seqnum", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &seqnum)) {
        return NULL;
    }
    if (seqnum > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPacketSequenceNumber(seqnum);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_Print(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyStdOstream *os;
    PyNs3OlsrPacketHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrPacketHeader__PythonHelper*> (self->obj);
    const char *keywords[] = {"os", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyStdOstream_Type, &os)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Print(*((PyStdOstream *) os)->obj)) : (self->obj->ns3::olsr::PacketHeader::Print(*((PyStdOstream *) os)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_SetPacketLength(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int length;
    const char *keywords[] = {"length", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &length)) {
        return NULL;
    }
    if (length > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPacketLength(length);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetInstanceTypeId(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    PyNs3OlsrPacketHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrPacketHeader__PythonHelper*> (self->obj);
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = (helper_class == NULL)? (self->obj->GetInstanceTypeId()) : (self->obj->ns3::olsr::PacketHeader::GetInstanceTypeId());
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetSerializedSize(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3OlsrPacketHeader__PythonHelper *helper_class = dynamic_cast<PyNs3OlsrPacketHeader__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetSerializedSize()) : (self->obj->ns3::olsr::PacketHeader::GetSerializedSize());
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrPacketHeader__copy__(PyNs3OlsrPacketHeader *self)
{

    PyNs3OlsrPacketHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3OlsrPacketHeader, &PyNs3OlsrPacketHeader_Type);
    py_copy->obj = new ns3::olsr::PacketHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrPacketHeader_methods[] = {
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPacketLength", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetPacketLength, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetPacketSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetPacketSequenceNumber, METH_NOARGS, NULL },
    {(char *) "SetPacketSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_SetPacketSequenceNumber, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPacketLength", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_SetPacketLength, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3OlsrPacketHeader__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrPacketHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrPacketHeader__tp_clear(PyNs3OlsrPacketHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::olsr::PacketHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3OlsrPacketHeader__tp_traverse(PyNs3OlsrPacketHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj) == typeid(PyNs3OlsrPacketHeader__PythonHelper) )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3OlsrPacketHeader__tp_dealloc(PyNs3OlsrPacketHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrPacketHeader__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrPacketHeader__tp_str(PyNs3OlsrPacketHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrPacketHeader__tp_richcompare (PyNs3OlsrPacketHeader *PYBINDGEN_UNUSED(self), PyNs3OlsrPacketHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrPacketHeader_Type)) {
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

PyTypeObject PyNs3OlsrPacketHeader_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.PacketHeader",            /* tp_name */
    sizeof(PyNs3OlsrPacketHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrPacketHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrPacketHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3OlsrPacketHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrPacketHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrPacketHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrPacketHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrPacketHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrPacketHeader__tp_init,             /* tp_init */
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
_wrap_PyNs3OlsrRoutingProtocol__tp_init__0(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrRoutingProtocol *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrRoutingProtocol_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::RoutingProtocol(*((PyNs3OlsrRoutingProtocol *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

static int
_wrap_PyNs3OlsrRoutingProtocol__tp_init__1(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::RoutingProtocol();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

int _wrap_PyNs3OlsrRoutingProtocol__tp_init(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrRoutingProtocol__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrRoutingProtocol__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrRoutingProtocol_AddHostNetworkAssociation(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *networkAddr;
    PyNs3Ipv4Mask *netmask;
    const char *keywords[] = {"networkAddr", "netmask", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &networkAddr, &PyNs3Ipv4Mask_Type, &netmask)) {
        return NULL;
    }
    self->obj->AddHostNetworkAssociation(*((PyNs3Ipv4Address *) networkAddr)->obj, *((PyNs3Ipv4Mask *) netmask)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_Dump(PyNs3OlsrRoutingProtocol *self)
{
    PyObject *py_retval;
    
    self->obj->Dump();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::olsr::RoutingProtocol::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_SetInterfaceExclusions(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::set< unsigned int > exceptions_value;
    const char *keywords[] = {"exceptions", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__std__set__lt___unsigned_int___gt__, &exceptions_value)) {
        return NULL;
    }
    self->obj->SetInterfaceExclusions(exceptions_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_GetRoutingTableEntries(PyNs3OlsrRoutingProtocol *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::RoutingTableEntry > retval;
    Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__;
    
    retval = self->obj->GetRoutingTableEntries();
    py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__ = PyObject_New(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__, &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type);
    py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__->obj = new std::vector< ns3::olsr::RoutingTableEntry >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_SetMainInterface(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->SetMainInterface(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_GetInterfaceExclusions(PyNs3OlsrRoutingProtocol *self)
{
    PyObject *py_retval;
    std::set< unsigned int > retval;
    Pystd__set__lt___unsigned_int___gt__ *py_std__set__lt___unsigned_int___gt__;
    
    retval = self->obj->GetInterfaceExclusions();
    py_std__set__lt___unsigned_int___gt__ = PyObject_New(Pystd__set__lt___unsigned_int___gt__, &Pystd__set__lt___unsigned_int___gt___Type);
    py_std__set__lt___unsigned_int___gt__->obj = new std::set< unsigned int >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__set__lt___unsigned_int___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_SetRoutingTableAssociation(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4StaticRouting *routingTable;
    ns3::Ipv4StaticRouting *routingTable_ptr;
    const char *keywords[] = {"routingTable", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4StaticRouting_Type, &routingTable)) {
        return NULL;
    }
    routingTable_ptr = (routingTable ? routingTable->obj : NULL);
    self->obj->SetRoutingTableAssociation(ns3::Ptr< ns3::Ipv4StaticRouting  > (routingTable_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrRoutingProtocol__copy__(PyNs3OlsrRoutingProtocol *self)
{

    PyNs3OlsrRoutingProtocol *py_copy;
    py_copy = PyObject_GC_New(PyNs3OlsrRoutingProtocol, &PyNs3OlsrRoutingProtocol_Type);
    py_copy->obj = new ns3::olsr::RoutingProtocol(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrRoutingProtocol_methods[] = {
    {(char *) "AddHostNetworkAssociation", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_AddHostNetworkAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Dump", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_Dump, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetInterfaceExclusions", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_SetInterfaceExclusions, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRoutingTableEntries", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_GetRoutingTableEntries, METH_NOARGS, NULL },
    {(char *) "SetMainInterface", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_SetMainInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInterfaceExclusions", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_GetInterfaceExclusions, METH_NOARGS, NULL },
    {(char *) "SetRoutingTableAssociation", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_SetRoutingTableAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrRoutingProtocol__tp_clear(PyNs3OlsrRoutingProtocol *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::olsr::RoutingProtocol *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3OlsrRoutingProtocol__tp_traverse(PyNs3OlsrRoutingProtocol *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3OlsrRoutingProtocol__tp_dealloc(PyNs3OlsrRoutingProtocol *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrRoutingProtocol__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrRoutingProtocol__tp_richcompare (PyNs3OlsrRoutingProtocol *PYBINDGEN_UNUSED(self), PyNs3OlsrRoutingProtocol *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrRoutingProtocol_Type)) {
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

PyTypeObject PyNs3OlsrRoutingProtocol_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.RoutingProtocol",            /* tp_name */
    sizeof(PyNs3OlsrRoutingProtocol),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrRoutingProtocol__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3OlsrRoutingProtocol__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrRoutingProtocol__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrRoutingProtocol__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrRoutingProtocol_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrRoutingProtocol, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrRoutingProtocol__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrRoutingTableEntry_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_destAddr(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->destAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_destAddr(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_distance(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->distance));
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_distance(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->distance)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_interface(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->interface));
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_interface(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->interface)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_nextAddr(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->nextAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_nextAddr(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->nextAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrRoutingTableEntry__getsets[] = {
    {
        (char*) "interface", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_interface, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_interface, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "distance", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_distance, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_distance, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "nextAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_nextAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_nextAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_destAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_destAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrRoutingTableEntry__tp_init__0(PyNs3OlsrRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrRoutingTableEntry *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrRoutingTableEntry_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::RoutingTableEntry(*((PyNs3OlsrRoutingTableEntry *) arg0)->obj);
    return 0;
}

static int
_wrap_PyNs3OlsrRoutingTableEntry__tp_init__1(PyNs3OlsrRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::RoutingTableEntry();
    return 0;
}

int _wrap_PyNs3OlsrRoutingTableEntry__tp_init(PyNs3OlsrRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrRoutingTableEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrRoutingTableEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrRoutingTableEntry__copy__(PyNs3OlsrRoutingTableEntry *self)
{

    PyNs3OlsrRoutingTableEntry *py_copy;
    py_copy = PyObject_New(PyNs3OlsrRoutingTableEntry, &PyNs3OlsrRoutingTableEntry_Type);
    py_copy->obj = new ns3::olsr::RoutingTableEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrRoutingTableEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrRoutingTableEntry_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrRoutingTableEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrRoutingTableEntry__tp_dealloc(PyNs3OlsrRoutingTableEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrRoutingTableEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrRoutingTableEntry_wrapper_registry.end()) {
        PyNs3OlsrRoutingTableEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::RoutingTableEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrRoutingTableEntry__tp_richcompare (PyNs3OlsrRoutingTableEntry *PYBINDGEN_UNUSED(self), PyNs3OlsrRoutingTableEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrRoutingTableEntry_Type)) {
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

PyTypeObject PyNs3OlsrRoutingTableEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.RoutingTableEntry",            /* tp_name */
    sizeof(PyNs3OlsrRoutingTableEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrRoutingTableEntry__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrRoutingTableEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrRoutingTableEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrRoutingTableEntry__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrRoutingTableEntry__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrTopologyTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_destAddr(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->destAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_destAddr(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_expirationTime(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_expirationTime(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_lastAddr(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->lastAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_lastAddr(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->lastAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_sequenceNumber(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->sequenceNumber);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_sequenceNumber(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->sequenceNumber = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrTopologyTuple__getsets[] = {
    {
        (char*) "lastAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_lastAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_lastAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_destAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_destAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "sequenceNumber", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_sequenceNumber, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_sequenceNumber, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrTopologyTuple__tp_init__0(PyNs3OlsrTopologyTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::TopologyTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrTopologyTuple__tp_init__1(PyNs3OlsrTopologyTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrTopologyTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTopologyTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::TopologyTuple(*((PyNs3OlsrTopologyTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrTopologyTuple__tp_init(PyNs3OlsrTopologyTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrTopologyTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrTopologyTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrTopologyTuple__copy__(PyNs3OlsrTopologyTuple *self)
{

    PyNs3OlsrTopologyTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrTopologyTuple, &PyNs3OlsrTopologyTuple_Type);
    py_copy->obj = new ns3::olsr::TopologyTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrTopologyTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrTopologyTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrTopologyTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrTopologyTuple__tp_dealloc(PyNs3OlsrTopologyTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrTopologyTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrTopologyTuple_wrapper_registry.end()) {
        PyNs3OlsrTopologyTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::TopologyTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrTopologyTuple__tp_str(PyNs3OlsrTopologyTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrTopologyTuple__tp_richcompare (PyNs3OlsrTopologyTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrTopologyTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrTopologyTuple_Type)) {
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

PyTypeObject PyNs3OlsrTopologyTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.TopologyTuple",            /* tp_name */
    sizeof(PyNs3OlsrTopologyTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrTopologyTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrTopologyTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrTopologyTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrTopologyTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrTopologyTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrTopologyTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrTwoHopNeighborTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrTwoHopNeighborTuple__get_expirationTime(PyNs3OlsrTwoHopNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrTwoHopNeighborTuple__set_expirationTime(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTwoHopNeighborTuple__get_neighborMainAddr(PyNs3OlsrTwoHopNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->neighborMainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTwoHopNeighborTuple__set_neighborMainAddr(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->neighborMainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTwoHopNeighborTuple__get_twoHopNeighborAddr(PyNs3OlsrTwoHopNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->twoHopNeighborAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTwoHopNeighborTuple__set_twoHopNeighborAddr(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->twoHopNeighborAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrTwoHopNeighborTuple__getsets[] = {
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrTwoHopNeighborTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTwoHopNeighborTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "neighborMainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTwoHopNeighborTuple__get_neighborMainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTwoHopNeighborTuple__set_neighborMainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "twoHopNeighborAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTwoHopNeighborTuple__get_twoHopNeighborAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTwoHopNeighborTuple__set_twoHopNeighborAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__0(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::TwoHopNeighborTuple();
    return 0;
}

static int
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__1(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrTwoHopNeighborTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTwoHopNeighborTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::TwoHopNeighborTuple(*((PyNs3OlsrTwoHopNeighborTuple *) arg0)->obj);
    return 0;
}

int _wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrTwoHopNeighborTuple__copy__(PyNs3OlsrTwoHopNeighborTuple *self)
{

    PyNs3OlsrTwoHopNeighborTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrTwoHopNeighborTuple, &PyNs3OlsrTwoHopNeighborTuple_Type);
    py_copy->obj = new ns3::olsr::TwoHopNeighborTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrTwoHopNeighborTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrTwoHopNeighborTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrTwoHopNeighborTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_dealloc(PyNs3OlsrTwoHopNeighborTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrTwoHopNeighborTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrTwoHopNeighborTuple_wrapper_registry.end()) {
        PyNs3OlsrTwoHopNeighborTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::TwoHopNeighborTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_str(PyNs3OlsrTwoHopNeighborTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_richcompare (PyNs3OlsrTwoHopNeighborTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrTwoHopNeighborTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrTwoHopNeighborTuple_Type)) {
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

PyTypeObject PyNs3OlsrTwoHopNeighborTuple_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.TwoHopNeighborTuple",            /* tp_name */
    sizeof(PyNs3OlsrTwoHopNeighborTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrTwoHopNeighborTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrTwoHopNeighborTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init,             /* tp_init */
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
Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >::iterator iter;
    PyNs3OlsrMessageHeaderHelloLinkMessage *py_LinkMessage;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_LinkMessage = PyObject_New(PyNs3OlsrMessageHeaderHelloLinkMessage, &PyNs3OlsrMessageHeaderHelloLinkMessage_Type);
    py_LinkMessage->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_LinkMessage->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage((*iter));
    PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry[(void *) py_LinkMessage->obj] = (PyObject *) py_LinkMessage;
    py_retval = Py_BuildValue((char *) "N", py_LinkMessage);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__MessageHeader__Hello__LinkMessage(PyObject *value, ns3::olsr::MessageHeader::Hello::LinkMessage *address)
{
    PyObject *py_retval;
    PyNs3OlsrMessageHeaderHelloLinkMessage *tmp_LinkMessage;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrMessageHeaderHelloLinkMessage_Type, &tmp_LinkMessage)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_LinkMessage->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__(PyObject *arg, std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::MessageHeader::Hello::LinkMessage item;
            if (!_wrap_convert_py2c__ns3__olsr__MessageHeader__Hello__LinkMessage(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ instance, or a list of ns3::olsr::MessageHeader::Hello::LinkMessage");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_init(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::MessageHeader::Hna::Association >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hna::Association >::iterator iter;
    PyNs3OlsrMessageHeaderHnaAssociation *py_Association;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Association = PyObject_New(PyNs3OlsrMessageHeaderHnaAssociation, &PyNs3OlsrMessageHeaderHnaAssociation_Type);
    py_Association->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Association->obj = new ns3::olsr::MessageHeader::Hna::Association((*iter));
    PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry[(void *) py_Association->obj] = (PyObject *) py_Association;
    py_retval = Py_BuildValue((char *) "N", py_Association);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__MessageHeader__Hna__Association(PyObject *value, ns3::olsr::MessageHeader::Hna::Association *address)
{
    PyObject *py_retval;
    PyNs3OlsrMessageHeaderHnaAssociation *tmp_Association;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrMessageHeaderHnaAssociation_Type, &tmp_Association)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_Association->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__(PyObject *arg, std::vector< ns3::olsr::MessageHeader::Hna::Association > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::MessageHeader::Hna::Association item;
            if (!_wrap_convert_py2c__ns3__olsr__MessageHeader__Hna__Association(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ instance, or a list of ns3::olsr::MessageHeader::Hna::Association");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_init(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::MessageHeader::Hna::Association >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    self->ob_type->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_iter(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter, &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::RoutingTableEntry >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::RoutingTableEntry >::iterator iter;
    PyNs3OlsrRoutingTableEntry *py_RoutingTableEntry;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_RoutingTableEntry = PyObject_New(PyNs3OlsrRoutingTableEntry, &PyNs3OlsrRoutingTableEntry_Type);
    py_RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_RoutingTableEntry->obj = new ns3::olsr::RoutingTableEntry((*iter));
    PyNs3OlsrRoutingTableEntry_wrapper_registry[(void *) py_RoutingTableEntry->obj] = (PyObject *) py_RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_RoutingTableEntry);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__RoutingTableEntry(PyObject *value, ns3::olsr::RoutingTableEntry *address)
{
    PyObject *py_retval;
    PyNs3OlsrRoutingTableEntry *tmp_RoutingTableEntry;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrRoutingTableEntry_Type, &tmp_RoutingTableEntry)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_RoutingTableEntry->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__RoutingTableEntry___gt__(PyObject *arg, std::vector< ns3::olsr::RoutingTableEntry > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::RoutingTableEntry item;
            if (!_wrap_convert_py2c__ns3__olsr__RoutingTableEntry(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__ instance, or a list of ns3::olsr::RoutingTableEntry");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_init(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::RoutingTableEntry >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__RoutingTableEntry___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.olsr.Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iternext,     /* tp_iternext */
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







std::map<void*, PyObject*> PyNs3OlsrState_wrapper_registry;


static int
_wrap_PyNs3OlsrState__tp_init__0(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrState *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrState_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::OlsrState(*((PyNs3OlsrState *) arg0)->obj);
    return 0;
}

static int
_wrap_PyNs3OlsrState__tp_init__1(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::OlsrState();
    return 0;
}

int _wrap_PyNs3OlsrState__tp_init(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrState__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrState__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrState_InsertDuplicateTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrDuplicateTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrDuplicateTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertDuplicateTuple(*((PyNs3OlsrDuplicateTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseOlderTopologyTuples(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *lastAddr;
    int ansn;
    const char *keywords[] = {"lastAddr", "ansn", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &lastAddr, &ansn)) {
        return NULL;
    }
    if (ansn > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->EraseOlderTopologyTuples(*((PyNs3Ipv4Address *) lastAddr)->obj, ansn);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseLinkTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrLinkTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrLinkTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseLinkTuple(*((PyNs3OlsrLinkTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertLinkTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrLinkTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    PyNs3OlsrLinkTuple *py_LinkTuple;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrLinkTuple_Type, &tuple)) {
        return NULL;
    }
    ns3::olsr::LinkTuple & retval = self->obj->InsertLinkTuple(*((PyNs3OlsrLinkTuple *) tuple)->obj);
    py_LinkTuple = PyObject_New(PyNs3OlsrLinkTuple, &PyNs3OlsrLinkTuple_Type);
    py_LinkTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_LinkTuple->obj = new ns3::olsr::LinkTuple(retval);
    PyNs3OlsrLinkTuple_wrapper_registry[(void *) py_LinkTuple->obj] = (PyObject *) py_LinkTuple;
    py_retval = Py_BuildValue((char *) "N", py_LinkTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseMprSelectorTuples(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *mainAddr;
    const char *keywords[] = {"mainAddr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &mainAddr)) {
        return NULL;
    }
    self->obj->EraseMprSelectorTuples(*((PyNs3Ipv4Address *) mainAddr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_FindSymNeighborTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::NeighborTuple const *retval;
    PyNs3Ipv4Address *mainAddr;
    const char *keywords[] = {"mainAddr", NULL};
    PyNs3OlsrNeighborTuple *py_NeighborTuple;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &mainAddr)) {
        return NULL;
    }
    retval = self->obj->FindSymNeighborTuple(*((PyNs3Ipv4Address *) mainAddr)->obj);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3OlsrNeighborTuple_wrapper_registry.find((void *) retval);
    if (wrapper_lookup_iter == PyNs3OlsrNeighborTuple_wrapper_registry.end()) {
        py_NeighborTuple = NULL;
    } else {
        py_NeighborTuple = (PyNs3OlsrNeighborTuple *) wrapper_lookup_iter->second;
        Py_INCREF(py_NeighborTuple);
    }
    
    if (py_NeighborTuple == NULL) {
        py_NeighborTuple = PyObject_New(PyNs3OlsrNeighborTuple, &PyNs3OlsrNeighborTuple_Type);
        py_NeighborTuple->obj = new ns3::olsr::NeighborTuple((*retval));
        py_NeighborTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3OlsrNeighborTuple_wrapper_registry[(void *) py_NeighborTuple->obj] = (PyObject *) py_NeighborTuple;
    }
    py_retval = Py_BuildValue((char *) "N", py_NeighborTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_FindMprAddress(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *address;
    const char *keywords[] = {"address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &address)) {
        return NULL;
    }
    retval = self->obj->FindMprAddress(*((PyNs3Ipv4Address *) address)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertIfaceAssocTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrIfaceAssocTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrIfaceAssocTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertIfaceAssocTuple(*((PyNs3OlsrIfaceAssocTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_GetMprSet(PyNs3OlsrState *self)
{
    PyObject *py_retval;
    ns3::olsr::MprSet retval;
    Pyns3__olsr__MprSet *py_ns3__olsr__MprSet;
    
    retval = self->obj->GetMprSet();
    py_ns3__olsr__MprSet = PyObject_New(Pyns3__olsr__MprSet, &Pyns3__olsr__MprSet_Type);
    py_ns3__olsr__MprSet->obj = new ns3::olsr::MprSet(retval);
    py_retval = Py_BuildValue((char *) "N", py_ns3__olsr__MprSet);
    return py_retval;
}



PyObject *
_wrap_PyNs3OlsrState_EraseTwoHopNeighborTuples__0(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *neighbor;
    const char *keywords[] = {"neighbor", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &neighbor)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseTwoHopNeighborTuples(*((PyNs3Ipv4Address *) neighbor)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrState_EraseTwoHopNeighborTuples__1(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *neighbor;
    PyNs3Ipv4Address *twoHopNeighbor;
    const char *keywords[] = {"neighbor", "twoHopNeighbor", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &neighbor, &PyNs3Ipv4Address_Type, &twoHopNeighbor)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseTwoHopNeighborTuples(*((PyNs3Ipv4Address *) neighbor)->obj, *((PyNs3Ipv4Address *) twoHopNeighbor)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrState_EraseTwoHopNeighborTuples(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrState_EraseTwoHopNeighborTuples__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrState_EraseTwoHopNeighborTuples__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrState_EraseNeighborTuple__0(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OlsrNeighborTuple *neighborTuple;
    const char *keywords[] = {"neighborTuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrNeighborTuple_Type, &neighborTuple)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseNeighborTuple(*((PyNs3OlsrNeighborTuple *) neighborTuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrState_EraseNeighborTuple__1(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *mainAddr;
    const char *keywords[] = {"mainAddr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &mainAddr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseNeighborTuple(*((PyNs3Ipv4Address *) mainAddr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrState_EraseNeighborTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrState_EraseNeighborTuple__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrState_EraseNeighborTuple__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrState_EraseAssociationTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociationTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociationTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseAssociationTuple(*((PyNs3OlsrAssociationTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertAssociation(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociation *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociation_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertAssociation(*((PyNs3OlsrAssociation *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseTwoHopNeighborTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTwoHopNeighborTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTwoHopNeighborTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseTwoHopNeighborTuple(*((PyNs3OlsrTwoHopNeighborTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertAssociationTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociationTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociationTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertAssociationTuple(*((PyNs3OlsrAssociationTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_PrintMprSelectorSet(PyNs3OlsrState *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->PrintMprSelectorSet();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseMprSelectorTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrMprSelectorTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMprSelectorTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseMprSelectorTuple(*((PyNs3OlsrMprSelectorTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseAssociation(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociation *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociation_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseAssociation(*((PyNs3OlsrAssociation *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_SetMprSet(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::MprSet mprSet_value;
    const char *keywords[] = {"mprSet", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__ns3__olsr__MprSet, &mprSet_value)) {
        return NULL;
    }
    self->obj->SetMprSet(mprSet_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_FindIfaceAssocTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::IfaceAssocTuple const *retval;
    PyNs3Ipv4Address *ifaceAddr;
    const char *keywords[] = {"ifaceAddr", NULL};
    PyNs3OlsrIfaceAssocTuple *py_IfaceAssocTuple;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &ifaceAddr)) {
        return NULL;
    }
    retval = self->obj->FindIfaceAssocTuple(*((PyNs3Ipv4Address *) ifaceAddr)->obj);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3OlsrIfaceAssocTuple_wrapper_registry.find((void *) retval);
    if (wrapper_lookup_iter == PyNs3OlsrIfaceAssocTuple_wrapper_registry.end()) {
        py_IfaceAssocTuple = NULL;
    } else {
        py_IfaceAssocTuple = (PyNs3OlsrIfaceAssocTuple *) wrapper_lookup_iter->second;
        Py_INCREF(py_IfaceAssocTuple);
    }
    
    if (py_IfaceAssocTuple == NULL) {
        py_IfaceAssocTuple = PyObject_New(PyNs3OlsrIfaceAssocTuple, &PyNs3OlsrIfaceAssocTuple_Type);
        py_IfaceAssocTuple->obj = new ns3::olsr::IfaceAssocTuple((*retval));
        py_IfaceAssocTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3OlsrIfaceAssocTuple_wrapper_registry[(void *) py_IfaceAssocTuple->obj] = (PyObject *) py_IfaceAssocTuple;
    }
    py_retval = Py_BuildValue((char *) "N", py_IfaceAssocTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseDuplicateTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrDuplicateTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrDuplicateTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseDuplicateTuple(*((PyNs3OlsrDuplicateTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_FindNeighborInterfaces(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    PyNs3Ipv4Address *neighborMainAddr;
    const char *keywords[] = {"neighborMainAddr", NULL};
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &neighborMainAddr)) {
        return NULL;
    }
    retval = self->obj->FindNeighborInterfaces(*((PyNs3Ipv4Address *) neighborMainAddr)->obj);
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertNeighborTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrNeighborTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrNeighborTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertNeighborTuple(*((PyNs3OlsrNeighborTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseIfaceAssocTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrIfaceAssocTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrIfaceAssocTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseIfaceAssocTuple(*((PyNs3OlsrIfaceAssocTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertTwoHopNeighborTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTwoHopNeighborTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTwoHopNeighborTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertTwoHopNeighborTuple(*((PyNs3OlsrTwoHopNeighborTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertMprSelectorTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrMprSelectorTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMprSelectorTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertMprSelectorTuple(*((PyNs3OlsrMprSelectorTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_EraseTopologyTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTopologyTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTopologyTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseTopologyTuple(*((PyNs3OlsrTopologyTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrState_InsertTopologyTuple(PyNs3OlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTopologyTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTopologyTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertTopologyTuple(*((PyNs3OlsrTopologyTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrState__copy__(PyNs3OlsrState *self)
{

    PyNs3OlsrState *py_copy;
    py_copy = PyObject_New(PyNs3OlsrState, &PyNs3OlsrState_Type);
    py_copy->obj = new ns3::OlsrState(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrState_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrState_methods[] = {
    {(char *) "InsertDuplicateTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertDuplicateTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseOlderTopologyTuples", (PyCFunction) _wrap_PyNs3OlsrState_EraseOlderTopologyTuples, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseLinkTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseLinkTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertLinkTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertLinkTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseMprSelectorTuples", (PyCFunction) _wrap_PyNs3OlsrState_EraseMprSelectorTuples, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindSymNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrState_FindSymNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindMprAddress", (PyCFunction) _wrap_PyNs3OlsrState_FindMprAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertIfaceAssocTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertIfaceAssocTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMprSet", (PyCFunction) _wrap_PyNs3OlsrState_GetMprSet, METH_NOARGS, NULL },
    {(char *) "EraseTwoHopNeighborTuples", (PyCFunction) _wrap_PyNs3OlsrState_EraseTwoHopNeighborTuples, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseAssociationTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseAssociationTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertAssociation", (PyCFunction) _wrap_PyNs3OlsrState_InsertAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseTwoHopNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseTwoHopNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertAssociationTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertAssociationTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PrintMprSelectorSet", (PyCFunction) _wrap_PyNs3OlsrState_PrintMprSelectorSet, METH_NOARGS, NULL },
    {(char *) "EraseMprSelectorTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseMprSelectorTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseAssociation", (PyCFunction) _wrap_PyNs3OlsrState_EraseAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMprSet", (PyCFunction) _wrap_PyNs3OlsrState_SetMprSet, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindIfaceAssocTuple", (PyCFunction) _wrap_PyNs3OlsrState_FindIfaceAssocTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseDuplicateTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseDuplicateTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindNeighborInterfaces", (PyCFunction) _wrap_PyNs3OlsrState_FindNeighborInterfaces, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseIfaceAssocTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseIfaceAssocTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertTwoHopNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertTwoHopNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertMprSelectorTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertMprSelectorTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseTopologyTuple", (PyCFunction) _wrap_PyNs3OlsrState_EraseTopologyTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertTopologyTuple", (PyCFunction) _wrap_PyNs3OlsrState_InsertTopologyTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrState__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrState__tp_dealloc(PyNs3OlsrState *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrState_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrState_wrapper_registry.end()) {
        PyNs3OlsrState_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::OlsrState *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrState__tp_richcompare (PyNs3OlsrState *PYBINDGEN_UNUSED(self), PyNs3OlsrState *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrState_Type)) {
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

PyTypeObject PyNs3OlsrState_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.OlsrState",            /* tp_name */
    sizeof(PyNs3OlsrState),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrState__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrState__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrState_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrState__tp_init,             /* tp_init */
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


