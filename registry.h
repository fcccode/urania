/**************************************************************************
 *
 *  registry.h
 *  by oZ/acy
 *  (c) 2004-2016 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  ���W�X�g������N���X
 *
 *  ����
 *    15 Feb 2004  �쐬
 *    24 Apr 2008  �C��
 *     4 Apr 2009  �C�� for UNICODE����
 *    29 Feb 2016  �C��
 **************************************************************************/
#ifndef INC_URANIA_REGISTRY_H___
#define INC_URANIA_REGISTRY_H___

#include <windows.h>
//#include <themis/inttype.h>
#include <string>


namespace urania {

enum RegRootKey {
  REGKEY_CLASSES_ROOT,
  REGKEY_CURRENT_USER,
  REGKEY_LOCAL_MACHINE,
  REGKEY_USERS,
  REGKEY_CURRENT_CONFIG,
};


/*----------------------------------------------------------
 *  class RegistryBase
 *  ���W�X�g������N���X���
 */
class RegistryBase
{
private:
  HKEY key_;

protected:
  RegistryBase() : key_(NULL) {}

  void setKey_(HKEY k) { key_ = k; }
  HKEY getKey_() const { return key_; }

public:
  ~RegistryBase()
  {
    if (key_)
      ::RegCloseKey(key_);
  }

protected:
  static HKEY getRoot_(RegRootKey k);
};


/*-----------------------------------------------------------
 *  class RegistryReader
 *  ���W�X�g��植��N���X
 */
class RegistryReader : public RegistryBase
{
public:
  RegistryReader(RegRootKey root, const std::wstring& path);

  operator bool() const { return getKey_() != NULL; }
  bool operator!() const { return getKey_() == NULL; }

  DWORD getDwordData(const std::wstring& name);
  std::wstring getStringData(const std::wstring& name);
};


/*-----------------------------------------------------------
 *  class RegistryWriter
 *  ���W�X�g�������N���X
 */
class RegistryWriter : public RegistryBase
{
public:
  RegistryWriter(RegRootKey root, const std::wstring& path);

  operator bool() const { return getKey_() != NULL; }
  bool operator!() const { return getKey_() == NULL; }

  void setDwordData(const std::wstring& name, DWORD val);
  void setStringData(const std::wstring& name, const std::wstring& val);
};


}// end of namespace urania


#endif // INC_URANIA_REGISTRY_H___
