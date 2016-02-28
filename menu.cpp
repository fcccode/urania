/**************************************************************************
 *
 *  menu.cpp
 *  by oZ/acy
 *  (c) 2002-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  class urania::Menu �̎�����`
 *
 *  ����
 *    2016.2.28  �C��
 *************************************************************************/

#include "menu.h"
#include "system.h"

/*====================================
 *  Menu::create()
 *  ���\�[�XID����Menu�𐶐�
 */
urania::RCP_Menu urania::Menu::create(int rc)
{
  RCP_Menu qm(new Menu);
  qm->link__(::LoadMenu(System::hi_S, MAKEINTRESOURCE(rc)));
  return qm;
}


/*===================================
 *  Menu::getSub()
 *  �T�u���j���[���擾
 */
urania::RCP_Menu urania::Menu::getSub(unsigned id)
{
  if (!hmenu_)
    return RCP_Menu();

  HMENU sub = ::GetSubMenu(hmenu_, id);
  if (!sub)
    return RCP_Menu();

  RCP_Menu mn(new Menu);
  mn->attach__(sub);
  return mn;
}


/*==================================================
 *  Menu::checkItem()
 *  �w��A�C�e���Ƀ`�F�b�N������
 */
void urania::Menu::checkItem(unsigned cmdid)
{
  if (hmenu_)
    ::CheckMenuItem(hmenu_, cmdid, MF_BYCOMMAND|MF_CHECKED);
}


/*======================================
*  Menu::uncheckItem()
*  �w��A�C�e���̃`�F�b�N���͂���
*=====================================*/
void urania::Menu::uncheckItem(unsigned cmdid)
{
  if (hmenu_)
    ::CheckMenuItem(hmenu_, cmdid, MF_BYCOMMAND|MF_UNCHECKED);
}


/*==========================================================
 *  Menu::getItemCheck()
 *  �A�C�e�����`�F�b�N����Ă��邩�ǂ������ׂ�
 */
bool urania::Menu::getItemCheck(unsigned cmdid)
{
  if (!hmenu_)
    return false;

  UINT stt = ::GetMenuState(hmenu_, cmdid, MF_BYCOMMAND);
  if (stt == (UINT)-1)
    return false;

  if (stt & MF_CHECKED)
    return true;
  else
    return false;
}


/*=========================================
 *  Menu::enableItem()
 *  �A�C�e����I���\�ɂ���
 */
void urania::Menu::enableItem(unsigned cmdid)
{
   if (hmenu_)
     ::EnableMenuItem(hmenu_, cmdid, MF_BYCOMMAND|MF_ENABLED);
}


/*=========================================
 *  Menu::disableItem()
 *  �A�C�e����I��s�ɂ���
 */
void urania::Menu::disableItem(unsigned cmdid)
{
  if (hmenu_)
    ::EnableMenuItem(hmenu_, cmdid, MF_BYCOMMAND|MF_DISABLED);
}


/*===============================================
 *  Menu::grayItem()
 *  �A�C�e����W�F�\��(�I��s��)�ɂ���
 */
void urania::Menu::grayItem(unsigned cmdid)
{
  if (hmenu_)
    ::EnableMenuItem(hmenu_, cmdid, MF_BYCOMMAND|MF_GRAYED);
}




//eof
