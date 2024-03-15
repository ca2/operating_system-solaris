#include "framework.h"
#include "apex/platform/launcher.h"
#include "launcher.h"
//#include "os_context.h"
//#include "ip_enum.h"
//#include "interprocess_communication.h"
#include "service_handler.h"
#include "node.h"
#include "apex/parallelization/service.h"
#include "apex/parallelization/service_handler.h"
#include "service_handler.h"


DECLARE_FACTORY(apex_darwin);


DECLARE_FACTORY(acme_freebsd);


IMPLEMENT_FACTORY(apex_freebsd)
{

   apex_darwin_factory(pfactory);

   acme_freebsd_factory(pfactory);


   //add_factory_item < ::freebsd::stdio_file, ::file::text_file >();
   //add_factory_item < ::freebsd::file, ::file::file >();
   //pfactory->add_factory_item < ::apex_freebsd::os_context, ::os_context >();
   //pfactory->add_factory_item < ::freebsd::pipe, ::process::pipe >();
   //pfactory->add_factory_item < ::freebsd::process, ::process::process >();

   //add_factory_item < ::freebsd::console, ::console::console >();
   //pfactory->add_factory_item < ::freebsd::crypto, ::crypto::crypto >();
   //pfactory->add_factory_item < ::apex_freebsd::ip_enum, ::networking::ip_enum >();


   //pfactory->add_factory_item < ::apex_freebsd::interprocess_communication_base, ::interprocess_communication::base >();
   //pfactory->add_factory_item < ::apex_freebsd::interprocess_communication_rx, ::interprocess_communication::rx >();
   //pfactory->add_factory_item < ::apex_freebsd::interprocess_communication_tx, ::interprocess_communication::tx >();
   //add_factory_item < ::freebsd::interprocess_communication, ::interprocess_communication::interprocess_communication >();


   //add_factory_item < ::freebsd::buffer, ::graphics::graphics >();
   //add_factory_item < ::freebsd::interaction_impl, ::user::interaction_impl >();

   //pfactory->add_factory_item < ::file::os_watcher, ::file::watcher >();
   //pfactory->add_factory_item < ::file::os_watch, ::file::watch >();

   //pfactory->add_factory_item < ::apex_freebsd::file_context, ::file_context >();
   pfactory->add_factory_item < ::apex_freebsd::service_handler, ::service_handler >();

   pfactory->add_factory_item < ::apex_freebsd::node, ::acme::node >();

   //add_factory_item < ::freebsd::copydesk, ::user::cop
   // 
   // 
   // ydesk >();
   ////add_factory_item < ::freebsd::shell, ::user::shell >();


}




