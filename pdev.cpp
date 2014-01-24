/**************************************************************************
 *
 *  pdev.cpp
 *  by oZ/acy
 *  (C) 2002-2011 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  class urania::PaintDevice �̎�����`���̈�
 *   �R���X�g���N�^�A�f�X�g���N�^�A�V�X�e���J���[�n�A�N���A�y��BLT����
 *
 *  last update : 8 Sep 2011
 *************************************************************************/

#include "pdev.h"
#include <cstring>


/*==========================================================
 *  PaintDevice::PaintDevice()
 *  DC�̊e�I�u�W�F�N�g�̌���ۑ��ƐV�K���蓖��
 */
urania::PaintDevice::PaintDevice(HDC dc, DestProc dp, void* ap, int w, int h)
  : hdc_(dc), dst_(dp), app_(ap), width_(w), height_(h)
{
  HBRUSH tb = CreateSolidBrush(RGB(255, 255, 255));
  HPEN tp = CreatePen(PS_SOLID, 0, RGB(255, 255, 255));
  HFONT tf
   = CreateFont(
       16, 0, 0, 0, 0, 0, 0, 0, SHIFTJIS_CHARSET, 0, 0, 0, FIXED_PITCH,
       nullptr);

  obr_ = (HBRUSH)SelectObject(hdc_, tb);
  opn_ = (HPEN)SelectObject(hdc_, tp);
  oft_ = (HFONT)SelectObject(hdc_, tf);
  obm_ = SetBkMode(hdc_, TRANSPARENT);
}


/*===============================================================
 *  PaintDevice::~PaintDevice()
 *  DC�̊e�I�u�W�F�N�g�̌��󕜋A�EDC����R�[���o�b�N�Ăяo��
 */
urania::PaintDevice::~PaintDevice()
{
  HBRUSH tb = (HBRUSH)SelectObject(hdc_, obr_);
  HPEN tp = (HPEN)SelectObject(hdc_, opn_);
  HFONT tf = (HFONT)SelectObject(hdc_, oft_);
  SetBkMode(hdc_, obm_);

  DeleteObject(tb);
  DeleteObject(tp);
  DeleteObject(tf);

  if (dst_)
    dst_(hdc_, app_);
}


/*===============================================================
 *  PaintDevice::create()
 *  Object����
 *   ����:  HDC dc      : �f�o�C�X�R���e�L�X�g�n���h��
 *          DestProc dp : DC����p�R�[���o�b�N
 *          void* a     : �R�[���o�b�N�ɓn���p�����[�^
 *          unsigned w  : �f�o�C�X��
 *          unsigned h  : �f�o�C�X����
 *   �Ԓl:  �I�u�W�F�N�g�̃X�}�[�g�|�C���^(Qointer)
 */
urania::PaintDevice* urania::PaintDevice::create(
  HDC dc, DestProc dp, void* a, int w, int h) throw()
{
  try
  {
    return new PaintDevice(dc, dp, a, w, h);
  }
  catch (std::bad_alloc)
  {
    return nullptr;
  }
}


/*====================================================================
 *  PaintDevice::getSysColor()
 *  �V�X�e���J���[�擾
 *   ���� : int id : �V�X�e���J���[��ID(gpGuiDef.h��enum��`)
 *   �Ԓl : �w�肵���V�X�e���J���[�̐F(BGR)
 */
urania::Color urania::PaintDevice::getSysColor(int id)
{
  COLORREF col = GetSysColor(id);
  return C_(GetRValue(col),GetGValue(col),GetBValue(col));
}


/*====================================================================
 *  PaintDevice::setSysColor()
 *  �V�X�e���J���[�ݒ�
 *   ���� : int id        : �V�X�e���J���[��ID(gpGuiDef.h��enum��`)
 *          const C_& col : �ݒ肷��F(BGR)
 */
void urania::PaintDevice::setSysColor(int id, const C_& col)
{
  int i[1];
  COLORREF c[1];

  i[0] = id;
  c[0] = col.getColorref();

  SetSysColors(1, i, c);
}


/*=====================================================
 *  PaintDevice::clear()
 *  �`��̈�̃N���A
 *   ���� : const C_& col : �N���A����Ƃ��̐F
 */
void urania::PaintDevice::clear(const C_& col)
{
  HBRUSH br = CreateSolidBrush(col.getColorref());
  RECT rc = {0, 0, width_, height_};
  FillRect(hdc_, &rc, br);
  DeleteObject(br);
}


/*=====================================================
 *  PaintDevice::blt()  �~ 4
 *  �`����e�̓]��
 *
 *   ���� : dx,dy  : �]���捶��p���W
 *          src    : �]����Object
 *          sx,sy  : �]��������p���W
 *          w,h    : �]�����E����
 *          mask   : �}�X�N����̈�
 */
void
urania::PaintDevice::blt(
  int dx, int dy, const urania::PaintMemDevice* src, int sx, int sy,
  int w, int h, const polymnia::Rect& mask)
{
  polymnia::imp_::Clip_ clip(sx,sy,w,h,dx,dy,mask);
  if (clip)
    BitBlt(
      hdc_, clip.dx, clip.dy, clip.w, clip.h, src->hdc_, clip.sx, clip.sy,
      SRCCOPY);
}

void
urania::PaintDevice::blt(
  int dx, int dy, const urania::PaintMemDevice* src, int sx, int sy,
  int w, int h)
{
  polymnia::Rect rect(0, 0, width_, height_);
  blt(dx, dy, src, sx, sy, w, h, rect);
}

void
urania::PaintDevice::blt(
  int dx, int dy, urania::PaintMemDeviceIndexed* src, int sx, int sy,
  int w, int h, const polymnia::Rect& mask)
{
  polymnia::imp_::Clip_ clip(sx, sy, w, h, dx, dy, mask);
  if (clip)
  {
    src->updatePalette();
    BitBlt(
      hdc_, clip.dx, clip.dy, clip.w, clip.h, src->hdc_, clip.sx, clip.sy,
      SRCCOPY);
  }
}

void
urania::PaintDevice::blt(
  int dx, int dy, urania::PaintMemDeviceIndexed* src, int sx, int sy,
  int w, int h)
{
  polymnia::Rect rect(0, 0, width_, height_);
  blt(dx, dy, src, sx, sy, w, h, rect);
}


/*=====================================================
 *  PaintDevice::blt()  �~ 2
 *  �`����e�̓]���A�A���g��k���t���őS�̈擯�m
 *
 *   ���� : src    : �]����Object
 */
void urania::PaintDevice::blt(const urania::PaintMemDevice* src)
{
  StretchBlt(
    hdc_, 0, 0, width_, height_, src->hdc_, 0, 0, src->width(), src->height(),
    SRCCOPY);
}

void urania::PaintDevice::blt(urania::PaintMemDeviceIndexed* src)
{
  src->updatePalette();
  StretchBlt(
    hdc_, 0, 0, width_, height_, src->hdc_, 0, 0, src->width(), src->height(),
    SRCCOPY);
}



//eof
