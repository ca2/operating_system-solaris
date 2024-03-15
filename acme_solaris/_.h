#pragma once


#include "operating_system-darwin/acme_darwin/_.h"


#if defined(_acme_freebsd_project)
#define CLASS_DECL_ACME_FREEBSD  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_FREEBSD  CLASS_DECL_IMPORT
#endif



CLASS_DECL_ACME_FREEBSD ::user::enum_desktop get_edesktop();




