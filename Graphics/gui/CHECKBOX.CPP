
	  
	#ifndef CHECKBOX_CPP
	#define CHECKBOX_CPP 
	
	#include <checkbox.h>
	#include <string.h>
	#include <graphics.h>


  
      
    CheckBox::CheckBox(int left, int top, int width, int height, char caption[],int Align, bool state)
    {
	 Left = left;
	 Top = top;
	 Width = width;
	 Height = height;
	 strcpy(Caption,caption);
	 Alignment = Align;
	 State = state;
	 hide = false;
	 chkStatus = CHECKBOX_STATUS_NORMAL;
    }				


    void CheckBox::Draw()
   {
	  int TopAlign = (Height/2) - (CHECK_BOX_HEIGHT/2);
	  int LeftAlign = 0;
	  
	  if(Alignment==RIGHT_TEXT)
		LeftAlign=Width-CHECK_BOX_WIDTH;

	  setfillstyle(SOLID_FILL,LIGHTGRAY);
	  bar(Left,Top,Left+Width,Top+Height);

      setfillstyle(SOLID_FILL,WHITE);
      bar(Left+LeftAlign+1,Top+TopAlign+1,Left+LeftAlign+CHECK_BOX_WIDTH,Top+TopAlign+CHECK_BOX_HEIGHT);

      setcolor(DARKGRAY);
      line(Left+LeftAlign,Top+TopAlign,Left+LeftAlign+CHECK_BOX_WIDTH,Top+TopAlign);
      line(Left+LeftAlign,Top+TopAlign,Left+LeftAlign,Top+TopAlign+CHECK_BOX_HEIGHT);

      setcolor(BLACK);
      line(Left+LeftAlign+1,Top+TopAlign+1,Left+LeftAlign+(CHECK_BOX_WIDTH-1),Top+TopAlign+1);
      line(Left+LeftAlign+1,Top+TopAlign+1,Left+LeftAlign+1,Top+TopAlign+(CHECK_BOX_HEIGHT-1));

      setcolor(LIGHTGRAY);
      line(Left+LeftAlign+(CHECK_BOX_WIDTH-1),Top+TopAlign+1,Left+LeftAlign+(CHECK_BOX_WIDTH-1),Top+TopAlign+(CHECK_BOX_HEIGHT-1));
      line(Left+LeftAlign+1,Top+TopAlign+(CHECK_BOX_HEIGHT-1),Left+LeftAlign+(CHECK_BOX_WIDTH-1),Top+TopAlign+(CHECK_BOX_HEIGHT-1));

      setcolor(WHITE);
      line(Left+LeftAlign,Top+TopAlign+CHECK_BOX_HEIGHT,Left+LeftAlign+CHECK_BOX_WIDTH,Top+TopAlign+CHECK_BOX_HEIGHT);
      line(Left+LeftAlign+CHECK_BOX_WIDTH,Top+TopAlign,Left+LeftAlign+CHECK_BOX_WIDTH,Top+TopAlign+CHECK_BOX_HEIGHT);

      setcolor(BLACK);
      if(Alignment==LEFT_TEXT)
      {
        settextjustify(LEFT_TEXT,CENTER_TEXT);
        outtextxy(Left+CHECK_BOX_WIDTH+3,Top+(Height/2)+1,Caption);
      }
     else
     {

	settextjustify(RIGHT_TEXT,CENTER_TEXT);
	outtextxy(Left+Width-(CHECK_BOX_WIDTH+3),Top+(Height/2)+1,Caption);
      }


	  if(State)
	  {
		setlinestyle(SOLID_LINE,0,3);
		setcolor(BLACK);
		line(Left+LeftAlign+2,Top+TopAlign+2,Left+LeftAlign+(CHECK_BOX_WIDTH-2),Top+TopAlign+(CHECK_BOX_HEIGHT-2));
		line(Left+LeftAlign+(CHECK_BOX_WIDTH-2),Top+TopAlign+2,Left+LeftAlign+2,Top+TopAlign+(CHECK_BOX_HEIGHT-2));
		setlinestyle(SOLID_LINE,0,1);
	  }


   }

   void CheckBox::Checked()
   {

       int TopAlign = (Height/2) - (CHECK_BOX_HEIGHT/2);
	   int LeftAlign = 0;
	   
	   if(Alignment==RIGHT_TEXT)
		LeftAlign=Width-CHECK_BOX_WIDTH;
	   
		if (hide) return;
		
	    setlinestyle(SOLID_LINE,0,3);
		setcolor(BLACK);
		line(Left+LeftAlign+2,Top+TopAlign+2,Left+LeftAlign+(CHECK_BOX_WIDTH-2),Top+TopAlign+(CHECK_BOX_HEIGHT-2));
		line(Left+LeftAlign+(CHECK_BOX_WIDTH-2),Top+TopAlign+2,Left+LeftAlign+2,Top+TopAlign+(CHECK_BOX_HEIGHT-2));
		setlinestyle(SOLID_LINE,0,1);

		State = true;

   }


    void CheckBox::UnChecked()
   {

	    int TopAlign = (Height/2) - (CHECK_BOX_HEIGHT/2);
	    int LeftAlign = 0;
		
		if(Alignment==RIGHT_TEXT)
		LeftAlign=Width-CHECK_BOX_WIDTH;

		if (hide) return;

	    setfillstyle(SOLID_FILL,WHITE);
	    bar(Left+LeftAlign+2,Top+TopAlign+2,Left+LeftAlign+(CHECK_BOX_WIDTH-2),Top+TopAlign+(CHECK_BOX_HEIGHT-2));

		State = false;


   }


   void CheckBox::EnableClickHandler()
   {


	  if(IsComboClick || IsMenuClick)return;
	
	  int TopAlign = (Height/2) - (CHECK_BOX_HEIGHT/2);
	  int LeftAlign = 0;
	  
	  mouse.ShowMouse();

	  if(hide) return;

	  if(Alignment==RIGHT_TEXT)
		LeftAlign=Width-CHECK_BOX_WIDTH;

		if(mouse.MouseInside(Left+LeftAlign+2,Top+TopAlign+2,Left+LeftAlign+(CHECK_BOX_WIDTH-2),Top+TopAlign+(CHECK_BOX_HEIGHT-2)) == 1)
		{

			if(mouse.GetButton() == MOUSE_LBUTTON)
				   chkStatus = CHECKBOX_STATUS_DOWN;



			else if(mouse.GetButton() == MOUSE_NORMAL && chkStatus == CHECKBOX_STATUS_DOWN)
			{

			   if(!State)
			   {
			     mouse.HideMouse();
			     Checked();
			     mouse.ShowMouse();
			   }

			   else
			   {
			      mouse.HideMouse();
			      UnChecked();
			      mouse.ShowMouse();

			    }
				  chkStatus = CHECKBOX_STATUS_NORMAL;
			}

		}

	}

	bool CheckBox::IsChecked()
	{
		return State;
	}

	void CheckBox::Hide()
	{
		if(hide) return;
		hide = true;
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(Left,Top,Left+Width,Top+Height);
	}
	void CheckBox::Show()
	{
		if(!hide) return;
		hide = false;
		Draw();
	}
	
	void CheckBox::SetText(char text[])
	{
		
		strcpy(Caption,text);
		Draw();
		
	}

	char *CheckBox::GetText()
	{
		return Caption;
	}
	
	void CheckBox::Clear()
	{
		strcpy(Caption,"");
		Draw();
	}
	
	


   #endif //CHECKBOX_CPP




















	

 
