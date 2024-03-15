#pragma once


namespace user
{


   bool gsettings_set(const char * pszSchema, const char * pszKey, const char * pszValue);

   bool gsettings_sync();

   char * gsettings_get_malloc(const char * pszSchema, const char * pszKey);

   bool g_enable_wallpaper_change_notification(const char * pszSchema, const char * pszKey);

   void g_defer_init();

   void g_defer_term();


} // namespace user
