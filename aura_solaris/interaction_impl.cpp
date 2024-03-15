#include "framework.h"
#include "interaction_impl.h"
#include "acme/constant/message.h"
#include "acme/platform/keep.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/message/user.h"
//#include "aura/operating_system.h"
#include "aura/platform/session.h"
#include "aura/windowing/window.h"



#define TEST 0


namespace aura_freebsd
{


   i64 g_iMouseMove = 0;

//   class x11data :
//      virtual public object
//   {
//   public:
//
//      XWindowAttributes             m_attr;
//      XVisualInfo                   m_visualinfo;
//      // GdkWindow *                   m_pgdkwindow;
//      void *                        m_pgdkwindow;
//
//   };


   interaction_impl::interaction_impl()
   {

      linux_interaction_impl_common_construct();

   }


//   interaction_impl::interaction_impl()
//   {
//
//      linux_interaction_impl_common_construct();
//
//   }


   void interaction_impl::linux_interaction_impl_common_construct()
   {

      //set_os_data(nullptr);

      m_bExposing    = false;
      m_bEnabled     = true;
      m_bMoveEvent   = false;
      m_bSizeEvent   = false;

   }


   interaction_impl::~interaction_impl()
   {

   }


//   ::user::interaction_impl * interaction_impl::from_os_data(void * pdata)
//   {
//
//      return from_handle((oswindow) pdata);
//
//   }


//   void * interaction_impl::get_os_data() const
//   {
//
//      return m_oswindow;
//
//   }


//   const MESSAGE* PASCAL interaction_impl::GetCurrentMessage()
//   {
//
//      return nullptr;
//
//   }
//

//   LRESULT interaction_impl::Default()
//   {
//
//      return 0;
//
//   }


//   ::user::interaction_impl * interaction_impl::from_handle(oswindow oswindow)
//   {
//
//      if(is_null(oswindow))
//      {
//
//         return nullptr;
//
//      }
//
//      if(is_null(oswindow->m_puserinteractionimpl))
//      {
//
//         return nullptr;
//
//      }
//
//      return oswindow->m_puserinteractionimpl;
//
//   }
//
//
//   ::user::interaction_impl * interaction_impl::FromHandlePermanent(oswindow oswindow)
//   {
//
//      if(oswindow->m_puserinteractionimpl == nullptr)
//      {
//
//         return nullptr;
//
//      }
//
//      return oswindow->m_puserinteractionimpl;
//
//   }
//
//
//   bool interaction_impl::Attach(oswindow hWndNew)
//   {
//
//      ASSERT(get_os_data() == nullptr);
//
//      if (hWndNew == nullptr)
//      {
//
//         return false;
//
//      }
//
//      //set_os_data(hWndNew);
//
//      return true;
//
//   }
//
//
//   oswindow interaction_impl::Detach()
//   {
//
////      oswindow hwnd = (oswindow) get_os_data();
////
////      if (hwnd != nullptr)
////      {
////
////         set_os_data(nullptr);
////
////      }
//
//      //return hwnd;
//
//      auto oswindow = get_oswindow();
//
//      m_pwindow->set_oswindow(nullptr);
//
//      return oswindow;
//
//   }


   void interaction_impl::pre_subclass_window()
   {


   }


//   ::e_status interaction_impl::native_create_host()
//   {
//
//      __pointer(::user::system) pusersystem;
//
//      if(m_puserinteraction->m_pusersystem)
//      {
//
//         pusersystem = m_puserinteraction->m_pusersystem;
//
//      }
//      else
//      {
//
//         pusersystem = __new(::user::system);
//
//      }
//
////      ENSURE_ARG(pusersystem->m_createstruct.lpszName == nullptr || __is_valid_string(pusersystem->m_createstruct.lpszName));
////
//      if (!m_puserinteraction->pre_create_window(pusersystem))
//      {
//
//         return false;
//
//      }
//
//      __refer(m_puserinteraction->m_pthreadUserInteraction, ::get_task());
//
//      //m_pthreadUserImpl = m_puserinteraction->m_pthreadUserInteraction;
//
//      install_message_routing(m_puserinteraction);
//
//      bool bOk = true;
//
////      if(pusersystem->m_createstruct.hwndParent == (oswindow) MESSAGE_WINDOW_PARENT)
////      {
////
////         auto pwindowing = m_pwindowwindowing();
////
////         m_oswindow = pwindowing->new_message_window(this);
////
////         m_puserinteraction->m_bMessageWindow = true;
////
////         //send_message(e_message_create, 0, (LPARAM) &cs);
////
////      }
////      else
//      {
//
//         m_puserinteraction->m_bMessageWindow = false;
//
//         auto psession = get_session();
//
//         auto puser = psession->user();
//
//         auto pwindowing = puser->windowing();
//
//         pwindowing->windowing_send(__routine(15_s, [&]()
//         {
//
//            auto psession = get_session();
//
//            auto puser = psession->user();
//
//            auto pwindowing = puser->windowing();
//
//            m_pwindow = pwindowing->new_window(this);
//
//            if(m_pwindow)
//            {
//
//               output_debug_string("window created");
//
//            }
//            else
//            {
//
//               output_debug_string("window not created");
//
//            }
//
//         }));
//
//      }
//
////      if(bOk)
////      {
////
////         m_puserinteraction->send_message(e_message_create, 0, (lparam) &pusersystem->m_createstruct);
////
////         m_puserinteraction->m_ewindowflag |= e_window_flag_window_created;
////
////      }
//
//      return bOk;
//
//   }


   bool interaction_impl::pre_create_window(::user::system * pusersystem)
   {

      return true;

   }


   void interaction_impl::install_message_routing(::channel * pchannel)
   {

      //m_pbuffer->InstallMessageHandling(pinterface);

      ::user::interaction_impl::last_install_message_routing(pchannel);

      ::user::interaction_impl::install_message_routing(pchannel);

      if(!m_puserinteraction->m_bMessageWindow)
      {

         MESSAGE_LINK(e_message_paint, pchannel, this,&interaction_impl::_001OnPaint);
//         MESSAGE_LINK(WM_PRINT, pchannel, this,&interaction_impl::_001OnPrint);

      }

      m_puserinteraction->install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this,&interaction_impl::on_message_create);

      if(!m_puserinteraction->m_bMessageWindow)
      {

         MESSAGE_LINK(e_message_set_cursor, pchannel, this,&interaction_impl::_001OnSetCursor);
         //MESSAGE_LINK(e_message_erase_background, pchannel, this,&interaction_impl::_001OnEraseBkgnd);
         //MESSAGE_LINK(e_message_size, pchannel, this,&interaction_impl::_001OnSize);
         //MESSAGE_LINK(e_message_nccalcsize, pchannel, this,&interaction_impl::_001OnNcCalcSize);

         // linux
         MESSAGE_LINK(e_message_reposition, pchannel, this, &interaction_impl::_001OnMove);
         MESSAGE_LINK(e_message_size, pchannel, this, &interaction_impl::_001OnSize);
         MESSAGE_LINK(e_message_show_window, pchannel, this, &interaction_impl::_001OnShowWindow);

         //MESSAGE_LINK(e_message_window_position_changing, pchannel, this,&interaction_impl::_001OnWindowPosChanging);
         //MESSAGE_LINK(e_message_window_position_changed, pchannel, this,&interaction_impl::_001OnWindowPosChanged);
         //MESSAGE_LINK(WM_GETMINMAXINFO, pchannel, this,&interaction_impl::_001OnGetMinMaxInfo);
         //MESSAGE_LINK(e_message_set_focus, pchannel, this,&interaction_impl::_001OnSetFocus);
         //MESSAGE_LINK(e_message_kill_focus, pchannel, this,&interaction_impl::_001OnKillFocus);
//         MESSAGE_LINK(ca2m_PRODEVIAN_SYNCH, pchannel, this,&interaction_impl::_001OnProdevianSynch);
         ::user::interaction_impl::prio_install_message_routing(pchannel);

      }

      MESSAGE_LINK(e_message_destroy, pchannel, this,&interaction_impl::_001OnDestroy);

   }


   void interaction_impl::defer_delayed_placement()
   {

      if(!m_puserinteraction->layout().is_changing())
      {

         if(m_bMoveEvent || m_bSizeEvent)
         {

            defer_branch("delayed_placement", [this]()
            {

               _thread_delayed_placement();

            });

         }

      }

   }


   void interaction_impl::_thread_delayed_placement()
   {

      while(m_timeLastPlacementEvent.elapsed() < 40_ms || m_puserinteraction->layout().is_changing())
      {

         if(!task_sleep(10_ms))
         {

            return;

         }

      }

      if(!task_get_run())
      {

         return;

      }

      bool bMove = m_bMoveEvent && m_puserinteraction->const_layout().sketch().origin() != m_pointLastMove;

      m_bMoveEvent = false;

      if (bMove)
      {

         information()<<"linux::interaction_impl Window Manager Move ("<<m_pointLastMove.x()<<", "<<m_pointLastMove.y()<<")";

         m_puserinteraction->set_position(m_pointLastMove);

         m_puserinteraction->set_reposition();

      }

      bool bSize = m_bSizeEvent && m_puserinteraction->const_layout().sketch().size() != m_sizeLastSize;

      m_bSizeEvent = false;

      if (bSize)
      {

         informationf("linux::interaction_impl Window Manager Size (%d, %d)", m_sizeLastSize.cx(), m_sizeLastSize.cy());

         m_puserinteraction->set_size(m_sizeLastSize);

         m_puserinteraction->set_need_layout();

      }

      if(bMove || bSize)
      {

         m_puserinteraction->display();

         m_puserinteraction->set_need_redraw();

         m_puserinteraction->post_redraw();

      }

   }


   void interaction_impl::_001OnMove(::message::message * pmessage)
   {

//      __pointer(::message::size) psize(pmessage);
//
//      if (m_bDestroyImplOnly)
//      {
//
//         return;
//
//      }
//
//      if (m_puserinteraction->layout().m_eflag)
//      {
//
//         pmessage->m_bRet = true;
//
//         return;
//
//      }

//      __pointer(::message::move) pmove(pmessage);
//
//      m_puserinteraction->layout().origin() = pmove->m_point;
//
//      m_puserinteraction->layout().screen_origin() = pmove->m_point;
//
//      if(m_puserinteraction->layout().window().origin() != m_puserinteraction->layout().sketch().origin())
//      {
//
//         m_puserinteraction->move_to(pmove->m_point);
//
//         m_puserinteraction->set_reposition();
//
//         m_puserinteraction->post_redraw();
//
//      }

   }


   void interaction_impl::_001OnSize(::message::message * pmessage)
   {

//      if (m_bDestroyImplOnly)
//      {
//
//         return;
//
//      }
//
//      if (m_puserinteraction->layout().m_eflag)
//      {
//
//         pmessage->m_bRet = true;
//
//         return;
//
//      }
//
//      __pointer(::message::size) psize(pmessage);

//      m_puserinteraction->window_state3().m_size = psize->m_size;
//
//      if(m_puserinteraction->window_state3().m_size != m_puserinteraction->layout().sketch().m_size)
//      {
//
//         m_puserinteraction->set_size(psize->m_size);
//
//         m_puserinteraction->set_need_layout();
//
//         m_puserinteraction->post_redraw();
//
//      }

   }


   void interaction_impl::_001OnShowWindow(::message::message * pmessage)
   {

      ::pointer < ::message::show_window > pshowwindow(pmessage);

      if(!m_puserinteraction)
      {

         return;

      }

      if(pshowwindow->m_bShow)
      {

         information() << "linux::interaction_impl::_001OnShowWindow VISIBLE edisplay=" << ::as_string(m_puserinteraction->const_layout().design().display().m_eenum);

         //m_puserinteraction->ModifyStyle(0, WS_VISIBLE);

         //m_puserinteraction->m_bVisible = true;

         if(m_puserinteraction->const_layout().design().display() == ::e_display_iconic && !m_pwindow->is_iconic())
         {

            //m_puserinteraction->hide();

//            if(m_puserinteraction->window_previous_display() == ::e_display_iconic)
//            {
//
//               m_puserinteraction->_001OnDeiconify(::e_display_stored);
//
//            }
//            else
//            {

               m_puserinteraction->display_previous();

//               m_puserinteraction->_001OnDeiconify(m_puserinteraction->window_previous_display());
//
//            }

         }

         m_puserinteraction->set_need_redraw();

         m_puserinteraction->post_redraw();

         //x11_defer_check_configuration(m_oswindow);

      }
      else
      {

         //m_puserinteraction->ModifyStyle(WS_VISIBLE, 0, 0);
         //m_puserinteraction->m_bVisible = false;

      }

   }


   void interaction_impl::on_start_layout_experience(enum_layout_experience elayout)
   {

      //child_post_quit("delayed_placement");

      ::user::interaction_impl::on_start_layout_experience(elayout);

   }


   void interaction_impl::on_end_layout_experience(enum_layout_experience elayout)
   {

      defer_delayed_placement();

   }


   void interaction_impl::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::interaction_impl::on_layout(pgraphics);

   }


   void interaction_impl::_001OnDestroy(::message::message * pmessage)
   {

//      UNREFERENCED_PARAMETER(pmessage);
//
//      {
//
//         single_lock synchronouslock(get_application() == nullptr ? nullptr : get_application()->mutex(), true);
//
//         auto ptask = ::get_task();
//
//         if (::is_null(ptask))
//         {
//
//            if (pthread->get_active_ui() == m_puserinteraction)
//            {
//
//               pthread->set_active_ui(nullptr);
//
//            }
//
//         }
//
//      }

//      ::parallelization::post_quit_and_wait(m_pthreadProDevian, seconds(10));

//      if (m_puserinteraction->m_pthread != nullptr)
//      {
//
//         synchronous_lock synchronouslock(m_puserinteraction->m_pthread->mutex());
//
//         if(m_puserinteraction->m_pthread->m_puiptra != nullptr)
//         {
//
//            m_puserinteraction->m_pthread->m_puiptra->erase(m_puserinteraction);
//
//         }
//
//      }

      //Default();

   }


   void interaction_impl::post_non_client_destroy()
   {

      //clear_os_data();

      if (m_pwindow)
      {

         m_pwindow->post_non_client_destroy();

      }

      ::user::interaction_impl::post_non_client_destroy();

   }


   void interaction_impl::on_final_release()
   {

      if (get_os_data() != nullptr)
      {

         start_destroying_window();

      }
      else
      {

         post_non_client_destroy();

      }

   }


