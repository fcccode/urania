/**************************************************************************
 *
 *  regwrite.cpp
 *  by oZ/acy
 *  (c) 2004-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  WXgμNX (Writer)
 *
 *  π
 *    22 Feb 2004  μ¬
 *    17 Mar 2006  C³
 *    24 Apr 2008  C³
 *     4 Apr 2009  C³ for UNICODEδ
 *     8 Sep 2011  C³ for C++11δ
 *    29 Feb 2016  C³
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
urania::RegistryWriter::setDwordData(const std::wstring& name, DWORD val)
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
