/**************************************************************************
 *
 *  bwin.h
 *  by oZ/acy
 *  (c) 2002-2014 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  Basic WINdow  for part "URANIA"
 *  Window�p���N���X
 *
 *  last update: 20 Jan MMXVI
 *
 *************************************************************************/

#ifndef INC_URANIA_BASICWINDOW_H___
#define INC_URANIA_BASICWINDOW_H___

#include "wbase.h"
#include "pdev.h"
#include <vector>


/*---------------------------------------
 *  class BasicWindow
 *  Window�Ǘ��E����p���N���X
 *-------------------------------------*/
class urania::BasicWindow : public urania::WndBase
{
public:
  typedef urania::BasicWindow BW_;
  typedef BW_* PBW_;


public:
  //-------------------
  //  struct D0_
  //  �L�q�\����
  //-------------------
  struct D0_
  {
    std::wstring title;  /* �^�C�g�� */
    HWND pwnd;  /* �e�E�B���h�E */
    HMENU hm;  /* ���j���[ */
    WNDPROC winproc;  /* �E�B���h�E�v���V�[�W�� */

    int x, y, w, h;  /* �E�B���h�E�̈ʒu�A�傫�� */

    unsigned icon;  /* �A�C�R���̃��\�[�X�ԍ� */
    unsigned cursor;  /* �J�[�\���̃��\�[�X�ԍ� */
    unsigned bkcolor;  /* �w�i�F�̔ԍ�(?) */

    bool maxbox;  /* �ő剻�{�b�N�X�t��? */
    bool minbox;  /* �ŏ����{�b�N�X�t��? */
    bool h_scrollbar;  /* ���X�N���[���o�[�t��? */
    bool v_scrollbar;  /* �c�X�N���[���o�[�t��? */
    bool popup;  /* �|�b�v�A�b�v�E�B���h�E? */
    bool border_only;  /* ���E����? */
    bool can_resize;  /* ���T�C�Y�\? */


    D0_()
    : pwnd(nullptr), hm(nullptr), winproc(nullptr),
      icon(DEFAULT_RC), cursor(DEFAULT_RC), bkcolor(BG_WHITE),
      x(CW_USEDEFAULT), w(CW_USEDEFAULT),
      maxbox(false), minbox(false),
      h_scrollbar(false), v_scrollbar(false), popup(false),
      border_only(false), can_resize(false)
    {}
  };


private:
  //----------------------------------
  //  struct WC_
  //  WNDCLASS �������i�[�N���X
  //--------------------------------//
  struct WC_
  {
    unsigned icon_id_;
    unsigned cursor_id_;
    unsigned bkcolor_;
    WNDPROC proc_;
    std::wstring wcname_;

    //========================================================================
    //  WNDCLASS �o�^�̗v�s�v�����߂邽�߂� operator==() �� operator!=()
    //========================================================================
    bool operator==(const WC_& my) const
    {
      if (icon_id_!=my.icon_id_)
        return false;
      if (cursor_id_!=my.cursor_id_)
        return false;
      if (bkcolor_!=my.bkcolor_)
        return false;
      if (proc_!=my.proc_)
        return false;

      return true;
    }

    bool operator!=(const WC_& my) const
    {
      return !(*this==my);
    }
  };


private:
  static std::vector<WC_> vwc_S;  // WNDCLASS���x�N�^

protected:
  BasicWindow() {}

  void createWindow0__(const D0_& de);

  //===========================================
  //  bindHWND__()
  //  BasicWindow �� HWND �̓�d�������`��
  //===========================================
  void bindHWND__(HWND hw)
  {
    link__(hw);
    SetWindowLongPtr(hw, 0, reinterpret_cast<ULONG_PTR>(this));
  }

  //==========================================
  //  unbindHWND__()
  //  HWND ���� BasicWindow �ւ̌�����؝�
  //==========================================
  void unbindHWND__()
  {
    if (hw_)
      SetWindowLongPtr(hw_, 0, reinterpret_cast<ULONG_PTR>(nullptr));
  }

