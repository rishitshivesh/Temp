


	  
	#ifndef __MSGBOX_H
	#define __MSGBOX_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H
	

  class MsgBox
  {

	private:
	
	int Left,Top,Width,Height;
	int MsgBtnType;
	int MsgIcon;
	char Caption[50];
	Button *MsgCloseBtn;
	Button *MsgBtn[3];
	TextBox *pInputBox;
	void SSLogo();
	void CriticalIcon(int left, int top);
	void QuestionIcon(int left, int top);			
	void ExclamationIcon(int left, int top);
	void InformationIcon(int left, int top);       
	void AboutIcon(int left, int top);
	int TotalLines(int x, int y, int width, char *str);
	void WriteMessage(int x, int y, int width, int fontColor, char *str);
	public:
	
	int MessageBox(int left, int top, char *title, char *msgtext, int fontColor, int btntype, int icon);
	char *InputBox(int left, int top, char *title, char *msgtext, int fontColor);
	
  }; 	
      
  #endif //__MSGBOX_H  			


















	

 
