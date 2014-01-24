/**************************************************************************
 *
 *  dialog.cpp
 *  by oZ/acy
 *  (c) 2002-2014 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  DialogBox �N���X����
 *
 *  last update : 21 Jan 2014
 *
 *************************************************************************/

#include "dialog.h"


/*====================================
 *  Dialog::doModal()
 *  Modal��DialogBox�̉^�p
 *==================================*/
int urania::Dialog::doModal(int rid, Ini_ ini, Ini_ ui, H_ hnd, void* app)
{
  Dialog* dlg = new Dialog(ini, ui, hnd, true, app);

  return
    ::DialogBoxParam(
      getHI__(), MAKEINTRESOURCE(rid), NULL, (DLGPROC)dlgproc__,
      reinterpret_cast<LPARAM>(dlg));
}


/*-----------------------------
 *  Dialog::doModeless()
 *  Modeless Dialog�̐���
 *---------------------------*/
urania::Dialog* urania::Dialog::doModeless(
  int rid, Ini_ ini, Ini_ ui, H_ hnd, void* app)
{
  Dialog* dlg = new Dialog(ini, ui, hnd, false, app);

  ::CreateDialogParam(
    getHI__(), MAKEINTRESOURCE(rid), NULL, (DLGPROC)dlgproc__,
    reinterpret_cast<LPARAM>(dlg));

  return dlg;
}


/*----------------------------------
 *  doOwnedModal()
 *  �I�[�i�[�t��Modal Dialog���s
 *--------------------------------*/
int urania::Dialog::doOwnedModal(
  int rid, urania::WndBase* par, Ini_ ini, Ini_ ui, H_ hnd, void* app)
{
  Dialog* dlg = new Dialog(ini, ui, hnd, true, app);

  return
    ::DialogBoxParam(
      getHI__(), MAKEINTRESOURCE(rid), getHW__(par), (DLGPROC)dlgproc__,
      reinterpret_cast<LPARAM>(dlg));
}


/*-------------------------------------
 *  doOwnedModeless()
 *  �I�[�i�[�t��ModelessDialog����
 *-----------------------------------*/
urania::Dialog* urania::Dialog::doOwnedModeless(
  int rid, urania::WndBase* par, Ini_ ini, Ini_ ui, H_ hnd, void* app)
{
  Dialog* dlg = new Dialog(ini, ui, hnd, false, app);

  ::CreateDialogParam(
    getHI__(), MAKEINTRESOURCE(rid), getHW__(par), (DLGPROC)dlgproc__,
    reinterpret_cast<LPARAM>(dlg));

  return dlg;
}



/*-------------------------------------------------
 *  Dialog::dlgproc__()
 *  Dialog�ƌ������Ă���DialogBox�p��DlgProc
 *-----------------------------------------------*/
BOOL CALLBACK urania::Dialog::dlgproc__(HWND hw, UINT msg, WPARAM wp, LPARAM lp)
{
  Dialog* dlg = (Dialog*)(GetWindowLongPtr(hw, DWLP_USER));

  if (!dlg)
  {
    if (msg==WM_INITDIALOG)
    {
      dlg = (Dialog*)lp;
      dlg->init__(hw);
      return TRUE;
    }
    else
      return FALSE;
  }

  if (msg==WM_DESTROY)
  {
    dlg->destroyed__();
    return TRUE;
  }
  else
    return dlg->dproc__(msg, wp, lp);
}


/*------------------------------------------
 *  Dialog::dproc__()
 *  �eDialog�̃��b�Z�[�W�����v���V�[�W��
 *----------------------------------------*/
BOOL urania::Dialog::dproc__(UINT msg, WPARAM wp, LPARAM lp)
{
  if (handler_)
    return (*handler_)(this, msg, wp, lp);
  else
    return FALSE;
}


/*-----------------------------
 *  Dialog::endModal()
 *  Modal DialogBox�̏I��
 *---------------------------*/
void urania::Dialog::endModal(int i)
{
  if (modal_)
    EndDialog(hw_, i);
}


/*------------------------------
 *  Dialog::destroyWindow__()
 *  DialogBox�̔j��
 *----------------------------*/
void urania::Dialog::destroyWindow__()
{
   if (modal_)
     endModal(0);
   else
     kill__();
}



/*-------------------------------
 *  Dialog::init__()
 *  ���b�Z�[�W�����n�̏�����
 *-----------------------------*/
void urania::Dialog::init__(HWND hw)
{
  // HWND��Window object�̌���
   if (modal_)
     attach__(hw);
   else
     link__(hw);

   SetWindowLong(hw, DWLP_USER, reinterpret_cast<ULONG_PTR>(this));

  // initializer�̌Ăяo��
   if (init_)
     init_(this);
}


/*-------------------------------
 *  Dialog::uninit__()
 *  ���b�Z�[�W�����n�̌�n��
 *  destroyed��deleting�̉���
 *-----------------------------*/
void urania::Dialog::uninit__()
{
  // uninitializer�̌Ăяo��
  if (uninit_)
    uninit_(this);

  // HWND������̃����N��ؒf
  if (hw_)
    ::SetWindowLong(hw_, DWLP_USER, reinterpret_cast<ULONG_PTR>(nullptr));
}



//eof
