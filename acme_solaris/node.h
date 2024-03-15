//
// Created by camilo on 21/01/2021. <33TBS!!
//
//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "acme_darwin/node.h"


namespace acme_freebsd
{


   class CLASS_DECL_ACME_FREEBSD node :
      virtual public ::acme_darwin::node
   {
   public:


      ::file::path m_strTimeFolder;
      ::file::path m_strNetSeedFolder;

      ::file::path m_strCommonAppData;
      ::file::path m_strAppData;
      ::file::path m_strPrograms;
      ::file::path m_strCommonPrograms;


      node();

      ~node() override;


      void initialize(::particle * pparticle) override;

      //virtual ::string dir_root() override;

      //virtual ::file::path get_memory_map_base_folder_path() const override;

      //virtual ::file::path home() override;

      //virtual ::file::path program_data() override;

      //virtual ::file::path roaming() override;


      virtual void install_crash_dump_reporting(const string & strModuleNameWithTheExeExtension) override;


      //virtual bool memcnts();

      //virtual ::file::path memcnts_base_path();

      //virtual ::e_status datetime_to_filetime(filetime_t * pFileTime, const ::datetime::time& time) override;


      //virtual ::e_status last_error_to_status(::u32 dwLastError);


      string audio_get_default_implementation_name() override;


      void shell_open(const ::file::path & path, const ::string & strParams = "", const ::file::path & pathFolder = "") override;


      ::pointer <::operating_system::summary > operating_system_summary() override;


   };


} // namespace acme_freebsd



