/**************************************************************************
 *
 *  menu.h
 *  by oZ/acy
 *  (c) 2002-2016 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  ���j���[�L�q�E����n�N���X��`
 *
 *  ����
 *    2016.2.28  �C��
 *************************************************************************/

#ifndef INC_URANIA_MENU_H___
#define INC_URANIA_MENU_H___

#include <vector>
#include <string>
#include <boost/utility.hpp>
#include <memory>
#include <windows.h>
#include "decl.h"


/*----------------------------
*  class MenuDesc
*  ���j���[�L�q�p�N���X
*---------------------------*/
class urania::MenuDesc
{
  friend class urania::Menu;

public:
  class Node_
  {
    friend class MenuDesc;

  public:
    enum
    {
      MN_BRANCH = 0,
      MN_SEPARATOR = -1
    };

  private:
    std::vector<Node_> ary_;
    std::wstring name_;
    int id_;

    Node_() : id_(MN_SEPARATOR) {}
    Node_(const std::wstring& s) : name_(s), id_(MN_BRANCH) {}
    Node_(const std::wstring& s, int i) : name_(s), id_(i) {}

  public:
    ~Node_() {}

    bool addSeparator();
    bool addPopup(const std::wstring& s);
    bool addPopup(const std::wstring& s, int i);

    Node_& operator[](int i) { return ary_[i]; }
    const Node_& operator[](int i) const { return ary_[i]; }
  };

private:
  std::vector<Node_> node_;

public:
  MenuDesc(){}
  ~MenuDesc(){}

  bool addPopup(const std::wstring& s);
  bool addPopup(const std::wstring& s, int i);

  Node_& operator[](int i) { return node_[i]; }
  const Node_& operator[](int i) const { return node_[i]; }

private:
  HMENU createHandle__() const;
  static void addPopupMenu__(HMENU pm, const Node_& item);
};


/*-------------------------------
*  class Menu
*  ���j���[�n���h�����b�p�[
*------------------------------*/
class urania::Menu : public boost::noncopyable
{
  friend class urania::Window;

private:
  typedef std::shared_ptr<urania::Menu> PP_;

private:
  HMENU hmenu_;
  bool dst_;

  Menu() : hmenu_(NULL), dst_(false) {}

  //==============================================
  //  link__()
  //  Object��HMENU�����łɘA��
  //  Object�j������MENU���j������悤�ɂ���
  //==============================================
  void link__(HMENU h)
  {
    attach__(h);
    if (hmenu_)
      dst_ = true;
  }

  //==============================================
  //  kill__()
  //  HMENU��Object��؂藣��
  //  ����link()__����Ă����HMENU��j������
  //==============================================
  void kill__()
  {
    if (dst_ && hmenu_)
      ::DestroyMenu(hmenu_);
     detach__();
  }


  //==============================================
  //  attach__()
  //  Object��HMENU���キ�A��
  //  Object�j������HMENU�͔j�����Ȃ�
  //==============================================
  void attach__(HMENU h)
  {
    kill__();
    hmenu_ = h;
  }

  //==============================================
  //  detach__()
  //  �A����؂� HMENU�̔j���͂��Ȃ�
  //==============================================
  void detach__()
  {
    hmenu_ = NULL;
    dst_ = false;
  }

  //========================================================
  //  giveHM__()
  //  Window�Ƀn���h����n���A
  //  link()__��Ԃ���attach__()��ԂɑJ��
  //========================================================
  HMENU giveHM__()
  {
    dst_ = false;
    return hmenu_;
  }


public:
  ~Menu() { kill__(); }

  static PP_ create(const urania::MenuDesc& desc);
  static PP_ create(int rc);

  PP_ getSub(unsigned id);

  void checkItem(unsigned cmdid);
  void uncheckItem(unsigned cmdid);
  bool getItemCheck(unsigned cmdid);

  void enableItem(unsigned cmdid);
  void disableItem(unsigned cmdid);
  void grayItem(unsigned cmdid);
};


namespace urania
{
  typedef std::shared_ptr<Menu> RCP_Menu;
}


#endif
