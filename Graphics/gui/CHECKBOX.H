


	  
	#ifndef __CHECKBOX_H
	#define __CHECKBOX_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H

	
	#define CHECK_BOX_HEIGHT 10
	#define CHECK_BOX_WIDTH 10
	
	
	enum CHECKBOX_STATUS
	{
		 CHECKBOX_STATUS_NORMAL,
		 CHECKBOX_STATUS_DOWN
	};

  class CheckBox
  {

	private:

	int Left,Top,Width,Height;
	char Caption[50];
	int Alignment;
	CHECKBOX_STATUS chkStatus;
	bool State;
	bool hide;
	
	public:
	
	CheckBox(int left, int top, int width, int height, char caption[], int Align, bool state);
	void Draw();
	void EnableClickHandler();	
	bool IsChecked();
	void Checked();
	void UnChecked();
	void Hide();
	void Show();
	void SetText(char text[]);
	char *GetText();
	void Clear();
  }; 	
      
  #endif //__CHECKBOX_H  			


















	

 
