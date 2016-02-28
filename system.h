/**************************************************************************
 *
 *  system.h
 *  by oZ/acy
 *  (c) 2001-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  SYStem manage
 *
 *  ����
 *    14 Feb 2004  System::getLongPathName() ��ǉ�
 *    27 Feb 2008  System::getDesktopWidth() ��ǉ�
 *                 System::getDesktopHeight() ��ǉ�
 *     4 Apr 2009  UNICODE����
 *     7 Nov 2009  System::cnvWStr2MBStr() ��ǉ�
 *     2 Sep 2010  task�n�폜�Estart�n�ǉ�
 *    13 May 2012  C++11����
 *    27 Feb 2016  �t�@�C�����̍X�A���\�b�h���̍X
 *************************************************************************/

#ifndef INC_GP_GUI_SYSTEM_H__
#define INC_GP_GUI_SYSTEM_H__

#include <windows.h>
#include <string>
#include <vector>
#include "decl.h"


//int PASCAL WinMain(HINSTANCE hi, HINSTANCE pv, LPSTR cl, int cs);


/*---------------------
 *  class System
 *-------------------*/
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
  //=============================================================
  //  void start()
  //  �J�n
  //  ��铓I�ɂ̓V�X�e������n���ꂽHINSTANCE�l���i�[���Ă���
  //=============================================================
  static void start(HINSTANCE hi)
  {
    hi_S = hi;
  }

  //=======================================================
  //  void quit()
  //  ���b�Z�[�W�L���[�ɏI���𓊂���
  //=======================================================
  static void quit(int r)
  {
    ::PostQuitMessage(r);
  }

  static void messageLoop();
  template<class Func_> static void messageLoop(Func_ f);
  //static void startRT();


  // ���b�Z�[�W�{�b�N�X�n

  //=======================================================
  //  static void alert()
  //  �x���p���b�Z�[�W�{�b�N�X��\��
  //=======================================================
  static void alert(const std::wstring& ttl, const std::wstring& msg)
  {
    ::MessageBox(NULL, msg.c_str(), ttl.c_str(), MB_OK | MB_ICONEXCLAMATION);
  }

  //=======================================================
  //  static void notify()
  //  �ʒm�p�̃��b�Z�[�W�{�b�N�X��\��
  //=======================================================
  static void notify(const std::wstring& ttl, const std::wstring& msg)
  {
    ::MessageBox(NULL, msg.c_str(), ttl.c_str(), MB_OK);
  }

  //=======================================================
  //  static askYesNoCancel()
  //  Yes, No, �L�����Z���O���̃��b�Z�[�W�{�b�N�X��\�� 
  //
  //  �߂�l: 1: OK, 2: NO, 3: CANCEL �̂��Âꂩ
  //=======================================================
  static int askYesNoCancel(const std::wstring& ttl, const std::wstring& msg)
  {
    int res = ::MessageBox(NULL, msg.c_str(), ttl.c_str(), MB_YESNOCANCEL);
    switch(res)
    {
    case IDYES:
      return 1;
    case IDNO:
      return 0;
    case IDCANCEL:
      return 2;
    default:
      return 2;  // �L�����Z��
    }
  }

  //=======================================================
  //  static askYNBox()
  //  �͂��A�������񝢂̃��b�Z�[�W�{�b�N�X��\��
  //
  //  �߂�l: true: Yes, false: No �̂��Âꂩ
  //=======================================================
  static bool askYesNo(const std::wstring& ttl, const std::wstring& msg)
  {
    int res = ::MessageBox(NULL, msg.c_str(), ttl.c_str(), MB_YESNO);
    if (res == IDYES)
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
  static std::vector<std::wstring> getCmdLineArgsW();

  // ���C�h������E�}���`������̊� (Win32API�g�p)
  static std::string strcpyWideToMultiByte(const std::wstring& ws);
  static std::wstring strcpyMultiByteToWide(const std::string& ws);


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


/*===============================================================
 *  System::messageLoop(f)
 *  Windows Application �̃��b�Z�[�W���[�v
 *  �E�B���h�E���b�Z�[�W���Ȃ��ꍇ�ɃR�[���o�b�N���Ăяo���B
 *  �R�[���o�b�N��bool��Ԃ��Afalse��Ԃ����ꍇ�́A
 *  ���ɃE�B���h�E���b�Z�[�W��|��������܂ŃR�[���o�b�N���Ȃ��B
 */
template<class Func_>
void urania::System::messageLoop(Func_ f)
{
  MSG msg;
  static bool idle = true;

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
