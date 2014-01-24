/**************************************************************************
 *
 *  regwrite.cpp
 *  by oZ/acy
 *  (c) 2004-2011 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  ���W�X�g������N���X (Writer)
 *
 *  ����
 *    22 Feb 2004  �쐬
 *    17 Mar 2006  �C��
 *    24 Apr 2008  �C��
 *     4 Apr 2009  �C�� for UNICODE����
 *     8 Sep 2011  �C�� for C++11���䓙
 *************************************************************************/
#include "registry.h"


/*=====================================================
 *  RegistryWriter::RegistryWriter()
 *
 */
urania::RegistryWriter::RegistryWriter(
  urania::RegRootKey root, const std::wstring& path)
{
  HKEY rootkey = getRoot_(root);
  if (!rootkey)
    return;

  HKEY key;
  RegCreateKeyEx(
    rootkey, path.c_str(), 0, nullptr, 0, KEY_ALL_ACCESS, nullptr, &key,
    nullptr);
  setKey_(key);
}


/*==========================================================
 *  RegistryWriter::setDwordData()
 *
 */
void
urania::RegistryWriter::setDwordData(
  const std::wstring& name, themis::Dword val)
{
  ::RegSetValueEx(
    getKey_(), name.c_str(), 0, REG_DWORD, reinterpret_cast<BYTE*>(&val),
    sizeof(val));
}


/*==========================================================
 *  RegistryWriter::setStringData()
 *
 */
void
urania::RegistryWriter::setStringData(
  const std::wstring& name, const std::wstring& val)
{
  ::RegSetValueEx(
    getKey_(), name.c_str(), 0, REG_SZ,
    reinterpret_cast<const BYTE*>(val.c_str()),
    (val.size() + 1) * sizeof(wchar_t));
}


//eof
