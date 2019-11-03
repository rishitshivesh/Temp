

	  
	#ifndef BUTTON_CPP
	#define BUTTON_CPP 
	
	#include <button.h>
	#include <graphics.h>
	#include <string.h>

Button::Button(int left, int top, int width, int height, char caption[], int Id)
    {
	Left = left;
	Top = top;
	Width = width;
	Height = height;
	strcpy(Caption,caption);
	ID = Id;
	btnStatus = BUTTON_STATUS_NORMAL;
	State = false;
    }				


    void Button::Draw()
   {
	setfillstyle(SOLID_FILL,BLACK);
	bar(Left,Top,Left+Width,Top+Height);

	setcolor(WHITE);
	line(Left,Top,Left+Width,Top);
	line(Left,Top,Left,Top+Height);

	setcolor(BLACK);
	line(Left+Width,Top,Left+Width,Top+Height);
	line(Left,Top+Height,Left+Width,Top+Height);

	settextjustify(LEFT_TEXT,TOP_TEXT);
	setcolor(YELLOW);
	outtextxy(Left + (Width/2) - textwidth(Caption)/2 + 1,
	Top + (Height/2) - textheight(Caption)/2 + 1, Caption);
	
	

   }

   void Button::MouseDown()
   {




				mouse.HideMouse();

				setcolor(BLACK);
				line(Left,Top,Left+Width,Top);
				line(Left,Top,Left,Top+Height);

				setcolor(WHITE);
				line(Left+Width,Top,Left+Width,Top+Height);
				line(Left,Top+Height,Left+Width,Top+Height);

				mouse.ShowMouse();




   }

   void Button::MouseUp()
   {



					mouse.HideMouse();

					setcolor(WHITE);
					line(Left,Top,Left+Width,Top);
					line(Left,Top,Left,Top+Height);

					setcolor(BLACK);
					line(Left+Width,Top,Left+Width,Top+Height);
					line(Left,Top+Height,Left+Width,Top+Height);

					mouse.ShowMouse();






   }

	char *Button::GetText()
	{
		return Caption;
	}

   void Button::EnableClickHandler()
   {

		if(IsComboClick || IsMenuClick)return;

		if(State)
		{
			ButtonId = 0;
			State = false;
			return;
		}
	
		if(mouse.MouseInside(Left,Top,Left+Width,Top+Height) == 1)
		{

			if(mouse.GetButton() == MOUSE_LBUTTON)
			{
				MouseDown();
				btnStatus = BUTTON_STATUS_DOWN;
			}

			else if(btnStatus == BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL) 
			{
				MouseUp();
				ButtonId = ID;
				btnStatus = BUTTON_STATUS_NORMAL;
				State = true;
				
			}

		}

	}
	
	


   #endif //BUTTON_CPP
   
		


















	

 
