// Create on 2021-03-22 09:12 <3ThomasBS_
#include "framework.h"
#include "acme_path.h"


namespace acme_freebsd
{

   
   acme_path::acme_path()
   {

      m_pplatformpath = this;

   }


   acme_path::~acme_path()
   {


   }


//   ::file::path acme_path::app_module()
//   {
//
//      ::file::path path;
//
//      char * pszModule = nullptr;
//
//      if((pszModule = br_find_exe(nullptr)) == nullptr)
//      {
//
//         if (!br_init_lib(nullptr))
//         {
//
//            char path[PATH_MAX * 4];
//
//            char dest[PATH_MAX * 4];
//
//            pid_t pid = getpid();
//
//            sprintf(path, "/proc/%d/exe", pid);
//
//            auto iSize = readlink(path, dest, PATH_MAX);
//
//            if (iSize > 0)
//            {
//
//               dest[iSize] = '\0';
//
//               pszModule = strdup(dest);
//
//
//            }
//
//         }
//
//      }
//
//      path = pszModule;
//
//      ::free(pszModule);
//
//      return path;
//
//   }


} // namespace acme_freebsd