//   void interaction_impl::assert_ok() const
//   {
//
//      if (get_os_data() == nullptr)
//      {
//
//         return;
//
//      }
//
//   }


//   void interaction_impl::dump(dump_context & dumpcontext) const
//   {
//
//      ::object::dump(dumpcontext);
//
//      dumpcontext << "\nm_hWnd = " << (void *)((interaction_impl *) this)->get_os_data();
//
//      /*
//
//      if (get_handle() == nullptr || get_handle() == oswindow_BOTTOM ||
//               get_handle() == oswindow_TOPMOST || get_handle() == oswindow_NOTOPMOST)
//      {
//
//         // not a normal interaction_impl - nothing more to dump
//            return;
//
//      }
//
//      */
//
//      /*
//
//      if (!::is_window((oswindow) get_handle()))
//      {
//
//         // not a valid interaction_impl
//         dumpcontext << " (illegal oswindow)";
//         return; // don't do anything more
//
//      }
//
//      */
//
//      __pointer(::user::interaction_impl) pWnd = (::user::interaction_impl *) this;
//      if (pWnd.m_p != this)
//         dumpcontext << " (Detached or temporary interaction_impl)";
//      else
//         dumpcontext << " (permanent interaction_impl)";
//
//      char szBuf [64];
//
//      ::rectangle_i32 rectangle;
//      ((::user::interaction_impl *) this)->m_puserinteraction->get_window_rect(&rectangle);
//      dumpcontext << "\nrect = " << rectangle;
//      dumpcontext << "\nparent __pointer(::interaction_impl) = " << (void *)((::user::interaction_impl *) this)->get_parent();
//
////      dumpcontext << "\nstyle = " << (void *)(dword_ptr)::GetWindowLong(get_handle(), GWL_STYLE);
//      //    if (::GetWindowLong(get_handle(), GWL_STYLE) & WS_CHILD)
//      //     dumpcontext << "\nid = " << __get_dialog_control_id(get_handle());
//
//      dumpcontext << "\n";
//   }


   void interaction_impl::start_destroying_window()
   {

      if(!m_pwindow)
      {

         //return true;

         return;

      }

//      if(m_oswindow->m_bMessageOnlyWindow)
//      {
//
//         ::user::interaction * pinteraction = m_puserinteraction;
//
//         send_message(e_message_destroy, 0, 0);
//
//         send_message(e_message_ncdestroy, 0, 0);
//
//         auto pwindowing = ::aura::get_system()->windowing();
//
//         pwindowing->erase_window(this);
//
//         return true;
//
//      }

      bool bResult = false;

//      auto oswindow = get_oswindow();
//
//      if (oswindow != nullptr)
//      {

//   if()///
         //bResult =

         m_pwindow->destroy_window();

         //Detach();

//      }

      //return bResult;

   }


   /////////////////////////////////////////////////////////////////////////////
   // Default interaction_impl implementation


   void interaction_impl::default_window_procedure(::message::message * pmessage)
   {

      /*  if (m_pfnSuper != nullptr)
           return ::callWindowProc(m_pfnSuper, get_handle(), nMsg, wparam, lparam);

        WNDPROC pfnWndProc;
        if ((pfnWndProc = *GetSuperWndProcaddr()) == nullptr)
        {

           return ::default_window_procedure(get_handle(), nMsg, wparam, lparam);

         }
        else
        {

           return ::callWindowProc(pfnWndProc, get_handle(), nMsg, wparam, lparam);

           }
           */


//      return 0;
   }

   /*
      WNDPROC* interaction_impl::GetSuperWndProcaddr()
      {
         // Note: it is no longer necessary to override GetSuperWndProcaddr
         //  for each control class with a different WNDCLASS.
         //  This implementation now uses instance data, such that the previous
         //  WNDPROC can be anything.

         return &m_pfnSuper;
      }
   */
   void interaction_impl::pre_translate_message(::message::message * pmessage)
   {
      UNREFERENCED_PARAMETER(pmessage);
      // no default processing
   }


//   void interaction_impl::get_window_text(string & rectString)
//   {
//
//      rectString = m_strWindowText;
//
//   }

   /*
      i32 interaction_impl::GetDlgItemText(i32 nID, string & rectString) const
      {
         ASSERT(::is_window((oswindow) get_handle()));
         rectString = "";    // is_empty without deallocating

         oswindow hWnd = ::GetDlgItem(get_handle(), nID);
         if (hWnd != nullptr)
         {
            i32 nLen = ::GetWindowTextLength(hWnd);
            ::GetWindowText(hWnd, rectString.get_string_buffer(nLen), nLen+1);
            rectString.ReleaseBuffer();
         }

         return (i32)rectString.get_length();
      }
   */

//   bool interaction_impl::GetWindowPlacement(WINDOWPLACEMENT* puserinteractionpl)
//
//   {
//      /*    ASSERT(::is_window((oswindow) get_handle()));
//          puserinteractionpl->length = sizeof(WINDOWPLACEMENT);
//
//          return ::GetWindowPlacement(get_handle(), puserinteractionpl) != false;*/
//
//      return false;
//   }
//
//   bool interaction_impl::SetWindowPlacement(const WINDOWPLACEMENT* puserinteractionpl)
//
//   {
//      /*      ASSERT(::is_window((oswindow) get_handle()));
//            ((WINDOWPLACEMENT*)puserinteractionpl)->length = sizeof(WINDOWPLACEMENT);
//
//            return ::SetWindowPlacement(get_handle(), puserinteractionpl) != false;*/
//
//      return false;
//   }

   /////////////////////////////////////////////////////////////////////////////
   // interaction_impl will delegate owner draw messages to self drawing controls

   // Drawing: for all 4 control types
// /*   void interaction_impl::OnDrawItem(i32 /*nIDCtl*/, LPDRAWITEMSTRUCT pDrawItemStruct)

   // {

   // reflect notification to child interaction_impl control
   //  if (ReflectLastMsg(pDrawItemStruct->hwndItem))

   //   return;     // eat it

   // not handled - do default
//      Default();
   // }

   // Drawing: for all 4 control types
//   i32 interaction_impl::OnCompareItem(i32 /*nIDCtl*/, LPCOMPAREITEMSTRUCT pCompareItemStruct)

   // {
   //  // reflect notification to child interaction_impl control
   //LRESULT lResult;
//      if (ReflectLastMsg(pCompareItemStruct->hwndItem, &lResult))

   //       return (i32)lResult;        // eat it

   // not handled - do default
   //  return (i32)Default();
//   }

   // void interaction_impl::OnDeleteItem(i32 /*nIDCtl*/, LPDELETEITEMSTRUCT pDeleteItemStruct)

   //{
   // reflect notification to child interaction_impl control
   // if (ReflectLastMsg(pDeleteItemStruct->hwndItem))

   //  return;     // eat it
   // not handled - do default
//      Default();
   // }

//   bool interaction_impl::_EnableToolTips(bool bEnable, ::u32 nFlag)
//   {
//      UNREFERENCED_PARAMETER(bEnable);
//      UNREFERENCED_PARAMETER(nFlag);
//      return false;
//   }

//   LRESULT interaction_impl::OnNTCtlColor(wparam wparam, lparam lparam)
//
//   {
//      return 0;
//   }
//
//
//   void interaction_impl::PrepareForHelp()
//   {
//   }


   void interaction_impl::route_command(::message::command * pcommand, bool bRouteKeyToDescendants)
   {

      channel::route_command(pcommand, bRouteKeyToDescendants);

   }


//   void interaction_impl::on_control_event(::user::control_event * pevent)
//   {
//
//      UNREFERENCED_PARAMETER(pevent);
//
//   }


//   void interaction_impl::_002OnDraw(::image * pimage)
//   {
//
//   }
//

