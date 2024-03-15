#include "framework.h"


//#include "acme/library.h"


char * get_current_dir_name();


namespace acme_freebsd
{


   ::u32 get_current_directory(string& str)
   {

      auto psz = ::get_current_dir_name();

      str = ::string_from_strdup(psz);

      return str.length();

   }


} // namespace acme_freebsd



