/**************************************************************************
 *
 *  getCLArgsW.cpp
 *  by oZ/acy
 *  (c) 2016 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  ����
 *    27 Feb 2016  getCmdLineArgs() �� wchar_t �ł��쐬
 *************************************************************************/

#include "system.h"

// ���������ăR���p�C���ˑ�??
extern int __argc;
extern wchar_t** __wargv;


/*===========================================
*  �R�}���h���C�����ɂ��擾(wchar_t��)
*/
std::vector<std::wstring> urania::System::getCmdLineArgsW()
{
  std::vector<std::wstring> args(__argc);

  for (int i = 0; i < __argc; i++)
    args[i] = __wargv[i];

  return args;
}


//eof
