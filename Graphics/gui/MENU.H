


	#ifndef __MENU_H
	#define __MENU_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H

	enum MENU_BUTTON_STATUS
	{
		 MENU_BUTTON_STATUS_NORMAL,
		 MENU_BUTTON_STATUS_DOWN
	};


  class Menu
  {

	private:

	int Left,Top,Width,Height,Items,MenuItemWidth;
	int ID;
	long int totalWidth,maxWidth;
	unsigned char Caption[250];
	char MenuText[50];
	char cap[50];
	bool Click;
	bool State;
	bool IsMousePointerInside;
	MENU_BUTTON_STATUS btnStatus;
	Label *pMenuButton[30];
	Label *pMenu;
	
	int _i, _j;
	

	
	void DrawItems();
	void HideItems();
	void MouseDown();
	void MouseUp();
	
	
	public:
	
	Menu(char *menutext,char *caption);
	void Draw();
	void EnableClickHandler();
  }; 	
      
  #endif //__MENU_H  