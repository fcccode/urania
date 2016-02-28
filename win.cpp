/**************************************************************************
 *
 *  win.cpp
 *  by oZ/acy
 *  (c) 2002-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  ����
 *    2016.2.28  �C��
 *************************************************************************/

#include <cstdlib>
#include <algorithm>
#include <functional>
#include <windowsx.h>
#include "win.h"

/*====================================
 *  WindowFactory::factory__()
 *  �E�B���h�E�����̉�����
 *==================================*/
urania::Window*
urania::WindowFactory::factory__(
  urania::WMHandler* mh, int menu, urania::BasicWindow* par, int cid)
{
  Window* res = new Window;

  // �n���h���}�l�[�W����D&D�̐ݒ�
  res->msgHandler_ = mh;
  res->dad_ = drag_and_drop;

  // BasicWindow�L�q�\���̂̍\�z
  BasicWindow::D0_ de0;

  de0.title = title;
  de0.x = x;
  de0.y = y;
  de0.w = w;
  de0.h = h;
  de0.icon = icon;
  de0.cursor = cursor;
  de0.bkcolor = bkcolor;
  de0.can_resize = resizeable;
  de0.v_scrollbar = v_scrollbar;
  de0.h_scrollbar = h_scrollbar;
  de0.minbox = minbox;
  de0.maxbox = maxbox;
  de0.popup = popup;
  de0.border_only = border_only;

  // �e���̓I�[�i�[Window��Menu���͎qWindowID�̐ݒ�
  if (par)
    de0.pwnd = res->getHW__(par);

  if (par && cid)
    de0.hm = (HMENU)cid;
  else if (menu)
    de0.hm = res->linkMenu__(Menu::create(menu));

  // ���ۂɐ���
  res->createWindow0__(de0);

  return res;
}




/*================================================
 *  Window::wproc__()
 *  �eWindow�̃��b�Z�[�W�����v���V�[�W��
 *==============================================*/
LRESULT urania::Window::wproc__(UINT msg, WPARAM wp, LPARAM lp)
{
  if (msgHandler_)
  {
    urania::WndMessage m;
    m.window = this;
    m.id = msg;
    m.wparam = wp;
    m.lparam = lp;
    return (*msgHandler_)(&m);
  }
  else
    return defHandler(msg, wp, lp);
}



/*==================================================
 *  Window::init__()
 *  ���b�Z�[�W�|���n�̏�����
 *================================================*/
void urania::Window::init__(HWND hw)
{
  // HWND��Window object�̌���
  bindHWND__(hw);

  // Drag and Drop�̐ݒ�
  if (dad_)
    ::DragAcceptFiles(hw, TRUE);
}


/*===============================================
 *  Window::uninit__()
 *  ���b�Z�[�W�|���n�̏���������
 *  destroyed��deleting�̉���
 *=============================================*/
void urania::Window::uninit__()
{
  // Drag and Drop�̐ݒ��n��
  if (dad_)
    ::DragAcceptFiles(hw_, FALSE);

  // �֘AMenu�̎n��
  if (!!menu_)
    menu_->detach__();

  // HWND������̃����N��ؒf
  unbindHWND__();
}


/*================================================
 *  WMHandler::operator()
 *  ���b�Z�[�W�ɜ䂶�ăn���h�����Ăяo��
 */
LRESULT urania::WMHandler::operator()(urania::WndMessage* msg)
{
  using namespace std;
  using namespace std::placeholders;

  switch (msg->id)
  {
  case WM_DESTROY:
    if (onDestroy())
      return 0;
    break;

  case WM_COMMAND:
    {
      std::map<int, CmdHandler>::iterator jt;
      jt = cmap_.find(msg->wparam & 0x0FFFF);
      if (jt != cmap_.end()) {
        (jt->second)(msg->window);
        return 0;
      }
    }
    break;

  case WM_SIZE:
    {
      int w = msg->lparam & 0x0FFFF;
      int h = (msg->lparam >> 16) & 0x0FFFF;
      if (onSize(msg->window, msg->wparam, w, h))
        return 0;
    }
    break;

  case WM_KEYDOWN:
    {
      int rep = msg->lparam & 0x0FFFF;
      bool prev = msg->lparam & 0x01 << 30;
    
      if (onKeyDown(msg->window, msg->wparam, rep, prev))
        return 0;
    }
    break;

  case WM_PAINT:
    return msg->window->onPaint(
             bind(&WMHandler::onPaint, this, _1, _2),
             msg->wparam, msg->lparam);
    break;

  case WM_MOUSEWHEEL:
    {
      int d = GET_WHEEL_DELTA_WPARAM(msg->wparam);
      int k = GET_KEYSTATE_WPARAM(msg->wparam);
      int x = GET_X_LPARAM(msg->lparam);
      int y = GET_Y_LPARAM(msg->lparam);
      onMouseWheel(msg->window, d, k, x, y);
    }
    return 0;
    break;

  case WM_HSCROLL:
  case WM_VSCROLL:
    onScroll_(msg->window, msg->id, msg->wparam, msg->lparam);
    return 0;
    break;

  case WM_DROPFILES:
    onDropFiles_(msg->window, msg->wparam);
    return 0;
    break;
  }

  return msg->window->defHandler(msg->id, msg->wparam, msg->lparam);
}




//eof