//   ::duration     durationDebugmessage_handlerTime;
//   int            iDebugmessage_handlerTime;
//   ::duration     durationLastMouseMove;
//   ::duration     durationLastPaint;
//

   void interaction_impl::message_handler(::message::message * pmessage)
   {


      ::user::interaction_impl::message_handler(pmessage);

//      bool bKeyMessage = false;
//
//      ::message::key * pkey = nullptr;
//
//      if (m_puserinteraction->pre_message_handler(pkey, bKeyMessage, pmessage))
//      {
//
//         return;
//
//      }
//
//      if(pmessage->m_atom == e_message_timer)
//      {
//
//         //m_pthread->step_timer();
//
//      }
//      else if(pmessage->m_atom == e_message_left_button_down)
//      {
//
//         output_debug_string("linux::interaction_impl::e_message_left_button_down\n");
//
//      }
//      else if(pmessage->m_atom == e_message_left_button_up)
//      {
//
//         output_debug_string("linux::interaction_impl::e_message_left_button_up\n");
//
//      }
//      else if(pmessage->m_atom == e_message_mouse_move)
//      {
//
//         g_iMouseMove++;
//
//         //TRACE("linux::interaction_impl::message_handler e_message_mouse_move");
//         //printf("g_iMouseMove = %d\n", g_iMouseMove);
//
//      }
//      else if(pmessage->m_atom == e_message_paint)
//      {
//
//      }
//      else if(pmessage->m_atom == e_message_left_button_up)
//      {
//
//         TRACE("e_message_left_button_up (0)");
//
//      }
//
////      if(::is_set(m_puserinteraction))
////      {
////
////         m_puserinteraction->pre_translate_message(pmessage);
////
////      }
//
////      if(tickDebugmessage_handlerTime.timeout(1))
////      {
////
////         iDebugmessage_handlerTime = 0;
////
////      }
////      else
////      {
////
////         if(iDebugmessage_handlerTime > 20)
////         {
////
////            ::output_debug_string("interaction_impl::message handler flooded?\n");
////
////         }
////         else
////         {
////
////            iDebugmessage_handlerTime++;
////
////         }
////
////      }
//
//      if(m_puserinteraction != nullptr)
//      {
//
//         if (m_puserinteraction->layout().is_moving())
//         {
//            //TRACE("moving: skip pre translate message");
//         }
//         else if (m_puserinteraction->layout().is_sizing())
//         {
//            //TRACE("sizing: skip pre translate message");
//         }
//         else
//         {
//
//            //m_puserinteraction->pre_translate_message(pmessage);
//
//            //if (pmessage->m_bRet)
//            //{
//
//              // return;
//
//            //}
//
//            //pmessage->m_uiMessageFlags |= 1;
//
//         }
//
//      }
//
//
//
////      if(bKeyMessage)
////      {
////
////         auto psession = get_session();
////
////         auto puser = psession->user();
////
////         auto pwindowing = puser->windowing();
////
////         __pointer(::message::key) pkey = pmessage;
////
////         //pwindowing->set(pkey, get_oswindow(), m_pwindow, pkey->m_id, pkey->m_wparam, pkey->m_lparam);
////
//////         if(pmessage->m_id == e_message_key_down)
//////         {
//////
//////            try
//////            {
//////
//////               psession->set_key_pressed(pkey->m_ekey, true);
//////
//////            }
//////            catch(...)
//////            {
//////
//////            }
//////
//////         }
//////         else if(pmessage->m_id == e_message_key_up)
//////         {
//////
//////            try
//////            {
//////
//////               psession->set_key_pressed(pkey->m_ekey, false);
//////
//////            }
//////            catch(...)
//////            {
//////
//////            }
//////
//////         }
////
////      }
//
//      pmessage->m_lresult = 0;
//
//      if(pmessage->m_atom == e_message_mouse_leave)
//      {
//
//         _000OnMouseLeave(pmessage);
//
//         return;
//
//      }
//
//      if(pmessage->m_atom == e_message_left_button_down ||
//            pmessage->m_atom == e_message_left_button_up ||
//            pmessage->m_atom == e_message_middle_button_down ||
//            pmessage->m_atom == e_message_middle_button_up ||
//            pmessage->m_atom == e_message_right_button_down ||
//            pmessage->m_atom == e_message_right_button_up ||
//            pmessage->m_atom == e_message_mouse_move ||
//            pmessage->m_atom == e_message_mouse_move)
////         pmessage->m_id == e_message_mouse_wheel)
//      {
//
//         if(::is_set(m_puserinteraction) && !m_puserinteraction->m_bUserElementOk)
//         {
//
//            return;
//
//         }
//
//         __pointer(::message::mouse) pmouse = pmessage;
//
//         auto psession = get_session();
//
//         if(psession != nullptr)
//         {
//
//            psession->on_ui_mouse_message(pmouse);
//
//            psession->m_pointCursor = pmouse->m_point;
//
//         }
//
////         if(m_puserinteraction != nullptr && m_puserinteraction->get_session()  != nullptr && m_puserinteraction->get_session() != get_session())
////         {
////
////            auto psystem = m_psystem;
////
////            auto psession = psystem->node();
////
////            psession->m_pointCursor = pmouse->m_point;
////
////         }
//
//         if(m_bTranslateMouseMessageCursor && !pmouse->m_bTranslated)
//         {
//            pmouse->m_bTranslated = true;
//            ::rectangle_i32 rectWindow;
////            if(m_bScreenRelativeMouseMessagePosition)
////            {
////
////               INFO("Screen Relative Mouse Message Position");
////
////               ::rectangle_i32 rectWindow32;
////
////               ::get_window_rect((oswindow) get_handle(), &rectWindow32);
////
////               ::copy(rectWindow, rectWindow32);
////
////            }
////            else
//            {
//               m_puserinteraction->get_window_rect(rectWindow);
//            }
//
//            auto pwindowing = m_puserinteraction->windowing();
//
//            auto pdisplay = pwindowing->display();
//
//            if(pdisplay->get_monitor_count() > 0)
//            {
//
//               ::rectangle_i32 rcMonitor;
//
//               pdisplay->get_monitor_rectangle(0, &rcMonitor);
//
//               if(rectWindow.left >= rcMonitor.left)
//               {
//
//                  pmouse->m_point.x += (::i32) rectWindow.left;
//
//               }
//
//               if(rectWindow.top >= rcMonitor.top)
//               {
//
//                  pmouse->m_point.y += (::i32) rectWindow.top;
//
//               }
//
//            }
//            else
//            {
//
//               if(rectWindow.left >= 0)
//               {
//
//                  pmouse->m_point.x += (::i32) rectWindow.left;
//
//               }
//
//               if(rectWindow.top >= 0)
//               {
//
//                  pmouse->m_point.y += (::i32) rectWindow.top;
//
//               }
//
//            }
//
//         }
//
//         auto puser = psession->user();
//
//         auto pwindowing = puser->windowing();
//
//         pwindowing->set(pmouse, get_oswindow(), m_pwindow, pmouse->m_atom, pmouse->m_wparam, pmouse->m_lparam);
//
//         if(pmessage->m_atom == e_message_mouse_move)
//         {
//
//            // We are at the message handler routine.
//            // mouse messages originated from message handler and that are mouse move events should end up with the correct cursor.
//            // So the routine starts by setting to the default cursor,
//            // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
//            // handler has set it to another one.
//
//            m_puserinteraction->m_pinteractionimpl->_on_mouse_move_step(pmouse->m_point);
//
//         }
//
//         //_008OnMouse(pmouse);
//
//         ::user::interaction * puserinteractionMouse = nullptr;
//
//         if(m_puserinteractionCapture)
//         {
//
////            if(g_puserinteractionMouseCapture123 == nullptr)
////            {
////
////               g_puserinteractionMouseCapture123 = m_puserinteractionCapture;
////
////            }
////            else if(g_puserinteractionMouseCapture123 != m_puserinteractionCapture)
////            {
////
////               output_debug_string("different capture (1)");
////
////            }
//
//            puserinteractionMouse = m_puserinteractionCapture;
//
//         }
//
////         if(g_puserinteractionMouseCapture123 != nullptr)
////         {
////
////            if(g_puserinteractionMouseCapture123 != puserinteractionMouse)
////            {
////
////               output_debug_string("different capture (2)");
////
////            }
////
////         }
////         else
////         {
////
////
////
////         }
//
//         if(pmouse->m_atom == e_message_left_button_down)
//         {
//
//
//            ::output_debug_string("left_button_down (A)");
//
//         }
//
//         if(!puserinteractionMouse)
//         {
//
//            puserinteractionMouse = m_puserinteraction->child_from_point(pmouse->m_point);
//
//         }
//
//         if(pmouse->m_atom == e_message_left_button_down)
//         {
//
//
//            ::output_debug_string("left_button_down");
//
//         }
//         else if(pmouse->m_atom == e_message_left_button_up)
//         {
//
//
//            ::output_debug_string("left_button_up");
//
//         }
//
//         string strUserInteractionType(::is_null(puserinteractionMouse) ? "(null)" : __type_name(puserinteractionMouse));
//
//         if(pmouse->m_atom == e_message_mouse_move)
//         {
//
//            static int s_iMotionNotify = 0;
//
//            s_iMotionNotify++;
//
//            if (strUserInteractionType.contains_ci("button"))
//            {
//
//               output_debug_string("mouse_move::userinteraction=button");
//
//            }
//            else
//            {
//
//
//               puserinteractionMouse = m_puserinteraction->child_from_point(pmouse->m_point);
//
//
//
//            }
//
//         }
//
//         if(puserinteractionMouse)
//         {
//
//            do
//            {
//
//               puserinteractionMouse->route_message(pmouse);
//
//               if(pmouse->m_bRet)
//               {
//
//                  break;
//
//               }
//
//               puserinteractionMouse = puserinteractionMouse->get_parent();
//
//            }while(puserinteractionMouse != nullptr);
//
//         }
//
//         return;
//
//      }
///*      else if(pmessage->m_id == e_message_key_down ||
//              pmessage->m_id == e_message_key_up ||
//              pmessage->m_id == e_message_char)*/
//      else if(bKeyMessage)
//      {
//
//         __pointer(::user::interaction) puiFocus =  m_puserinteractionFocus1;
//
//         if(puiFocus)
//         {
//
//            puiFocus->route_message(pkey);
//
//         }
//         else
//         {
//
//             m_puserinteraction->route_message(pkey);
//
//         }
//
//         if(pmessage->m_bRet)
//         {
//
//            return;
//
//         }
//
//         default_window_procedure(pmessage);
//
//         return;
//
//      }
//
//      if(pmessage->m_atom == e_message_subject)
//      {
//
//         if(m_puserinteraction != nullptr)
//         {
//
//            m_puserinteraction->handle((::topic *) pmessage->m_lparam.m_lparam, nullptr);
//
//         }
////         else
////         {
////
////            on_control_event((::user::control_event *) pmessage->m_lparam.m_lparam);
////
////         }
//
//         return;
//
//      }
//
//      if(::is_set(m_puserinteraction))
//      {
//
//         m_puserinteraction->route_message(pmessage);
//
//      }
//      else
//      {
//
//         route_message(pmessage);
//
//      }
//
//      if(pmessage->m_bRet)
//      {
//
//         return;
//
//      }
//
//      default_window_procedure(pmessage);

   }


//   bool interaction_impl::OnCommand(wparam wparam, lparam lparam)
//   {
//
//      UNREFERENCED_PARAMETER(wparam);
//      UNREFERENCED_PARAMETER(lparam);
//
//      return false;
//
//   }
//
//
//   bool interaction_impl::OnNotify(WPARAM, lparam lparam, LRESULT* pResult)
//   {
//
//      return false;
//
//   }


//   ::user::interaction * interaction_impl::get_parent()
//   {
//
//      if(!::is_window((oswindow) get_handle()))
//      {
//
//         return nullptr;
//
//      }
//
//      if(get_handle() == nullptr)
//      {
//
//         return nullptr;
//
//      }
//
//      //return ::linux::interaction_impl::from_handle(::get_parent(get_handle()));
//
//      return nullptr;
//
//   }


//   ::user::interaction * interaction_impl::get_top_level()
//   {
//
//      if(!::is_window((oswindow) get_handle()))
//         return nullptr;
//
//      if(get_handle() == nullptr)
//         return nullptr;
//
//      return m_puserinteraction;
//
//   }


   /*
      ::user::interaction * interaction_impl::GetTopLevelOwner()
      {
         if (get_handle() == nullptr) // no oswindow attached
            return nullptr;

         ASSERT_VALID(this);

   //      oswindow hWndOwner = get_handle();
     //    oswindow hWndT;
       //  while ((hWndT = ::GetWindow(hWndOwner, GW_OWNER)) != nullptr)
         //   hWndOwner = hWndT;

   //      return ::linux::interaction_impl::from_handle(hWndOwner);
           return nullptr;
      }

      ::user::interaction * interaction_impl::GetParentOwner()
      {
         if (get_handle() == nullptr) // no oswindow attached
            return nullptr;

         ASSERT_VALID(this);

   //         oswindow hWndParent = get_handle();
   //         oswindow hWndT;
   //         while ((::GetWindowLong(hWndParent, GWL_STYLE) & WS_CHILD) &&
   //            (hWndT = ::get_parent(hWndParent)) != nullptr)
   //         {
   //            hWndParent = hWndT;
   //         }
   //
   //         return ::linux::interaction_impl::from_handle(hWndParent);

   //return nullptr;
   //}

   */

//   bool interaction_impl::IsTopParentActive()
//   {
//      ASSERT(get_handle() != nullptr);
//      ASSERT_VALID(this);
//
//      __pointer(::user::interaction)pWndTopLevel=EnsureTopLevel();
//
//      return interaction_impl::GetForegroundWindow() == pWndTopLevel->GetLastActivePopup();
//   }

//   void interaction_impl::ActivateTopParent()
//   {
//      // special activate logic for floating toolbars and palettes
//      __pointer(::user::interaction) pActiveWnd = GetForegroundWindow();
////      if (pActiveWnd == nullptr || !(LNX_WINDOW(pActiveWnd)->get_handle() == get_handle() || ::IsChild(LNX_WINDOW(pActiveWnd)->get_handle(), get_handle())))
//      {
//         // clicking on floating frame when it does not have
//         // focus itself -- activate the toplevel frame instead.
//         EnsureTopLevel()->SetForegroundWindow();
//      }
//   }

   /*
      __pointer(::user::frame_window) interaction_impl::top_level_frame()
      {
         if (get_handle() == nullptr) // no oswindow attached
            return nullptr;

         ASSERT_VALID(this);

         __pointer(::user::frame_window) pFrameWnd = nullptr;
         if(m_puserinteraction != this)
            pFrameWnd =  (m_puserinteraction);
         else
            pFrameWnd =  (this);
         if (pFrameWnd == nullptr || !pFrameWnd->is_frame_window())
            pFrameWnd = get_parent_frame();

         if (pFrameWnd != nullptr)
         {
            __pointer(::user::frame_window) pTemp;
            while ((pTemp = pFrameWnd->get_parent_frame()) != nullptr)
               pFrameWnd = pTemp;
         }
         return pFrameWnd;
      }*/

   /*   __pointer(::interaction_impl) interaction_impl::GetSafeOwner(::interaction_impl * pParent, oswindow* pWndTop)
      {
         oswindow hWnd = GetSafeOwner_((oswindow) pParent->get_handle(), pWndTop);
         return ::linux::interaction_impl::from_handle(hWnd);
      }
   */
//   i32 interaction_impl::message_box(const char * pszText, const char * pszcaption, ::u32 nType)
//   {
//
//      string strCaption;
//
//      if (pszcaption == nullptr)
//      {
//
//         strCaption = get_application()->m_strAppName;
//
//      }
//      else
//      {
//
//         strCaption = pszcaption;
//
//      }
//
//      i32 nResult = ::os_message_box((oswindow)get_handle(), pszText, strCaption, nType);
//
//      return nResult;
//
//   }


   /////////////////////////////////////////////////////////////////////////////
   // Scroll bar helpers
   //  hook for interaction_impl functions
   //    only works for derived class (eg: ::view) that override 'GetScrollBarCtrl'
   // if the interaction_impl doesn't have a _visible_ windows scrollbar - then
   //   look for a sibling with the appropriate ID


//   i32 interaction_impl::SetScrollPos(i32 nBar, i32 nPos, bool bRedraw)
//   {
////      return ::SetScrollPos(get_handle(), nBar, nPos, bRedraw);
//      return 0;
//   }
//
//   i32 interaction_impl::GetScrollPos(i32 nBar) const
//   {
//      //return ::GetScrollPos(get_handle(), nBar);
//      return 0;
//   }
//
//   void interaction_impl::SetScrollRange(i32 nBar, i32 nMinPos, i32 nMaxPos, bool bRedraw)
//   {
//      //::SetScrollRange(get_handle(), nBar, nMinPos, nMaxPos, bRedraw);
//   }

