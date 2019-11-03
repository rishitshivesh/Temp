



	#ifndef COMBOBOX_CPP
	#define COMBOBOX_CPP

	#include <combobox.h>
	#include <string.h>
	#include <graphics.h>
	#include <stdio.h>


	ComboBox::ComboBox(int left, int top, int width, int height, char *combotext,char *caption)
	{
		Left = left;
		Top = top;
		Width = width;
		Height = height;
		Click = false;
		strcpy(Caption,caption);
		strcpy(ComboText,combotext);
		bReadOnly = false;
		btnStatus = COMBO_BUTTON_STATUS_NORMAL;
		_i = 0;
		_j = 0;
		
		while (_i < strlen(Caption))
		{
			if(Caption[_i] == 44)
			_j++;

			_i++;
		}

		if(_j > 0)	
		Items = _j+1;
		else
		{
			if(strlen(Caption) > 0)
			Items = 1;
			else
			Items = 0;
		}	
	}


	void ComboBox::Draw()
	{
		pComboTxt = new TextBox(Left, Top, Width, Height, ComboText,LEFT_TEXT, 9809);
		pComboTxt->Draw();

		setfillstyle(SOLID_FILL,WHITE);
		bar(Left+Width,Top,Left+Width+12,Top+Height);
		setcolor(DARKGRAY);
		rectangle(Left+Width,Top,Left+Width+12,Top+Height);
		setcolor(WHITE);
		line(Left+Width,Top+1,Left+Width,Top+Height-1);

		
		setcolor(BLACK);
		outtextxy(Left+Width+2,Top+(Height/2)-(textheight("")/2)+1,"");
		
	}
	

	void ComboBox::DrawItems()
	{

		if(Items == 0)return;
		
		int l=0,m=0;
		int i=0;
		int x = Left, y = Top+Height;


		while(l < strlen(Caption))
		{
			if(Caption[l] == 44)
			{
				pComboLabel[i] = new Label(x,y+1,Width+12,Height,cap,CENTER_TEXT,WHITE,BLACK,i+1);
				pComboLabel[i]->Draw();
				for(int s=0; s<=m; s++)
				cap[s] = 0;
				m=0;
				l++;
				i++;
				y += Height;
			}

			cap[m] = Caption[l];

			l++;
			m++;
		}
		pComboLabel[i] = new Label(x,y+1,Width+12,Height,cap,CENTER_TEXT,WHITE,BLACK,i+1);
		pComboLabel[i]->Draw();

	}


	void ComboBox::HideItems()
	{
	    if(Items == 0)return;
		int i=0;
		
		do {
		
			delete pComboLabel[i];
			
			i++;
			
		}while(i < Items);
				
	}
	
	void ComboBox::AddText(char text[])
	{
	
		int i = 0;
		int j = 0;
		
		while (i < strlen(text))
		{
			if(text[i] == 44)
			j++;

			i++;
		}
	
		if(Items > 0 && strlen(text) > 0)
		{
			strcat(Caption,",");
			strcat(Caption,text);
		}
		else if(Items == 0 && strlen(text) > 0)
		strcpy(Caption,text);

		if(j > 0)
		Items += j+1;
		else
		{
			if(strlen(text) > 0)
			Items += 1;
			else
			{
			}

		}	
		
		
	}
	
	void ComboBox::SetText(char text[])
	{
		pComboTxt->Clear();
		pComboTxt->SetText(text);
	}
	char *ComboBox::GetText()
	{
		return pComboTxt->GetText();
	}
	void ComboBox::Clear()
	{
		pComboTxt->Clear();
	}
	void ComboBox::SetReadOnly(bool ReadOnly)
	{
		bReadOnly = ReadOnly;
	}
	void ComboBox::EnableClickHandler()
	{
		if(IsMenuClick)return;

		if(!bReadOnly)
		{
		  pComboTxt->EnableClickHandler();
		  setcolor(WHITE);
		  line(Left+Width,Top+1,Left+Width,Top+Height-1);
		}


		if(mouse.MouseInside(Left+Width,Top,Left+Width+12,Top+Height) == 1)
		{

			if(mouse.GetButton() == MOUSE_LBUTTON)
			{
				btnStatus = COMBO_BUTTON_STATUS_DOWN;
			}

			else if(btnStatus == COMBO_BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL && Click == false && IsComboClick == false)
			{
					btnStatus = COMBO_BUTTON_STATUS_NORMAL;
					mouse.HideMouse();
					getimage(Left,Top+Height,Left+Width+12,Top+1+(Items+1)*Height,buffer);
					DrawItems();
					mouse.ShowMouse();
					Click = true;
					IsComboClick = true;


			}

			else if(btnStatus == COMBO_BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL && Click == true)
			{
					btnStatus = COMBO_BUTTON_STATUS_NORMAL;
					mouse.HideMouse();
					HideItems();
					flushall();
					putimage(Left,Top+Height,buffer,COPY_PUT);
					mouse.ShowMouse();
					Click = false;
					IsComboClick = false;

			}
		}

		if(mouse.MouseInside(Left+Width,Top,Left+Width+12,Top+Height) != 1 && mouse.MouseInside(Left,Top+Height,Left+Width+12,Top+1+(Items+1)*Height) != 1 && Click == true && IsComboClick == true)
		{

			if(mouse.GetButton() == MOUSE_LBUTTON)
			{
				btnStatus = COMBO_BUTTON_STATUS_DOWN;
			}

			else if(btnStatus == COMBO_BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL )
			{
					
					btnStatus = COMBO_BUTTON_STATUS_NORMAL;
					mouse.HideMouse();
					HideItems();
					flushall();
					putimage(Left,Top+Height,buffer,COPY_PUT);
					mouse.ShowMouse();
					Click = false;
					IsComboClick = false;

			}
        }
		
		
				if(Click)
				{
						for(int i=0;i<Items;i++)
							pComboLabel[i]->EnableClickHandler(CYAN,BLACK,WHITE,BLACK);

						if(LabelId !=0)
						{

							pComboTxt->Clear();
							pComboTxt->SetText(pComboLabel[LabelId-1]->GetText());
							mouse.HideMouse();
							HideItems();
							flushall();
							putimage(Left,Top+Height,buffer,COPY_PUT);
							mouse.ShowMouse();
							Click = false;
							IsComboClick = false;
							LabelId = 0;



						}


				}

	}


  #endif // COMBOBOX_CPP