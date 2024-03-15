//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "acme_freebsd/node.h"
#include "apex_posix/node.h"


namespace apex_freebsd
{


   class CLASS_DECL_APEX_FREEBSD node :
           virtual public ::acme_freebsd::node,
           virtual public ::apex_posix::node
   {
   public:


      node();

      ~node() override;


      void initialize(::particle * pparticle) override;


      string get_user_name() override;

      void process_init();


      void _001InitializeShellOpen() override;

      //virtual ::e_status shell_create_link(::file::path pathObj, ::file::path pathLnk, string strDesc, ::file::path pathIco, int iIcon) override;


      //virtual bool _os_calc_app_dark_mode();

      //virtual bool _os_calc_system_dark_mode();


      //virtual ::color::color get_default_color(::u64 u);

      //virtual void set_console_colors(::u32 dwScreenColors, ::u32 dwPopupColors, ::u32 dwWindowAlpha);

      //virtual ::e_status set_system_dark_mode1(bool bSet = true);

      //virtual ::e_status set_app_dark_mode1(bool bSet = true);

      //virtual double get_time_zone();

      //virtual ::e_status get_system_time(system_time_t * psystemtime);

      //virtual ::e_status open_folder(::file::path & pathFolder);

      //virtual ::e_status register_dll(const ::file::path & pathDll);

      //virtual ::e_status start();

      //::e_status get_firefox_installation_info(string& strPathToExe, string& strInstallDirectory);




      //virtual string veriwell_multimedia_music_midi_get_default_library_name() override;


      //virtual string multimedia_audio_mixer_get_default_library_name() override;


      //virtual string multimedia_audio_get_default_library_name() override;


//         bool is_application_installed(const ::file::path & pathExe, string strAppId, string & strBuild,
//                                               const ::string & strPlatform, const ::string & strConfiguration,
//                                               const ::string & strLocale, const ::string & strSchema) override;
//
//         bool set_application_installed(const ::file::path & pathExe, string strAppId, const ::string & strBuild,
//                                                const ::string & strPlatform, const ::string & strConfiguration,
//                                                const ::string & strLocale, const ::string & strSchema) override;
//
//         ::e_status set_last_run_application_path(const string & strAppId) override;


      //virtual ::u32       get_file_attributes(const char* pFileName);
      //virtual ::u32       get_current_directory(string& str);
      //virtual ::u32       get_temp_path(string& str);
      //virtual ::i32        reg_query_value(HKEY hkey, const char* pszSubKey, string& str);
      //virtual  HICON       extract_icon(HINSTANCE hInst, const char* pszExeFileName, ::u32 nIconIndex);
      //virtual  bool        delete_file(const char* pFileName);
      // virtual  i32     get_menu_string(HMENU hMenu, ::u32 uDItem, string& str, ::u32 flags);
      //virtual  void        time_to_filetime(::matter* pobject, const ::datetime::time& time, LPFILETIME pFileTime);


      //virtual string get_version();
      //virtual void show_wait_cursor(bool bShow);



        //string get_command_line() override;


        void reboot() override;
        void shutdown(bool bPowerOff) override;

        void terminate_processes_by_title(const ::string & strName) override;


        virtual bool freebsd_can_exec(const char *file);


        //virtual ::file::path get_module_path(HMODULE hmodule) override;


        //virtual bool path_pid(::u32 & dwPid, const ::string & strName) override;
        //virtual bool title_pid(::u32 & dwPid, const ::string & strName) override;
        //virtual void get_all_processes(u32_array & dwa) override;
        //virtual ::file::path get_process_path(::u32 dwPid) override;
        //virtual int get_pid() override;

        virtual ::payload connection_settings_get_auto_detect() override;
        virtual ::payload connection_settings_get_auto_config_url() override;


        void local_machine_set_run(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet) override;
        void local_machine_set_run_once(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet) override;
        void current_user_set_run(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet) override;
        void current_user_set_run_once(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet) override;
        void defer_register_ca2_plugin_for_mozilla() override;

        void file_extension_get_open_with_list_keys(string_array & straKey, const ::string & strExtension) override;
        void file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & strExtension) override;

        void file_association_set_default_icon(const ::string & strExtension, const ::string & strExtensionNamingClass, const ::string & strIconPath) override;
        void file_association_set_shell_open_command(const ::string & strExtension, const ::string & strExtensionNamingClass, const ::string & strCommand, const ::string & strParam) override;
        void file_association_get_shell_open_command(const ::string & strExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;


        //virtual bool open_in_ie(const char * pcsz);


        void enable_service(const ::string & strServiceName, const ::string & strDisplayName, const ::string & strCommand, const ::string & strUser = "", const ::string & strPass = "") override;

        void disable_service(const ::string & strServiceName) override;

        void start_service(const ::string & strServiceName) override;

        void stop_service(const ::string & strServiceName) override;

        void raise_exception( ::u32 dwExceptionCode, ::u32 dwExceptionFlags);

        virtual bool is_remote_session() override;

        //virtual void post_to_all_threads(const ::id & id, wparam wparam, lparam lparam);


        virtual void initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch) override;

        virtual void get_default_browser(string & strId, ::file::path & path, string & strParam) override;

        virtual void file_open(const ::file::path & path, const ::string & strParams = "", const ::file::path & pathFolder = "") override;

        //virtual void list_process(::file::path_array & patha, u32_array & iaPid) override;

   };


} // namespace apex_freebsd



