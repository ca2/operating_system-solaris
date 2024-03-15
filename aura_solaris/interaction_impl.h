#pragma once


#include "aura/user/user/interaction_impl.h"


namespace aura_freebsd
{


//   LRESULT CALLBACK __send_message_hook(i32, WPARAM, LPARAM);
//   // void _::ca2::StandardSubclass(oswindow);
//   LRESULT CALLBACK __cbt_filter_hook(i32, WPARAM, LPARAM);
//   LRESULT __call_window_procedure(::user::interaction * pWnd, oswindow hWnd, ::u32 nMsg, WPARAM wParam, LPARAM lParam);


   class x11data;


   class interaction_impl :
      virtual public ::user::interaction_impl
   {
   public:


      string                           m_strWindowText;
      ::user::primitive *              m_pbasewnd;
      bool                             m_bExposing;
      //__pointer(x11data)             m_px11data;
      i32                              m_iDepth;
      i32                              m_iScreen;
      bool                             m_bEnabled;

      //__pointer(::thread)            m_pthreadDraw;
      ::rectangle_i64                  m_rectLastPos;
      class ::time                     m_timeLastPos;

      ::point_i32                      m_pointLastMove;
      bool                             m_bMoveEvent;
      ::size_i32                       m_sizeLastSize;
      bool                             m_bSizeEvent;
      class ::time                     m_timeLastPlacementEvent;


      interaction_impl();
      ~interaction_impl() override;


      void linux_interaction_impl_common_construct();


      //void assert_ok() const override;
      //void dump(dump_context & dumpcontext) const override;


      //static const MESSAGE * GetCurrentMessage();

      virtual void install_message_routing(::channel * pchannel) override;

      //bool operator==(const ::user::interaction_impl& wnd) const;
      //bool operator!=(const ::user::interaction_impl& wnd) const;

//      ::u32 GetStyle() const override;
      //::u32 GetExStyle() const override;
      //bool ModifyStyle(::u32 dwRemove, ::u32 dwAdd, ::u32 nFlags = 0) override;
      //bool ModifyStyleEx(::u32 dwRemove, ::u32 dwAdd, ::u32 nFlags = 0) override;

      //virtual ::e_status set_tool_window(bool bSet = true) override;

      //virtual ::user::interaction * get_owner();
      //virtual ::user::primitive * set_owner(::user::primitive * pprimitiveOwner) override;

      //virtual oswindow get_handle() const override;

      virtual void route_command(::message::command * pcommand, bool bRouteKeyToDescendants = false) override;

      //virtual void on_control_event(::user::control_event * pevent) override;

      DECLARE_MESSAGE_HANDLER(_001OnEraseBkgnd);
      DECLARE_MESSAGE_HANDLER(_001OnMove);
      DECLARE_MESSAGE_HANDLER(_001OnSize);
      DECLARE_MESSAGE_HANDLER(_001OnShowWindow);


      //virtual void window_show_change_visibility(::e_display edisplay, ::e_activation eactivation) override;


      //virtual ::user::interaction_impl * from_os_data(void * pdata) override;
      //virtual void * get_os_data() const override;

      //static user::interaction_impl * from_handle(::oswindow hWnd);
      //static user::interaction_impl * FromHandlePermanent(oswindow hWnd);
      //static void DeleteTempMap();
      //bool Attach(oswindow hWndNew);
      //oswindow Detach();

      // subclassing/unsubclassing functions
      virtual void pre_subclass_window() override;
//      bool SubclassWindow(oswindow hWnd);
//      //bool SubclassDlgItem(::u32 nID, __pointer(::interaction_impl) pParent);
//      oswindow UnsubclassWindow();

      // handling of RT_DLGINIT resource (extension to RT_DIALOG)
//      bool ExecuteDlgInit(const char * pszResourceName);
//
//      bool ExecuteDlgInit(LPVOID pResource);

      //virtual bool create_message_queue(::user::interaction * pinteraction, const char * lpszName) override;

//      using ::user::interaction_impl::create_window;

      // for child windows, views, panes etc
//      virtual bool create_window(
//      ::user::interaction * pinteraction,
//      const char * pszClassName,

//      const char * pszWindowName,

//      ::u32 dwStyle,
//      const ::rectangle_i32 & rectangle,
//      ::user::interaction * pParentWnd,
//      id id,
//      ::create * pContext = nullptr) override;
//
//      // advanced creation (allows access to extended styles)
//      virtual bool create_window_ex(
//      ::user::interaction * pinteraction,
//      __pointer(::user::system) pusersystem,
//      ::user::interaction * pParentWnd = nullptr,
//      id id = ::id()) override;


         //virtual ::e_status native_create_host() override;


//      virtual bool native_create_window_ex(
//      ::user::interaction * pinteraction,
//      __pointer(::user::system) pusersystem,
//      ::user::interaction * pParentWnd = nullptr,
//      id id = ::id());

      void start_destroying_window() override;

      // special pre-creation and ::user::interaction_impl rectangle_i32 adjustment hooks
      virtual bool pre_create_window(::user::system * pusersystem) override;

      // Advanced: virtual AdjustWindowRect
//      enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
//      virtual void CalcWindowRect(RECTANGLE_I32 * pClientRect, ::u32 nAdjustType = adjustBorder);




      void _thread_delayed_placement();

      void defer_delayed_placement();


      void on_start_layout_experience(enum_layout_experience elayoutexperience) override;
      void on_end_layout_experience(enum_layout_experience elayoutexperience) override;


      void on_layout(::draw2d::graphics_pointer & pgraphics) override;




      //bool _is_window() const override;
//
//#if(WINVER >= 0x0500)
//
//      ::user::interaction * GetAncestor(::u32 gaFlags) const;
//
//#endif   // WINVER >= 0x0500

      //LRESULT send_message(const ::id & id, WPARAM wParam = 0, lparam lparam = 0) override;

      //bool post_message(const ::id & id, WPARAM wParam = 0, lparam lparam = 0) override;


//      bool SendNotifyMessage(const ::id & id, WPARAM wParam, lparam lParam);
//
//      bool SendChildNotifyLastMsg(LRESULT* pResult = nullptr);
//
//      bool DragDetect(const ::point_i32 & point) const;





//      // oswindow Text Functions
//      void set_window_text(const ::string & strString) override;
//
//      //strsize GetWindowText(char * pszStringBuf, strsize nMaxCount);
//
//      void get_window_text(string & str) override;
      //strsize GetWindowTextLength();
      void SetFont(::write_text::font* pFont, bool bRedraw = true);
      ::write_text::font* GetFont();


      // oswindow size_i32 and position Functions
      //virtual bool node_is_iconic() override;
      //virtual bool layout().is_zoomed();
      //virtual bool layout().is_full_screen();
      //void MoveWindow(i32 x, i32 y, i32 nWidth, i32 nHeight,
        //              bool bRepaint = true);
      //void MoveWindow(const ::rectangle_i32 & rectangle, bool bRepaint = true);

//      i32 SetWindowRgn(HRGN hRgn, bool bRedraw);
//      i32 GetWindowRgn(HRGN hRgn);


//      virtual void _001OnExitIconic() override;
//      virtual void _001OnExitFullScreen() override;
//      virtual void _001OnExitZoomed() override;


      //virtual bool set_window_position(iptr z, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags);
//      virtual ::u32 ArrangeIconicWindows();
      //virtual bool BringWindowToTop();
//      virtual bool get_window_rect(RECTANGLE_I64 * prectangle);

  //    virtual bool _001GetWindowRect(RECTANGLE_I64 * prectangle);

      //using ::user::interaction_impl::get_client_rect;
      //virtual bool get_client_rect(RECTANGLE_I64 * prectangle);


      //virtual bool has_focus() override;
      //virtual bool is_active() override;

      //virtual ::point_i32 client_screen_top_left() override;

//      virtual bool client_to_screen(RECTANGLE_I32 * prectangle);

//      virtual bool client_to_screen(POINT_I32 * ppoint);

//      virtual bool client_to_screen(RECTANGLE_I64 * prectangle);

//      virtual bool client_to_screen(POINT_I64 * ppoint);

//      virtual bool screen_to_client(RECTANGLE_I32 * prectangle);

//      virtual bool screen_to_client(POINT_I32 * ppoint);

//      virtual bool screen_to_client(RECTANGLE_I64 * prectangle);

//      virtual bool screen_to_client(POINT_I64 * ppoint);


//      virtual bool GetWindowPlacement(WINDOWPLACEMENT* puserinteractionpl);
//
//      virtual bool SetWindowPlacement(const WINDOWPLACEMENT* puserinteractionpl);


      // Coordinate Mapping Fufnctions
//      virtual void MapWindowPoints(::user::interaction * puserinteractionTo, POINT_I32 * pPoint, ::u32 nCount);
//
//      virtual void MapWindowPoints(::user::interaction * puserinteractionTo, RECTANGLE_I32 * prectangle);


      // Update/Painting Functions
//      virtual ::draw2d::graphics * GetDC();
//      virtual ::draw2d::graphics * GetWindowDC();
//      virtual bool ReleaseDC(::image * pimage);
//      virtual void Print(::draw2d::graphics_pointer & pgraphics, ::u32 dwFlags) const;
//      virtual void PrintClient(::draw2d::graphics_pointer & pgraphics, ::u32 dwFlags) const;

//      virtual void UpdateWindow();
//      virtual void SetRedraw(bool bRedraw = true);
//      virtual bool GetUpdateRect(RECTANGLE_I32 * prectangle, bool bErase = false);
//
//      virtual i32 GetUpdateRgn(::draw2d::region* pRgn, bool bErase = false);
//      virtual void Invalidate(bool bErase = true);
//      virtual void InvalidateRect(const ::rectangle_i32 & rectangle, bool bErase = true);
//
//      virtual void InvalidateRgn(::draw2d::region* pRgn, bool bErase = true);
//      virtual void ValidateRect(const ::rectangle_i32 & rectangle);
//
//      virtual void ValidateRgn(::draw2d::region* pRgn);
      //virtual bool display(::e_display edisplay) override;

//      virtual bool WfiOnStartDock();
//      virtual void WfiOnDock(edisplay edisplay);
//      virtual void prodevian_prepare_down();
//      virtual void prodevian_prepare_up();
//      virtual void WfiOnRestore();
//      virtual void WfiOnMinimize(bool bNoActivate);
//      virtual void WfiOnMaximize();
//      virtual void WfiOnFullScreen();
//      virtual void WfiOnExitFullScreen();
//      virtual void WfiOnClose();
//      virtual void WfiOnNotifyIcon();


      //virtual bool _is_window_visible() override;
      //virtual void ShowOwnedPopups(bool bShow = true);

      //virtual ::draw2d::graphics * GetDCEx(::draw2d::region* prgnClip, ::u32 flags);
      //virtual bool LockWindowUpdate();
      //virtual void UnlockWindowUpdate();
//      virtual bool RedrawWindow(const ::rectangle_i32& rectUpdate = nullptr,
//                                ::draw2d::region* prgnUpdate = nullptr,
//                                ::u32 flags = RDW_INVALIDATE | RDW_ERASE);
      // xxx      virtual bool EnableScrollBar(i32 nSBFlags, ::u32 nArrowFlags = ESB_ENABLE_BOTH);

      virtual void set_origin(::draw2d::graphics_pointer & pgraphics) override;

//
//      //virtual bool DrawAnimatedRects(i32 idAni, const LPRECTprcFrom, const LPRECTlprcTo);
//
//      virtual bool DrawCaption(::draw2d::graphics_pointer & pgraphics, const rectangle_i32 & prc, ::u32 uFlags);
//
//
//#if(WINVER >= 0x0500)
//
//      virtual bool AnimateWindow(::u32 millis, ::u32 dwFlags);
//
//#endif   // WINVER >= 0x0500
//
//#if(_WIN32_WINNT >= 0x0501)
//
//      virtual bool PrintWindow(::draw2d::graphics_pointer & pgraphics, ::u32 nFlags) const;
//
//#endif   // _WIN32_WINNT >= 0x0501



//      // Timer Functions
//      virtual bool SetTimer(uptr uEvent, ::u32 nElapse, PFN_TIMER pfnTimer);
//      virtual bool KillTimer(uptr uEvent);

      // oswindow State Functions
      virtual bool IsWindowEnabled();
      virtual bool EnableWindow(bool bEnable = true);


      //void prodevian_update_screen() override;


      DECLARE_MESSAGE_HANDLER(on_message_create);
      DECLARE_MESSAGE_HANDLER(_001OnDestroy);
      DECLARE_MESSAGE_HANDLER(_001OnPaint);
      DECLARE_MESSAGE_HANDLER(_001OnPrint);
      DECLARE_MESSAGE_HANDLER(_001OnSetCursor);



      virtual void pre_translate_message(::message::message * pmessage) override;


      virtual void message_handler(::message::message * pusermessage) override;

      virtual void default_window_procedure(::message::message * pusermessage) override;

      virtual void post_non_client_destroy() override;

      virtual void on_final_release() override;

      //static void get_app_wnda(user::oswindow_array & wnda);

      //virtual iptr get_window_long_ptr(i32 nIndex) const override;
      //virtual iptr set_window_long_ptr(i32 nIndex, iptr lValue) override;

      //void _001OnTriggerMouseInside();


      //::user::interaction * get_next(bool bIgnoreChildren, i32 * piLevel);

      //void show_task(bool bShow) override;

      virtual void non_top_most_upper_window_rects(::rectangle_i32_array& recta) override;


      void show_software_keyboard(::user::element* pprimitive) override;
      void hide_software_keyboard(::user::element * pprimitive) override;


   };


} // namespace aura_freebsd



