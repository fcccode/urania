/**************************************************************************
*
*  getCLArgs.cpp
*  by oZ/acy
*  (c) 2004-2008 oZ/acy.  ALL RIGHTS RESERVED.
*
*  ����
*    14 Feb 2004  �쐬
*    30 Mar 2008  �C��
**************************************************************************/

#include "sys.h"

// ���������ăR���p�C���ˑ�??
extern int __argc;
extern char** __argv;


/*===========================================
*  �R�}���h���C�����ɂ��擾
*/
std::vector<std::string> urania::System::getCmdLineArgs()
{
  std::vector<std::string> args(__argc);

  for (int i=0; i < __argc; i++)
    args[i] = __argv[i];

  return args;
}


//eof
