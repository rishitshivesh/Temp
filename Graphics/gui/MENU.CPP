



	#ifndef MENU_CPP
	#define MENU_CPP

	#include <menu.h>
	#include <string.h>
	#include <graphics.h>
	#include <stdio.h>


	Menu::Menu(char *menutext,char *caption)
	{
		ID = NumberOfMenus+2;
		Click = false;
		State=false;
		totalWidth=0;
		maxWidth=0;
		IsMousePointerInside=false;
		strcpy(Caption,caption);
		strcpy(MenuText,menutext);
		NumberOfMenus++;
		
		settextstyle(SMALL_FONT,0,0);
		
		MenuWidth[NumberOfMenus]=textwidth(MenuText)+2;
		Width = textwidth(MenuText)+3;
		btnStatus = MENU_BUTTON_STATUS_NORMAL;
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

		for(int w=0;w<NumberOfMenus;w++)
		{
			totalWidth+=MenuWidth[w];
		}

		
			Left = WindowLeft+totalWidth+1+NumberOfMenus*5;

		Top = WindowTop+TITLEBARHEIGHT+2;
		Height =TITLEBARHEIGHT;

		int maxlen=0;
		for(int mx=0;mx<strlen(Caption);mx++)
		{
			if(Caption[mx]==44)
			{
				if(maxlen>maxWidth)
					maxWidth=maxlen;
				maxlen=0;

			}
			maxlen++;
		}
		if(maxlen>maxWidth)
			maxWidth=maxlen;

		MenuItemWidth=textwidth(MenuText)+maxWidth*textwidth("H")+4;
		
		settextstyle(0,0,0);

	}


	void Menu::Draw()
	{

		if(IsMenuBarCreated==false)
		{
			setcolor(DARKGRAY);
			line(WindowLeft+2,WindowTop+2*Height+2,WindowLeft+WindowWidth-2,WindowTop+2*Height+2);
			setcolor(WHITE);
			line(WindowLeft+2,WindowTop+2*Height+3,WindowLeft+WindowWidth-2,WindowTop+2*Height+3);

			IsMenuBarCreated=true;
		}

		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(Left+3,Top+1,Left+Width+1,Top+Height-2);
		settextjustify(LEFT_TEXT,TOP_TEXT);
		settextstyle(SMALL_FONT,0,0);
		setcolor(BLACK);
		outtextxy(Left+5,Top+((Height/2)-(textheight(MenuText)/2))-2,MenuText);
		settextstyle(0,0,0);
	}
	
	void Menu::MouseDown()
   {
		mouse.HideMouse();
		setcolor(DARKGRAY);
		line(Left+3,Top+1,Left+Width+2,Top+1);
		line(Left+3,Top+1,Left+3,Top+Height-2);

		setcolor(WHITE);
		line(Left+Width+2,Top+1,Left+Width+2,Top+Height-2);
		line(Left+3,Top+Height-2,Left+Width+2,Top+Height-2);
		mouse.ShowMouse();

   }

   void Menu::MouseUp()
   {
		mouse.HideMouse();
		setcolor(LIGHTGRAY);
		line(Left+3,Top+1,Left+Width+2,Top+1);
		line(Left+3,Top+1,Left+3,Top+Height-2);

		line(Left+Width+2,Top+1,Left+Width+2,Top+Height-2);
		line(Left+3,Top+Height-2,Left+Width+2,Top+Height-2);
		mouse.ShowMouse();

   }
	

	void Menu::DrawItems()
	{

		if(Items == 0)return;
		
		int l=0,m=0;
		int i=0;
		int x = Left+7, y = Top+Height+7;
		
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(Left+3,Top+Height+3,Left+MenuItemWidth+22,Top+10+(Items+1)*Height);
		
		setcolor(WHITE);
		line(Left+3,Top+Height+3,Left+MenuItemWidth+22,Top+Height+3);
		line(Left+3,Top+Height+3,Left+3,Top+10+(Items+1)*Height);
		
		setcolor(BLACK);
		line(Left+MenuItemWidth+22,Top+Height+3,Left+MenuItemWidth+22,Top+10+(Items+1)*Height);
		line(Left+3,Top+10+(Items+1)*Height,Left+MenuItemWidth+22,Top+10+(Items+1)*Height);
		
		setcolor(DARKGRAY);
		line(Left+MenuItemWidth+22-1,Top+Height+3+1,Left+MenuItemWidth+22-1,Top+10+(Items+1)*Height-1);
		line(Left+3+1,Top+10+(Items+1)*Height-1,Left+MenuItemWidth+22-1,Top+10+(Items+1)*Height-1);
		
		setcolor(WHITE);
		line(Left+3+2,Top+Height+3+2,Left+MenuItemWidth+22-2,Top+Height+3+2);
		line(Left+3+2,Top+Height+3+2,Left+3+2,Top+10+(Items+1)*Height-2);


		while(l < strlen(Caption))
		{
			if(Caption[l] == 44)
			{
				
				pMenuButton[i] = new Label(x,y+1,MenuItemWidth+12,Height,cap,LEFT_TEXT,LIGHTGRAY,BLACK,i+1);
				pMenuButton[i]->Draw();
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
		
		pMenuButton[i] = new Label(x,y+1,MenuItemWidth+12,Height,cap,LEFT_TEXT,LIGHTGRAY,BLACK,i+1);
		pMenuButton[i]->Draw();
		

	}


	void Menu::HideItems()
	{
	    if(Items == 0)return;
		int i=0;
		
		do {

			delete pMenuButton[i];

			i++;

		}while(i < Items);

	}


	void Menu::EnableClickHandler()
	{
		if(IsComboClick)return;

		if(State)
		{
			State=false;
			MenuId=0;
			MenuItemId=0;
			return;
		}


		if(mouse.MouseInside(Left+3,Top+1,Left+Width+1,Top+Height-2) == 1)
		{
			if(IsMousePointerInside==false)
			{
				MouseDown();
				IsMousePointerInside=true;
			}

			if(mouse.GetButton() == MOUSE_LBUTTON)
			{
				btnStatus = MENU_BUTTON_STATUS_DOWN;
			}

			else if(btnStatus == MENU_BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL && Click == false && IsMenuClick == false)
			{
					btnStatus = MENU_BUTTON_STATUS_NORMAL;
					mouse.HideMouse();
					getimage(Left+3,Top+Height+3,Left+MenuItemWidth+22,Top+10+(Items+1)*Height,buffer);
					DrawItems();
					MouseDown();
					mouse.ShowMouse();
					Click = true;
					IsMenuClick = true;
					IsMousePointerInside=false;


			}

			else if(btnStatus == MENU_BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL && Click == true)
			{
					btnStatus = MENU_BUTTON_STATUS_NORMAL;
					mouse.HideMouse();
					HideItems();
					flushall();
					MouseDown();
					putimage(Left+3,Top+Height+3,buffer,COPY_PUT);
					mouse.ShowMouse();
					Click = false;
					IsMenuClick = false;
					MenuId=0;
					MenuItemId=0;

			}
		}

		else if(IsMousePointerInside && Click==false)
		{
			MouseUp();
			IsMousePointerInside=false;
		}
		if(mouse.MouseInside(Left+3,Top+1,Left+Width+1,Top+Height-2) != 1 && mouse.MouseInside(Left+7,Top+Height+7,Left+7+MenuItemWidth+13,Top+7+(Items+1)*Height) != 1 && Click == true && IsMenuClick == true)
		{

			if(mouse.GetButton() == MOUSE_LBUTTON)
			{
				btnStatus = MENU_BUTTON_STATUS_DOWN;
			}

			else if(btnStatus == MENU_BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL )
			{

					btnStatus = MENU_BUTTON_STATUS_NORMAL;
					mouse.HideMouse();
					HideItems();
					flushall();
					MouseUp();
					putimage(Left+3,Top+Height+3,buffer,COPY_PUT);
					mouse.ShowMouse();
					Click = false;
					IsMenuClick = false;
					MenuId=0;
					MenuItemId=0;

			}
	}


				if(Click)
				{
						for(int i=0;i<Items;i++)
							pMenuButton[i]->EnableClickHandler(CYAN,BLACK,LIGHTGRAY,BLACK);

						if(LabelId !=0)
						{
							mouse.HideMouse();
							HideItems();
							flushall();
							putimage(Left+3,Top+Height+3,buffer,COPY_PUT);
							mouse.ShowMouse();
							IsMenuClick = false;
							MenuItemId=LabelId;
							MenuId=ID;
							LabelId = 0;
							Click=false;
							State=true;

						}


				}

	}


  #endif // MENU_CPP