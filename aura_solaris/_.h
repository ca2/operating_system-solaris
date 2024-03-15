#pragma once


#include "aura/_.h"
#include "aura_posix/_.h"
#include "apex_freebsd/_.h"


#if defined(_AURA_FREEBSD_LIBRARY)
#define CLASS_DECL_AURA_FREEBSD  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_AURA_FREEBSD  CLASS_DECL_IMPORT
#endif



