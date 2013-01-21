#include "ns3module.h"

std::map<void*, PyObject*> PyNs3Ipv4MulticastRoutingTableEntry_wrapper_registry;


static int
_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init__0(PyNs3Ipv4MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv4MulticastRoutingTableEntry();
    return 0;
}

static int
_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init__1(PyNs3Ipv4MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4MulticastRoutingTableEntry *route;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4MulticastRoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4MulticastRoutingTableEntry(*((PyNs3Ipv4MulticastRoutingTableEntry *) route)->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init__2(PyNs3Ipv4MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4MulticastRoutingTableEntry *route;
    ns3::Ipv4MulticastRoutingTableEntry *route_ptr;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4MulticastRoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    route_ptr = (route ? route->obj : NULL);
    self->obj = new ns3::Ipv4MulticastRoutingTableEntry(route_ptr);
    return 0;
}

int _wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init(PyNs3Ipv4MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetOutputInterface(PyNs3Ipv4MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    unsigned int n;
    const char *keywords[] = {"n", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &n)) {
        return NULL;
    }
    retval = self->obj->GetOutputInterface(n);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetOrigin(PyNs3Ipv4MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetOrigin();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetInputInterface(PyNs3Ipv4MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetInputInterface();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4MulticastRoutingTableEntry_CreateMulticastRoute(PyNs3Ipv4MulticastRoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *origin;
    PyNs3Ipv4Address *group;
    unsigned int inputInterface;
    std::vector< unsigned int > outputInterfaces_value;
    const char *keywords[] = {"origin", "group", "inputInterface", "outputInterfaces", NULL};
    PyNs3Ipv4MulticastRoutingTableEntry *py_Ipv4MulticastRoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!IO&", (char **) keywords, &PyNs3Ipv4Address_Type, &origin, &PyNs3Ipv4Address_Type, &group, &inputInterface, _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &outputInterfaces_value)) {
        return NULL;
    }
    ns3::Ipv4MulticastRoutingTableEntry retval = ns3::Ipv4MulticastRoutingTableEntry::CreateMulticastRoute(*((PyNs3Ipv4Address *) origin)->obj, *((PyNs3Ipv4Address *) group)->obj, inputInterface, outputInterfaces_value);
    py_Ipv4MulticastRoutingTableEntry = PyObject_New(PyNs3Ipv4MulticastRoutingTableEntry, &PyNs3Ipv4MulticastRoutingTableEntry_Type);
    py_Ipv4MulticastRoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4MulticastRoutingTableEntry->obj = new ns3::Ipv4MulticastRoutingTableEntry(retval);
    PyNs3Ipv4MulticastRoutingTableEntry_wrapper_registry[(void *) py_Ipv4MulticastRoutingTableEntry->obj] = (PyObject *) py_Ipv4MulticastRoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4MulticastRoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetNOutputInterfaces(PyNs3Ipv4MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNOutputInterfaces();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetOutputInterfaces(PyNs3Ipv4MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    std::vector< unsigned int > retval;
    Pystd__vector__lt___unsigned_int___gt__ *py_std__vector__lt___unsigned_int___gt__;
    
    retval = self->obj->GetOutputInterfaces();
    py_std__vector__lt___unsigned_int___gt__ = PyObject_New(Pystd__vector__lt___unsigned_int___gt__, &Pystd__vector__lt___unsigned_int___gt___Type);
    py_std__vector__lt___unsigned_int___gt__->obj = new std::vector< unsigned int >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_int___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetGroup(PyNs3Ipv4MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetGroup();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ipv4MulticastRoutingTableEntry__copy__(PyNs3Ipv4MulticastRoutingTableEntry *self)
{

    PyNs3Ipv4MulticastRoutingTableEntry *py_copy;
    py_copy = PyObject_New(PyNs3Ipv4MulticastRoutingTableEntry, &PyNs3Ipv4MulticastRoutingTableEntry_Type);
    py_copy->obj = new ns3::Ipv4MulticastRoutingTableEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv4MulticastRoutingTableEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv4MulticastRoutingTableEntry_methods[] = {
    {(char *) "GetOutputInterface", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetOutputInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetOrigin", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetOrigin, METH_NOARGS, NULL },
    {(char *) "GetInputInterface", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetInputInterface, METH_NOARGS, NULL },
    {(char *) "CreateMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry_CreateMulticastRoute, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "GetNOutputInterfaces", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetNOutputInterfaces, METH_NOARGS, NULL },
    {(char *) "GetOutputInterfaces", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetOutputInterfaces, METH_NOARGS, NULL },
    {(char *) "GetGroup", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry_GetGroup, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv4MulticastRoutingTableEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_dealloc(PyNs3Ipv4MulticastRoutingTableEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv4MulticastRoutingTableEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv4MulticastRoutingTableEntry_wrapper_registry.end()) {
        PyNs3Ipv4MulticastRoutingTableEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ipv4MulticastRoutingTableEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_str(PyNs3Ipv4MulticastRoutingTableEntry *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_richcompare (PyNs3Ipv4MulticastRoutingTableEntry *PYBINDGEN_UNUSED(self), PyNs3Ipv4MulticastRoutingTableEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4MulticastRoutingTableEntry_Type)) {
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

PyTypeObject PyNs3Ipv4MulticastRoutingTableEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4MulticastRoutingTableEntry",            /* tp_name */
    sizeof(PyNs3Ipv4MulticastRoutingTableEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4MulticastRoutingTableEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4MulticastRoutingTableEntry__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Ipv4RoutingTableEntry_wrapper_registry;


static int
_wrap_PyNs3Ipv4RoutingTableEntry__tp_init__0(PyNs3Ipv4RoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv4RoutingTableEntry();
    return 0;
}

static int
_wrap_PyNs3Ipv4RoutingTableEntry__tp_init__1(PyNs3Ipv4RoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4RoutingTableEntry *route;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4RoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4RoutingTableEntry(*((PyNs3Ipv4RoutingTableEntry *) route)->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv4RoutingTableEntry__tp_init__2(PyNs3Ipv4RoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4RoutingTableEntry *route;
    ns3::Ipv4RoutingTableEntry *route_ptr;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4RoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    route_ptr = (route ? route->obj : NULL);
    self->obj = new ns3::Ipv4RoutingTableEntry(route_ptr);
    return 0;
}

int _wrap_PyNs3Ipv4RoutingTableEntry__tp_init(PyNs3Ipv4RoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Ipv4RoutingTableEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4RoutingTableEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Ipv4RoutingTableEntry__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Ipv4RoutingTableEntry_IsNetwork(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsNetwork();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_IsGateway(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsGateway();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_GetGateway(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetGateway();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_IsHost(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsHost();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_GetDestNetwork(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetDestNetwork();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_CreateNetworkRouteTo__0(PyNs3Ipv4RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"network", "networkMask", "nextHop", "interface", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask, &PyNs3Ipv4Address_Type, &nextHop, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv4RoutingTableEntry retval = ns3::Ipv4RoutingTableEntry::CreateNetworkRouteTo(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj, *((PyNs3Ipv4Address *) nextHop)->obj, interface);
    py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry(retval);
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_CreateNetworkRouteTo__1(PyNs3Ipv4RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    unsigned int interface;
    const char *keywords[] = {"network", "networkMask", "interface", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv4RoutingTableEntry retval = ns3::Ipv4RoutingTableEntry::CreateNetworkRouteTo(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj, interface);
    py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry(retval);
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv4RoutingTableEntry_CreateNetworkRouteTo(PyNs3Ipv4RoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4RoutingTableEntry_CreateNetworkRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4RoutingTableEntry_CreateNetworkRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4RoutingTableEntry_GetDestNetworkMask(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    ns3::Ipv4Mask retval = self->obj->GetDestNetworkMask();
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(retval);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_GetInterface(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetInterface();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_CreateHostRouteTo__0(PyNs3Ipv4RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *dest;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"dest", "nextHop", "interface", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &dest, &PyNs3Ipv4Address_Type, &nextHop, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv4RoutingTableEntry retval = ns3::Ipv4RoutingTableEntry::CreateHostRouteTo(*((PyNs3Ipv4Address *) dest)->obj, *((PyNs3Ipv4Address *) nextHop)->obj, interface);
    py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry(retval);
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_CreateHostRouteTo__1(PyNs3Ipv4RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *dest;
    unsigned int interface;
    const char *keywords[] = {"dest", "interface", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &dest, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv4RoutingTableEntry retval = ns3::Ipv4RoutingTableEntry::CreateHostRouteTo(*((PyNs3Ipv4Address *) dest)->obj, interface);
    py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry(retval);
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv4RoutingTableEntry_CreateHostRouteTo(PyNs3Ipv4RoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4RoutingTableEntry_CreateHostRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4RoutingTableEntry_CreateHostRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4RoutingTableEntry_CreateDefaultRoute(PyNs3Ipv4RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"nextHop", "interface", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &nextHop, &interface)) {
        return NULL;
    }
    ns3::Ipv4RoutingTableEntry retval = ns3::Ipv4RoutingTableEntry::CreateDefaultRoute(*((PyNs3Ipv4Address *) nextHop)->obj, interface);
    py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry(retval);
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_IsDefault(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsDefault();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry_GetDest(PyNs3Ipv4RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetDest();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ipv4RoutingTableEntry__copy__(PyNs3Ipv4RoutingTableEntry *self)
{

    PyNs3Ipv4RoutingTableEntry *py_copy;
    py_copy = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_copy->obj = new ns3::Ipv4RoutingTableEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv4RoutingTableEntry_methods[] = {
    {(char *) "IsNetwork", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_IsNetwork, METH_NOARGS, NULL },
    {(char *) "IsGateway", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_IsGateway, METH_NOARGS, NULL },
    {(char *) "GetGateway", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_GetGateway, METH_NOARGS, NULL },
    {(char *) "IsHost", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_IsHost, METH_NOARGS, NULL },
    {(char *) "GetDestNetwork", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_GetDestNetwork, METH_NOARGS, NULL },
    {(char *) "CreateNetworkRouteTo", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_CreateNetworkRouteTo, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "GetDestNetworkMask", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_GetDestNetworkMask, METH_NOARGS, NULL },
    {(char *) "GetInterface", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_GetInterface, METH_NOARGS, NULL },
    {(char *) "CreateHostRouteTo", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_CreateHostRouteTo, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "CreateDefaultRoute", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_CreateDefaultRoute, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "IsDefault", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_IsDefault, METH_NOARGS, NULL },
    {(char *) "GetDest", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry_GetDest, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv4RoutingTableEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv4RoutingTableEntry__tp_dealloc(PyNs3Ipv4RoutingTableEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv4RoutingTableEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv4RoutingTableEntry_wrapper_registry.end()) {
        PyNs3Ipv4RoutingTableEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ipv4RoutingTableEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Ipv4RoutingTableEntry__tp_str(PyNs3Ipv4RoutingTableEntry *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Ipv4RoutingTableEntry__tp_richcompare (PyNs3Ipv4RoutingTableEntry *PYBINDGEN_UNUSED(self), PyNs3Ipv4RoutingTableEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4RoutingTableEntry_Type)) {
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

PyTypeObject PyNs3Ipv4RoutingTableEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4RoutingTableEntry",            /* tp_name */
    sizeof(PyNs3Ipv4RoutingTableEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4RoutingTableEntry__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Ipv4RoutingTableEntry__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4RoutingTableEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4RoutingTableEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4RoutingTableEntry__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Ipv6MulticastRoutingTableEntry_wrapper_registry;


static int
_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init__0(PyNs3Ipv6MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv6MulticastRoutingTableEntry();
    return 0;
}

static int
_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init__1(PyNs3Ipv6MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6MulticastRoutingTableEntry *route;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6MulticastRoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv6MulticastRoutingTableEntry(*((PyNs3Ipv6MulticastRoutingTableEntry *) route)->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init__2(PyNs3Ipv6MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6MulticastRoutingTableEntry *route;
    ns3::Ipv6MulticastRoutingTableEntry *route_ptr;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6MulticastRoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    route_ptr = (route ? route->obj : NULL);
    self->obj = new ns3::Ipv6MulticastRoutingTableEntry(route_ptr);
    return 0;
}

int _wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init(PyNs3Ipv6MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetOutputInterface(PyNs3Ipv6MulticastRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    unsigned int n;
    const char *keywords[] = {"n", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &n)) {
        return NULL;
    }
    retval = self->obj->GetOutputInterface(n);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetOrigin(PyNs3Ipv6MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetOrigin();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetInputInterface(PyNs3Ipv6MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetInputInterface();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6MulticastRoutingTableEntry_CreateMulticastRoute(PyNs3Ipv6MulticastRoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *origin;
    PyNs3Ipv6Address *group;
    unsigned int inputInterface;
    std::vector< unsigned int > outputInterfaces_value;
    const char *keywords[] = {"origin", "group", "inputInterface", "outputInterfaces", NULL};
    PyNs3Ipv6MulticastRoutingTableEntry *py_Ipv6MulticastRoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!IO&", (char **) keywords, &PyNs3Ipv6Address_Type, &origin, &PyNs3Ipv6Address_Type, &group, &inputInterface, _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &outputInterfaces_value)) {
        return NULL;
    }
    ns3::Ipv6MulticastRoutingTableEntry retval = ns3::Ipv6MulticastRoutingTableEntry::CreateMulticastRoute(*((PyNs3Ipv6Address *) origin)->obj, *((PyNs3Ipv6Address *) group)->obj, inputInterface, outputInterfaces_value);
    py_Ipv6MulticastRoutingTableEntry = PyObject_New(PyNs3Ipv6MulticastRoutingTableEntry, &PyNs3Ipv6MulticastRoutingTableEntry_Type);
    py_Ipv6MulticastRoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6MulticastRoutingTableEntry->obj = new ns3::Ipv6MulticastRoutingTableEntry(retval);
    PyNs3Ipv6MulticastRoutingTableEntry_wrapper_registry[(void *) py_Ipv6MulticastRoutingTableEntry->obj] = (PyObject *) py_Ipv6MulticastRoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6MulticastRoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetNOutputInterfaces(PyNs3Ipv6MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNOutputInterfaces();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetOutputInterfaces(PyNs3Ipv6MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    std::vector< unsigned int > retval;
    Pystd__vector__lt___unsigned_int___gt__ *py_std__vector__lt___unsigned_int___gt__;
    
    retval = self->obj->GetOutputInterfaces();
    py_std__vector__lt___unsigned_int___gt__ = PyObject_New(Pystd__vector__lt___unsigned_int___gt__, &Pystd__vector__lt___unsigned_int___gt___Type);
    py_std__vector__lt___unsigned_int___gt__->obj = new std::vector< unsigned int >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_int___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetGroup(PyNs3Ipv6MulticastRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetGroup();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ipv6MulticastRoutingTableEntry__copy__(PyNs3Ipv6MulticastRoutingTableEntry *self)
{

    PyNs3Ipv6MulticastRoutingTableEntry *py_copy;
    py_copy = PyObject_New(PyNs3Ipv6MulticastRoutingTableEntry, &PyNs3Ipv6MulticastRoutingTableEntry_Type);
    py_copy->obj = new ns3::Ipv6MulticastRoutingTableEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv6MulticastRoutingTableEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv6MulticastRoutingTableEntry_methods[] = {
    {(char *) "GetOutputInterface", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetOutputInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetOrigin", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetOrigin, METH_NOARGS, NULL },
    {(char *) "GetInputInterface", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetInputInterface, METH_NOARGS, NULL },
    {(char *) "CreateMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry_CreateMulticastRoute, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "GetNOutputInterfaces", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetNOutputInterfaces, METH_NOARGS, NULL },
    {(char *) "GetOutputInterfaces", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetOutputInterfaces, METH_NOARGS, NULL },
    {(char *) "GetGroup", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry_GetGroup, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv6MulticastRoutingTableEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_dealloc(PyNs3Ipv6MulticastRoutingTableEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv6MulticastRoutingTableEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv6MulticastRoutingTableEntry_wrapper_registry.end()) {
        PyNs3Ipv6MulticastRoutingTableEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ipv6MulticastRoutingTableEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_str(PyNs3Ipv6MulticastRoutingTableEntry *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_richcompare (PyNs3Ipv6MulticastRoutingTableEntry *PYBINDGEN_UNUSED(self), PyNs3Ipv6MulticastRoutingTableEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv6MulticastRoutingTableEntry_Type)) {
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

PyTypeObject PyNs3Ipv6MulticastRoutingTableEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv6MulticastRoutingTableEntry",            /* tp_name */
    sizeof(PyNs3Ipv6MulticastRoutingTableEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv6MulticastRoutingTableEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv6MulticastRoutingTableEntry__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Ipv6RoutingTableEntry_wrapper_registry;


static int
_wrap_PyNs3Ipv6RoutingTableEntry__tp_init__0(PyNs3Ipv6RoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv6RoutingTableEntry();
    return 0;
}

static int
_wrap_PyNs3Ipv6RoutingTableEntry__tp_init__1(PyNs3Ipv6RoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6RoutingTableEntry *route;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6RoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv6RoutingTableEntry(*((PyNs3Ipv6RoutingTableEntry *) route)->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv6RoutingTableEntry__tp_init__2(PyNs3Ipv6RoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6RoutingTableEntry *route;
    ns3::Ipv6RoutingTableEntry *route_ptr;
    const char *keywords[] = {"route", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6RoutingTableEntry_Type, &route)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    route_ptr = (route ? route->obj : NULL);
    self->obj = new ns3::Ipv6RoutingTableEntry(route_ptr);
    return 0;
}

int _wrap_PyNs3Ipv6RoutingTableEntry__tp_init(PyNs3Ipv6RoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Ipv6RoutingTableEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6RoutingTableEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Ipv6RoutingTableEntry__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Ipv6RoutingTableEntry_GetDestNetworkPrefix(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Prefix *py_Ipv6Prefix;
    
    ns3::Ipv6Prefix retval = self->obj->GetDestNetworkPrefix();
    py_Ipv6Prefix = PyObject_New(PyNs3Ipv6Prefix, &PyNs3Ipv6Prefix_Type);
    py_Ipv6Prefix->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Prefix->obj = new ns3::Ipv6Prefix(retval);
    PyNs3Ipv6Prefix_wrapper_registry[(void *) py_Ipv6Prefix->obj] = (PyObject *) py_Ipv6Prefix;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Prefix);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_IsNetwork(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsNetwork();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_GetPrefixToUse(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetPrefixToUse();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_IsGateway(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsGateway();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_GetGateway(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetGateway();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_SetPrefixToUse(PyNs3Ipv6RoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *prefix;
    const char *keywords[] = {"prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &prefix)) {
        return NULL;
    }
    self->obj->SetPrefixToUse(*((PyNs3Ipv6Address *) prefix)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_GetDestNetwork(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetDestNetwork();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo__0(PyNs3Ipv6RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *networkPrefix;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"network", "networkPrefix", "nextHop", "interface", NULL};
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &networkPrefix, &PyNs3Ipv6Address_Type, &nextHop, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv6RoutingTableEntry retval = ns3::Ipv6RoutingTableEntry::CreateNetworkRouteTo(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) networkPrefix)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface);
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo__1(PyNs3Ipv6RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *networkPrefix;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    PyNs3Ipv6Address *prefixToUse;
    const char *keywords[] = {"network", "networkPrefix", "nextHop", "interface", "prefixToUse", NULL};
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!IO!", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &networkPrefix, &PyNs3Ipv6Address_Type, &nextHop, &interface, &PyNs3Ipv6Address_Type, &prefixToUse)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv6RoutingTableEntry retval = ns3::Ipv6RoutingTableEntry::CreateNetworkRouteTo(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) networkPrefix)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface, *((PyNs3Ipv6Address *) prefixToUse)->obj);
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo__2(PyNs3Ipv6RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *networkPrefix;
    unsigned int interface;
    const char *keywords[] = {"network", "networkPrefix", "interface", NULL};
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &networkPrefix, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv6RoutingTableEntry retval = ns3::Ipv6RoutingTableEntry::CreateNetworkRouteTo(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) networkPrefix)->obj, interface);
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo(PyNs3Ipv6RoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo__2(self, args, kwargs, &exceptions[2]);
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
    return NULL;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_IsHost(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsHost();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_GetInterface(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetInterface();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_CreateHostRouteTo__0(PyNs3Ipv6RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *dest;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    PyNs3Ipv6Address *prefixToUse = NULL;
    const char *keywords[] = {"dest", "nextHop", "interface", "prefixToUse", NULL};
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I|O!", (char **) keywords, &PyNs3Ipv6Address_Type, &dest, &PyNs3Ipv6Address_Type, &nextHop, &interface, &PyNs3Ipv6Address_Type, &prefixToUse)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv6RoutingTableEntry retval = ns3::Ipv6RoutingTableEntry::CreateHostRouteTo(*((PyNs3Ipv6Address *) dest)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface, (prefixToUse ? (*((PyNs3Ipv6Address *) prefixToUse)->obj) : ns3::Ipv6Address()));
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_CreateHostRouteTo__1(PyNs3Ipv6RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *dest;
    unsigned int interface;
    const char *keywords[] = {"dest", "interface", NULL};
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &dest, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Ipv6RoutingTableEntry retval = ns3::Ipv6RoutingTableEntry::CreateHostRouteTo(*((PyNs3Ipv6Address *) dest)->obj, interface);
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv6RoutingTableEntry_CreateHostRouteTo(PyNs3Ipv6RoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv6RoutingTableEntry_CreateHostRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6RoutingTableEntry_CreateHostRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv6RoutingTableEntry_CreateDefaultRoute(PyNs3Ipv6RoutingTableEntry *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"nextHop", "interface", NULL};
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &nextHop, &interface)) {
        return NULL;
    }
    ns3::Ipv6RoutingTableEntry retval = ns3::Ipv6RoutingTableEntry::CreateDefaultRoute(*((PyNs3Ipv6Address *) nextHop)->obj, interface);
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_IsDefault(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsDefault();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry_GetDest(PyNs3Ipv6RoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetDest();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ipv6RoutingTableEntry__copy__(PyNs3Ipv6RoutingTableEntry *self)
{

    PyNs3Ipv6RoutingTableEntry *py_copy;
    py_copy = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_copy->obj = new ns3::Ipv6RoutingTableEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv6RoutingTableEntry_methods[] = {
    {(char *) "GetDestNetworkPrefix", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_GetDestNetworkPrefix, METH_NOARGS, NULL },
    {(char *) "IsNetwork", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_IsNetwork, METH_NOARGS, NULL },
    {(char *) "GetPrefixToUse", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_GetPrefixToUse, METH_NOARGS, NULL },
    {(char *) "IsGateway", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_IsGateway, METH_NOARGS, NULL },
    {(char *) "GetGateway", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_GetGateway, METH_NOARGS, NULL },
    {(char *) "SetPrefixToUse", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_SetPrefixToUse, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDestNetwork", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_GetDestNetwork, METH_NOARGS, NULL },
    {(char *) "CreateNetworkRouteTo", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_CreateNetworkRouteTo, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "IsHost", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_IsHost, METH_NOARGS, NULL },
    {(char *) "GetInterface", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_GetInterface, METH_NOARGS, NULL },
    {(char *) "CreateHostRouteTo", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_CreateHostRouteTo, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "CreateDefaultRoute", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_CreateDefaultRoute, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "IsDefault", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_IsDefault, METH_NOARGS, NULL },
    {(char *) "GetDest", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry_GetDest, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv6RoutingTableEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv6RoutingTableEntry__tp_dealloc(PyNs3Ipv6RoutingTableEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv6RoutingTableEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv6RoutingTableEntry_wrapper_registry.end()) {
        PyNs3Ipv6RoutingTableEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ipv6RoutingTableEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Ipv6RoutingTableEntry__tp_str(PyNs3Ipv6RoutingTableEntry *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Ipv6RoutingTableEntry__tp_richcompare (PyNs3Ipv6RoutingTableEntry *PYBINDGEN_UNUSED(self), PyNs3Ipv6RoutingTableEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv6RoutingTableEntry_Type)) {
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

PyTypeObject PyNs3Ipv6RoutingTableEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv6RoutingTableEntry",            /* tp_name */
    sizeof(PyNs3Ipv6RoutingTableEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv6RoutingTableEntry__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Ipv6RoutingTableEntry__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv6RoutingTableEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv6RoutingTableEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv6RoutingTableEntry__tp_init,             /* tp_init */
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
_wrap_PyNs3Ipv4StaticRouting__tp_init__0(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4StaticRouting *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4StaticRouting_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4StaticRouting(*((PyNs3Ipv4StaticRouting *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv4StaticRouting__tp_init__1(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv4StaticRouting();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

int _wrap_PyNs3Ipv4StaticRouting__tp_init(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4StaticRouting__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4StaticRouting__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4StaticRouting_NotifyAddAddress(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    PyNs3Ipv4InterfaceAddress *address;
    const char *keywords[] = {"interface", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &interface, &PyNs3Ipv4InterfaceAddress_Type, &address)) {
        return NULL;
    }
    self->obj->NotifyAddAddress(interface, *((PyNs3Ipv4InterfaceAddress *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv4StaticRouting_RemoveMulticastRoute__0(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *origin;
    PyNs3Ipv4Address *group;
    unsigned int inputInterface;
    const char *keywords[] = {"origin", "group", "inputInterface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &origin, &PyNs3Ipv4Address_Type, &group, &inputInterface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->RemoveMulticastRoute(*((PyNs3Ipv4Address *) origin)->obj, *((PyNs3Ipv4Address *) group)->obj, inputInterface);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv4StaticRouting_RemoveMulticastRoute__1(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->RemoveMulticastRoute(index);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv4StaticRouting_RemoveMulticastRoute(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4StaticRouting_RemoveMulticastRoute__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4StaticRouting_RemoveMulticastRoute__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4StaticRouting_NotifyInterfaceUp(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->NotifyInterfaceUp(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_NotifyInterfaceDown(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->NotifyInterfaceDown(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_SetIpv4(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4 *ipv4;
    ns3::Ipv4 *ipv4_ptr;
    const char *keywords[] = {"ipv4", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4_Type, &ipv4)) {
        return NULL;
    }
    ipv4_ptr = (ipv4 ? ipv4->obj : NULL);
    self->obj->SetIpv4(ns3::Ptr< ns3::Ipv4  > (ipv4_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_GetNRoutes(PyNs3Ipv4StaticRouting *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNRoutes();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv4StaticRouting_AddHostRouteTo__0(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *dest;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"dest", "nextHop", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I|I", (char **) keywords, &PyNs3Ipv4Address_Type, &dest, &PyNs3Ipv4Address_Type, &nextHop, &interface, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddHostRouteTo(*((PyNs3Ipv4Address *) dest)->obj, *((PyNs3Ipv4Address *) nextHop)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv4StaticRouting_AddHostRouteTo__1(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *dest;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"dest", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I|I", (char **) keywords, &PyNs3Ipv4Address_Type, &dest, &interface, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddHostRouteTo(*((PyNs3Ipv4Address *) dest)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv4StaticRouting_AddHostRouteTo(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4StaticRouting_AddHostRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4StaticRouting_AddHostRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4StaticRouting_GetMulticastRoute(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4MulticastRoutingTableEntry *py_Ipv4MulticastRoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv4MulticastRoutingTableEntry retval = self->obj->GetMulticastRoute(i);
    py_Ipv4MulticastRoutingTableEntry = PyObject_New(PyNs3Ipv4MulticastRoutingTableEntry, &PyNs3Ipv4MulticastRoutingTableEntry_Type);
    py_Ipv4MulticastRoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4MulticastRoutingTableEntry->obj = new ns3::Ipv4MulticastRoutingTableEntry(retval);
    PyNs3Ipv4MulticastRoutingTableEntry_wrapper_registry[(void *) py_Ipv4MulticastRoutingTableEntry->obj] = (PyObject *) py_Ipv4MulticastRoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4MulticastRoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_AddMulticastRoute(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *origin;
    PyNs3Ipv4Address *group;
    unsigned int inputInterface;
    std::vector< unsigned int > outputInterfaces_value;
    const char *keywords[] = {"origin", "group", "inputInterface", "outputInterfaces", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!IO&", (char **) keywords, &PyNs3Ipv4Address_Type, &origin, &PyNs3Ipv4Address_Type, &group, &inputInterface, _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &outputInterfaces_value)) {
        return NULL;
    }
    self->obj->AddMulticastRoute(*((PyNs3Ipv4Address *) origin)->obj, *((PyNs3Ipv4Address *) group)->obj, inputInterface, outputInterfaces_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv4StaticRouting_AddNetworkRouteTo__0(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"network", "networkMask", "nextHop", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I|I", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask, &PyNs3Ipv4Address_Type, &nextHop, &interface, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddNetworkRouteTo(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj, *((PyNs3Ipv4Address *) nextHop)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv4StaticRouting_AddNetworkRouteTo__1(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"network", "networkMask", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I|I", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask, &interface, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddNetworkRouteTo(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv4StaticRouting_AddNetworkRouteTo(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4StaticRouting_AddNetworkRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4StaticRouting_AddNetworkRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4StaticRouting_GetNMulticastRoutes(PyNs3Ipv4StaticRouting *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNMulticastRoutes();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_RouteOutput(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv4Route > retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    PyNs3Ipv4Header *header;
    PyNs3NetDevice *oif;
    ns3::NetDevice *oif_ptr;
    ns3::Socket::SocketErrno  sockerr;
    const char *keywords[] = {"p", "header", "oif", "sockerr", NULL};
    PyNs3Ipv4Route *py_Ipv4Route;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!i", (char **) keywords, &PyNs3Packet_Type, &p, &PyNs3Ipv4Header_Type, &header, &PyNs3NetDevice_Type, &oif, &sockerr)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    oif_ptr = (oif ? oif->obj : NULL);
    retval = self->obj->RouteOutput(ns3::Ptr< ns3::Packet  > (p_ptr), *((PyNs3Ipv4Header *) header)->obj, ns3::Ptr< ns3::NetDevice  > (oif_ptr), sockerr);
    if (!(const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_Ipv4Route = NULL;
    } else {
        py_Ipv4Route = (PyNs3Ipv4Route *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4Route);
    }
    
    if (py_Ipv4Route == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)))), &PyNs3Ipv4Route_Type);
        py_Ipv4Route = PyObject_New(PyNs3Ipv4Route, wrapper_type);
        py_Ipv4Route->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv4Route->obj = const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_Ipv4Route->obj] = (PyObject *) py_Ipv4Route;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Route);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_GetMetric(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetMetric(index);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_GetRoute(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv4RoutingTableEntry retval = self->obj->GetRoute(i);
    py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry(retval);
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_SetDefaultMulticastRoute(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int outputInterface;
    const char *keywords[] = {"outputInterface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &outputInterface)) {
        return NULL;
    }
    self->obj->SetDefaultMulticastRoute(outputInterface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_GetDefaultRoute(PyNs3Ipv4StaticRouting *self)
{
    PyObject *py_retval;
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    
    ns3::Ipv4RoutingTableEntry retval = self->obj->GetDefaultRoute();
    py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
    py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry(retval);
    PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_SetDefaultRoute(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"nextHop", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I|I", (char **) keywords, &PyNs3Ipv4Address_Type, &nextHop, &interface, &metric)) {
        return NULL;
    }
    self->obj->SetDefaultRoute(*((PyNs3Ipv4Address *) nextHop)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_RemoveRoute(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    self->obj->RemoveRoute(i);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ipv4StaticRouting::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4StaticRouting_NotifyRemoveAddress(PyNs3Ipv4StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    PyNs3Ipv4InterfaceAddress *address;
    const char *keywords[] = {"interface", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &interface, &PyNs3Ipv4InterfaceAddress_Type, &address)) {
        return NULL;
    }
    self->obj->NotifyRemoveAddress(interface, *((PyNs3Ipv4InterfaceAddress *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ipv4StaticRouting__copy__(PyNs3Ipv4StaticRouting *self)
{

    PyNs3Ipv4StaticRouting *py_copy;
    py_copy = PyObject_GC_New(PyNs3Ipv4StaticRouting, &PyNs3Ipv4StaticRouting_Type);
    py_copy->obj = new ns3::Ipv4StaticRouting(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv4StaticRouting_methods[] = {
    {(char *) "NotifyAddAddress", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_NotifyAddAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RemoveMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_RemoveMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceUp", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_NotifyInterfaceUp, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceDown", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_NotifyInterfaceDown, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIpv4", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_SetIpv4, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNRoutes", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_GetNRoutes, METH_NOARGS, NULL },
    {(char *) "AddHostRouteTo", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_AddHostRouteTo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_GetMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_AddMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddNetworkRouteTo", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_AddNetworkRouteTo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNMulticastRoutes", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_GetNMulticastRoutes, METH_NOARGS, NULL },
    {(char *) "RouteOutput", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_RouteOutput, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMetric", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_GetMetric, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_GetRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_SetDefaultMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDefaultRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_GetDefaultRoute, METH_NOARGS, NULL },
    {(char *) "SetDefaultRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_SetDefaultRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RemoveRoute", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_RemoveRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyRemoveAddress", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting_NotifyRemoveAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv4StaticRouting__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ipv4StaticRouting__tp_clear(PyNs3Ipv4StaticRouting *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ipv4StaticRouting *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ipv4StaticRouting__tp_traverse(PyNs3Ipv4StaticRouting *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3Ipv4StaticRouting__tp_dealloc(PyNs3Ipv4StaticRouting *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ipv4StaticRouting__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4StaticRouting__tp_richcompare (PyNs3Ipv4StaticRouting *PYBINDGEN_UNUSED(self), PyNs3Ipv4StaticRouting *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4StaticRouting_Type)) {
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

PyTypeObject PyNs3Ipv4StaticRouting_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4StaticRouting",            /* tp_name */
    sizeof(PyNs3Ipv4StaticRouting),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4StaticRouting__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Ipv4StaticRouting__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ipv4StaticRouting__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4StaticRouting__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4StaticRouting_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ipv4StaticRouting, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4StaticRouting__tp_init,             /* tp_init */
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
_wrap_PyNs3Ipv6StaticRouting__tp_init__0(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6StaticRouting *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6StaticRouting_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv6StaticRouting(*((PyNs3Ipv6StaticRouting *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv6StaticRouting__tp_init__1(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv6StaticRouting();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

int _wrap_PyNs3Ipv6StaticRouting__tp_init(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv6StaticRouting__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6StaticRouting__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv6StaticRouting_NotifyAddAddress(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    PyNs3Ipv6InterfaceAddress *address;
    const char *keywords[] = {"interface", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &interface, &PyNs3Ipv6InterfaceAddress_Type, &address)) {
        return NULL;
    }
    self->obj->NotifyAddAddress(interface, *((PyNs3Ipv6InterfaceAddress *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv6StaticRouting_RemoveMulticastRoute__0(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv6Address *origin;
    PyNs3Ipv6Address *group;
    unsigned int inputInterface;
    const char *keywords[] = {"origin", "group", "inputInterface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &origin, &PyNs3Ipv6Address_Type, &group, &inputInterface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->RemoveMulticastRoute(*((PyNs3Ipv6Address *) origin)->obj, *((PyNs3Ipv6Address *) group)->obj, inputInterface);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6StaticRouting_RemoveMulticastRoute__1(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->RemoveMulticastRoute(i);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv6StaticRouting_RemoveMulticastRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv6StaticRouting_RemoveMulticastRoute__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6StaticRouting_RemoveMulticastRoute__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo__0(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *networkPrefix;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"network", "networkPrefix", "nextHop", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I|I", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &networkPrefix, &PyNs3Ipv6Address_Type, &nextHop, &interface, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddNetworkRouteTo(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) networkPrefix)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo__1(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *networkPrefix;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    PyNs3Ipv6Address *prefixToUse;
    unsigned int metric = 0;
    const char *keywords[] = {"network", "networkPrefix", "nextHop", "interface", "prefixToUse", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!IO!|I", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &networkPrefix, &PyNs3Ipv6Address_Type, &nextHop, &interface, &PyNs3Ipv6Address_Type, &prefixToUse, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddNetworkRouteTo(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) networkPrefix)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface, *((PyNs3Ipv6Address *) prefixToUse)->obj, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo__2(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *networkPrefix;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"network", "networkPrefix", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I|I", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &networkPrefix, &interface, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddNetworkRouteTo(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) networkPrefix)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo__2(self, args, kwargs, &exceptions[2]);
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
    return NULL;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_GetMetric(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetMetric(index);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_GetRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv6RoutingTableEntry retval = self->obj->GetRoute(i);
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_HasNetworkDest(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv6Address *dest;
    unsigned int interfaceIndex;
    const char *keywords[] = {"dest", "interfaceIndex", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &dest, &interfaceIndex)) {
        return NULL;
    }
    retval = self->obj->HasNetworkDest(*((PyNs3Ipv6Address *) dest)->obj, interfaceIndex);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_NotifyAddRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *dst;
    PyNs3Ipv6Prefix *mask;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    PyNs3Ipv6Address *prefixToUse = NULL;
    const char *keywords[] = {"dst", "mask", "nextHop", "interface", "prefixToUse", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I|O!", (char **) keywords, &PyNs3Ipv6Address_Type, &dst, &PyNs3Ipv6Prefix_Type, &mask, &PyNs3Ipv6Address_Type, &nextHop, &interface, &PyNs3Ipv6Address_Type, &prefixToUse)) {
        return NULL;
    }
    self->obj->NotifyAddRoute(*((PyNs3Ipv6Address *) dst)->obj, *((PyNs3Ipv6Prefix *) mask)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface, (prefixToUse ? (*((PyNs3Ipv6Address *) prefixToUse)->obj) : ns3::Ipv6Address::GetZero( )));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_NotifyInterfaceDown(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->NotifyInterfaceDown(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_GetDefaultRoute(PyNs3Ipv6StaticRouting *self)
{
    PyObject *py_retval;
    PyNs3Ipv6RoutingTableEntry *py_Ipv6RoutingTableEntry;
    
    ns3::Ipv6RoutingTableEntry retval = self->obj->GetDefaultRoute();
    py_Ipv6RoutingTableEntry = PyObject_New(PyNs3Ipv6RoutingTableEntry, &PyNs3Ipv6RoutingTableEntry_Type);
    py_Ipv6RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6RoutingTableEntry->obj = new ns3::Ipv6RoutingTableEntry(retval);
    PyNs3Ipv6RoutingTableEntry_wrapper_registry[(void *) py_Ipv6RoutingTableEntry->obj] = (PyObject *) py_Ipv6RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_GetNMulticastRoutes(PyNs3Ipv6StaticRouting *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNMulticastRoutes();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_NotifyRemoveRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *dst;
    PyNs3Ipv6Prefix *mask;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    PyNs3Ipv6Address *prefixToUse = NULL;
    const char *keywords[] = {"dst", "mask", "nextHop", "interface", "prefixToUse", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I|O!", (char **) keywords, &PyNs3Ipv6Address_Type, &dst, &PyNs3Ipv6Prefix_Type, &mask, &PyNs3Ipv6Address_Type, &nextHop, &interface, &PyNs3Ipv6Address_Type, &prefixToUse)) {
        return NULL;
    }
    self->obj->NotifyRemoveRoute(*((PyNs3Ipv6Address *) dst)->obj, *((PyNs3Ipv6Prefix *) mask)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface, (prefixToUse ? (*((PyNs3Ipv6Address *) prefixToUse)->obj) : ns3::Ipv6Address::GetZero( )));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_SetIpv6(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6 *ipv6;
    ns3::Ipv6 *ipv6_ptr;
    const char *keywords[] = {"ipv6", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6_Type, &ipv6)) {
        return NULL;
    }
    ipv6_ptr = (ipv6 ? ipv6->obj : NULL);
    self->obj->SetIpv6(ns3::Ptr< ns3::Ipv6  > (ipv6_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv6StaticRouting_RemoveRoute__0(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->RemoveRoute(i);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6StaticRouting_RemoveRoute__1(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *prefix;
    unsigned int ifIndex;
    PyNs3Ipv6Address *prefixToUse;
    const char *keywords[] = {"network", "prefix", "ifIndex", "prefixToUse", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!IO!", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &prefix, &ifIndex, &PyNs3Ipv6Address_Type, &prefixToUse)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->RemoveRoute(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) prefix)->obj, ifIndex, *((PyNs3Ipv6Address *) prefixToUse)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv6StaticRouting_RemoveRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv6StaticRouting_RemoveRoute__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6StaticRouting_RemoveRoute__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv6StaticRouting_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ipv6StaticRouting::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_NotifyInterfaceUp(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->NotifyInterfaceUp(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv6StaticRouting_AddHostRouteTo__0(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *dest;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    PyNs3Ipv6Address *prefixToUse = NULL;
    unsigned int metric = 0;
    const char *keywords[] = {"dest", "nextHop", "interface", "prefixToUse", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I|O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &dest, &PyNs3Ipv6Address_Type, &nextHop, &interface, &PyNs3Ipv6Address_Type, &prefixToUse, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddHostRouteTo(*((PyNs3Ipv6Address *) dest)->obj, *((PyNs3Ipv6Address *) nextHop)->obj, interface, (prefixToUse ? (*((PyNs3Ipv6Address *) prefixToUse)->obj) : ns3::Ipv6Address(((const char*)"::"))), metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv6StaticRouting_AddHostRouteTo__1(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *dest;
    unsigned int interface;
    unsigned int metric = 0;
    const char *keywords[] = {"dest", "interface", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I|I", (char **) keywords, &PyNs3Ipv6Address_Type, &dest, &interface, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddHostRouteTo(*((PyNs3Ipv6Address *) dest)->obj, interface, metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv6StaticRouting_AddHostRouteTo(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv6StaticRouting_AddHostRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6StaticRouting_AddHostRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv6StaticRouting_GetMulticastRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv6MulticastRoutingTableEntry *py_Ipv6MulticastRoutingTableEntry;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv6MulticastRoutingTableEntry retval = self->obj->GetMulticastRoute(i);
    py_Ipv6MulticastRoutingTableEntry = PyObject_New(PyNs3Ipv6MulticastRoutingTableEntry, &PyNs3Ipv6MulticastRoutingTableEntry_Type);
    py_Ipv6MulticastRoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6MulticastRoutingTableEntry->obj = new ns3::Ipv6MulticastRoutingTableEntry(retval);
    PyNs3Ipv6MulticastRoutingTableEntry_wrapper_registry[(void *) py_Ipv6MulticastRoutingTableEntry->obj] = (PyObject *) py_Ipv6MulticastRoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6MulticastRoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_NotifyRemoveAddress(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    PyNs3Ipv6InterfaceAddress *address;
    const char *keywords[] = {"interface", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &interface, &PyNs3Ipv6InterfaceAddress_Type, &address)) {
        return NULL;
    }
    self->obj->NotifyRemoveAddress(interface, *((PyNs3Ipv6InterfaceAddress *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_GetNRoutes(PyNs3Ipv6StaticRouting *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNRoutes();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_AddMulticastRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *origin;
    PyNs3Ipv6Address *group;
    unsigned int inputInterface;
    std::vector< unsigned int > outputInterfaces_value;
    const char *keywords[] = {"origin", "group", "inputInterface", "outputInterfaces", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!IO&", (char **) keywords, &PyNs3Ipv6Address_Type, &origin, &PyNs3Ipv6Address_Type, &group, &inputInterface, _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &outputInterfaces_value)) {
        return NULL;
    }
    self->obj->AddMulticastRoute(*((PyNs3Ipv6Address *) origin)->obj, *((PyNs3Ipv6Address *) group)->obj, inputInterface, outputInterfaces_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_RouteOutput(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv6Route > retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    PyNs3Ipv6Header *header;
    PyNs3NetDevice *oif;
    ns3::NetDevice *oif_ptr;
    ns3::Socket::SocketErrno  sockerr;
    const char *keywords[] = {"p", "header", "oif", "sockerr", NULL};
    PyNs3Ipv6Route *py_Ipv6Route;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!i", (char **) keywords, &PyNs3Packet_Type, &p, &PyNs3Ipv6Header_Type, &header, &PyNs3NetDevice_Type, &oif, &sockerr)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    oif_ptr = (oif ? oif->obj : NULL);
    retval = self->obj->RouteOutput(ns3::Ptr< ns3::Packet  > (p_ptr), *((PyNs3Ipv6Header *) header)->obj, ns3::Ptr< ns3::NetDevice  > (oif_ptr), sockerr);
    if (!(const_cast<ns3::Ipv6Route *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::Ipv6Route *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_Ipv6Route = NULL;
    } else {
        py_Ipv6Route = (PyNs3Ipv6Route *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv6Route);
    }
    
    if (py_Ipv6Route == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Ipv6Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv6Route__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv6Route *> (ns3::PeekPointer (retval)))), &PyNs3Ipv6Route_Type);
        py_Ipv6Route = PyObject_New(PyNs3Ipv6Route, wrapper_type);
        py_Ipv6Route->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv6Route *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv6Route->obj = const_cast<ns3::Ipv6Route *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_Ipv6Route->obj] = (PyObject *) py_Ipv6Route;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Route);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_SetDefaultMulticastRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int outputInterface;
    const char *keywords[] = {"outputInterface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &outputInterface)) {
        return NULL;
    }
    self->obj->SetDefaultMulticastRoute(outputInterface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6StaticRouting_SetDefaultRoute(PyNs3Ipv6StaticRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *nextHop;
    unsigned int interface;
    PyNs3Ipv6Address *prefixToUse = NULL;
    unsigned int metric = 0;
    const char *keywords[] = {"nextHop", "interface", "prefixToUse", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I|O!I", (char **) keywords, &PyNs3Ipv6Address_Type, &nextHop, &interface, &PyNs3Ipv6Address_Type, &prefixToUse, &metric)) {
        return NULL;
    }
    self->obj->SetDefaultRoute(*((PyNs3Ipv6Address *) nextHop)->obj, interface, (prefixToUse ? (*((PyNs3Ipv6Address *) prefixToUse)->obj) : ns3::Ipv6Address(((const char*)"::"))), metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ipv6StaticRouting__copy__(PyNs3Ipv6StaticRouting *self)
{

    PyNs3Ipv6StaticRouting *py_copy;
    py_copy = PyObject_GC_New(PyNs3Ipv6StaticRouting, &PyNs3Ipv6StaticRouting_Type);
    py_copy->obj = new ns3::Ipv6StaticRouting(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv6StaticRouting_methods[] = {
    {(char *) "NotifyAddAddress", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_NotifyAddAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RemoveMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_RemoveMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddNetworkRouteTo", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_AddNetworkRouteTo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMetric", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_GetMetric, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_GetRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "HasNetworkDest", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_HasNetworkDest, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyAddRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_NotifyAddRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceDown", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_NotifyInterfaceDown, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDefaultRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_GetDefaultRoute, METH_NOARGS, NULL },
    {(char *) "GetNMulticastRoutes", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_GetNMulticastRoutes, METH_NOARGS, NULL },
    {(char *) "NotifyRemoveRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_NotifyRemoveRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIpv6", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_SetIpv6, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RemoveRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_RemoveRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyInterfaceUp", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_NotifyInterfaceUp, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddHostRouteTo", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_AddHostRouteTo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_GetMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyRemoveAddress", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_NotifyRemoveAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNRoutes", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_GetNRoutes, METH_NOARGS, NULL },
    {(char *) "AddMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_AddMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RouteOutput", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_RouteOutput, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultMulticastRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_SetDefaultMulticastRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultRoute", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting_SetDefaultRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv6StaticRouting__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ipv6StaticRouting__tp_clear(PyNs3Ipv6StaticRouting *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ipv6StaticRouting *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ipv6StaticRouting__tp_traverse(PyNs3Ipv6StaticRouting *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3Ipv6StaticRouting__tp_dealloc(PyNs3Ipv6StaticRouting *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ipv6StaticRouting__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv6StaticRouting__tp_richcompare (PyNs3Ipv6StaticRouting *PYBINDGEN_UNUSED(self), PyNs3Ipv6StaticRouting *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv6StaticRouting_Type)) {
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

PyTypeObject PyNs3Ipv6StaticRouting_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv6StaticRouting",            /* tp_name */
    sizeof(PyNs3Ipv6StaticRouting),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv6StaticRouting__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Ipv6StaticRouting__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ipv6StaticRouting__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv6StaticRouting__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv6StaticRouting_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ipv6StaticRouting, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv6StaticRouting__tp_init,             /* tp_init */
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


