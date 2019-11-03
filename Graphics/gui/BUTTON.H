


	  
	#ifndef __BUTTON_H
	#define __BUTTON_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H

	
	enum BUTTON_STATUS
	{
		 BUTTON_STATUS_NORMAL,
		 BUTTON_STATUS_DOWN
	};	


  class Button
  {

	private:

	int Left,Top,Width,Height,ID;
	char Caption[50];
	BUTTON_STATUS btnStatus;
	void MouseDown();
	void MouseUp();
	bool State;

	public:
	
	Button(int left, int top, int width, int height, char caption[], int Id);
	void Draw();
	char *GetText();
	void EnableClickHandler();	
	
  }; 	
      
  #endif //__BUTTON_H  			


















	

 
