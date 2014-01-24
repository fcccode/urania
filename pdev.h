/**************************************************************************
 *
 *  pdev.h
 *  by oZ/acy
 *  (C) 2002-2011 oZ/acy.  ALL RIGHTS RESERVED.
 *
 *  Paint DEVice
 *  Windows DC �`�`�p�N���X
 *
 *  last update : 2011.9.8
 *
 *************************************************************************/
#ifndef INC_URANIA_PAINTDEVICE_H___
#define INC_URANIA_PAINTDEVICE_H___

#include <windows.h>
#include <themis/inttype.h>
#include <polymnia/picture.h>

namespace urania
{
  //-------------------------------
  //  Color
  //  Windows�pBGR�J���[�\����
  //-------------------------------
  class Color
  {
  public:
    themis::UByte b;
    themis::UByte g;
    themis::UByte r;

  public:
    Color() : r(0),g(0),b(0) {}
    Color(themis::UByte rr, themis::UByte gg, themis::UByte bb)
      : r(rr),g(gg),b(bb) {}
    Color(const polymnia::RgbColor& org) : r(org.r),g(org.g),b(org.b) {}

    explicit Color(COLORREF cr)
    {
      r = GetRValue(cr);
      g = GetGValue(cr);
      b = GetBValue(cr);
    }

    Color& operator=(const polymnia::RgbColor& org)
    {
      r = org.r;
      g = org.g;
      b = org.b;
      return *this;
    }

    COLORREF getColorref() const
    {
      return (themis::UDWord)r|((themis::UDWord)g<<8)|((themis::UDWord)b<<16);
    }

    operator polymnia::RgbColor() const { return polymnia::RgbColor(r,g,b); }
  };


  // class�錾
  class PaintDevice;
  class PaintMemDevice;
  class PaintMemDeviceIndexed;

}//end of namespace urania



/*=====================================================
 *  PaintMemDevice
 *  PaintDevice�݊��������㉼�z�f�o�C�X(24bit color)
 */
class urania::PaintMemDevice : public polymnia::ImageBuffer<urania::Color>
{
  friend class urania::PaintDevice;

private:
  typedef urania::PaintMemDevice* PP_;
  typedef urania::Color C_;

protected:
  HDC hdc_;
  HBITMAP oldbmp_;


protected:
  PaintMemDevice(unsigned ww, unsigned hh);

public:
  ~PaintMemDevice();

  static PP_ create(unsigned w, unsigned h) throw();
  static PP_ create(const polymnia::Picture* pct);

  polymnia::Picture* createPicture() const;
  PP_ clone() const;
};



/*===============================================================
 *  PaintMemDeviceIndexed
 *  PaintDevice�݊��������㉼�z�f�o�C�X(256 palette color)
 */
class urania::PaintMemDeviceIndexed
  : public polymnia::ImageBuffer<themis::UByte>
{
  friend class urania::PaintDevice;

private:
  typedef PaintMemDeviceIndexed* PP_;
  typedef urania::Color C_;

protected:
  HDC hdc_;
  C_ pal_[256];
  HPALETTE hpal_;
  HBITMAP oldbmp_;
  polymnia::RgbColor oldpal_[256];

  PaintMemDeviceIndexed(unsigned ww, unsigned hh);

 public:
  ~PaintMemDeviceIndexed();

  static PP_ create(unsigned w, unsigned h) throw();
  static PP_ create(const polymnia::PictureIndexed* pct);

  polymnia::PictureIndexed* createPicture() const;
  PP_ clone() const;

  C_& palette(int id) { return pal_[id]; }
  const C_& palette(int id) const { return pal_[id]; }
  C_* paletteBuffer() { return pal_; }
  const C_* paletteBuffer() const { return pal_; }

  void updatePalette();
};



/*================================================
 *  PaintDevice
 *  Windows �f�o�C�X�R���e�L�X�g�̃��b�p�[
 */
class urania::PaintDevice : boost::noncopyable
{
public:
  typedef urania::PaintDevice* PP_;
  typedef urania::Color C_;
  typedef void (*DestProc)(HDC, void*);

protected:
  HDC hdc_;
  int width_, height_;

  HBRUSH obr_;
  HPEN   opn_;
  HFONT  oft_;
  int    obm_;

  void* app_;
  DestProc dst_;


protected:
  PaintDevice(HDC dc, DestProc dp, void* a, int w, int h);

public:
  ~PaintDevice();


  //=============================================================
  //  static create()
  //  Object����
  //   ����:  HDC dc      : �f�o�C�X�R���e�L�X�g�n���h��
  //          DestProc dp : DC����p�R�[���o�b�N(�s�v�Ȃ�nullptr)
  //          void* a     : �R�[���o�b�N�ɓn���p�����[�^
  //          unsigned w  : �f�o�C�X��
  //          unsigned h  : �f�o�C�X����
  //   �Ԓl:  �I�u�W�F�N�g�̃X�}�[�g�|�C���^(RCPtr)
  //=============================================================
  static PP_ create(HDC dc, DestProc dp, void* a, int w, int h) throw();


  //========================================================
  //  clear()
  //  �`�`�̈�̑S�h��ׂ�(�N���A)
  //   ���� : const Color_PD& col : �h��ׂ��F
  //========================================================
  void clear(const C_& col);


