/**************************************************************************
*
*  wmain.cpp
*  by oZ/acy
*  (c) 2002-2004 oZ/acy.  ALL RIGHTS RESERVED.
*
*  WinMain()
*
*  ����
*    14 Feb 2004 : userMain() �̈��ɜE�~
**************************************************************************/

#include "sys.h"

// ���C�u�����g�p�҂̎����I�J�n�n�_
int userMain();


/*=======================
*  WinMain()
*======================*/
int PASCAL WinMain(HINSTANCE hi, HINSTANCE pv, LPSTR cl, int cs)
{
  (void)pv;
  (void)cl;
  (void)cs;

  urania::System::hi_S = hi;
  return userMain();
}


//eof