//   void interaction_impl::GetScrollRange(i32 nBar, LPINT pMinPos, LPINT lpMaxPos) const
//
//   {
//      //::GetScrollRange(get_handle(), nBar, pMinPos, lpMaxPos);
//
//   }
//
//   // Turn on/off non-control scrollbars
//   //   for WS_?SCROLL scrollbars - show/hide them
//   //   for control scrollbar - enable/disable them
//   void interaction_impl::EnableScrollBarCtrl(i32 nBar, bool bEnable)
//   {
//      // WS_?SCROLL scrollbar - show or hide
//      ShowScrollBar(nBar, bEnable);
//   }

   /*
      bool interaction_impl::SetScrollInfo(i32 nBar, LPSCROLLINFO pScrollInfo, bool bRedraw)

      {
         ASSERT(pScrollInfo != nullptr);


         oswindow hWnd = get_handle();
         pScrollInfo->cbSize = sizeof(*lpScrollInfo);

         ::SetScrollInfo(hWnd, nBar, pScrollInfo, bRedraw);

         return true;
      }

      bool interaction_impl::GetScrollInfo(i32 nBar, LPSCROLLINFO pScrollInfo, ::u32 nMask)

      {
         UNREFERENCED_PARAMETER(nMask);
         ASSERT(pScrollInfo != nullptr);


         oswindow hWnd = get_handle();
         return ::GetScrollInfo(hWnd, nBar, pScrollInfo) != false;

      }
   */
//   i32 interaction_impl::GetScrollLimit(i32 nBar)
//   {
//      i32 nMin, nMax;
//      GetScrollRange(nBar, &nMin, &nMax);
//      /*      SCROLLINFO info;
//            if (GetScrollInfo(nBar, &info, SIF_PAGE))
//            {
//               nMax -= maximum(info.nPage-1,0);
//            }*/
//      return nMax;
//   }
//
//   void interaction_impl::ScrollWindow(i32 xAmount, i32 yAmount,
//                                       const ::rectangle_i32 & rectangle, const ::rectangle_i32 & lpClipRect)
//
//   {
//      /*      ASSERT(::is_window((oswindow) get_handle()));
//
//            if (is_window_visible() || prectangle != nullptr || lpClipRect != nullptr)
//
//            {
//               // When visible, let oswindows do the scrolling
//               ::ScrollWindow(get_handle(), xAmount, yAmount, prectangle, lpClipRect);
//
//            }
//            else
//            {
//               // oswindows does not perform any scrolling if the interaction_impl is
//               // not visible.  This leaves child windows unscrolled.
//               // To account for this oversight, the child windows are moved
//               // directly instead.
//               oswindow hWndChild = ::GetWindow(get_handle(), GW_CHILD);
//               if (hWndChild != nullptr)
//               {
//                  for (; hWndChild != nullptr;
//                     hWndChild = ::GetNextWindow(hWndChild, GW_HWNDNEXT))
//                  {
//                     ::rectangle_i32 rectangle;
//                     ::get_window_rect(hWndChild, &rectangle);
//                     screen_to_client(&rectangle);
//                     ::set_window_position(hWndChild, nullptr,
//                        rectangle.left+xAmount, rectangle.top+yAmount, 0, 0,
//                        SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER);
//                  }
//               }
//            }
//      */
//   }
//
//
//   void interaction_impl::CalcWindowRect(RECTANGLE_I32 * pClientRect, ::u32 nAdjustType)
//   {
//
//      /*::u32 dwExStyle = GetExStyle();
//      if (nAdjustType == 0)
//         dwExStyle &= ~WS_EX_CLIENTEDGE;
//      ::AdjustWindowRectEx(pClientRect, GetStyle(), false, dwExStyle);*/
//
//   }
//
//   /////////////////////////////////////////////////////////////////////////////
//   // Special keyboard/system command processing
//
//   bool interaction_impl::HandleFloatingSysCommand(::u32 nID, lparam lparam)
//
//   {
//      /*      __pointer(::user::interaction) pParent = GetTopLevelParent();
//            switch (nID & 0xfff0)
//            {
//            case SC_PREVWINDOW:
//            case SC_NEXTWINDOW:
//               if (LOWORD(lparam) == VK_F6 && pParent != nullptr)
//
//               {
//                  pParent->SetFocus();
//                  return true;
//               }
//               break;
//
//            case SC_CLOSE:
//            case SC_KEYMENU:
//               // Check lparam.  If it is 0L, then the ::account::user may have done
//
//               // an Alt+Tab, so just ignore it.  This breaks the ability to
//               // just press the Alt-key and have the first menu selected,
//               // but this is minor compared to what happens in the Alt+Tab
//               // case.
//               if ((nID & 0xfff0) == SC_CLOSE || lparam != 0L)
//
//               {
//                  if (pParent != nullptr)
//                  {
//                     // Sending the above WM_SYSCOMMAND may destroy the cast,
//                     // so we have to be careful about restoring activation
//                     // and focus after sending it.
//                     oswindow hWndSave = get_handle();
//                     oswindow hWndFocus = ::GetFocus();
//                     pParent->SetActiveWindow();
//                     pParent->send_message(WM_SYSCOMMAND, nID, lparam);
//
//
//                     // be very careful here...
//                     if (::is_window(hWndSave))
//                        ::SetActiveWindow(hWndSave);
//                     if (::is_window(hWndFocus))
//                        ::SetFocus(hWndFocus);
//                  }
//               }
//               return true;
//            }
//            return false;*/
//
//      return false;
//   }

//   void interaction_impl::WalkPreTranslateTree(::user::interaction * puiStop, ::message::message * pmessage)
//   {
//      ASSERT(puiStop == nullptr || puiStop->is_window());
//      ASSERT(pmessage != nullptr);
//
//      __pointer(::user::message) pmessage(pmessage);
//      // walk from the target interaction_impl up to the hWndStop interaction_impl checking
//      //  if any interaction_impl wants to translate this message
//
//      for (__pointer(::user::interaction) pinteraction = pmessage->m_puserinteraction; pinteraction != nullptr; pinteraction->get_parent())
//      {
//
//         pinteraction->pre_translate_message(pmessage);
//
//         if(pmessage->m_bRet)
//            return; // trapped by target interaction_impl (eg: accelerators)
//
//         // got to hWndStop interaction_impl without interest
//         if(pinteraction == puiStop)
//            break;
//
//      }
//      // no special processing
//   }
//
//
//   bool interaction_impl::SendChildNotifyLastMsg(LRESULT* pResult)
//   {
//
//      return false;
//
//   }
//
//
//   bool PASCAL interaction_impl::ReflectLastMsg(oswindow hWndChild, LRESULT* pResult)
//   {
//      // get the ::collection::map, and if no ::collection::map, then this message does not need reflection
//      /*      single_lock synchronouslock(afxMutexHwnd(), true);
//            hwnd_map * pMap = afxMapHWND();
//            if (pMap == nullptr)
//               return false;
//
//            // check if in permanent ::collection::map, if it is reflect it (could be OLE control)
//            __pointer(::interaction_impl) pWnd =  (pMap->lookup_permanent(hWndChild)); */
//
//      __s_throw(xtodo());
////      __pointer(::user::interaction) pWnd =  (FromHandlePermanent(hWndChild));
////      ASSERT(pWnd == nullptr || pWnd->get_handle() == hWndChild);
////      if (pWnd == nullptr)
////      {
////         return false;
////      }
////
////      // only OLE controls and permanent windows will get reflected msgs
////      ASSERT(pWnd != nullptr);
////      return pWnd->SendChildNotifyLastMsg(pResult);
//   }
//
//   bool interaction_impl::OnChildNotify(::u32 uMsg, wparam wparam, lparam lparam, LRESULT* pResult)
//
//   {
//
//      return ReflectChildNotify(uMsg, wparam, lparam, pResult);
//
//   }
//
//   bool interaction_impl::ReflectChildNotify(::u32 uMsg, wparam wparam, lparam lparam, LRESULT* pResult)
//
//   {
//      UNREFERENCED_PARAMETER(wparam);
//      // Note: reflected messages are send directly to interaction_impl::OnWndMsg
//      //  and interaction_impl::_001OnCommand for speed and because these messages are not
//      //  routed by normal _001OnCommand routing (they are only dispatched)
//
//      switch (uMsg)
//      {
//      // normal messages (just wparam, lparam through OnWndMsg)
//
//      case e_message_hscroll:
//      case e_message_vscroll:
//      case WM_PARENTNOTIFY:
//      case WM_DRAWITEM:
//      case e_message_measure_item:
//      case WM_DELETEITEM:
//      case WM_VKEYTOITEM:
//      case WM_CHARTOITEM:
//      case WM_COMPAREITEM:
//         // reflect the message through the message ::collection::map as WM_REFLECT_BASE+uMsg
//         //return interaction_impl::OnWndMsg(WM_REFLECT_BASE+uMsg, wparam, lparam, pResult);
//
//         return false;
//
//      // special case for e_message_command
//      case e_message_command:
//      {
//         // reflect the message through the message ::collection::map as OCM_COMMAND
//         /* xxx         i32 nCode = HIWORD(wparam);
//         if (interaction_impl::_001OnCommand(0, MAKELONG(nCode, WM_REFLECT_BASE+e_message_command), nullptr, nullptr))
//         {
//         if (pResult != nullptr)
//         *pResult = 1;
//         return true;
//         } */
//      }
//      break;
//
//      // special case for WM_NOTIFY
//      /*      case WM_NOTIFY:
//               {
//                  // reflect the message through the message ::collection::map as OCM_NOTIFY
//                  NMHDR* pNMHDR = (NMHDR*)lparam;
//
//                  //            i32 nCode = pNMHDR->code;
//                  //            __NOTIFY notify;
//                  //          notify.pResult = pResult;
//                  //        notify.pNMHDR = pNMHDR;
//                  // xxxx         return interaction_impl::_001OnCommand(0, MAKELONG(nCode, WM_REFLECT_BASE+WM_NOTIFY), &notify, nullptr);
//               }
//
//               // other special cases (WM_CTLCOLOR family)*/
//      default:
//         if (uMsg >= WM_CTLCOLORMSGBOX && uMsg <= WM_CTLCOLORSTATIC)
//         {
//            // fill in special struct for compatiblity with 16-bit WM_CTLCOLOR
//            /*__CTLCOLOR ctl;
//            ctl.hDC = (HDC)wparam;
//            ctl.nCtlType = uMsg - WM_CTLCOLORMSGBOX;
//            //ASSERT(ctl.nCtlType >= CTLCOLOR_MSGBOX);
//            ASSERT(ctl.nCtlType <= CTLCOLOR_STATIC);
//
//            // reflect the message through the message ::collection::map as OCM_CTLCOLOR
//            bool bResult = interaction_impl::OnWndMsg(WM_REFLECT_BASE+WM_CTLCOLOR, 0, (LPARAM)&ctl, pResult);
//            if ((HBRUSH)*pResult == nullptr)
//            bResult = false;
//            return bResult;*/
//            return false;
//         }
//         break;
//      }
//
//      return false;   // let the parent handle it
//   }
//
//   void interaction_impl::OnParentNotify(const ::id & id, lparam lparam)
//
//   {
//      if ((LOWORD(message) == e_message_create || LOWORD(message) == e_message_destroy))
//      {
//         if (ReflectLastMsg((oswindow)lparam))
//
//            return;     // eat it
//      }
//      // not handled - do default
////      Default();
//   }
//
//   void interaction_impl::OnSetFocus(::user::interaction *)
//   {
//      bool bHandled;
//
//      bHandled = false;
//      if( !bHandled )
//      {
////         Default();
//      }
//   }
//
//
//   LRESULT interaction_impl::OnActivateTopLevel(wparam wparam, LPARAM)
//   {
//
//      return 0;
//
//   }
//
//
//   void interaction_impl::OnSysColorChange()
//   {
//
//   }
//
//
//   bool gen_GotScrollLines;
//
//
//   void interaction_impl::OnSettingChange(::u32 uFlags, const char * pszSection)
//
//   {
//
//      gen_GotScrollLines = false;
//
//      interaction_impl::OnDisplayChange(0, 0);
//
//   }
//
//
//   LRESULT interaction_impl::OnDisplayChange(WPARAM, LPARAM)
//   {
//
//      if (!(GetStyle() & WS_CHILD))
//      {
//
//         const MESSAGE* pMsg = GetCurrentMessage();
//
//         send_message_to_descendants(pMsg->message, pMsg->wParam, pMsg->lParam, true, true);
//
//      }
//
////      return Default();
//
//      return 0;
//
//   }
//
//
//   LRESULT interaction_impl::OnDragList(WPARAM, lparam lparam)
//
//   {
//
//      throw not_implemented();
////
////      LPDRAGLISTINFO pInfo = (LPDRAGLISTINFO)lparam;
//
////      ASSERT(pInfo != nullptr);
//
////
////      LRESULT lResult;
////      if (ReflectLastMsg(pInfo->hWnd, &lResult))
//
////         return (i32)lResult;    // eat it
////
////      // not handled - do default
////      return (i32)Default();
//   }
//
////
////   void interaction_impl::present()
////   {
////
////      _001UpdateWindow();
////
////   }
////
//
////   void interaction_impl::prodevian_task()
////   {
////
////
////      if (m_pthreadProDevian.is_null())
////      {
////
////         m_pthreadProDevian = fork([&]()
////         {
////
////            ::u32 tickStart;
////
////            while (::task_get_run())
////            {
////
//// auto tickStart = ::millis::now();
////
////               bool bUpdateScreen = false;
////
////               if (!m_puserinteraction->m_bLockWindowUpdate)
////               {
////
////                  if (m_puserinteraction->m_bProDevian ||
////                        m_puserinteraction->has_pending_graphical_update() ||
////                        m_puserinteraction->check_need_layout())
////                  {
////
////                     _001UpdateBuffer();
////
////                     m_puserinteraction->on_after_graphical_update();
////
////                     bUpdateScreen = true;
////
////                  }
////
////               }
////               else
////               {
////
////                  output_debug_string("window is locked for drawing update");
////
////                  fflush(stdout);
////
////               }
////
////               if(bUpdateScreen)
////               {
////
////                  windowing_output_debug_string("\nGoing to _001UpdateScreen");
////
////                  fflush(stdout);
////
////                  _001UpdateScreen();
////
////               }
////
////               ::u32 dwDiff = tickStart.elapsed();
////
////               if (dwDiff < 20)
////               {
////
////                  sleep(20 - dwDiff);
////
////               }
////
////               //sleep(500_ms);
////
////            }
////
////            m_pthreadProDevian.release();
////
////         });
////
////      }
////
////
////   }
//
//
////   void interaction_impl::set_need_redraw()
////   {
////
////      ::user::interaction_impl::set_need_redraw();
////
////   }
//

   void interaction_impl::on_message_create(::message::message * pmessage)
   {

      UNREFERENCED_PARAMETER(pmessage);

//      Default();

//      if(m_puserinteraction->is_message_only_window())
//      {
//
//         TRACE("good : opt out!");
//
//      }
//      else
//      {
//
//         m_pthreadDraw = fork([&]()
//         {
//
//
//         });
//
//      }
//
   }



