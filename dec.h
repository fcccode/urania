/*******************************************************************************
 *  dec.h
 *
 *  by oZ/acy
 *  last update : 13 May 2012
 *
 *  DEClaration classes  for part "URANIA"
 */
#ifndef INC_URANIA_DEC_H___
#define INC_URANIA_DEC_H___

namespace urania
{
  class System;

  class WndBase;
    class BasicWindow;
      class Window;
//        class MDIFrame;
//        class MDIChild;
      class Dialog;

  class CommonDialogBase;
    class FileDialogBase;
      class OpenFileDialog;
      class SaveFileDialog;

  class Menu;
  class MenuDesc;

  class PaintDevice;
  class PaintMemDevice;
  class PaintMemDevicePal;


  struct CtrlDesc
  {
    int x, y, w, h;
  };

  enum // window style
  {
    WST_NORMAL  = 0,
    WST_POPUP   = 1,        // �g�Ȃ��E�B���h�E
    WST_BORDER  = 1<<1,     // �g�݂̂̃E�B���h�E
    WST_THICK   = 1<<2,     // �T�C�Y�ύX�\�E�B���h�E
    WST_VSCROLL = 1<<3,     // �c�X�N���[���o�[�t��
    WST_HSCROLL = 1<<4,     // ���X�N���[���o�[�t��
    WST_MAXBOX  = 1<<5,     // �ő剻�{�^���t��
    WST_MINBOX  = 1<<6,     // �ŏ����{�^���t��
    WST_DRAGANDDROP = 1<<7  // Drag&Drop�󂯕t��
  };

  enum //system color
  {
    SYSC_SCROLLBAR =0,        // �X�N���[���o�[�D�F�̈�
    SYSC_BACKGROUND,          // �f�X�N�g�b�v
    SYSC_ACTIVECAPTION,       // �A�N�e�B�u�E�B���h�E�̃L���v�V����
    SYSC_INACTIVECAPTION,     // ��A�N�e�B�u�E�B���h�E�L���v�V����
    SYSC_MENU,                // ���j���[�w�i
    SYSC_WINDOW,              // �E�B���h�E�w�i
    SYSC_WINDOWFRAME,         // �E�B���h�E�g
    SYSC_MENUTEXT,            // ���j���[�̃e�L�X�g
    SYSC_WINDOWTEXT,          // �E�B���h�E�̃e�L�X�g
    SYSC_CAPTIONTEXT,         // �L���v�V�����̃e�L�X�g
    SYSC_ACTIVEBORDER,        // �A�N�e�B�u�E�B���h�E���E
    SYSC_INACTIVEBORDER,      // ��A�N�e�B�u�E�B���h�E���E
    SYSC_APPWORKSPACE,        // MDI�w�i
    SYSC_HIGHLIGHT,           // �I�����ڔw�i
    SYSC_HIGHLIGHTTEXT,       // �I�����ڕ���
    SYSC_BTNFACE,             // �{�^���\�ʂ̉e
    SYSC_BTNSHADOW,           // �{�^�����̉e
    SYSC_GRAYTEXT,            // �W�F�e�L�X�g
    SYSC_BTNTEXT,             // �{�^���e�L�X�g
    SYSC_INACTIVECAPTIONTEXT, // ��A�N�e�B�u�L���v�V�����̃e�L�X�g
    SYSC_BTNHIGHLIGHT,        // �I�����ꂽ�{�^��
  };

  enum //ComboBox & ListBox   DIR OPTION
  {
    CTD_READWRITE = 0x0100, //�ǂݏ������p
    CTD_READONRY = 0x0001,  //�ǂݎ���p
    CTD_HIDDEN = 0x0002,    //�B���t�@�C��
    CTD_SYSTEM = 0x0004,    //�V�X�e���t�@�C��
    CTD_DIRECTORY = 0x0010, //�f�B���N�g��
    CTD_ARCHIVE = 0x0020,   //�A�[�J�C�u�t�@�C��
    CTD_DRIVE = 0x4000,     //�h���C�u
    CTD_EXCLUSIVE = 0x8000  //�w��^�C�v�ȊO��r��
  };

  enum //WC_ & WCIN_ �p�萔��`  for Icon&Cursor���\�[�X
  {
     DEFAULT_RC =0
  };

  enum //WC_ & WCIN_ �p�萔��`  for BackGroundColor
  {
     BG_WHITE =0,
     BG_BLACK,
     BG_GRAY,
     BG_LTGRAY,
     BG_DKGRAY,
     BG_APPWORKSPACE,
     BG_BKWINDOW
  };

  enum // Scroll Bar �� ��zID (����ȊO�͎q�E�B���h�EID�Ŏ���)
  {
    ID_SBV =0,
    ID_SBH =1
  };




}//end of namespace urania


#endif
//eof
