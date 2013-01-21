#include "ns3module.h"

std::map<void*, PyObject*> PyNs3GlobalRouteManager_wrapper_registry;

static int
_wrap_PyNs3GlobalRouteManager__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'GlobalRouteManager' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3GlobalRouteManager_BuildGlobalRoutingDatabase(void)
{
    PyObject *py_retval;
    
    ns3::GlobalRouteManager::BuildGlobalRoutingDatabase();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouteManager_InitializeRoutes(void)
{
    PyObject *py_retval;
    
    ns3::GlobalRouteManager::InitializeRoutes();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouteManager_DeleteGlobalRoutes(void)
{
    PyObject *py_retval;
    
    ns3::GlobalRouteManager::DeleteGlobalRoutes();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouteManager_AllocateRouterId(void)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = ns3::GlobalRouteManager::AllocateRouterId();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}

static PyMethodDef PyNs3GlobalRouteManager_methods[] = {
    {(char *) "BuildGlobalRoutingDatabase", (PyCFunction) _wrap_PyNs3GlobalRouteManager_BuildGlobalRoutingDatabase, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "InitializeRoutes", (PyCFunction) _wrap_PyNs3GlobalRouteManager_InitializeRoutes, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "DeleteGlobalRoutes", (PyCFunction) _wrap_PyNs3GlobalRouteManager_DeleteGlobalRoutes, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AllocateRouterId", (PyCFunction) _wrap_PyNs3GlobalRouteManager_AllocateRouterId, METH_NOARGS|METH_STATIC, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3GlobalRouteManager__tp_dealloc(PyNs3GlobalRouteManager *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GlobalRouteManager_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GlobalRouteManager_wrapper_registry.end()) {
        PyNs3GlobalRouteManager_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::GlobalRouteManager *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GlobalRouteManager__tp_richcompare (PyNs3GlobalRouteManager *PYBINDGEN_UNUSED(self), PyNs3GlobalRouteManager *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GlobalRouteManager_Type)) {
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

PyTypeObject PyNs3GlobalRouteManager_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.GlobalRouteManager",            /* tp_name */
    sizeof(PyNs3GlobalRouteManager),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GlobalRouteManager__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3GlobalRouteManager__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GlobalRouteManager_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GlobalRouteManager__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3GlobalRoutingLSA_wrapper_registry;


static int
_wrap_PyNs3GlobalRoutingLSA__tp_init__0(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::GlobalRoutingLSA();
    return 0;
}

static int
_wrap_PyNs3GlobalRoutingLSA__tp_init__1(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    ns3::GlobalRoutingLSA::SPFStatus status;
    PyNs3Ipv4Address *linkStateId;
    PyNs3Ipv4Address *advertisingRtr;
    const char *keywords[] = {"status", "linkStateId", "advertisingRtr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iO!O!", (char **) keywords, &status, &PyNs3Ipv4Address_Type, &linkStateId, &PyNs3Ipv4Address_Type, &advertisingRtr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GlobalRoutingLSA(status, *((PyNs3Ipv4Address *) linkStateId)->obj, *((PyNs3Ipv4Address *) advertisingRtr)->obj);
    return 0;
}

static int
_wrap_PyNs3GlobalRoutingLSA__tp_init__2(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GlobalRoutingLSA *lsa;
    const char *keywords[] = {"lsa", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GlobalRoutingLSA_Type, &lsa)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GlobalRoutingLSA(*((PyNs3GlobalRoutingLSA *) lsa)->obj);
    return 0;
}

int _wrap_PyNs3GlobalRoutingLSA__tp_init(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3GlobalRoutingLSA__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GlobalRoutingLSA__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3GlobalRoutingLSA__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3GlobalRoutingLSA_SetNetworkLSANetworkMask(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *mask;
    const char *keywords[] = {"mask", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Mask_Type, &mask)) {
        return NULL;
    }
    self->obj->SetNetworkLSANetworkMask(*((PyNs3Ipv4Mask *) mask)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetAdvertisingRouter(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetAdvertisingRouter();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetLinkStateId(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetLinkStateId();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_SetNode(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    self->obj->SetNode(ns3::Ptr< ns3::Node  > (node_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_SetLSType(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::GlobalRoutingLSA::LSType typ;
    const char *keywords[] = {"typ", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &typ)) {
        return NULL;
    }
    self->obj->SetLSType(typ);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_AddAttachedRouter(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3Ipv4Address *addr;
    const char *keywords[] = {"addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &addr)) {
        return NULL;
    }
    retval = self->obj->AddAttachedRouter(*((PyNs3Ipv4Address *) addr)->obj);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetNetworkLSANetworkMask(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    ns3::Ipv4Mask retval = self->obj->GetNetworkLSANetworkMask();
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(retval);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetStatus(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    ns3::GlobalRoutingLSA::SPFStatus retval;
    
    retval = self->obj->GetStatus();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_SetStatus(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::GlobalRoutingLSA::SPFStatus status;
    const char *keywords[] = {"status", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &status)) {
        return NULL;
    }
    self->obj->SetStatus(status);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetLSType(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    ns3::GlobalRoutingLSA::LSType retval;
    
    retval = self->obj->GetLSType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_ClearLinkRecords(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    
    self->obj->ClearLinkRecords();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_IsEmpty(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsEmpty();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetAttachedRouter(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int n;
    const char *keywords[] = {"n", NULL};
    PyNs3Ipv4Address *py_Ipv4Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &n)) {
        return NULL;
    }
    ns3::Ipv4Address retval = self->obj->GetAttachedRouter(n);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetNLinkRecords(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNLinkRecords();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_Print(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3GlobalRoutingLSA_GetNode(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetNode();
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) == typeid(PyNs3Node__PythonHelper))
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_CopyLinkRecords(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3GlobalRoutingLSA *lsa;
    const char *keywords[] = {"lsa", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GlobalRoutingLSA_Type, &lsa)) {
        return NULL;
    }
    self->obj->CopyLinkRecords(*((PyNs3GlobalRoutingLSA *) lsa)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_SetAdvertisingRouter(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *rtr;
    const char *keywords[] = {"rtr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &rtr)) {
        return NULL;
    }
    self->obj->SetAdvertisingRouter(*((PyNs3Ipv4Address *) rtr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_SetLinkStateId(PyNs3GlobalRoutingLSA *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *addr;
    const char *keywords[] = {"addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &addr)) {
        return NULL;
    }
    self->obj->SetLinkStateId(*((PyNs3Ipv4Address *) addr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLSA_GetNAttachedRouters(PyNs3GlobalRoutingLSA *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNAttachedRouters();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3GlobalRoutingLSA__copy__(PyNs3GlobalRoutingLSA *self)
{

    PyNs3GlobalRoutingLSA *py_copy;
    py_copy = PyObject_New(PyNs3GlobalRoutingLSA, &PyNs3GlobalRoutingLSA_Type);
    py_copy->obj = new ns3::GlobalRoutingLSA(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GlobalRoutingLSA_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GlobalRoutingLSA_methods[] = {
    {(char *) "SetNetworkLSANetworkMask", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_SetNetworkLSANetworkMask, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAdvertisingRouter", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetAdvertisingRouter, METH_NOARGS, NULL },
    {(char *) "GetLinkStateId", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetLinkStateId, METH_NOARGS, NULL },
    {(char *) "SetNode", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_SetNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLSType", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_SetLSType, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddAttachedRouter", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_AddAttachedRouter, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNetworkLSANetworkMask", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetNetworkLSANetworkMask, METH_NOARGS, NULL },
    {(char *) "GetStatus", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetStatus, METH_NOARGS, NULL },
    {(char *) "SetStatus", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_SetStatus, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLSType", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetLSType, METH_NOARGS, NULL },
    {(char *) "ClearLinkRecords", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_ClearLinkRecords, METH_NOARGS, NULL },
    {(char *) "IsEmpty", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_IsEmpty, METH_NOARGS, NULL },
    {(char *) "GetAttachedRouter", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetAttachedRouter, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNLinkRecords", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetNLinkRecords, METH_NOARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNode", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetNode, METH_NOARGS, NULL },
    {(char *) "CopyLinkRecords", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_CopyLinkRecords, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAdvertisingRouter", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_SetAdvertisingRouter, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLinkStateId", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_SetLinkStateId, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNAttachedRouters", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA_GetNAttachedRouters, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GlobalRoutingLSA__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3GlobalRoutingLSA__tp_dealloc(PyNs3GlobalRoutingLSA *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GlobalRoutingLSA_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GlobalRoutingLSA_wrapper_registry.end()) {
        PyNs3GlobalRoutingLSA_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::GlobalRoutingLSA *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3GlobalRoutingLSA__tp_str(PyNs3GlobalRoutingLSA *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyString_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3GlobalRoutingLSA__tp_richcompare (PyNs3GlobalRoutingLSA *PYBINDGEN_UNUSED(self), PyNs3GlobalRoutingLSA *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GlobalRoutingLSA_Type)) {
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

PyTypeObject PyNs3GlobalRoutingLSA_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.GlobalRoutingLSA",            /* tp_name */
    sizeof(PyNs3GlobalRoutingLSA),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GlobalRoutingLSA__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3GlobalRoutingLSA__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3GlobalRoutingLSA__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GlobalRoutingLSA_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GlobalRoutingLSA__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3GlobalRoutingLinkRecord_wrapper_registry;


static int
_wrap_PyNs3GlobalRoutingLinkRecord__tp_init__0(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GlobalRoutingLinkRecord *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GlobalRoutingLinkRecord_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GlobalRoutingLinkRecord(*((PyNs3GlobalRoutingLinkRecord *) arg0)->obj);
    return 0;
}

static int
_wrap_PyNs3GlobalRoutingLinkRecord__tp_init__1(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::GlobalRoutingLinkRecord();
    return 0;
}

static int
_wrap_PyNs3GlobalRoutingLinkRecord__tp_init__2(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    ns3::GlobalRoutingLinkRecord::LinkType linkType;
    PyNs3Ipv4Address *linkId;
    PyNs3Ipv4Address *linkData;
    int metric;
    const char *keywords[] = {"linkType", "linkId", "linkData", "metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iO!O!i", (char **) keywords, &linkType, &PyNs3Ipv4Address_Type, &linkId, &PyNs3Ipv4Address_Type, &linkData, &metric)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (metric > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GlobalRoutingLinkRecord(linkType, *((PyNs3Ipv4Address *) linkId)->obj, *((PyNs3Ipv4Address *) linkData)->obj, metric);
    return 0;
}

int _wrap_PyNs3GlobalRoutingLinkRecord__tp_init(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3GlobalRoutingLinkRecord__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GlobalRoutingLinkRecord__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3GlobalRoutingLinkRecord__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3GlobalRoutingLinkRecord_SetLinkData(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *addr;
    const char *keywords[] = {"addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &addr)) {
        return NULL;
    }
    self->obj->SetLinkData(*((PyNs3Ipv4Address *) addr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLinkRecord_SetMetric(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int metric;
    const char *keywords[] = {"metric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &metric)) {
        return NULL;
    }
    if (metric > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMetric(metric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLinkRecord_SetLinkId(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *addr;
    const char *keywords[] = {"addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &addr)) {
        return NULL;
    }
    self->obj->SetLinkId(*((PyNs3Ipv4Address *) addr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLinkRecord_GetLinkData(PyNs3GlobalRoutingLinkRecord *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetLinkData();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLinkRecord_GetMetric(PyNs3GlobalRoutingLinkRecord *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetMetric();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLinkRecord_GetLinkId(PyNs3GlobalRoutingLinkRecord *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetLinkId();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLinkRecord_SetLinkType(PyNs3GlobalRoutingLinkRecord *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::GlobalRoutingLinkRecord::LinkType linkType;
    const char *keywords[] = {"linkType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &linkType)) {
        return NULL;
    }
    self->obj->SetLinkType(linkType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRoutingLinkRecord_GetLinkType(PyNs3GlobalRoutingLinkRecord *self)
{
    PyObject *py_retval;
    ns3::GlobalRoutingLinkRecord::LinkType retval;
    
    retval = self->obj->GetLinkType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3GlobalRoutingLinkRecord__copy__(PyNs3GlobalRoutingLinkRecord *self)
{

    PyNs3GlobalRoutingLinkRecord *py_copy;
    py_copy = PyObject_New(PyNs3GlobalRoutingLinkRecord, &PyNs3GlobalRoutingLinkRecord_Type);
    py_copy->obj = new ns3::GlobalRoutingLinkRecord(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GlobalRoutingLinkRecord_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GlobalRoutingLinkRecord_methods[] = {
    {(char *) "SetLinkData", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_SetLinkData, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMetric", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_SetMetric, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLinkId", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_SetLinkId, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLinkData", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_GetLinkData, METH_NOARGS, NULL },
    {(char *) "GetMetric", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_GetMetric, METH_NOARGS, NULL },
    {(char *) "GetLinkId", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_GetLinkId, METH_NOARGS, NULL },
    {(char *) "SetLinkType", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_SetLinkType, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLinkType", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord_GetLinkType, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GlobalRoutingLinkRecord__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3GlobalRoutingLinkRecord__tp_dealloc(PyNs3GlobalRoutingLinkRecord *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GlobalRoutingLinkRecord_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GlobalRoutingLinkRecord_wrapper_registry.end()) {
        PyNs3GlobalRoutingLinkRecord_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::GlobalRoutingLinkRecord *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GlobalRoutingLinkRecord__tp_richcompare (PyNs3GlobalRoutingLinkRecord *PYBINDGEN_UNUSED(self), PyNs3GlobalRoutingLinkRecord *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GlobalRoutingLinkRecord_Type)) {
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

PyTypeObject PyNs3GlobalRoutingLinkRecord_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.GlobalRoutingLinkRecord",            /* tp_name */
    sizeof(PyNs3GlobalRoutingLinkRecord),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GlobalRoutingLinkRecord__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3GlobalRoutingLinkRecord__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GlobalRoutingLinkRecord_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GlobalRoutingLinkRecord__tp_init,             /* tp_init */
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
_wrap_PyNs3GlobalRouter__tp_init(PyNs3GlobalRouter *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::GlobalRouter();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}


PyObject *
_wrap_PyNs3GlobalRouter_GetNumLSAs(PyNs3GlobalRouter *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNumLSAs();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_GetNInjectedRoutes(PyNs3GlobalRouter *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNInjectedRoutes();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_GetRoutingProtocol(PyNs3GlobalRouter *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv4GlobalRouting > retval;
    PyNs3Ipv4GlobalRouting *py_Ipv4GlobalRouting;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetRoutingProtocol();
    if (!(const_cast<ns3::Ipv4GlobalRouting *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Ipv4GlobalRouting *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_Ipv4GlobalRouting = NULL;
    } else {
        py_Ipv4GlobalRouting = (PyNs3Ipv4GlobalRouting *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4GlobalRouting);
    }
    
    if (py_Ipv4GlobalRouting == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv4GlobalRouting *> (ns3::PeekPointer (retval)))), &PyNs3Ipv4GlobalRouting_Type);
        py_Ipv4GlobalRouting = PyObject_GC_New(PyNs3Ipv4GlobalRouting, wrapper_type);
        py_Ipv4GlobalRouting->inst_dict = NULL;
        py_Ipv4GlobalRouting->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv4GlobalRouting *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv4GlobalRouting->obj = const_cast<ns3::Ipv4GlobalRouting *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_Ipv4GlobalRouting->obj] = (PyObject *) py_Ipv4GlobalRouting;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4GlobalRouting);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::GlobalRouter::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_GetRouterId(PyNs3GlobalRouter *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetRouterId();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_DiscoverLSAs(PyNs3GlobalRouter *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->DiscoverLSAs();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_GetInjectedRoute(PyNs3GlobalRouter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ipv4RoutingTableEntry *retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = self->obj->GetInjectedRoute(i);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Ipv4RoutingTableEntry_wrapper_registry.find((void *) retval);
    if (wrapper_lookup_iter == PyNs3Ipv4RoutingTableEntry_wrapper_registry.end()) {
        py_Ipv4RoutingTableEntry = NULL;
    } else {
        py_Ipv4RoutingTableEntry = (PyNs3Ipv4RoutingTableEntry *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4RoutingTableEntry);
    }
    
    if (py_Ipv4RoutingTableEntry == NULL) {
        py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
        py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry((*retval));
        py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_InjectRoute(PyNs3GlobalRouter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    const char *keywords[] = {"network", "networkMask", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask)) {
        return NULL;
    }
    self->obj->InjectRoute(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_SetRoutingProtocol(PyNs3GlobalRouter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4GlobalRouting *routing;
    ns3::Ipv4GlobalRouting *routing_ptr;
    const char *keywords[] = {"routing", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4GlobalRouting_Type, &routing)) {
        return NULL;
    }
    routing_ptr = (routing ? routing->obj : NULL);
    self->obj->SetRoutingProtocol(ns3::Ptr< ns3::Ipv4GlobalRouting  > (routing_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_RemoveInjectedRoute(PyNs3GlobalRouter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    self->obj->RemoveInjectedRoute(i);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_WithdrawRoute(PyNs3GlobalRouter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    const char *keywords[] = {"network", "networkMask", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask)) {
        return NULL;
    }
    retval = self->obj->WithdrawRoute(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GlobalRouter_GetLSA(PyNs3GlobalRouter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    unsigned int n;
    PyNs3GlobalRoutingLSA *lsa;
    const char *keywords[] = {"n", "lsa", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &n, &PyNs3GlobalRoutingLSA_Type, &lsa)) {
        return NULL;
    }
    retval = self->obj->GetLSA(n, *((PyNs3GlobalRoutingLSA *) lsa)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

static PyMethodDef PyNs3GlobalRouter_methods[] = {
    {(char *) "GetNumLSAs", (PyCFunction) _wrap_PyNs3GlobalRouter_GetNumLSAs, METH_NOARGS, NULL },
    {(char *) "GetNInjectedRoutes", (PyCFunction) _wrap_PyNs3GlobalRouter_GetNInjectedRoutes, METH_NOARGS, NULL },
    {(char *) "GetRoutingProtocol", (PyCFunction) _wrap_PyNs3GlobalRouter_GetRoutingProtocol, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3GlobalRouter_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetRouterId", (PyCFunction) _wrap_PyNs3GlobalRouter_GetRouterId, METH_NOARGS, NULL },
    {(char *) "DiscoverLSAs", (PyCFunction) _wrap_PyNs3GlobalRouter_DiscoverLSAs, METH_NOARGS, NULL },
    {(char *) "GetInjectedRoute", (PyCFunction) _wrap_PyNs3GlobalRouter_GetInjectedRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InjectRoute", (PyCFunction) _wrap_PyNs3GlobalRouter_InjectRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetRoutingProtocol", (PyCFunction) _wrap_PyNs3GlobalRouter_SetRoutingProtocol, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RemoveInjectedRoute", (PyCFunction) _wrap_PyNs3GlobalRouter_RemoveInjectedRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "WithdrawRoute", (PyCFunction) _wrap_PyNs3GlobalRouter_WithdrawRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLSA", (PyCFunction) _wrap_PyNs3GlobalRouter_GetLSA, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3GlobalRouter__tp_clear(PyNs3GlobalRouter *self)
{
    Py_CLEAR(self->inst_dict);
    
}


static int
PyNs3GlobalRouter__tp_traverse(PyNs3GlobalRouter *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3GlobalRouter__tp_dealloc(PyNs3GlobalRouter *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3GlobalRouter__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GlobalRouter__tp_richcompare (PyNs3GlobalRouter *PYBINDGEN_UNUSED(self), PyNs3GlobalRouter *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GlobalRouter_Type)) {
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

PyTypeObject PyNs3GlobalRouter_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.GlobalRouter",            /* tp_name */
    sizeof(PyNs3GlobalRouter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GlobalRouter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3GlobalRouter__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3GlobalRouter__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3GlobalRouter__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GlobalRouter_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3GlobalRouter, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GlobalRouter__tp_init,             /* tp_init */
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
_wrap_PyNs3Ipv4GlobalRouting__tp_init__0(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4GlobalRouting *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4GlobalRouting_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4GlobalRouting(*((PyNs3Ipv4GlobalRouting *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

static int
_wrap_PyNs3Ipv4GlobalRouting__tp_init__1(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv4GlobalRouting();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    return 0;
}

int _wrap_PyNs3Ipv4GlobalRouting__tp_init(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4GlobalRouting__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4GlobalRouting__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4GlobalRouting_NotifyAddAddress(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4GlobalRouting_NotifyInterfaceUp(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4GlobalRouting_NotifyInterfaceDown(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4GlobalRouting_GetNRoutes(PyNs3Ipv4GlobalRouting *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNRoutes();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}



PyObject *
_wrap_PyNs3Ipv4GlobalRouting_AddHostRouteTo__0(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *dest;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"dest", "nextHop", "interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &dest, &PyNs3Ipv4Address_Type, &nextHop, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddHostRouteTo(*((PyNs3Ipv4Address *) dest)->obj, *((PyNs3Ipv4Address *) nextHop)->obj, interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv4GlobalRouting_AddHostRouteTo__1(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *dest;
    unsigned int interface;
    const char *keywords[] = {"dest", "interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &dest, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddHostRouteTo(*((PyNs3Ipv4Address *) dest)->obj, interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv4GlobalRouting_AddHostRouteTo(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4GlobalRouting_AddHostRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4GlobalRouting_AddHostRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4GlobalRouting_AddNetworkRouteTo__0(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"network", "networkMask", "nextHop", "interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask, &PyNs3Ipv4Address_Type, &nextHop, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddNetworkRouteTo(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj, *((PyNs3Ipv4Address *) nextHop)->obj, interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Ipv4GlobalRouting_AddNetworkRouteTo__1(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    unsigned int interface;
    const char *keywords[] = {"network", "networkMask", "interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddNetworkRouteTo(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj, interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Ipv4GlobalRouting_AddNetworkRouteTo(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4GlobalRouting_AddNetworkRouteTo__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4GlobalRouting_AddNetworkRouteTo__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ipv4GlobalRouting_AddASExternalRouteTo(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *network;
    PyNs3Ipv4Mask *networkMask;
    PyNs3Ipv4Address *nextHop;
    unsigned int interface;
    const char *keywords[] = {"network", "networkMask", "nextHop", "interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &network, &PyNs3Ipv4Mask_Type, &networkMask, &PyNs3Ipv4Address_Type, &nextHop, &interface)) {
        return NULL;
    }
    self->obj->AddASExternalRouteTo(*((PyNs3Ipv4Address *) network)->obj, *((PyNs3Ipv4Mask *) networkMask)->obj, *((PyNs3Ipv4Address *) nextHop)->obj, interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4GlobalRouting_RouteOutput(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4GlobalRouting_GetRoute(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ipv4RoutingTableEntry *retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4RoutingTableEntry *py_Ipv4RoutingTableEntry;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = self->obj->GetRoute(i);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Ipv4RoutingTableEntry_wrapper_registry.find((void *) retval);
    if (wrapper_lookup_iter == PyNs3Ipv4RoutingTableEntry_wrapper_registry.end()) {
        py_Ipv4RoutingTableEntry = NULL;
    } else {
        py_Ipv4RoutingTableEntry = (PyNs3Ipv4RoutingTableEntry *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4RoutingTableEntry);
    }
    
    if (py_Ipv4RoutingTableEntry == NULL) {
        py_Ipv4RoutingTableEntry = PyObject_New(PyNs3Ipv4RoutingTableEntry, &PyNs3Ipv4RoutingTableEntry_Type);
        py_Ipv4RoutingTableEntry->obj = new ns3::Ipv4RoutingTableEntry((*retval));
        py_Ipv4RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3Ipv4RoutingTableEntry_wrapper_registry[(void *) py_Ipv4RoutingTableEntry->obj] = (PyObject *) py_Ipv4RoutingTableEntry;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingTableEntry);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4GlobalRouting_SetIpv4(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4GlobalRouting_RemoveRoute(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4GlobalRouting_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ipv4GlobalRouting::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4GlobalRouting_NotifyRemoveAddress(PyNs3Ipv4GlobalRouting *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Ipv4GlobalRouting__copy__(PyNs3Ipv4GlobalRouting *self)
{

    PyNs3Ipv4GlobalRouting *py_copy;
    py_copy = PyObject_GC_New(PyNs3Ipv4GlobalRouting, &PyNs3Ipv4GlobalRouting_Type);
    py_copy->obj = new ns3::Ipv4GlobalRouting(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv4GlobalRouting_methods[] = {
    {(char *) "NotifyAddAddress", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_NotifyAddAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceUp", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_NotifyInterfaceUp, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceDown", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_NotifyInterfaceDown, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNRoutes", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_GetNRoutes, METH_NOARGS, NULL },
    {(char *) "AddHostRouteTo", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_AddHostRouteTo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddNetworkRouteTo", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_AddNetworkRouteTo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddASExternalRouteTo", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_AddASExternalRouteTo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RouteOutput", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_RouteOutput, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRoute", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_GetRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIpv4", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_SetIpv4, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RemoveRoute", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_RemoveRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyRemoveAddress", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting_NotifyRemoveAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv4GlobalRouting__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ipv4GlobalRouting__tp_clear(PyNs3Ipv4GlobalRouting *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ipv4GlobalRouting *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ipv4GlobalRouting__tp_traverse(PyNs3Ipv4GlobalRouting *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3Ipv4GlobalRouting__tp_dealloc(PyNs3Ipv4GlobalRouting *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ipv4GlobalRouting__tp_clear(self);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4GlobalRouting__tp_richcompare (PyNs3Ipv4GlobalRouting *PYBINDGEN_UNUSED(self), PyNs3Ipv4GlobalRouting *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4GlobalRouting_Type)) {
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

PyTypeObject PyNs3Ipv4GlobalRouting_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    (char *) "ns3.Ipv4GlobalRouting",            /* tp_name */
    sizeof(PyNs3Ipv4GlobalRouting),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4GlobalRouting__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Ipv4GlobalRouting__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ipv4GlobalRouting__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4GlobalRouting__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4GlobalRouting_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ipv4GlobalRouting, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4GlobalRouting__tp_init,             /* tp_init */
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








