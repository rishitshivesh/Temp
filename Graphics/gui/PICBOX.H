
	#ifndef __PICBOX_H
	#define __PICBOX_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H
	
	enum PICTURE_BUTTON_STATUS
	{
		 PICTURE_BUTTON_STATUS_NORMAL,
		 PICTURE_BUTTON_STATUS_DOWN
	};	

  class PictureBox
  {

	private:

	int Left,Top,Width,Height,ID;
	char Path[70];
	Bitmap *pBitmap;
	PICTURE_BUTTON_STATUS btnStatus;
	void MouseDown();
	void MouseUp();
	bool State;

	void DrawFrame();
	public:
	
	PictureBox(int left, int top, int width, int height, char *path, int Id);
	void Draw();
	void EnableClickHandler();
	
  }; 	
  
  #endif //__PICBOX_H  		