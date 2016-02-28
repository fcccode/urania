/**************************************************************************
 *
 *  drop-h.cpp
 *  by oZ/acy
 *  (c) 2009-2014 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  Dropfiles Handler
 *
 *  ����
 *    2016.2.28  �C��
 */

#include "win.h"


/*===============================================================
 *  WMHandler::onDropFiles_()
 *  �h���b�v�t�@�C���̒�^�|�����s�ЁA���[�U���䕔���Ăяo��
 */
void urania::WMHandler::onDropFiles_(urania::Window* win, WPARAM wp)
{
  HDROP hd = (HDROP)wp;
  POINT p;
  DragQueryPoint(hd, &p);

  std::vector<std::wstring> astr;
  wchar_t temp[MAX_PATH];
  int n = DragQueryFile(hd, 0xffffffff, nullptr, 0);

  for (int i = 0; i < n; i++)
  {
    DragQueryFile(hd, i, temp, MAX_PATH);
    astr.push_back(temp);
  }

  DragFinish(hd);

  // ���[�U���T�u�N���X�ŃI�[�o�[���C�h����n���h�����Ăяo��
  onDropFiles(win, astr, p.x, p.y);
}




//eof
