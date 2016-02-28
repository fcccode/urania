/**************************************************************************
 *
 *  clkpanel.h
 *  by oZ/acy
 *  (c) 2000-2016 oZ/acy.  All Rights Reserved.
 *
 *  ����
 *    2016.2.28  �C��
 *
 *************************************************************************/

#ifndef INC_URANIA_CLKPANEL_H___
#define INC_URANIA_CLKPANEL_H___

#include "bwin.h"

namespace urania {


class ClickPanel : public urania::BasicWindow
{
public:
  typedef ClickPanel* PCP_;
  typedef void (*PH_)(urania::BasicWindow*, urania::PaintDevice*, void*);

private:
  HWND pw_;
  int id_;
  PH_ ph_;
  void* app_;

  ClickPanel() : ph_(nullptr), app_(nullptr) {}

  LRESULT wproc__(UINT msg, WPARAM wp, LPARAM lp);

  void init__(HWND hw)
  {
    bindHWND__(hw);
  }

  void uninit__()
  {
    unbindHWND__();
  }


public:
  ~ClickPanel() {}


  //================================================================
  //  static create()
  //  Canvas Object �𐶐�
  //  ����  x,y,w,h : �p�l���ʒu�ƕ��ƍ���
  //        ph      : �`�`�n���h��
  //        ap      : �n���h���p�f�[�^
  //        par     : �e Window
  //        id      : �p�l���̎qWindowID
  //================================================================
  static ClickPanel* create(
    int x, int y, int w, int h, PH_ ph, void* ap, WndBase* par, int id);

  //=====================================
  //  paint()
  //  �`�`�n���h�����Ăяo��
  //=====================================
  void paint(BasicWindow* w, PaintDevice* pdev)
  {
    if (ph_)
      ph_(w, pdev, app_);
  }
};


}// end of namespace urania


#endif // INC_URANIA_CLKPANEL_H___