  //====================================
  //  dotset()
  //  �y��`�`
  //   ����  x,y : ���W
  //         col : �`�`�F
  //====================================
  void dotset(int x, int y, const C_& col);


  //==================================================================
  //  line()
  //  ������`�`
  //   ����  x1, y1, x2, y2 : ���W (x1, y1)-(x2, y2)�Ԃɒ���������
  //         col            : �`�`�F
  //==================================================================
  void line(int x1, int y1, int x2, int y2, const C_& col);


  //=============================================================
  //  box()
  //  �����`��`�`
  //   ����  x1, y1, x2, y2 : ���p���_�̍��W (x1, y1), (x2, y2)
  //         col            : �`�`�F
  //         f              : true�œh��ׂ��Afalse�Řg���̂�
  //=============================================================
  void box(int x1, int y1, int x2, int y2, const C_& col, bool f =false);


  //===================================================
  //  ellipse()
  //  �ȉ~��`�`
  //   ����  x,y : ���S���W
  //         a,b : x���a�y��y���a
  //         col : �`�`�F
  //         f   : true�œh��ׂ��Afalse�Řg���̂�
  //===================================================
  void ellipse(int x, int y, int a, int b, const C_& col, bool f =false);


  //===================================================
  //  circle()
  //  �~��`�`
  //   ����  x,y : ���S���W
  //         r   : ���a
  //         col : �`�`�F
  //         f   : true�œh��ׂ��Afalse�Řg���̂�
  //===================================================
  void circle(int x, int y, int r, const C_& col, bool f =false)
  {
    ellipse(x,y,r,r,col,f);
  }



  //===================================================
  //  text()
  //  �e�L�X�g��`�`
  //   ����  x,y : ����p���W
  //         str : �`�`���镶����
  //         col : ���̐F
  //   �Ԓl  �`�`�����`�̉E���p���W
  //===================================================
  polymnia::Point text(int x, int y, const std::wstring& str, const C_& col);


  //==============================================
  //  text()
  //  �e�L�X�g��`�` (���w��o�[�W����)
  //   ����  x,y : ����p���W
  //         w   : ��
  //         str : �`�`���镶����
  //         col : ���̐F
  //   �Ԓl  �`�`�����`�̉E���p���W
  //==============================================
  polymnia::Point
  text(int x, int y, int w, const std::wstring& str, const C_& col);


  //==================================================================
  //  changeFont()
  //  �t�H���g�̕ύX
  //   ����  size : �t�H���g�T�C�Y
  //         fn   : �t�H���g��(L""���\�A���̂Ƃ��̓f�t�H���g)
  //         ro   : true�Ȃ烍�}�[���^�C�v(��Ƀf�t�H���g���ɉe��)
  //         fx   : true�Ȃ瓙���t�H���g�Afalse�Ȃ�v���|�[�V���i��
  //         bo   : true�Ȃ�{�[���h��
  //         itl  : true�Ȃ�Α�
  //         ul   : true�Ȃ牺���t��
  //         sk   : true�Ȃ�ł��������t��
  //==================================================================
  void
  changeFont(
    int size, const std::wstring& fn, bool ro, bool fx,
    bool bo, bool itl, bool ul, bool sk);


  //===============================
  //  width(), height()
  //  �`�`�̈�̕��ƍ����̎擾
  //===============================
  int width() const { return width_; }
  int height() const { return height_; }


  //==============================================
  //  blt()  �~ 4
  //  �`�`���e���z��
  //
  //   ����  dx, dy  : �z�����ۍ���p���W
  //         src     : �z����Object
  //         sx, sy  : �z��������p���W
  //         w, h    : �z�����E����
  //         mask    : �z�����ۂ��z���\�̈�
  //==============================================
  void blt(
    int dx, int dy, const urania::PaintMemDevice* src, int sx, int sy,
    int w, int h);

  void blt(
    int dx, int dy, const urania::PaintMemDevice* src, int sx, int sy,
    int w, int h, const polymnia::Rect& mask);

  void blt(
    int dx, int dy, urania::PaintMemDeviceIndexed* src,
    int sx, int sy, int w, int h);

  void blt(
    int dx, int dy, urania::PaintMemDeviceIndexed* src,
    int sx, int sy, int w, int h, const polymnia::Rect& mask);


  //===================================================
  //  blt()  �~ 2
  //  �`�`���e���z���A�A������k�������őS�̈擯�m
  //
  //   ����  src    : �]����Object
  //===================================================
  void blt(const urania::PaintMemDevice* src);
  void blt(urania::PaintMemDeviceIndexed* src);


  //=============================================================
  //  static getSysColor()
  //  �V�X�e���J���[�擾
  //   ���� : int id : �V�X�e���J���[��ID (dec.h�Œ�`)
  //   �Ԓl : �w�肵���V�X�e���J���[�̐F
  //=============================================================
  static C_ getSysColor(int id);


  //=======================================================================
  //  static setSysColor()
  //  �V�X�e���J���[�ݒ�
  //   ���� : int id                   : �V�X�e���J���[ID (dec.h�Œ�`)
  //          const urania::Color& col : �ݒ肷��F
  //=======================================================================
  static void setSysColor(int id, const C_& col);


private:
  void changeBrush__(const C_& col);
  void changePen__(const C_& col);
};



#endif
//eof
