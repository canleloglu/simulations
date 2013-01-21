#include "ns3module.h"



static int
_wrap_PyNs3Ipv4ListRouting__tp_init__0(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4ListRouting *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4ListRouting_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4ListRouting(*((PyNs3Ipv4ListRouting *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv4ListRouting__tp_init__1(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv4ListRouting();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

int _wrap_PyNs3Ipv4ListRouting__tp_init(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4ListRouting__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4ListRouting__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4ListRouting_NotifyAddAddress(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4ListRouting_NotifyInterfaceUp(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4ListRouting_NotifyInterfaceDown(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4ListRouting_GetRoutingProtocol(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv4RoutingProtocol > retval;
    unsigned int index;
    int16_t  priority;
    const char *keywords[] = {"index", NULL};
    PyNs3Ipv4RoutingProtocol *py_Ipv4RoutingProtocol;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetRoutingProtocol(index, priority);
    if (!(const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_Ipv4RoutingProtocol = NULL;
    } else {
        py_Ipv4RoutingProtocol = (PyNs3Ipv4RoutingProtocol *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4RoutingProtocol);
    }
    
    if (py_Ipv4RoutingProtocol == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval)))), &PyNs3Ipv4RoutingProtocol_Type);
        py_Ipv4RoutingProtocol = PyObject_GC_New(PyNs3Ipv4RoutingProtocol, wrapper_type);
        py_Ipv4RoutingProtocol->inst_dict = NULL;
        py_Ipv4RoutingProtocol->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv4RoutingProtocol->obj = const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_Ipv4RoutingProtocol->obj] = (PyObject *) py_Ipv4RoutingProtocol;
    }
    py_retval = Py_BuildValue((char *) "Nh", py_Ipv4RoutingProtocol, priority);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4ListRouting_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ipv4ListRouting::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4ListRouting_RouteOutput(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4ListRouting_SetIpv4(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4ListRouting_AddRoutingProtocol(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4RoutingProtocol *routingProtocol;
    ns3::Ipv4RoutingProtocol *routingProtocol_ptr;
    int priority;
    const char *keywords[] = {"routingProtocol", "priority", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4RoutingProtocol_Type, &routingProtocol, &priority)) {
        return NULL;
    }
    routingProtocol_ptr = (routingProtocol ? routingProtocol->obj : NULL);
    if (priority > 0x7fff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->AddRoutingProtocol(ns3::Ptr< ns3::Ipv4RoutingProtocol  > (routingProtocol_ptr), priority);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4ListRouting_GetNRoutingProtocols(PyNs3Ipv4ListRouting *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNRoutingProtocols();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4ListRouting_NotifyRemoveAddress(PyNs3Ipv4ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4ListRouting__copy__(PyNs3Ipv4ListRouting *self)
{

    PyNs3Ipv4ListRouting *py_copy;
    py_copy = PyObject_GC_New(PyNs3Ipv4ListRouting, &PyNs3Ipv4ListRouting_Type);
    py_copy->obj = new ns3::Ipv4ListRouting(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv4ListRouting_methods[] = {
    {(char *) "NotifyAddAddress", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_NotifyAddAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceUp", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_NotifyInterfaceUp, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceDown", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_NotifyInterfaceDown, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRoutingProtocol", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_GetRoutingProtocol, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "RouteOutput", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_RouteOutput, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIpv4", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_SetIpv4, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddRoutingProtocol", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_AddRoutingProtocol, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNRoutingProtocols", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_GetNRoutingProtocols, METH_NOARGS, NULL },
    {(char *) "NotifyRemoveAddress", (PyCFunction) _wrap_PyNs3Ipv4ListRouting_NotifyRemoveAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv4ListRouting__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ipv4ListRouting__tp_clear(PyNs3Ipv4ListRouting *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ipv4ListRouting *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ipv4ListRouting__tp_traverse(PyNs3Ipv4ListRouting *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3Ipv4ListRouting__tp_dealloc(PyNs3Ipv4ListRouting *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ipv4ListRouting__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4ListRouting__tp_richcompare (PyNs3Ipv4ListRouting *PYBINDGEN_UNUSED(self), PyNs3Ipv4ListRouting *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4ListRouting_Type)) {
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

PyTypeObject PyNs3Ipv4ListRouting_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4ListRouting",            /* tp_name */
    sizeof(PyNs3Ipv4ListRouting),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4ListRouting__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Ipv4ListRouting__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ipv4ListRouting__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4ListRouting__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4ListRouting_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ipv4ListRouting, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4ListRouting__tp_init,             /* tp_init */
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
_wrap_PyNs3Ipv6ListRouting__tp_init__0(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6ListRouting *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6ListRouting_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv6ListRouting(*((PyNs3Ipv6ListRouting *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv6ListRouting__tp_init__1(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv6ListRouting();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

int _wrap_PyNs3Ipv6ListRouting__tp_init(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv6ListRouting__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6ListRouting__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv6ListRouting_NotifyAddAddress(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv6ListRouting_NotifyAddRoute(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv6ListRouting_NotifyInterfaceUp(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv6ListRouting_NotifyInterfaceDown(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv6ListRouting_GetRoutingProtocol(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv6RoutingProtocol > retval;
    unsigned int index;
    int16_t  priority;
    const char *keywords[] = {"index", "priority", NULL};
    PyNs3Ipv6RoutingProtocol *py_Ipv6RoutingProtocol;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Ih", (char **) keywords, &index, &priority)) {
        return NULL;
    }
    retval = self->obj->GetRoutingProtocol(index, priority);
    if (!(const_cast<ns3::Ipv6RoutingProtocol *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Ipv6RoutingProtocol *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_Ipv6RoutingProtocol = NULL;
    } else {
        py_Ipv6RoutingProtocol = (PyNs3Ipv6RoutingProtocol *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv6RoutingProtocol);
    }
    
    if (py_Ipv6RoutingProtocol == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv6RoutingProtocol *> (ns3::PeekPointer (retval)))), &PyNs3Ipv6RoutingProtocol_Type);
        py_Ipv6RoutingProtocol = PyObject_GC_New(PyNs3Ipv6RoutingProtocol, wrapper_type);
        py_Ipv6RoutingProtocol->inst_dict = NULL;
        py_Ipv6RoutingProtocol->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv6RoutingProtocol *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv6RoutingProtocol->obj = const_cast<ns3::Ipv6RoutingProtocol *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_Ipv6RoutingProtocol->obj] = (PyObject *) py_Ipv6RoutingProtocol;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv6RoutingProtocol);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6ListRouting_RouteOutput(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv6ListRouting_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ipv6ListRouting::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6ListRouting_NotifyRemoveRoute(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv6ListRouting_SetIpv6(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv6ListRouting_AddRoutingProtocol(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6RoutingProtocol *routingProtocol;
    ns3::Ipv6RoutingProtocol *routingProtocol_ptr;
    int priority;
    const char *keywords[] = {"routingProtocol", "priority", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv6RoutingProtocol_Type, &routingProtocol, &priority)) {
        return NULL;
    }
    routingProtocol_ptr = (routingProtocol ? routingProtocol->obj : NULL);
    if (priority > 0x7fff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->AddRoutingProtocol(ns3::Ptr< ns3::Ipv6RoutingProtocol  > (routingProtocol_ptr), priority);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6ListRouting_GetNRoutingProtocols(PyNs3Ipv6ListRouting *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNRoutingProtocols();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6ListRouting_NotifyRemoveAddress(PyNs3Ipv6ListRouting *self, PyObject *args, PyObject *kwargs)
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


static PyObject*
_wrap_PyNs3Ipv6ListRouting__copy__(PyNs3Ipv6ListRouting *self)
{

    PyNs3Ipv6ListRouting *py_copy;
    py_copy = PyObject_GC_New(PyNs3Ipv6ListRouting, &PyNs3Ipv6ListRouting_Type);
    py_copy->obj = new ns3::Ipv6ListRouting(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv6ListRouting_methods[] = {
    {(char *) "NotifyAddAddress", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_NotifyAddAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyAddRoute", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_NotifyAddRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceUp", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_NotifyInterfaceUp, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceDown", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_NotifyInterfaceDown, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRoutingProtocol", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_GetRoutingProtocol, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RouteOutput", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_RouteOutput, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyRemoveRoute", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_NotifyRemoveRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIpv6", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_SetIpv6, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddRoutingProtocol", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_AddRoutingProtocol, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNRoutingProtocols", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_GetNRoutingProtocols, METH_NOARGS, NULL },
    {(char *) "NotifyRemoveAddress", (PyCFunction) _wrap_PyNs3Ipv6ListRouting_NotifyRemoveAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv6ListRouting__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ipv6ListRouting__tp_clear(PyNs3Ipv6ListRouting *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ipv6ListRouting *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ipv6ListRouting__tp_traverse(PyNs3Ipv6ListRouting *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3Ipv6ListRouting__tp_dealloc(PyNs3Ipv6ListRouting *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ipv6ListRouting__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv6ListRouting__tp_richcompare (PyNs3Ipv6ListRouting *PYBINDGEN_UNUSED(self), PyNs3Ipv6ListRouting *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv6ListRouting_Type)) {
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

PyTypeObject PyNs3Ipv6ListRouting_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv6ListRouting",            /* tp_name */
    sizeof(PyNs3Ipv6ListRouting),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv6ListRouting__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Ipv6ListRouting__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ipv6ListRouting__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv6ListRouting__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv6ListRouting_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ipv6ListRouting, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv6ListRouting__tp_init,             /* tp_init */
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


