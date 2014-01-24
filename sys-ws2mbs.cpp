/**************************************************************************
 *
 *  sys-ws2mbs.cpp
 *  by oZ/acy
 *  (c) 2009-2011 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  ����
 *    4 Apr MMIX  �쐬
 *    7 Nov MMIX  �C��
 *    8 Sep MMXI  �C��
 */
#include "sys.h"

std::string urania::System::cnvWStr2MBStr(const std::wstring& ws)
{
  using namespace std;

  int len = WideCharToMultiByte(
              CP_THREAD_ACP, 0, ws.c_str(), -1, nullptr, 0, nullptr, nullptr);

  char* buf = new char[len];

  WideCharToMultiByte(
    CP_THREAD_ACP, 0, ws.c_str(), -1, buf, len, nullptr, nullptr);

  string r = buf;
  delete[] buf;
  return r;
}


//eof
