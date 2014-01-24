/**************************************************************************
 *
 *  sys.h
 *  by oZ/acy
 *  (c) 2001-2012 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  SYStem manage
 *
 *  ����
 *    14 Feb 2004:  System::getLongPathName() ��ǉ�
 *    27 Feb 2008:  System::getDesktopWidth() ��ǉ�
 *                  System::getDesktopHeight() ��ǉ�
 *     4 Apr 2009:  UNICODE����
 *     7 Nov 2009:  System::cnvWStr2MBStr() ��ǉ�
 *     2 Sep 2010:  task�n�폜�Estart�n�ǉ�
 *    13 May 2012:  C++11����
 *************************************************************************/

#ifndef INC_GP_GUI_SYS_H__
#define INC_GP_GUI_SYS_H__

#include <windows.h>
#include <string>
#include <vector>
#include "dec.h"


int PASCAL WinMain(HINSTANCE hi, HINSTANCE pv, LPSTR cl, int cs);


/*---------------------
*  class System
*--------------------*/
class urania::System
{
  friend class urania::WndBase;
  friend class urania::Window;
  friend class urania::Dialog;
  friend class urania::Menu;
  friend int PASCAL ::WinMain(HINSTANCE hi, HINSTANCE pv, LPSTR cl, int cs);

private:
  static HINSTANCE hi_S;

private:
  System() =delete; //�C���X�^���X�����֎~

public:
  //=======================================================
  //  void quit()
  //  ���b�Z�[�W�L���[�ɏI���𓊂���
  //=======================================================
  static void quit(int r)
  {
    ::PostQuitMessage(r);
  }


  // ���b�Z�[�W���[�v�n

  //static bool task();
  ////static bool taskMDI(urania::MDIFrame*);
  //static bool taskRT();
  ////static bool taskRT_MDI(urania::MDIFrame*);

  //template<class Func_>
  //static bool taskIdle(Func_ f);

  static void start();
  static void startRT();

  template<class Func_>
  static void start(Func_ f);


  // ���b�Z�[�W�{�b�N�X�n

  //=======================================================
  //  static void alertBox()
  //  �x���p���b�Z�[�W�{�b�N�X��\��
  //=======================================================
  static void alertBox(const std::wstring& ttl, const std::wstring& msg)
  {
    ::MessageBox(NULL, msg.c_str(), ttl.c_str(), MB_OK|MB_ICONEXCLAMATION);
  }

  //=======================================================
  //  static void msgBox()
  //  OK����̃��b�Z�[�W�{�b�N�X��\��
  //=======================================================
  static void msgBox(const std::wstring& ttl, const std::wstring& msg)
  {
    ::MessageBox(NULL, msg.c_str(), ttl.c_str(), MB_OK);
  }

  //=======================================================
  //  static askYNCBox()
  //  Yes, No, �L�����Z��3���̃��b�Z�[�W�{�b�N�X��\�� 
  //
  //  �߂�l: 1: OK, 2: NO, 3: CANCEL �̂��Âꂩ
  //=======================================================
  static int askYNCBox(const std::wstring& ttl, const std::wstring& msg);

  //=======================================================
  //  static askYNBox()
  //  �͂��A������2���̃��b�Z�[�W�{�b�N�X��\��
  //
  //  �߂�l: true: Yes, false: No �̂��Âꂩ
  //=======================================================
  static bool askYNBox(const std::wstring& ttl, const std::wstring& msg)
  {
    int res = ::MessageBox(NULL, msg.c_str(), ttl.c_str(), MB_YESNO);
    if (res==IDYES)
      return true;
    else
      return false;
  }



  // �J�[�\���n
  static void showCursor()
    { 
      ::ShowCursor(TRUE);
    }
  static void hideCursor()
    {
      ::ShowCursor(FALSE);
    }

  // �t�@�C����萗�
  static std::wstring getLongPathName(const std::wstring& path);

  // �R�}���h���C�����Ɏ擾
  static std::vector<std::string> getCmdLineArgs();

  // ���C�h������E�}���`������̊� (Win32API�g�p)
  static std::string cnvWStr2MBStr(const std::wstring& ws);
  static std::wstring cnvMBStr2WStr(const std::string& ws);


  // �f�X�N�g�b�v���擾
  static int getDesktopWidth()
  {
    RECT rc;
    ::GetWindowRect(NULL, &rc);
    return rc.right - rc.left;
  }

  static int getDesktopHeight()
  {
    RECT rc;
    ::GetWindowRect(NULL, &rc);
    return rc.bottom - rc.top;
  }

};


/*
template<class Func_>
bool urania::System::taskIdle(Func_ f)
{
  MSG msg;
  static bool idle = false;

  if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
  {
    if (msg.message==WM_QUIT)
    {
      ::PostQuitMessage(0);
      return false;
    }

    ::TranslateMessage(&msg);
    ::DispatchMessage(&msg);

    idle = true;
  }
  else if (idle)
  {
    if (!f())
      idle = false;
  }
  else
  {
    ::WaitMessage();
  }

  return true;      
}
*/


template<class Func_>
void urania::System::start(Func_ f)
{
  MSG msg;
  static bool idle = false;

  for (;;) {
    if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      if (msg.message==WM_QUIT)
      {
        ::PostQuitMessage(0);
        return;
      }

      ::TranslateMessage(&msg);
      ::DispatchMessage(&msg);

      idle = true;
    }
    else if (idle)
    {
      if (!f())
        idle = false;
    }
    else
    {
      ::WaitMessage();
    }
  }
}




#endif
