/**
 * @file dialog.h
 * @brief ダイアログクラス
 * @author oZ/acy
 *
 * @date 2016.2.28  修正
 * @date 2016.10.1  修正: friend class を削除
 */
#ifndef INC_URANIA_DIALOG_H___
#define INC_URANIA_DIALOG_H___

#include "wbase.h"


/**
 * @brief ダイアログ
 */
class urania::Dialog : public urania::WndBase
{
//  friend class urania::System;
  friend class urania::Window;

private:
  /** @brief メッセージハンドラの型 */
  typedef BOOL (*H_)(urania::Dialog*, UINT, WPARAM, LPARAM);
  /** @brief 初期化函數の型 */
  typedef void (*Ini_)(urania::Dialog*);

 protected:
  Ini_ init_;
  Ini_ uninit_;
  H_ handler_;
  bool modal_;
  void* app_;

  Dialog(Ini_ i, Ini_ u, H_ h, bool m, void* a)
  : init_(i), uninit_(i), handler_(h), modal_(m), app_(a) {}

  void init__(HWND hw);
  void uninit__();
  void destroyWindow__();


 public:
  ~Dialog() { deleting__(); }

  static int doModal(int rid, Ini_ ini, Ini_ ui, H_ hnd, void* app =nullptr);

  static urania::Dialog* doModeless(
    int rid, Ini_ ini, Ini_ ui, H_ hnd, void* app =nullptr);

  static int doOwnedModal(
    int rid, urania::WndBase* par, Ini_ ini, Ini_ ui, H_ hnd,
    void* app =nullptr);

  static urania::Dialog* doOwnedModeless(
    int rid, urania::WndBase* par, Ini_ ini, Ini_ ui, H_ hnd,
    void* app =nullptr);

  void endModal(int i);

  /**
   * @brief 作成時に設定されたポインタを返す
   * @return 作成時に設定されたポインタ(void*)。
   */
  void* getAppData() { return app_; }

 protected:
  virtual BOOL dproc__(UINT msg, WPARAM wp, LPARAM lp);
  static BOOL CALLBACK dlgproc__(HWND hw, UINT msg, WPARAM wp, LPARAM lp);
};



#endif
//eof
