
# include "globals.h"


/*****************************************************************/
/***********																					************/
/***********               WM_COMMAND                 ************/
/***********																					************/
/*****************************************************************/

void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT CodeNotify)
{

  TCHAR	 msgbuf[2048], cop01[64], cop02[64];
  TCHAR  *bm_path = _TEXT("test.bmp");  
  HWND   hwndGetById;
  HDC  hDc;  

  switch(id)
  {
     case IDBT_SAVE_BMP :
     {
       writeBMPintoFile(pcvdt);
       break ;      
     } //case IDBT_SAVE_BMP
///*****************************************************************************

     case IDBT_CAPTURE :
     {
        CaptureCamFrame(pcvdt);
        MakeBMPfromIplImage(pcvdt);
        break ;      
     } 
///*****************************************************************************
 
///****************************************************************************  

    case IDM_EXIT:
      cvReleaseCapture(&cvdt.capture);
      if(NULL != cvdt.hbFrame) 
         DeleteObject(cvdt.hbFrame);
      if(NULL != hbStaticPic) 
         DeleteObject(hbStaticPic);
           
///        ini_write(pic_x86);

      PostQuitMessage(0);     
      break ; 
          
   case IDM_ABOUT:        
               
        break ;      
     } //    switch (id))  { 

} //void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT CodeNotify){
   


