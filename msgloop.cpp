/**************************************************************************
 *
 *  msgloop.cpp
 *  by oZ/acy
 *  (c) 2002-2016 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  ���b�Z�[�W���[�v���� �W��
 *
 *  ����
 *    2016.2.27  �t�@�C�����̍X�Astart() �� messageLoop()�ɉ���
 *************************************************************************/

#include "system.h"

void urania::System::messageLoop()
{
  MSG msg;

  while (::GetMessage(&msg, NULL, 0, 0))
  {
    ::TranslateMessage(&msg);
    ::DispatchMessage(&msg);
  }

  ::PostQuitMessage(0);
  return;
}


//eof
