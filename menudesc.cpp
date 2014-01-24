/**************************************************************************
 *
 *  menudesc.cpp
 *  by oZ/acy
 *  (c) 2002-2011 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  class urania::MenuDesc, class urania::Menu(�ꕔ) �̎�����`
 *
 *  last update : 8 Sep MMXI
 *
 *************************************************************************/
#include "menu.h"


/*============================
 *  MenuDesc::addPopup()
 *  �|�b�v�A�b�v���ڂ�ǉ�
 */
bool urania::MenuDesc::addPopup(const std::wstring& s)
{
  node_.push_back(Node_(s));
  return true;
}


/*============================
 *  MenuDesc::addPopup()
 *  �I�����ڂ�ǉ�
 */
bool urania::MenuDesc::addPopup(const std::wstring& s,int i)
{
  if (i==Node_::MN_BRANCH || i==Node_::MN_SEPARATOR)
    return false;
  node_.push_back(Node_(s,i));
  return true;
}


/*======================================
 *  MenuDesc::createHandle__()
 *  Object�ŋK�肳�ꂽ���j���[�𐶐�
 */
HMENU urania::MenuDesc::createHandle__() const
{
  if (node_.size()==0)
    return NULL;

  HMENU hmenu = CreateMenu();
  for (unsigned i=0; i<node_.size(); i++)
    addPopupMenu__(hmenu, node_[i]);

  return hmenu;
}


/*===============================================================
 *  MenuDesc::addPopupMenu__()
 *  createHandle__()�̉������Ƃ��ă|�b�v�A�b�v���j���[�𐶐�
 */
void urania::MenuDesc::addPopupMenu__(HMENU pm, const MenuDesc::Node_& item)
{
  if (item.id_==Node_::MN_SEPARATOR)
    AppendMenu(pm, MF_SEPARATOR, 0, nullptr);
  else if (item.id_==Node_::MN_BRANCH)
  {
    HMENU hm = CreatePopupMenu();
    for (unsigned i=0; i<item.ary_.size(); i++)
      addPopupMenu__(hm, item[i]);
    AppendMenu(pm, MF_ENABLED|MF_POPUP, (ULONG_PTR)hm, item.name_.c_str());
  }
  else
    AppendMenu(pm, MF_ENABLED|MF_STRING, item.id_, item.name_.c_str());
}



/*======================================
 *  MenuDesc::Node_::addSeparator()
 *  ��؂����ǉ�
 */
bool urania::MenuDesc::Node_::addSeparator()
{
  if (id_!=MN_BRANCH)
    return false;
  ary_.push_back(Node_());
  return true;
}


/*======================================
 *  MenuDesc::Node_::addPopup()
 *  �|�b�v�A�b�v���ڂ�ǉ�
 */
bool urania::MenuDesc::Node_::addPopup(const std::wstring& s)
{
  if (id_!=MN_BRANCH)
    return false;
  ary_.push_back(Node_(s));
  return true;
}


/*======================================
 *  MenuDesc::Node_::addPopup()
 *  �I�����ڂ�ǉ�
 */
bool urania::MenuDesc::Node_::addPopup(const std::wstring& s,int i)
{
  if (id_!=MN_BRANCH)
    return false;
  if (i==MN_BRANCH || i==MN_SEPARATOR)
    return false;
  ary_.push_back(Node_(s,i));
  return true;
}


/*=====================================================
 *  Menu::create(const urania::MenuDesc& desc)
 *  MenuDesc����Menu�𐶐�
 */
urania::RCP_Menu urania::Menu::create(const urania::MenuDesc& desc)
{
  RCP_Menu qm(new Menu);
  qm->link__(desc.createHandle__());
  return qm;
}




//eof
