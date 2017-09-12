
#include "globals.h"


/***************************************************************************/ 
 int  _duc(double d)
{ 

  UINT		  convcount;
  int		  subbuf;
  double		realbuf;
  int		  decimal, sign;
  char		  *fromsrc, buf[8], msgbuf[256];

  realbuf = fabs(d);
  fromsrc = _ecvt(realbuf, 8, &decimal, &sign);

  convcount = 0;
  while(convcount < decimal)
  {
	  buf[convcount] = *fromsrc;
      convcount++;
      fromsrc++;
  }
  buf[convcount] = '\0';
  subbuf = atoi(buf);

  return subbuf;
}

/***************************************************************************/

void  SetTimeString(TCHAR* timebuf, size_t sz, size_t f)
{
  SYSTEMTIME time;
  UINT       yy, mn, dd, hh, mm, ss;
  TCHAR      tb[8];
  size_t     tbsz = 8;

///  tb = new TCHAR[sz/2];

  GetLocalTime(&time);
  switch(f){
    case 0: 
      if(time.wHour<10)  
        swprintf(timebuf, sz, _TEXT("0%u:"), time.wHour);
        else 
          swprintf(timebuf, sz, _TEXT("%u:"), time.wHour);
    
      if(time.wMinute<10)  
        swprintf(tb, tbsz, _TEXT("0%u:"), time.wMinute);
        else 
          swprintf(tb, tbsz, _TEXT("%u:"), time.wMinute);

      wcscat(timebuf, tb);

      if(time.wSecond<10) 
        swprintf(tb, tbsz, _TEXT("0%u"), time.wSecond);
        else 
          swprintf(tb, tbsz, _TEXT("%u"), time.wSecond);
   
      wcscat(timebuf, tb);
      break;

    case 1:
      swprintf(timebuf, sz, _TEXT("%u-"), time.wYear);

      if(time.wMonth<10)  
        swprintf(tb, tbsz, _TEXT("0%u-"), time.wMonth);
        else 
          swprintf(tb, tbsz, _TEXT("%u-"), time.wMonth);

      wcscat(timebuf, tb);

      if(time.wDay<10)  
        swprintf(tb, tbsz, _TEXT("0%u-"), time.wDay);
        else 
          swprintf(tb, tbsz, _TEXT("%u-"), time.wDay);

      wcscat(timebuf, tb);
 
      if(time.wHour<10)  
        swprintf(tb, tbsz, _TEXT("0%u-"), time.wHour);
        else 
          swprintf(tb, tbsz, _TEXT("%u-"), time.wHour);

      wcscat(timebuf, tb);
    
      if(time.wMinute<10)  
        swprintf(tb, tbsz, _TEXT("0%u-"), time.wMinute);
        else 
          swprintf(tb, tbsz, _TEXT("%u-"), time.wMinute);

      wcscat(timebuf, tb);

      if(time.wSecond<10) 
        swprintf(tb, tbsz, _TEXT("0%u"), time.wSecond);
        else 
          swprintf(tb, tbsz, _TEXT("%u"), time.wSecond);
   
      wcscat(timebuf, tb);
      break;

  } /// switch(f)
}

