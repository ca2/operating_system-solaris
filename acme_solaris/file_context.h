#pragma once


#include "acme_darwin/file_context.h"


namespace acme_freebsd
{


   class CLASS_DECL_ACME_FREEBSD file_context :
      virtual public ::acme_darwin::file_context
   {
   public:


      file_context();
      ~file_context() override;


      void initialize(::particle * pparticle) override;


      void init_system() override;
      void init_context() override;


      ::file::path dropbox_info_network_payload() override;


   };


} // namespace acme_freebsd



