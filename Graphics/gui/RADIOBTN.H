


	  
	#ifndef __RADIOBTN_H
	#define __RADIOBTN_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H
	
	
	#define RADIO_BUTTON_RADIUS 8
	#define MOUSE_RADIUS 2

	
	
	enum RADIO_BUTTON_STATUS
	{
		 RADIO_BUTTON_STATUS_NORMAL,
		 RADIO_BUTTON_STATUS_DOWN
	};

  class RadioButton
  {

	private:

	int Left,Top,Width,Height,ID;
	char Caption[50];
	int Alignment;
	RADIO_BUTTON_STATUS radioBtnStatus;
	bool State;
	
	void Enable();
	void Disable();
	bool IsMouseInside(int R_Xpos,int R_Ypos,int M_Xpos,int M_Ypos);

	public:

	RadioButton(int left, int top, int width, int height, char caption[], int Align,int ID);
	void Draw();
	void EnableClickHandler();
	void EnableRadioButton();
	void DisableRadioButton();
	void SetText(char text[]);
	char *GetText();
	void Clear();
  };
      
  #endif //__RADIOBTN_H  			


















	

 
