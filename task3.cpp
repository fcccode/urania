/**************************************************************************
*
*  task3.cpp
*  by oZ/acy
*  (c) 2002-2010 oZ/acy. ALL RIGHTS RESERVED.
*
*
*  �����ԙ|���������b�Z�[�W�|��
*
*  last update: 2 Sep MMX
**************************************************************************/

#include "sys.h"


/* DirectX �Ȃǂ̛����ԙ|���ł̃��b�Z�[�W���[�v�|���p */
/*
bool urania::System::taskRT()
{
  MSG msg;
  while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
  {
    if (msg.message==WM_QUIT)
    {
      ::PostQuitMessage(0);
      return false;
    }

    ::TranslateMessage(&msg);
    ::DispatchMessage(&msg);
  }
  return true;
}
*/


void urania::System::startRT()
{
  MSG msg;
  for (;;) {
    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      if (msg.message==WM_QUIT)
      {
        ::PostQuitMessage(0);
        return;
      }

      ::TranslateMessage(&msg);
      ::DispatchMessage(&msg);
    }
  }
}




//eof
