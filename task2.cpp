/*
 *  task2.cpp
 *  (C) 2002 oZ/acy, ALL RIGHTS RESERVED.
 *  last update : 21 Jul 2002
 *
 *  MDI�̏ꍇ�̃��b�Z�[�W���� URANIA�ɖ��Ή�
 */

#include "gpgui/mdi.h"
#include "gpgui/sys.h"


bool gplib::gui::System::taskMDI(MDIFrame* frm)
{
   MSG msg;
   if(::GetMessage(&msg,NULL,0,0))
   {
      if(!TranslateMDISysAccel(frm->mdiclient_D,&msg))
      {
         ::TranslateMessage (&msg);
         ::DispatchMessage (&msg);
      }
      return true;
   }
   else
   {
      ::PostQuitMessage(0);
      return false;
   }
}


//eof
