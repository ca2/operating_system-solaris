#include "framework.h"
#include "node.h"
#include "acme_directory.h"
#include "acme_file.h"
#include "acme_path.h"
#include "dir_system.h"
#include "file_system.h"
#include "dir_context.h"
#include "file_context.h"
//#include "file.h"


__FACTORY_EXPORT void acme_darwin_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_freebsd_factory(::factory::factory * pfactory)
{

   acme_darwin_factory(pfactory);


   pfactory->add_factory_item < ::acme_freebsd::dir_system, ::dir_system >();
   pfactory->add_factory_item < ::acme_freebsd::file_system, ::file_system >();

   pfactory->add_factory_item < ::acme_freebsd::dir_context, ::dir_context >();
   pfactory->add_factory_item < ::acme_freebsd::file_context, ::file_context >();


   pfactory->add_factory_item < ::acme_freebsd::node, ::acme::node >();
   pfactory->add_factory_item < ::acme_freebsd::acme_directory, ::acme_directory >();
   pfactory->add_factory_item < ::acme_freebsd::acme_file, ::acme_file >();
   pfactory->add_factory_item < ::acme_freebsd::acme_path, ::acme_path >();


//   pfactory->add_factory_item < ::acme_freebsd::file, ::file::file >();


}