  void destroyWindow__()
  {
    kill__();
  }

  virtual LRESULT wproc__(UINT msg, WPARAM wp, LPARAM lp) =0;
  static LRESULT CALLBACK winproc__(HWND hw, UINT msg, WPARAM wp, LPARAM lp);

  static std::wstring registWC__(const WC_& wc);


public:
  ~BasicWindow() {}


  void update()
  {
    if (hw_)
      ::UpdateWindow(hw_);
  }

  void invalidate()
  {
    if (hw_)
      ::InvalidateRect(hw_, nullptr, FALSE);
  }

  void invalidate(const polymnia::Rect& rect)
  {
    if (hw_)
    {
      ::RECT r;
      r.left = rect.x1;
      r.right = rect.x2;
      r.top = rect.y1;
      r.bottom = rect.y2;

      ::InvalidateRect(hw_, &r, FALSE);
    }
  }

  urania::PaintDevice* getPaintDevice();
  template<class PT_> LRESULT onPaint(PT_ proc, WPARAM wp, LPARAM lp);

  int getClientWidth()
  {
    if (!hw_)
      return 0;
    RECT rc;
    ::GetClientRect(hw_, &rc);
    return rc.right;
  }

  int getClientHeight()
  {
    if (!hw_)
      return 0;
    RECT rc;
    ::GetClientRect(hw_, &rc);
    return rc.bottom;
  }

  bool getClientWidthAndHeight(int* w, int* h)
  {
    if (!hw_)
      return false;
    RECT rc;
    ::GetClientRect(hw_, &rc);
    *w = rc.right;
    *h = rc.bottom;
    return true;
  }

  polymnia::Rect getClientWidthAndHeight()
  {
    polymnia::Rect re(0, 0, 0, 0);
    if (hw_)
    {
      RECT rc;
      ::GetClientRect(hw_, &rc);
      re.x2 = rc.right;
      re.y2 = rc.bottom;
    }
    return re;
  }

  void resize(int w, int h)
  {
    if (hw_)
      ::SetWindowPos(hw_, nullptr, 0, 0, w, h, SWP_NOMOVE|SWP_NOZORDER);
  }

  void resizeScreen(int w, int h)
  {
    if (!hw_)
      return;
    RECT wr, cr;
    ::GetWindowRect(hw_, &wr);
    ::GetClientRect(hw_, &cr);
    w += wr.right - wr.left - cr.right;
    h += wr.bottom - wr.top - cr.bottom;
    ::SetWindowPos(hw_, nullptr, 0, 0, w, h, SWP_NOMOVE|SWP_NOZORDER);
  }

  void setTimer(int id, int elapse) { ::SetTimer(hw_, id, elapse, nullptr); }
  void killTimer(int id) { ::KillTimer(hw_, id); }


  //==========================================================
  //  BasicWindow::defHandler()
  //  �f�t�H���g�̃��b�Z�[�W����
  //==========================================================
  virtual LRESULT defHandler(UINT msg, WPARAM wp, LPARAM lp);
};




/*=================================================================
 *  BasicWindow::onPaint()
 *  WM_PAINT�ɑΉ����邽�߂̃w���p
 *  PaintDevice�𐶐�����proc�ɓn��
 *  ���[�U��`�̃n���h������K�v�ɉ����Ė����I�ɌĂяo������
 *===============================================================*/
template<class PT_>
inline LRESULT urania::BasicWindow::onPaint(PT_ proc, WPARAM wp, LPARAM lp)
{
  (void)wp;
  (void)lp;

  PAINTSTRUCT ps;
  ::BeginPaint(hw_, &ps);
  RECT rc;
  ::GetClientRect(hw_, &rc);
  PaintDevice* pd
   = PaintDevice::create(ps.hdc, nullptr, nullptr, rc.right, rc.bottom);

  proc(this, pd);

  delete pd;
  ::EndPaint(hw_, &ps);

  return 0;
}



#endif
//eof
