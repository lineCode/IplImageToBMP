#ifndef _CV_DATA_H
#define _CV_DATA_H


typedef union WBBUNI
{  //WordByteByteUnion
  unsigned short int	word;
  struct
  {
    unsigned char Lo;
    unsigned char Hi;
  } bytes;
} WBBUNI, *PWBBUNI;

typedef struct CVDT
{  //
  CvCapture*    capture;
  IplImage*     frame;
  HBITMAP       hbFrame;
  HDC           memDc;
  BITMAP        bm;
  BITMAPINFO    bmi;
///  BYTE        *picv;
  unsigned char *picv;
  HWND          hwnd;
} CVDT, *PCVDT;

#endif
