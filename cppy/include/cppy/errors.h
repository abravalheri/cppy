/*-----------------------------------------------------------------------------
| Copyright (c) 2014, Nucleic Development Team.
|
| Distributed under the terms of the Modified BSD License.
|
| The full license is in the file COPYING.txt, distributed with this software.
|----------------------------------------------------------------------------*/
#pragma once

#include <Python.h>


namespace cppy
{

inline PyObject* bad_internal_call( const char* message )
{
    PyErr_SetString( PyExc_SystemError, message );
    return 0;
}


inline PyObject* type_error( const char* message )
{
    PyErr_SetString( PyExc_TypeError, message );
    return 0;
}


inline PyObject* type_error( PyObject* ob, const char* expected )
{
    PyErr_Format(
        PyExc_TypeError,
        "Expected object of type `%s`. Got object of type `%s` instead.",
        expected,
        ob->ob_type->tp_name );
    return 0;
}


inline PyObject* value_error( const char* message )
{
    PyErr_SetString( PyExc_ValueError, message );
    return 0;
}


inline PyObject* runtime_error( const char* message )
{
    PyErr_SetString( PyExc_RuntimeError, message );
    return 0;
}


inline PyObject* attribute_error( const char* message )
{
    PyErr_SetString( PyExc_AttributeError, message );
    return 0;
}


inline PyObject* attribute_error( PyObject* ob, const char* attr )
{
    PyErr_Format( PyExc_AttributeError,
                  "'%s' object has no attribute '%s'",
                  ob->ob_type->tp_name,
                  attr );
    return 0;
}

} // namespace cppy
