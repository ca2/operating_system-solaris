#include "framework.h"
#include "apex/operating_system.h"
#include "shell_launcher.h"


namespace apex_freebsd
{

   
   shell_launcher::shell_launcher()
   {


   }


   shell_launcher::~shell_launcher()
   {


   }


   ::e_status shell_launcher::launch()
   {

      //if(m_iMode == 0)
      //{

      //   m_h = ::ShellExecuteW(
      //      m_oswindow,
      //      wstring(m_strOperation),
      //      wstring(m_strFile),
      //      wstring(m_strParameters),
      //      wstring(m_strDirectory),
      //      freebsd_show_window(m_edisplay, m_eactivation));

      //}

      __throw(error_interface_only);

      return ::error_interface_only;

   }


   //bool shell_launcher::succeeded()
   //{

   //   //return ((iptr)m_h) >= 32;

   //   return false;

   //}


} // namespace apex_freebsd



