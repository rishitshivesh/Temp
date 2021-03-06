

	  
	#ifndef __LABEL_H
	#define __LABEL_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H

	#include <graphics.h>

	
	enum LABEL_BUTTON_STATUS
	{
		 LABEL_BUTTON_STATUS_NORMAL,
		 LABEL_BUTTON_STATUS_DOWN
	};	

	
	
  class Label
  {

	private:
	
	int Left,Top,Width,Height;
	char Caption[50];
	int Bgcolor,Fgcolor,ID;
	int Alignment;
	bool State;
	bool Click;
	LABEL_BUTTON_STATUS btnStatus;
	
	public:
	
	Label(int left, int top, int width, int height, char caption[], int Align, int bgcolor , int fgcolor, int Id );
	void Draw();
	void EnableClickHandler(int bgcolor1 ,int fgcolor1 , int bgcolor2 , int fgcolor2 );	
	void SetText(char text[]);
	char *GetText();
	void Clear();
	
  }; 	
      
  #endif //__LABEL_H  			


















	

 
