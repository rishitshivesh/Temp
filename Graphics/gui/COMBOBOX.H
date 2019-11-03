



	#ifndef __COMBOBOX_H
	#define __COMBOBOX_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H

	enum COMBO_BUTTON_STATUS
	{
		 COMBO_BUTTON_STATUS_NORMAL,
		 COMBO_BUTTON_STATUS_DOWN
	};



  class ComboBox
  {

	private:

	int Left,Top,Width,Height,Items;
	unsigned char Caption[250];
	char ComboText[50];
	char cap[50];
	bool bReadOnly;
	bool Click;
	COMBO_BUTTON_STATUS btnStatus;
	Label *pComboLabel[30];
	
	int _i, _j;
	
	
	TextBox *pComboTxt;

	
	void DrawItems();
	void HideItems();
	
	
	public:
	
	ComboBox(int left, int top, int width, int height, char *combotext,char *caption);
	void Draw();
	void EnableClickHandler();
	void SetText(char text[]);
	char *GetText();
	void Clear();
	void SetReadOnly(bool ReadOnly);
	void AddText(char text[]);
  }; 	
      
  #endif //__COMBOBOX_H  