//   bool CALLBACK interaction_impl::GetAppsEnumWindowsProc(oswindow hwnd, lparam lparam)
//
//   {
//      user::oswindow_array * phwnda = (user::oswindow_array *) lparam;
//
//      phwnda->add(hwnd);
//      return true;
//   }
//
//   void interaction_impl::get_app_wnda(user::oswindow_array & wnda)
//   {
//      __s_throw(not_implemented());
////      EnumWindows(GetAppsEnumWindowsProc, (LPARAM) &wnda);
//   }

//   void interaction_impl::_001OnDeferPaintLayeredWindowBackground(::image * pimage)
//   {
//
//      _001DeferPaintLayeredWindowBackground(pgraphics);
//
//   }



//   class print_window :
//      virtual ::object
//   {
//   public:
//
//
//
//      manual_reset_event m_event;
//      oswindow m_hwnd;
//      HDC m_hdc;
//
//      print_window(::object * pobject, oswindow hwnd, HDC hdc, ::u32 tickTimeout) :
//         ::object(pobject)
//      {
//         m_event.ResetEvent();
//         m_hwnd = hwnd;
//         m_hdc = hdc;
//
//         fork();
//#undef timeout
//
//         if(m_event.wait(millis(tickTimeout)).timeout())
//         {
//            TRACE("print_window::time_out");
//         }
//      }
//
//
//      virtual ::e_status     run() override
//      {
//
//         try
//         {
////            HANDLE hevent = (HANDLE) pprintwindow->m_event.get_os_data();
//            //          throw not_implemented();
//            /*            ::PrintWindow(pprintwindow->m_hwnd, pprintwindow->m_hdc, 0);
//                        ::SetEvent(hevent);*/
//         }
//         catch(...)
//         {
//         }
//         return ::success;
//      }
//   };
//
//   void interaction_impl::_001DeferPaintLayeredWindowBackground(HDC hdc)
//   {
//
//      ::rectangle_i32 rectClient;
//
//      m_puserinteraction->get_client_rect(rectClient);
//
//
//      //pgraphics->FillSolidRect(rectClient, 0x00000000);
//
//      //return;
//      ::rectangle_i32 rectUpdate;
//      m_puserinteraction->get_window_rect(rectUpdate);
////      SetViewportOrgEx(hdc, 0, 0, nullptr);
//      ::rectangle_i32 rectPaint;
//      rectPaint = rectUpdate;
//      m_puserinteraction->screen_to_client(rectPaint);
//      user::oswindow_array wndaApp;
//
//
//      HRGN rgnWindow;
//      HRGN rgnIntersect;
//      HRGN rgnUpdate = nullptr;
//
//      throw not_implemented();
//      /*
//            rgnWindow = CreateRectRgn(0, 0, 0, 0);
//            rgnIntersect = CreateRectRgn(0, 0, 0, 0);
//      */
//      //      i32 iCount = wndaApp.get_count();
//
//      throw not_implemented();
//   }
//
//   void interaction_impl::_001OnProdevianSynch(::message::message * pmessage)
//   {
//      UNREFERENCED_PARAMETER(pmessage);
//   }


   void interaction_impl::_001OnPaint(::message::message * pmessage)
   {

      set_need_redraw();

      //m_puserinteraction->defer_start_prodevian();

   }


   void interaction_impl::_001OnPrint(::message::message * pmessage)
   {

      set_need_redraw();

   }


//   bool interaction_impl::is_window() const
//   {
//
//      if(::is_null(m_pwindow))
//      {
//
//         return false;
//
//      }
//
//      return m_pwindow->is_window();
//
//   }


//   oswindow interaction_impl::get_handle() const
//   {
//
//      return m_oswindow;
//
//   }


//   void interaction_impl::_001OnExitIconic()
//   {
//
//      if(!m_pwindow)
//      {
//
//         return;
//
//      }
//
//
//         m_psystem->windowing_post([this]()
//                          {
//
//                             m_pwindow->exit_iconify();
//
//                          });
//
//
//   }
//
//
//   void interaction_impl::_001OnExitFullScreen()
//   {
//
//      if(!m_pwindow)
//      {
//
//         return;
//
//      }
//
////      auto psession = get_session();
////
////      auto puser = psession->user();
////
////      auto pwindowing = puser->windowing();
////
////      if(pwindowing)
//      {
//
//         m_psystem->windowing_post([this]()
//         {
//
//            m_pwindow->exit_full_screen();
//
//         });
//
//      }
//
//   }
//
//
//   void interaction_impl::_001OnExitZoomed()
//   {
//
//      if(!m_pwindow)
//      {
//
//         return;
//
//      }
//
////      auto psession = get_session();
////
////      auto puser = psession->user();
////
////      auto pwindowing = puser->windowing();
////
////      if(pwindowing)
//      {
//
//         m_psystem->windowing_post([this]()
//         {
//
//            m_pwindow->exit_zoomed();
//
//         });
//
//      }
//
//   }



//   bool interaction_impl::node_is_iconic()
//   {
//
//      if(!::is_window(m_oswindow))
//      {
//
//         return false;
//
//      }
//
//#ifdef LINUX
//
//      return m_puserinteraction->layout().design().display() == ::e_display_iconic;
//
//#else
//
//      if(GetExStyle() & WS_EX_LAYERED)
//      {
//
//         return m_puserinteraction->m_edisplay == ::e_display_iconic;
//
//      }
//      else
//      {
//
//         return ::is_iconic((oswindow) get_handle()) != false;
//
//      }
//
//#endif
//
//   }
//
////
////   iptr interaction_impl::get_window_long_ptr(i32 nIndex) const
////   {
////
////      return get_window_long(nIndex);
////
////   }
////
////
////   iptr interaction_impl::set_window_long_ptr(i32 nIndex, iptr lValue)
////   {
////
////      return set_window_long(nIndex, lValue);
////
////   }
////
//
//
//
//
//   // interaction_impl
//   /* interaction_impl::operator oswindow() const
//   { return this == nullptr ? nullptr : get_handle(); }*/
//   bool interaction_impl::operator==(const ::user::interaction_impl& wnd) const
//   {
//      return wnd.get_handle() ==((interaction_impl *)this)->get_handle();
//   }
//
//   bool interaction_impl::operator!=(const ::user::interaction_impl& wnd) const
//   {
//      return wnd.get_handle() != ((interaction_impl *)this)->get_handle();
//   }
//
//   ::u32 interaction_impl::GetStyle() const
//   {
//
//      return (::u32)get_window_long(GWL_STYLE);
//
//   }
//
//
//   ::u32 interaction_impl::GetExStyle() const
//   {
//
//      return (::u32)get_window_long(GWL_EXSTYLE);
//
//   }


//   bool interaction_impl::ModifyStyle(::u32 dwRemove, ::u32 dwAdd, ::u32 nFlags)
//   {
//
//      set_window_long(GWL_STYLE, (GetStyle() | dwAdd) & ~(dwRemove));
//
//      if(nFlags != 0)
//      {
//
//         //set_window_position(0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOMOVE | nFlags);
//         set_need_redraw();
//
//      }
//
//      return true;
//
//   }
//
//
//   bool interaction_impl::ModifyStyleEx(::u32 dwRemove, ::u32 dwAdd, ::u32 nFlags)
//   {
//
//      set_window_long(GWL_EXSTYLE, (GetExStyle() | dwAdd) & ~(dwRemove));
//
//      if(nFlags != 0)
//      {
//
//         //set_window_position(0, 0, 0, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOMOVE | nFlags);
//         set_need_redraw();
//
//      }
//
//      return true;
//
//   }
//
//
//   ::user::primitive * interaction_impl::set_owner(::user::primitive * pprimitiveOwner)
//   {
//
//      auto puserinteraction = m_puserinteraction;
//
//      if(::is_null(puserinteraction))
//      {
//
//         return nullptr;
//
//      }
//
//      auto puserinteractionOwner = puserinteraction->m_puserinteractionOwner;
//
//      if(::is_null(puserinteractionOwner))
//      {
//
//         return nullptr;
//
//      }
//
//      return puserinteractionOwner;
//
//   }


//   LRESULT interaction_impl::send_message(const ::id & id, wparam wparam, lparam lparam)
//   {
//
//      return ::user::interaction_impl::send_message(id, wparam, lparam);
//
//   }


//   bool interaction_impl::post_message(const ::id & id, wparam wparam, lparam lparam)
//   {
//
////      if(::is_set(m_pwindowthread))
////      {
////
////         return ::user::interaction_impl::post_message(message, wparam, lparam);
////
////      }
////
//      return ::post_message((oswindow) get_handle(), id, wparam, lparam) != false;
//
//   }


//   bool interaction_impl::DragDetect(const ::point_i32 & point) const
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//
//      //return ::DragDetect(get_handle(), point_i32) != false;
//
//   }
//


//   void interaction_impl::set_window_text(const ::string & strText)
//   {
//
//      m_strWindowText = strText;
//
//      //windowing_output_debug_string("\nlinux::interaction_impl::set_window_text");
//
//      //fflush(stdout);
//
////      x11_store_name(m_oswindow, m_strWindowText);
//
//      //windowing_output_debug_string("\nlinux::interaction_impl::set_window_text END");
//
//      //fflush(stdout);
//
//   }


//   strsize interaction_impl::GetWindowText(char * pszString, strsize nMaxCount)

//   {
//
//      ansi_count_copy(pszString, m_strWindowText, nMaxCount);

//
//      return minimum(nMaxCount, m_strWindowText.get_length());
//
//   }

//
//   strsize interaction_impl::GetWindowTextLength()
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//
//      //return ::GetWindowTextLength(get_handle());
//
//   }


   void interaction_impl::SetFont(::write_text::font* pfont, bool bRedraw)
   {

      UNREFERENCED_PARAMETER(bRedraw);

      //ASSERT(::is_window((oswindow) get_handle())); m_pfont = new ::write_text::font(*pfont);

   }


   ::write_text::font* interaction_impl::GetFont()
   {

      //ASSERT(::is_window((oswindow) get_handle()));

      //return m_pfont;
      return nullptr;

   }


