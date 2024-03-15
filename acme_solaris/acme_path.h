// Create on 2021-03-22 09:12 <3ThomasBS_
#pragma once


#include "acme_darwin/acme_path.h"


namespace acme_freebsd
{


   class CLASS_DECL_ACME_FREEBSD acme_path :
      virtual public ::acme_darwin::acme_path
   {
   public:


      acme_path();
      ~acme_path() override;


      //virtual ::file::path app_module() override;


   };


} // namespace acme_freebsd



