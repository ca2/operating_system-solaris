#pragma once


namespace freebsd
{


   class CLASS_DECL_APEX printer :
      virtual public ::user::printer
   {
   public:


      class CLASS_DECL_APEX document_properties :
         virtual public ::object
      {
      public:


         DEVMODE *      m_pdevmode;
         HDC            m_hdc;


         document_properties(__pointer(base_application) papp);
         virtual ~document_properties();


         virtual bool initialize(::freebsd::printer * pprinter, DEVMODE * pdevmode = nullptr);
         virtual bool close();
         virtual ::draw2d::graphics * create_graphics();

      };


      HANDLE                  m_hPrinter;
      document_properties     m_documentproperties;


      printer(__pointer(base_application) papp);
      virtual ~printer();


      virtual bool open(const char * pszDeviceName);
      virtual ::draw2d::graphics * create_graphics();
      virtual bool is_opened();
      virtual bool close();



   };
} // namespace user