//   void interaction_impl::DragAcceptFiles(bool bAccept)
//   {
//
//      throw not_implemented();
//
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::DragAcceptFiles(get_handle(), bAccept);
//
//   }
//
//   /*
//      __pointer(::user::frame_window) interaction_impl::EnsureParentFrame()
//      {
//
//         __pointer(::user::frame_window) pFrameWnd=get_parent_frame();
//
//         ENSURE_VALID(pFrameWnd);
//
//         return pFrameWnd;
//
//      }
//
//
//      ::user::interaction * interaction_impl::EnsureTopLevelParent()
//      {
//
//         __pointer(::user::interaction)pWnd=GetTopLevelParent();
//
//         ENSURE_VALID(pWnd);
//
//         return pWnd;
//
//      }
//
//   */
//
//
////   void interaction_impl::MoveWindow(const ::rectangle_i32 & rectangle, bool bRepaint)
////   {
////
////      MoveWindow(rectangle.left, rectangle.top, rectangle.right - rectangle.left, rectangle.bottom - rectangle.top, bRepaint);
////
////   }
//
//
//   ::u32 interaction_impl::ArrangeIconicWindows()
//   {
//
//      throw not_implemented();
//
////      ASSERT(::is_window((oswindow) get_handle())); return ::ArrangeIconicWindows(get_handle());
//
//   }
//
//
//   i32 interaction_impl::SetWindowRgn(HRGN hRgn, bool bRedraw)
//   {
//
//      UNREFERENCED_PARAMETER(hRgn);
//      UNREFERENCED_PARAMETER(bRedraw);
//
//      //throw not_implemented();
//
////      ASSERT(::is_window((oswindow) get_handle())); return ::SetWindowRgn(get_handle(), hRgn, bRedraw);
//      return 0;
//   }
//
//
//   i32 interaction_impl::GetWindowRgn(HRGN hRgn)
//   {
//
//      throw not_implemented();
//
////      ASSERT(::is_window((oswindow) get_handle()) && hRgn != nullptr); return ::GetWindowRgn(get_handle(), hRgn);
//
//   }
//
//
//   bool interaction_impl::BringWindowToTop()
//   {
//
////      throw not_implemented();
////      return ::BringWindowToTop(get_handle()) != false;
//      return true;
//   }
//
//
//   void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, POINT_I32 * pPoint, ::u32 nCount)
//
//   {
//
//      throw not_implemented();
//
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_handle(), pPoint, nCount);
//
//
//   }
//
//
//   void interaction_impl::MapWindowPoints(::user::interaction * puserinteractionTo, RECTANGLE_I32 * prectangle)
//
//   {
//
//      throw not_implemented();
//
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_handle(), (POINT_I32 *)prectangle, 2);
//
//
//   }


//   ::draw2d::graphics * interaction_impl::GetDC()
//   {
//
//      ::draw2d::graphics_pointer g(e_create);
//
//      windowing_output_debug_string("\nlinux::interaction_impl::GetDC");
//
//      fflush(stdout);
//
//      xdisplay d(m_oswindow->display());
//
//      oswindow oswindow;
//
//      if(get_handle() == nullptr)
//      {
//
////         oswindow = ::get_desktop_window();
//
//      }
//      else
//      {
//
//         oswindow = (::oswindow) get_handle();
//
//      }
//
//      ::rectangle_i32 rectClient;
//
//      //oswindow->get_client_rect(rectClient);
//
//      rectClient.left = 0;
//      rectClient.top = 0;
//      rectClient.right = 500;
//      rectClient.bottom = 500;
////      (dynamic_cast < ::linux::graphics * >(g.m_p))->attach(cairo_create(cairo_xlib_surface_create(oswindow->display(), oswindow->interaction_impl(), oswindow->draw2d(),rectClient.width(), rectClient.height())));
//
//      windowing_output_debug_string("\nlinux::interaction_impl::GetDC END");
//
//      fflush(stdout);
//
//      return g.detach();
//
//   }
//
//
//   ::draw2d::graphics * interaction_impl::GetWindowDC()
//   {
//      ASSERT(::is_window((oswindow) get_handle()));
//      //::draw2d::graphics_pointer g(e_create);
//      //g->attach(::GetWindowDC(get_handle()));
//      //return g.detach();
//      return nullptr;
//   }
//
//   bool interaction_impl::ReleaseDC(::image * pimage)
//   {
//
//      if(pimage->is_null())
//         return false;
//
//      /*      cairo_t * pcairo = (cairo_t *) pgraphics->get_os_data();
//
//            cairo_surface_t * psurface = cairo_get_target(pcairo);
//      	if(pcairo ==  g_cairo)
//      	{
//               printf("123");
//
//      	}
//
//            cairo_destroy(pcairo);
//
//      if(psurface == g_cairosurface)
//      {
//         printf("123");
//      }      cairo_surface_destroy(psurface);*/
//
////      if(((Gdiplus::Graphics *)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle()) == nullptr)
//      //       return false;
//
//      //::ReleaseDC(get_handle(), (dynamic_cast < ::linux::graphics * > (pgraphics))->detach());
//
////      (dynamic_cast<::linux::graphics * >(pgraphics))->m_hdc = nullptr;
//
////      pgraphics->release();
//
//      return true;
//
//   }
//
//   void interaction_impl::UpdateWindow()
//   {
//      //throw not_implemented();
//      //::UpdateWindow(get_handle());
//   }
//
//   void interaction_impl::SetRedraw(bool bRedraw)
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::SendMessage(get_handle(), WM_SETREDRAW, bRedraw, 0);
//   }
//
//   bool interaction_impl::GetUpdateRect(RECTANGLE_I32 * prectangle, bool bErase)
//
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //return ::GetUpdateRect(get_handle(), prectangle, bErase) != false;
//
//   }
//
//   i32 interaction_impl::GetUpdateRgn(draw2d::region * pRgn, bool bErase)
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //return ::GetUpdateRgn(get_handle(), (HRGN)pRgn->get_handle(), bErase);
//   }
//
//   void interaction_impl::Invalidate(bool bErase)
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::InvalidateRect(get_handle(), nullptr, bErase);
//   }
//
//   void interaction_impl::InvalidateRect(const ::rectangle_i32 & rectangle, bool bErase)
//
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::InvalidateRect(get_handle(), prectangle, bErase);
//
//   }
//
//   void interaction_impl::InvalidateRgn(::draw2d::region* pRgn, bool bErase)
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::InvalidateRgn(get_handle(), (HRGN)pRgn->get_handle(), bErase);
//   }
//
//   void interaction_impl::ValidateRect(const ::rectangle_i32 & rectangle)
//
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::ValidateRect(get_handle(), prectangle);
//
//   }
//
//   void interaction_impl::ValidateRgn(::draw2d::region* pRgn)
//   {
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::ValidateRgn(get_handle(), (HRGN)pRgn->get_handle());
//   }


//   bool interaction_impl::_is_window_visible()
//   {
//
//      if(!m_puserinteraction->is_this_visible())
//      {
//
//         return false;
//
//      }
//
//      if(m_puserinteraction->m_puserinteractionParent != nullptr)
//      {
//
//         if(!m_puserinteraction->m_puserinteractionParent->is_window_visible())
//         {
//
//            return false;
//
//         }
//
//      }
//
//      return true;
//
//   }


//   void interaction_impl::ShowOwnedPopups(bool bShow)
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::ShowOwnedPopups(get_handle(), bShow);
//
//   }
//
////   void interaction_impl::send_message_to_descendants(const ::id & id, wparam wparam, lparam lparam, bool bDeep, bool bOnlyPerm)
//
////   {
////      ASSERT(::is_window((oswindow) get_handle()));
////      //interaction_impl::send_message_to_descendants(get_handle(), message, wparam, lparam, bDeep, bOnlyPerm);
//
////
////      // walk through oswindows to avoid creating temporary interaction_impl objects
////      // unless we need to call this function recursively
////      user::interaction * pinteraction = m_puserinteraction->first_child();
////      while(pinteraction != nullptr)
////      {
////         try
////         {
////            pinteraction->send_message(message, wparam, lparam);
//
////         }
////         catch(...)
////         {
////         }
////         if (bDeep)
////         {
////            // send to child windows after parent
////            try
////            {
////               pinteraction->send_message_to_descendants(message, wparam, lparam, bDeep, bOnlyPerm);
//
////            }
////            catch(...)
////            {
////            }
////         }
////         try
////         {
////            pinteraction = pinteraction->next_sibling();
////         }
////         catch(...)
////         {
////            break;
////         }
////      }
////   }
////
//
//   ::draw2d::graphics * interaction_impl::GetDCEx(::draw2d::region * prgnClip, ::u32 flags)
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::draw2d::graphics_pointer g(this);
//      //g->attach(::GetDCEx(get_handle(), (HRGN)prgnClip->get_handle(), flags));
//      //return g.detach();
//
//   }
//
//   bool interaction_impl::LockWindowUpdate()
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //return ::LockWindowUpdate(get_handle()) != false;
//
//   }
//
//   void interaction_impl::UnlockWindowUpdate()
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //::LockWindowUpdate(nullptr);
//
//   }
//

//   bool interaction_impl::RedrawWindow(const ::rectangle_i32& rectUpdate, ::draw2d::region * prgnUpdate, ::u32 flags)
//   {
//
////      ASSERT(::is_window((oswindow) get_handle()));
//
//      if(flags & RDW_UPDATENOW)
//      {
//
//         _001UpdateWindow();
//
//      }
//      else
//      {
//
//         m_puserinteraction->m_bRedraw = true;
//
//      }
//
//      return true;
//
//   }

   /*
      bool interaction_impl::EnableScrollBar(i32 nSBFlags, ::u32 nArrowFlags)
      {

         ASSERT(::is_window((oswindow) get_handle()));

         return ::EnableScrollBar(get_handle(), nSBFlags, nArrowFlags) != false;

      }
   */

//   bool interaction_impl::DrawAnimatedRects(i32 idAni, const LPRECTprcFrom, const LPRECTlprcTo)
//
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //return ::DrawAnimatedRects(get_handle(), idAni, prcFrom, lprcTo) != false;
//
//
//   }


//   bool interaction_impl::DrawCaption(::draw2d::graphics_pointer & pgraphics, const rectangle_i32 & prc, ::u32 uFlags)
//
//   {
//
//      throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //return ::DrawCaption(get_handle(), (HDC)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle(), prc, uFlags) != false;
//
//
//   }
//
//
//   bool interaction_impl::SetTimer(uptr uEvent, ::u32 nElapse, PFN_TIMER pfnTimer)
//   {
//
//      return ::user::interaction_impl::SetTimer(uEvent, nElapse, pfnTimer);
//
//
////        UNREFERENCED_PARAMETER(pfnTimer);
//
////
////        m_puserinteraction->get_application()->set_timer(m_puserinteraction, uEvent, nElapse);
////
////        return uEvent;
//
//      //throw not_implemented();
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //return ::SetTimer(get_handle(), uEvent, nElapse, pfnTimer);
//
//
//   }
//
//
//   bool interaction_impl::KillTimer(uptr uEvent)
//   {
//
//      return ::user::interaction_impl::KillTimer(uEvent);
//
////       m_puserinteraction->get_application()->unset_timer(m_puserinteraction, uEvent);
//
//      //     return true;
//
//      //return ::user::int
//
//      //ASSERT(::is_window((oswindow) get_handle()));
//      //return ::KillTimer(get_handle(), uEvent)  != false;
//
//   }


   bool interaction_impl::IsWindowEnabled()
   {

      return m_bEnabled;

   }


   bool interaction_impl::EnableWindow(bool bEnable)
   {

      return m_bEnabled = bEnable;

   }


//   ::user::interaction * interaction_impl::GetActiveWindow()
//   {
//
//      oswindow oswindow = nullptr;
//
//      x11_sync([&]()
//      {
//
//         oswindow = ::get_active_window();
//
//      });
//
//      if(oswindow == nullptr)
//      {
//
//         return nullptr;
//
//      }
//
//      ::user::interaction_impl * pimpl = ::linux::interaction_impl::from_handle(oswindow);
//
//      if(pimpl == nullptr)
//      {
//
//         return nullptr;
//
//      }
//
//      return pimpl->m_puserinteraction;
//
//   }


//   ::user::interaction * interaction_impl::SetActiveWindow()
//   {
//
//      return nullptr;
//
//
////      ::user::interaction_impl * pimpl = ::linux::interaction_impl::from_handle(::set_active_window(get_handle()));
//
//  //    if(pimpl == nullptr)
//    //  {
//
//      //   return nullptr;
//
//      //}
//
//      //return pimpl->m_puserinteraction;
//
//   }


//   ::user::interaction * interaction_impl::get_keyboard_focus()
//   {
//
//      return __user_interaction(m_pprimitiveFocus);
//
//   }


//   ::e_status interaction_impl::set_keyboard_focus()
//   {
//
//      auto estatus = ::user::interaction_impl::set_keyboard_focus();
//
//      return estatus;
////
////
////      oswindow w = ::set_focus(get_handle());
////
////      if(w  == nullptr)
////      {
////
////         return false;
////
////      }
////
////      return true;
//
//   }


//   ::user::interaction * interaction_impl::get_desktop_window()
//   {
//      /*
//            return ::linux::interaction_impl::from_handle(::get_desktop_window());
//      */
//      return nullptr;
//   }


