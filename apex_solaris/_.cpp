#include "framework.h"
#include "acme/_library.h"



//
//void CLASS_DECL_APEX_FREEBSD __cdecl _ca2_purecall()
//{
//
//   __throw(::exception::exception());
//
//}
//






namespace freebsd
{




   //HINSTANCE load_library(const char* psz)

   //{

   //   return ::LoadLibraryW(::str::international::utf8_to_unicode(psz));


   //}


   //bool CLASS_DECL_APEX_FREEBSD shell_get_special_folder_path(HWND hwnd, ::file::path& str, i32 csidl, bool fCreate)
   //{

   //   return ::SHGetSpecialFolderPathW(hwnd, wtostring(str, MAX_PATH * 8), csidl, fCreate) != false;

   //}


   //::file::path CLASS_DECL_APEX_FREEBSD shell_get_special_folder_path(i32 csidl, bool fCreate, ::windowing::window* pwindow)
   //{

   //   ::file::path path;

   //   if (!shell_get_special_folder_path(nullptr, path, csidl, fCreate))
   //   {

   //      return "";

   //   }

   //   return path;

   //}




   //::u32 get_current_directory(string& str)
   //{

   //   return ::GetCurrentDirectoryW(MAX_PATH * 8, wtostring(str, MAX_PATH * 8));

   //}


   //::u32 get_temp_path(string& str)
   //{

   //   return ::GetTempPathW(MAX_PATH * 8, wtostring(str, MAX_PATH * 8));

   //}


   //::i32 reg_query_value(HKEY hkey, const char* pszSubKey, string& str)
   //{

   //   DWORD dwType = 0;
   //   DWORD dwSize = 0;
   //   ::i32 lResult = RegQueryValueExW(hkey, wstring(pszSubKey), nullptr, &dwType, nullptr, &dwSize);

   //   if (lResult != ERROR_SUCCESS)
   //      return lResult;
   //   ASSERT(dwType == REG_SZ || dwType == REG_MULTI_SZ || dwType == REG_EXPAND_SZ);
   //   if (dwType == REG_SZ || dwType == REG_MULTI_SZ || dwType == REG_EXPAND_SZ)
   //   {

   //      natural_wstring pwsz(byte_count, dwSize);

   //      lResult = RegQueryValueExW(hkey, wstring(pszSubKey), nullptr, &dwType, (byte*)(unichar*)pwsz, &dwSize);

   //      str = pwsz;

   //      //str.release_string_buffer(dwSize);

   //      return lResult;

   //   }
   //   else
   //   {

   //      return ERROR_NOT_SUPPORTED;

   //   }

   //}


   //HICON extract_icon(HINSTANCE hInst, const char* pszExeFileName, ::u32 nIconIndex)

   //{

   //   return ::ExtractIconW(hInst, ::str::international::utf8_to_unicode(pszExeFileName), nIconIndex);


   //}


   //bool delete_file(const char* pFileName)

   //{

   //   return ::DeleteFileW(::str::international::utf8_to_unicode(pFileName)) != false;


   //}

   //CLASS_DECL_ACME ::file::path user_appdata_local();

   //CLASS_DECL_APEX_FREEBSD void time_to_filetime(::matter* pobject, const ::datetime::time& time, LPFILETIME pFileTime)
   //{

   //   SYSTEMTIME sysTime;

   //   sysTime.wYear = (::u16)time.GetYear();
   //   sysTime.wMonth = (::u16)time.GetMonth();
   //   sysTime.wDay = (::u16)time.GetDay();
   //   sysTime.wHour = (::u16)time.GetHour();
   //   sysTime.wMinute = (::u16)time.GetMinute();
   //   sysTime.wSecond = (::u16)time.GetSecond();
   //   sysTime.wMilliseconds = 0;

   //   // convert system time to local file time
   //   FILETIME localTime;

   //   DWORD dwLastError = ::GetLastError();

   //   if (!SystemTimeToFileTime((LPSYSTEMTIME)&sysTime, &localTime))
   //      ::file::throw_os_error(dwLastError);

   //   // convert local file time to UTC file time
   //   if (!LocalFileTimeToFileTime(&localTime, pFileTime))
   //      ::file::throw_os_error(dwLastError);

   //}



   //::file::path user_appdata_local()
   //{

   //   return shell_get_special_folder_path(CSIDL_LOCAL_APPDATA);

   //}



   //CLASS_DECL_ACME::file::path get_known_folder(REFKNOWNFOLDERID kfid)
   //{

   //   ::file::path str;

   //   ::cotaskptr < PWSTR > pwszPath;

   //   HANDLE hToken = nullptr;

   //   ::OpenProcessToken(::GetCurrentProcess(), TOKEN_QUERY | TOKEN_IMPERSONATE | TOKEN_DUPLICATE, &hToken);

   //   HRESULT hr = SHGetKnownFolderPath(kfid, 0, hToken, &pwszPath);

   //   return pwszPath;

   //}


} // namespace freebsd



//LRESULT CALLBACK __window_procedure(HWND oswindow, const ::id & id, wparam wparam, lparam lparam);
//
//WNDPROC get_window_procedure()
//{
//
//   return &::__window_procedure;
//
//}





