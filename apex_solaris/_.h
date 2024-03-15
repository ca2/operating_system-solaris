#pragma once


#include "apex/_.h"
#include "apex_posix/_.h"
#include "acme_freebsd/_.h"


#if defined(_APEX_FREEBSD_LIBRARY)
#define CLASS_DECL_APEX_FREEBSD  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APEX_FREEBSD  CLASS_DECL_IMPORT
#endif


namespace apex_freebsd
{


   class dir_context;
   class dir_system;

   class file_context;
   class file_system;

   class node;


} // namespace apex_freebsd