//   // Helper for radio buttons
//   i32 interaction_impl::GetCheckedRadioButton(i32 nIDFirstButton, i32 nIDLastButton)
//   {
//      for (i32 nID = nIDFirstButton; nID <= nIDLastButton; nID++)
//      {
//         if (IsDlgButtonChecked(nID))
//            return nID; // id that matched
//      }
//      return 0; // invalid ID
//   }
//
//   void interaction_impl::CheckDlgButton(i32 nIDButton, ::u32 nCheck)
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::CheckDlgButton(get_handle(), nIDButton, nCheck);
//
//   }
//
//   void interaction_impl::CheckRadioButton(i32 nIDFirstButton, i32 nIDLastButton, i32 nIDCheckButton)
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::CheckRadioButton(get_handle(), nIDFirstButton, nIDLastButton, nIDCheckButton);
//
//   }
//
//   i32 interaction_impl::DlgDirList(char * pPathSpec, i32 nIDListBox, i32 nIDStaticPath, ::u32 nFileType)
//
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::DlgDirList(get_handle(), pPathSpec, nIDListBox, nIDStaticPath, nFileType);
//
//
//   }
//
//   i32 interaction_impl::DlgDirListComboBox(char * pPathSpec, i32 nIDComboBox, i32 nIDStaticPath, ::u32 nFileType)
//
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::DlgDirListComboBox(get_handle(), pPathSpec, nIDComboBox, nIDStaticPath, nFileType);
//
//
//   }
//
//   bool interaction_impl::DlgDirSelect(char * pString, i32 nSize, i32 nIDListBox)
//
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::DlgDirSelectEx(get_handle(), pString, nSize, nIDListBox) != false;
//
//
//   }
//
//   bool interaction_impl::DlgDirSelectComboBox(char * pString, i32 nSize, i32 nIDComboBox)
//
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::DlgDirSelectComboBoxEx(get_handle(), pString, nSize, nIDComboBox) != false;
//
//
//   }
//
//   /*
//      void interaction_impl::GetDlgItem(id id, oswindow* phWnd) const
//      {
//
//         ASSERT(::is_window((oswindow) get_handle()));
//         ASSERT(phWnd != nullptr);
//         *phWnd = ::GetDlgItem(get_handle(), (i32) id);
//
//      }
//   */
//
//   /*
//      ::u32 interaction_impl::GetDlgItemInt(i32 nID, int_bool * pTrans, bool bSigned) const
//
//      {
//
//         ASSERT(::is_window((oswindow) get_handle()));
//
//         return ::GetDlgItemInt(get_handle(), nID, pTrans, bSigned);
//
//
//      }
//   */
//
////   i32 interaction_impl::GetDlgItemText(i32 nID, char * pStr, i32 nMaxCount) const
//
////   {
////
////      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle())); return ::GetDlgItemText(get_handle(), nID, pStr, nMaxCount);}
//
//
//   ::user::interaction * interaction_impl::GetNextDlgGroupItem(::user::interaction * pWndCtl, bool bPrevious) const
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::linux::interaction_impl::from_handle(::GetNextDlgGroupItem(get_handle(), (oswindow) pWndCtl->get_handle(), bPrevious));
//
//   }
//
//   ::user::interaction * interaction_impl::GetNextDlgTabItem(::user::interaction * pWndCtl, bool bPrevious) const
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::linux::interaction_impl::from_handle(::GetNextDlgTabItem(get_handle(), (oswindow) pWndCtl->get_handle(), bPrevious));
//
//   }
//
//   ::u32 interaction_impl::IsDlgButtonChecked(i32 nIDButton) const
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::IsDlgButtonChecked(get_handle(), nIDButton);
//
//   }
//
//   LPARAM interaction_impl::SendDlgItemMessage(i32 nID, const ::id & id, wparam wparam, lparam lparam)
//
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::SendDlgItemMessage(get_handle(), nID, message, wparam, lparam);
//
//
//   }
//
//   void interaction_impl::SetDlgItemInt(i32 nID, ::u32 nValue, bool bSigned)
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::SetDlgItemInt(get_handle(), nID, nValue, bSigned);
//
//   }
//
//   void interaction_impl::SetDlgItemText(i32 nID, const char * pszString)
//
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::SetDlgItemText(get_handle(), nID, pszString);
//
//
//   }
//
//   i32 interaction_impl::ScrollWindowEx(i32 dx, i32 dy, const rectangle_i32 & pRectScroll, const rectangle_i32 & lpRectClip, ::draw2d::region * prgnUpdate, RECTANGLE_I32 * lpRectUpdate, ::u32 flags)
//
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::ScrollWindowEx(get_handle(), dx, dy, pRectScroll, lpRectClip, (HRGN)prgnUpdate->get_handle(), lpRectUpdate, flags);
//
//
//   }
//
//   void interaction_impl::ShowScrollBar(::u32 nBar, bool bShow)
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::ShowScrollBar(get_handle(), nBar, bShow);
//
//   }
//
//   ::user::interaction * interaction_impl::ChildWindowFromPoint(const ::point_i32 & point)
//   {
//
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::linux::interaction_impl::from_handle(::ChildWindowFromPoint(get_handle(), point_i32));
//
//   }
//
//   ::user::interaction * interaction_impl::ChildWindowFromPoint(const ::point_i32 & point, ::u32 nFlags)
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::linux::interaction_impl::from_handle(::ChildWindowFromPointEx(get_handle(), point, nFlags));
//
//   }
//
//
//
//
//
//
//   ::user::interaction * interaction_impl::GetTopWindow() const
//   {
//
//      if(m_puserinteraction->m_uiptraChild.get_size() <= 0)
//         return nullptr;
//
//      return m_puserinteraction->m_uiptraChild[0];
//      //  throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::linux::interaction_impl::from_handle(::GetTopWindow(get_handle()));
//
//   }
//
//   ::user::interaction * interaction_impl::GetWindow(::u32 nCmd)
//   {
//
//      ASSERT(::is_window((oswindow) get_handle()));
////      return ::linux::interaction_impl::from_handle(::GetWindow(get_handle(), nCmd));
//      return nullptr;
//
//   }
//
//   ::user::interaction * interaction_impl::GetLastActivePopup()
//   {
//
//
//      __throw(xtodo);
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::linux::interaction_impl::from_handle(::GetLastActivePopup(get_handle()));
//
//   }
//

//   ::user::interaction * interaction_impl::SetParent(::user::interaction * pWndNewParent)
//   {
//
//      ASSERT(::is_window((oswindow) get_handle()));
//
//      return ::linux::interaction_impl::from_handle(::SetParent(get_handle(), (oswindow) pWndNewParent->get_handle()))->m_puserinteraction;
//
//   }
//
//
//   ::user::interaction * PASCAL interaction_impl::oswindowFromPoint(const ::point_i32 & point)
//   {
//
//      __s_throw(not_implemented());
////      return ::linux::interaction_impl::from_handle(::oswindowFromPoint(point));
//
//   }
//
//
//   bool interaction_impl::FlashWindow(bool bInvert)
//   {
//
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::FlashWindow(get_handle(), bInvert) != false;
//
//   }
//
//   bool interaction_impl::ChangeClipboardChain(oswindow hWndNext)
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::ChangeClipboardChain(get_handle(), hWndNext) != false;
//
//   }
//
//   oswindow interaction_impl::SetClipboardViewer()
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::SetClipboardViewer(get_handle());
//
//   }
//
//   bool interaction_impl::OpenClipboard()
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::OpenClipboard(get_handle()) != false;
//
//   }
//
//
//   ::user::interaction * PASCAL interaction_impl::GetOpenClipboardWindow()
//   {
//
//      __s_throw(not_implemented());
////      return ::linux::interaction_impl::from_handle(::GetOpenClipboardWindow());
//
//   }
//
//
//   ::user::interaction * PASCAL interaction_impl::GetClipboardOwner()
//   {
//
//      __s_throw(not_implemented());
////      return ::linux::interaction_impl::from_handle(::GetClipboardOwner());
//
//   }
//
//
//   ::user::interaction * PASCAL interaction_impl::GetClipboardViewer()
//   {
//
//      __s_throw(not_implemented());
////      return ::linux::interaction_impl::from_handle(::GetClipboardViewer());
//
//   }
//
//
//
//
//
//   point_i32 PASCAL interaction_impl::GetCaretPos()
//   {
//
//      __s_throw(not_implemented());
////      const ::point_i32 & point;
////      ::GetcaretPos((POINT_I32 *)&point); return point;
//
//   }
//
//
//   void PASCAL interaction_impl::SetCaretPos(const ::point_i32 & point)
//   {
//
//      __s_throw(not_implemented());
////      ::SetcaretPos(point.x, point.y);
//
//   }
//
//
//   void interaction_impl::HideCaret()
//   {
//
//      throw not_implemented();
////      ::Hidecaret(get_handle());
//
//   }
//
//   void interaction_impl::ShowCaret()
//   {
//
//      throw not_implemented();
////    ::Showcaret(get_handle());
//   }
//


//   bool interaction_impl::SetForegroundWindow()
//   {
//
//      return ::set_foreground_window(get_handle()) != false;
//
//   }

//
//
//   ::user::interaction * PASCAL interaction_impl::GetForegroundWindow()
//   {
//
//      return nullptr;
//
//      __s_throw(not_implemented());
////      return ::linux::interaction_impl::from_handle(::GetForegroundWindow());
//
//   }
//
//
//   bool interaction_impl::SendNotifyMessage(const ::id & id, wparam wparam, lparam lparam)
//
//   {
//
//      throw not_implemented();
////      return ::SendNotifyMessage(get_handle(), message, wparam, lparam) != false;
//
//
//   }
//
//   void interaction_impl::Print(::draw2d::graphics_pointer & pgraphics, ::u32 dwFlags) const
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      const_cast < interaction_impl * > (this)->send_message(WM_PRINT, (WPARAM)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle(), dwFlags);
//
//   }
//
//   void interaction_impl::PrintClient(::draw2d::graphics_pointer & pgraphics, ::u32 dwFlags) const
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      const_cast < interaction_impl * > (this)->send_message(WM_PRINTCLIENT, (WPARAM)(dynamic_cast<::linux::graphics * >(pgraphics))->get_handle(), dwFlags);
//
//   }
//
//   bool interaction_impl::SetWindowContextHelpId(::u32 dwContextHelpId)
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::SetWindowContextHelpId(get_handle(), dwContextHelpId) != false;
//
//   }
//
//   ::u32 interaction_impl::GetWindowContextHelpId() const
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::GetWindowContextHelpId(get_handle());
//
//   }
//
//
//   // Default message ::collection::map implementations
//   void interaction_impl::OnActivateApp(bool, ::u32)
//   {
//   //Default();
//   }
//   void interaction_impl::OnActivate(::u32, ::user::interaction *, bool)
//   {
//   //Default();
//   }
//   void interaction_impl::OncancelMode()
//   {
//   //Default();
//   }
//   void interaction_impl::OnChildActivate()
//   {
//   //Default();
//   }
//   void interaction_impl::OnClose()
//   {
//   //Default();
//   }
//   void interaction_impl::OnContextMenu(::user::interaction *, point_i32)
//   {
//   //Default();
//   }
//
//   bool interaction_impl::OnCopyData(::user::interaction *, COPYDATASTRUCT*)
//   {
//   //Default();
//   return false;
//   }
//
//   void interaction_impl::OnEnable(bool)
//   {
//   //Default();
//   }
//   void interaction_impl::OnEndSession(bool)
//   {
//   //Default();
//   }
//
//   bool interaction_impl::OnEraseBkgnd(::draw2d::graphics *)
//   {
//   //Default();
//   }
//
//   void interaction_impl::OnGetMinMaxInfo(MINMAXINFO*)
//   {
//   //Default();
//   }
//   void interaction_impl::OnIconEraseBkgnd(::draw2d::graphics *)
//   {
//   //Default();
//   }
//   void interaction_impl::OnKillFocus(::user::interaction *)
//   {
//   //Default();
//   }
//   LRESULT interaction_impl::OnMenuChar(::u32, ::u32, ::user::menu*)
//   {
//   //Default();
//   }
//   void interaction_impl::OnMenuSelect(::u32, ::u32, HMENU)
//   {
//   //Default();
//   }
//   void interaction_impl::OnMove(i32, i32)
//   {
//   //Default();
//   }
//
//   bool interaction_impl::OnQueryEndSession()
//   {
//   //return Default();
//   return true;
//   }
//
//   bool interaction_impl::OnQueryNewPalette()
//   {
//
//      //return Default() != false;
//      return true;
//
//   }
//
//   bool interaction_impl::OnQueryOpen()
//   {
//
//      //return Default() != false;
//      return true;
//
//   }
//


   void interaction_impl::_001OnSetCursor(::message::message * pmessage)
   {

//      __pointer(::user::message) pmessage(pmessage);
//
//      auto psession = get_session();
//
//      if(psession->get_cursor() != nullptr
//            && psession->get_cursor()->m_ecursor != cursor_system)
//      {
//
//         throw not_implemented();
////         ::SetCursor(nullptr);
//      }
//      pmessage->m_lresult  = 1;
//      pmessage->m_bRet = true;
//      //(bool)Default();
   }


//   void interaction_impl::OnShowWindow(bool, ::u32)
//   {
//   //Default();
//   }
//   void interaction_impl::OnSize(::u32, i32, i32)
//   {
//   //Default();
//   }
//   void interaction_impl::OnTcard(::u32, ::u32)
//   {
//   //Default();
//   }
//   void interaction_impl::OnWindowPosChanging(WINDOWPOS*)
//   {
//   //Default();
//   }
//   void interaction_impl::OnWindowPosChanged(WINDOWPOS*)
//   {
//   //Default();
//   }
//   void interaction_impl::OnDropFiles(HDROP)
//   {
//   //Default();
//   }
//   void interaction_impl::OnPaletteIsChanging(::user::interaction *)
//   {
//   //Default();
//   }
//
//   bool interaction_impl::OnNcActivate(bool)
//   {
//
//      //return Default() != false;
//      return true;
//
//   }
//
//   void interaction_impl::OnNcCalcSize(bool, NCCALCSIZE_PARAMS*)
//   {
//   //Default();
//   }
//
//   bool interaction_impl::OnNcCreate(::user::system *)
//   {
//
////      return Default() != false;
//return true;
//
//   }

