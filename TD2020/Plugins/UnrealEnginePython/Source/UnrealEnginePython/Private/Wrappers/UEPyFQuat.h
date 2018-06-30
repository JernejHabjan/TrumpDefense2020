#pragma once

#include "UnrealEnginePython.h"

#include "Runtime/Core/Public/Math/Quat.h"

typedef struct {
	PyObject_HEAD
	/* Type-specific fields go here. */
	FQuat quat;
} ue_PyFQuat;

PyObject *py_ue_new_fquat(FQuat);
ue_PyFQuat *py_ue_is_fquat(PyObject *);

void ue_python_init_fquat(PyObject *);

bool py_ue_quat_arg(PyObject *, FQuat &);