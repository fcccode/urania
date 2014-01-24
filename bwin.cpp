/**************************************************************************
 *
 *  bwin.cpp
 *  by oZ/acy
 *  (c) 2002-2014 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  Window�p���N���X ����
 *
 *  last update: 20 Jan MMXIV
 *
 *************************************************************************/

#include "bwin.h"
#include <cstdlib>
#include <algorithm>
#include <sstream>


/* WNDCLASS�o�^���x�N�^ */
std::vector<urania::BasicWindow::WC_> urania::BasicWindow::vwc_S;


/*============================================
 *  BasicWindow::registWC__()
 *  WNDCLASS�o�^ & WNDCLASS����Ԃ�
 *  �������e��WNDCLASS�̓�d�o�^��j�~����
 *==========================================*/
std::wstring urania::BasicWindow::registWC__
(const urania::BasicWindow::WC_& wc)
{
  std::vector<WC_>::iterator it = std::find(vwc_S.begin(), vwc_S.end(), wc);
  if (it==vwc_S.end())
  {
    ////////////////////////////////////////////////////////
    // WNDCLASS�̓o�^��vector�ւ̒ǉ�
    ////////////////////////////////////////////////////////

    // �N���X����WC_�ɐݒ�
    WC_ wc2 = wc;
    //std::wostringstream tmp;
    std::basic_ostringstream<wchar_t> tmp;
    tmp << vwc_S.size();

    wc2.wcname_ = std::wstring(L"GPWNDCLASS") + tmp.str();

    // WNDCLASS Structure
    WNDCLASS wndcls =
    {
      CS_HREDRAW | CS_VREDRAW,
      wc2.proc_,
      0,
      sizeof(Window*),
      getHI__(),
      NULL,
      NULL,
      NULL,
      nullptr,
      wc2.wcname_.c_str()
    };

    // Icon �̐ݒ�
    if (wc2.icon_id_!=DEFAULT_RC)
      wndcls.hIcon = LoadIcon(getHI__(), MAKEINTRESOURCE(wc2.icon_id_));
    else
      wndcls.hIcon = LoadIcon(0, IDI_APPLICATION);

    // Cursor �̐ݒ�
    if (wc2.cursor_id_!=DEFAULT_RC)
      wndcls.hCursor = LoadCursor(getHI__(), MAKEINTRESOURCE(wc2.cursor_id_));
    else
      wndcls.hCursor = LoadCursor(0, IDC_ARROW);


    // �w�i�F�̐ݒ�
    switch (wc2.bkcolor_)
    {
    case BG_WHITE:
      wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
      break;

    case BG_BLACK:
      wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
      break;

    case BG_GRAY:
      wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
      break;

    case BG_LTGRAY:
      wndcls.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
      break;

    case BG_DKGRAY:
      wndcls.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
      break;

    case BG_APPWORKSPACE:
      wndcls.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE + 1);
      break;

    case BG_BKWINDOW:
      wndcls.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
      break;

    default:
      wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
      break;
    }

    // ���ۂɓo�^
    ::RegisterClass(&wndcls);

    vwc_S.push_back(wc2);
    return wc2.wcname_;
  }
  else
    return it->wcname_; // WNDCLASS����Ԃ�
}


/*=========================================
 *  BasicWindow::createWindow0__()
 *  �E�B���h�E�̐���
 *=======================================*/
void urania::BasicWindow::createWindow0__(const urania::BasicWindow::D0_& de)
{
  HWND hwnd;
  int style = WS_CLIPCHILDREN;

  // WNDCLASS�����o�^�Ȃ�o�^����
  WC_ wc;
  wc.icon_id_ = de.icon;
  wc.cursor_id_ = de.cursor;
  wc.bkcolor_ = de.bkcolor;
  if (de.winproc)
    wc.proc_ = de.winproc;
  else
    wc.proc_ = winproc__;
  std::wstring wcname = registWC__(wc);

  // Window Style �̐ݒ�
  if (de.can_resize)
    style |= WS_THICKFRAME;
  if (de.v_scrollbar)
    style |= WS_VSCROLL;
  if (de.h_scrollbar)
    style |= WS_HSCROLL;
  if (de.maxbox)
    style |= WS_MAXIMIZEBOX;
  if (de.minbox)
    style |= WS_MINIMIZEBOX;

  // �qWindow�ɂȂ邩�ǂ����ŕς��ݒ�
  if (de.pwnd && de.hm)
  {
    style |= WS_CHILD | WS_CLIPSIBLINGS;
    if (!de.popup && !de.border_only)
      style |= WS_CAPTION | WS_SYSMENU;
    else if (de.border_only)
      style |= WS_BORDER;
  }
  else
  {
    if (!de.border_only && !de.popup)
      style |= WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
    else if (de.border_only)
      style |= WS_POPUP | WS_BORDER | WS_SYSMENU;
    else
      style |= WS_POPUP;
  }

  // Window�����ۂɐ����E�����E�X�V
  hwnd
    = ::CreateWindow(
        wcname.c_str(), de.title.c_str(), style, de.x, de.y, de.w, de.h,
        de.pwnd, de.hm, getHI__(), (void*)this);

  ::ShowWindow(hwnd, SW_SHOW);
  ::UpdateWindow(hwnd);
}


/*===================================================================
 *  BasicWindow::winproc__()
 *  BasicWindow�ƌ������Ă���HWND�p��Window Procedure
 *=================================================================*/
LRESULT CALLBACK urania::BasicWindow::winproc__(
  HWND hw, UINT msg, WPARAM wp, LPARAM lp)
{
  BasicWindow* pw = (BasicWindow*)GetWindowLongPtr(hw, 0);

  // pw���ݒ肳��ĂȂ��Ƃ��̏���
  if (!pw)
  {
    if (msg != WM_CREATE)
      return ::DefWindowProc(hw, msg, wp, lp);

    LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lp;
    BasicWindow* p= (BasicWindow*)(lpcs->lpCreateParams);
    p->init__(hw);
    p->wproc__(msg, wp, lp);

    return 0;
  }

  if (msg==WM_DESTROY)
  {
    pw->wproc__(msg, wp, lp);
    pw->destroyed__();
    return 0;
  }
  else
    return pw->wproc__(msg, wp, lp);
}


/*=======================================
 *  BasicWindow::defHandler()
 *  �f�t�H���g�̃��b�Z�[�W����
 *=====================================*/
LRESULT urania::BasicWindow::defHandler(UINT msg, WPARAM wp, LPARAM lp)
{
  return ::DefWindowProc(hw_, msg, wp, lp);
}



/*========================================================
 *  BasicWindow::getPaintDevice()
 *  Window��DC�ɑΉ�����PaintDevice�𐶐�
 *======================================================*/
namespace
{
  void releasePaint__(HDC dc, void* app)
  {
    ::ReleaseDC((HWND)app, dc);
  }
}

urania::PaintDevice* urania::BasicWindow::getPaintDevice()
{
  RECT rc;
  ::GetClientRect(hw_, &rc);

  return
    PaintDevice::create(GetDC(hw_), releasePaint__, hw_, rc.right, rc.bottom);
}



//eof