//   LRESULT interaction_impl::OnNcHitTest(point)
//   { return Default(); }
//   void interaction_impl::OnNcLButtonDblClk(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcLButtonDown(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcLButtonUp(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcMButtonDblClk(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcMButtonDown(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcMButtonUp(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcMouseMove(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcPaint()
//   { Default(); }
//   void interaction_impl::OnNcRButtonDblClk(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcRButtonDown(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnNcRButtonUp(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnSysChar(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnSysCommand(::u32, LPARAM)
//   { Default(); }
//   void interaction_impl::OnSysDeadChar(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnSysKeyDown(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnSysKeyUp(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnCompacting(::u32)
//   { Default(); }
//   void interaction_impl::OnFontChange()
//   { Default(); }
//   void interaction_impl::OnPaletteChanged(::user::interaction *)
//   { Default(); }
//   void interaction_impl::OnSpoolerStatus(::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnTimeChange()
//   { Default(); }
//   void interaction_impl::OnChar(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnDeadChar(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnKeyDown(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnKeyUp(::u32, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnLButtonDblClk(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnLButtonDown(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnLButtonUp(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnMButtonDblClk(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnMButtonDown(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnMButtonUp(::u32, point_i32)
//   { Default(); }
//   i32 interaction_impl::OnMouseActivate(::user::interaction *, ::u32, ::u32)
//   { return (i32)Default(); }
//   void interaction_impl::OnMouseMove(::u32, point_i32)
//   { Default(); }

//   bool interaction_impl::OnMouseWheel(::u32, short, point_i32)
//   {
//
//      return Default() != false;
//
//   }
//
//   LRESULT interaction_impl::OnRegisteredMouseWheel(WPARAM, LPARAM)
//   { return Default(); }
//   void interaction_impl::OnRButtonDblClk(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnRButtonDown(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnRButtonUp(::u32, point_i32)
//   { Default(); }
//   void interaction_impl::OnTimer(uptr)
//   { Default(); }
//   void interaction_impl::OnInitMenu(::user::menu*)
//   { Default(); }
//   void interaction_impl::OnInitMenuPopup(::user::menu*, ::u32, bool)
//   { Default(); }
//   void interaction_impl::OnAskCbFormatName(::u32 nMaxCount, char * lpszName)
//   {
//      (nMaxCount);
//      if(nMaxCount>0)
//      {
//         /* defwindow proc should do this for us, but to be safe, we'll do it here too */
//         lpszName[0]='\0';
//      }
//      Default();
//   }
//   void interaction_impl::OnChangeCbChain(oswindow, oswindow)
//   { Default(); }
//   void interaction_impl::OnDestroyClipboard()
//   { Default(); }
//   void interaction_impl::OnDrawClipboard()
//   { Default(); }
//   void interaction_impl::OnHScrollClipboard(::user::interaction *, ::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnPaintClipboard(::user::interaction *, HGLOBAL)
//   { Default(); }
//   void interaction_impl::OnRenderAllFormats()
//   { Default(); }
//   void interaction_impl::OnRenderFormat(::u32)
//   { Default(); }
//   void interaction_impl::OnSizeClipboard(::user::interaction *, HGLOBAL)
//   { Default(); }
//   void interaction_impl::OnVScrollClipboard(::user::interaction *, ::u32, ::u32)
//   { Default(); }
//   ::u32 interaction_impl::OnGetDlgCode()
//   { return (::u32)Default(); }
//   void interaction_impl::OnMDIActivate(bool, ::user::interaction *, ::user::interaction *)
//   { Default(); }
//   void interaction_impl::OnEnterMenuLoop(bool)
//   { Default(); }
//   void interaction_impl::OnExitMenuLoop(bool)
//   { Default(); }
//   // Win4 support
////   void interaction_impl::OnStyleChanged(i32, LPSTYLESTRUCT)
////   { Default(); }
////   void interaction_impl::OnStyleChanging(i32, LPSTYLESTRUCT)
////   { Default(); }
//   void interaction_impl::OnSizing(::u32, RECTANGLE_I32 *)
//   { Default(); }
//   void interaction_impl::OnMoving(::u32, RECTANGLE_I32 *)
//   { Default(); }
//   void interaction_impl::OncaptureChanged(::user::interaction *)
//   { Default(); }
//
//   bool interaction_impl::OnDeviceChange(::u32, dword_ptr)
//   {
//
//      return Default() != false;
//
//   }
//
//   void interaction_impl::OnWinIniChange(const char *)
//   { Default(); }
//   void interaction_impl::OnChangeUIState(::u32, ::u32)
//   { Default(); }
//   void interaction_impl::OnUpdateUIState(::u32, ::u32)
//   { Default(); }
//
//   ::u32 interaction_impl::OnQueryUIState()
//   {
//
//      return (::u32)Default();
//
//   }

   // interaction_impl dialog data support
   //    void interaction_impl::DoDataExchange(CDataExchange*)
   //   { } // default does nothing

   // interaction_impl modality support

//   void interaction_impl::BeginModalState()
//   {
//
//      __throw(xtodo);
//
//      //::EnableWindow(get_handle(), false);
//
//   }
//
//   void interaction_impl::EndModalState()
//   {
//
//      __throw(xtodo);
//
//      //::EnableWindow(get_handle(), true);
//
//   }
//
//   // frame_window
//   /*    void frame_window::DelayUpdateFrameTitle()
//   { m_nIdleFlags |= idleTitle; }
//   void frame_window::DelayRecalcLayout(bool bNotify)
//   { m_nIdleFlags |= (idleLayout | (bNotify ? idleNotify : 0)); };
//   bool frame_window::InModalState() const
//   { return m_cModalStack != 0; }
//   void frame_window::set_title(const char * pszTitle)
//
//   { m_strTitle = pszTitle; }
//
//   string frame_window::get_title() const
//   { return m_strTitle; }
//   */
//
//
//
//   void interaction_impl::CloseWindow()
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      ::CloseWindow(get_handle());
//
//   }
//
//   bool interaction_impl::OpenIcon()
//   {
//
//      throw not_implemented();
////      ASSERT(::is_window((oswindow) get_handle()));
////      return ::OpenIcon(get_handle()) != false;
//
//   }
//
//   ////////////////////////////////////////////////////////////////////////////
//   // UI related ::user::interaction_impl functions
//
//   oswindow PASCAL interaction_impl::GetSafeOwner_(oswindow hParent, oswindow* pWndTop)
//   {
//      // get ::user::interaction_impl to start with
//      oswindow hWnd = hParent;
//      if (hWnd == nullptr)
//      {
//         /* trans      __pointer(frame_window) pFrame = channel::GetRoutingFrame_();
//         if (pFrame != nullptr)
//         hWnd = pFrame->get_handle();
//         else
//         hWnd = ::aura::get_system()->GetMainWnd()->get_handle();*/
//      }
//
//      // a popup ::user::interaction_impl cannot be owned by a child ::user::interaction_impl
//      while (hWnd != nullptr && (::GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD))
//         hWnd = ::get_parent(hWnd);
//
//      // determine toplevel ::user::interaction_impl to disable as well
//      oswindow hWndTop = hWnd, hWndTemp = hWnd;
//      for (;;)
//      {
//         if (hWndTemp == nullptr)
//            break;
//         else
//            hWndTop = hWndTemp;
//         hWndTemp = ::get_parent(hWndTop);
//      }
//
//      __s_throw(xtodo());
//      // get last active popup of first non-child that was found
//      //    if (hParent == nullptr && hWnd != nullptr)
//      //       hWnd = ::GetLastActivePopup(hWnd);
//
//      // disable and store top level parent ::user::interaction_impl if specified
//      if (pWndTop != nullptr)
//      {
//         /*         if (hWndTop != nullptr && ::IsWindowEnabled(hWndTop) && hWndTop != hWnd)
//                  {
//                     *pWndTop = hWndTop;
//                     ::EnableWindow(hWndTop, false);
//                  }
//                  else
//                     *pWndTop = nullptr;*/
//      }
//
//      return hWnd;    // return the owner as oswindow
//   }
//
//   void interaction_impl::on_delete(::object * pinteraction)
//   {
//      UNREFERENCED_PARAMETER(pinteraction);
//   }
//
//
//
//
////   void interaction_impl::_001OnEraseBkgnd(::message::message * pmessage)
////   {
////      __pointer(::message::erase_bkgnd) perasebkgnd(pmessage);
////      perasebkgnd->m_bRet = true;
////      perasebkgnd->set_result(true);
////   }
//
//
//   void interaction_impl::_001BaseWndInterfaceMap()
//   {
//
//      ::user::interaction_impl::_001BaseWndInterfaceMap();
//
//   }
//
//
//   void interaction_impl::_001OnTriggerMouseInside()
//   {
//

////      m_bMouseHover = true;
//
//   }


   void interaction_impl::set_origin(::draw2d::graphics_pointer & pgraphics)
   {

      pgraphics->set_origin(::point_i32());

   }


//   void interaction_impl::window_show_change_visibility(::e_display edisplay, ::e_activation eactivation)
//   {
//
//      __keep_flag_on(m_puserinteraction->layout().m_eflag, ::user::interaction_layout::flag_show_window);
//
//      //auto edisplay = m_puserinteraction->layout().design().display();
//
//      //auto eactivation = m_puserinteraction->layout().design().activation();
//
//      //if(eactivation &)
////      {
////
////         wm_add_erase_state(m_oswindow, net_wm_state_hidden, false);
////
////      }
////
//
//      m_pwindow->show_window(edisplay, eactivation);
//
////      if (edisplay == e_display_full_screen)
////      {
////
////         if(m_puserinteraction->m_bWorkspaceFullScreen)
////         {
////
////            ::show_window(m_oswindow, e_display_zoomed);
////
////         }
////         else
////         {
////
////            m_oswindow->full_screen();
////
////         }
////
////      }
////      else
////      {
////
////         ::user::interaction_impl::window_show_change_visibility(edisplay, eactivation);
////
////      }
//
//   }


//   ::user::interaction * interaction_impl::GetNextWindow(::u32 nFlag)
//   {
//
//      if(nFlag == GW_HWNDNEXT)
//      {
//
//         return get_next(true, nullptr);
//
//      }
//      else
//      {
//
//         __throw(error_interface_only);
//
//      }
//
//   }
//
//
//   ::user::interaction * interaction_impl::get_next(bool bIgnoreChildren,i32 * piLevel)
//   {
//
//      return  m_puserinteraction->get_next(bIgnoreChildren, piLevel);
//
//   }
//

//   void interaction_impl::show_task(bool bShow)
//   {
//
//      wm_toolwindow(get_handle(), bShow ? 0: 1);
//
//   }


//   bool interaction_impl::has_keyboard_focus() const
//   {
//
//      if(!m_pwindow)
//      {
//
//         return false;
//
//      }
//
//      return m_pwindow->has_keyboard_focus();
//
//   }
//
//
//   bool interaction_impl::is_active_window() const
//   {
//
//      if(!::is_window(m_oswindow))
//      {
//
//         return false;
//
//      }

//      x11_sync([this]()
//      {
//
//         m_puserinteraction->m_ewindowflag.set(::window_flag_active, m_oswindow == ::get_active_window());
//
//      });
//
//      return m_puserinteraction->m_ewindowflag & ::e_window_flag_active;
//
//   }


//   void interaction_impl::prodevian_update_screen()
//   {
//
//      if(!m_puserinteraction)
//      {
//
//         throw exception(error_null_pointer);
//
//      }
//
//      if(m_puserinteraction->m_ewindowflag & e_window_flag_embedded_prodevian)
//      {
//
//         _001UpdateScreen();
//
//      }
//      else
//      {
//
//         //x11_async_runnable(__routine([&]()
//         //{
//
//            //synchronous_lock synchronouslock(x11_mutex());
//
//            _001UpdateScreen();
//
//         //}));
//
//      }
//
//      //return true;
//
//   }


   void interaction_impl::non_top_most_upper_window_rects(::rectangle_i32_array& recta)
   {

//      auto psession = get_session();
//
//      auto puser = psession->user();
//
//      auto pwindowing = puser->windowing();
//
//      pwindowing->upper_window_rects(get_oswindow(), recta);

   }


//   ::e_status interaction_impl::set_tool_window(bool bSet)
//   {
//
//      wm_toolwindow(m_oswindow, bSet);
//
//      return ::success;
//
//   }


   void interaction_impl::show_software_keyboard(::user::element* pprimitive)
   {


   }


   void interaction_impl::hide_software_keyboard(::user::element * pprimitive)
   {


   }


} // namespace aura_freebsd



