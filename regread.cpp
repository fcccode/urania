/**************************************************************************
 *
 *  regread.cpp
 *  by oZ/acy
 *  (c) 2004-2016 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  WXgμNX (Reader)
 *
 *  π
 *    22 Feb 2004  μ¬
 *    28 Dec 2005  C³
 *    24 Apr 2008  C³
 *     4 Apr 2009  C³ for UNICODEδ
 *     8 Sep 2011  C³ for C++11δ
 *    29 Feb 2016  C³
 *************************************************************************/

#include <memory>
#include <cstdlib>
#include "registry.h"


/*==========================================================
 *  RegistryReader::RegistryReader()
 *
 */
urania::RegistryReader::RegistryReader(
  urania::RegRootKey root, const std::wstring& path)
{
  HKEY rootkey = getRoot_(root);
  if (!rootkey)
    return;

  HKEY key;
  RegOpenKeyEx(rootkey, path.c_str(), 0, KEY_QUERY_VALUE, &key);
  setKey_(key);
}



/*==========================================================
 *  RegistryReader::getDwordData()
 *
 */
DWORD urania::RegistryReader::getDwordData(const std::wstring& name)
{
  DWORD typ;
  DWORD sz = 0;

  if (::RegQueryValueEx(getKey_(), name.c_str(), nullptr, &typ, nullptr, &sz))
    return 0;

  if (typ != REG_DWORD)
    return 0;

  // f[^i[ΜζπmΫ
  std::unique_ptr<unsigned char[]> data(new unsigned char[sz]);

  // f[^πζΎ·ι
  if (::RegQueryValueEx(
          getKey_(), name.c_str(), nullptr, nullptr, (BYTE *)(data.get()), &sz))
  {
    return 0;
  }

  return *(DWORD*)(data.get());
}


/*==========================================================
 *  RegistryReader::getStringData()
 *
 */
std::wstring urania::RegistryReader::getStringData(const std::wstring& name)
{
  DWORD typ;
  DWORD sz = 0;

  if (::RegQueryValueEx(getKey_(), name.c_str(), nullptr, &typ, nullptr, &sz))
    return L"";

  if (typ != REG_SZ)
    return L"";

  // f[^i[ΜζπmΫ
  std::unique_ptr<unsigned char[]> data(new unsigned char[sz]);

  // f[^πζΎ·ι
  if (::RegQueryValueEx(
          getKey_(), name.c_str(), nullptr, nullptr, (BYTE*)(data.get()), &sz))
  {
    return L"";
  }

  return std::wstring(reinterpret_cast<wchar_t*>(data.get()));
}




//eof
