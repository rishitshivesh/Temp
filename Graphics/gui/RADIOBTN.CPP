



	#ifndef RADIOBTN_CPP
	#define RADIOBTN_CPP

	#include <radiobtn.h>
	#include <graphics.h>
	#include <math.h>
	#include <string.h>




    RadioButton::RadioButton(int left, int top, int width, int height, char caption[], int Align, int Id)
    {
	 Left = left;
	 Top = top;
	 Width = width;
	 Height = height;
	 strcpy(Caption,caption);
	 Alignment = Align;
	 ID = Id;
	 State = true;
	 radioBtnStatus = RADIO_BUTTON_STATUS_NORMAL;
    }


    void RadioButton::Draw()
   {

	  int LeftAlign = RADIO_BUTTON_RADIUS + 1;

	  if(Alignment==RIGHT_TEXT)
		LeftAlign=Width-RADIO_BUTTON_RADIUS - 1;

	 setfillstyle(SOLID_FILL,LIGHTGRAY);
	 bar(Left,Top,Left+Width,Top+Height);

	 setfillstyle(SOLID_FILL,LIGHTGRAY);
	 setcolor(LIGHTGRAY);
	 circle(Left + LeftAlign,Top + (Height/2) + 1,RADIO_BUTTON_RADIUS);
	 floodfill(Left + LeftAlign,Top + (Height/2) + 1,LIGHTGRAY);

	 setcolor(DARKGRAY);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,0,180,RADIO_BUTTON_RADIUS);
	 setcolor(BLACK);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,0,180,RADIO_BUTTON_RADIUS-1);
	 setcolor(WHITE);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,180,0,RADIO_BUTTON_RADIUS);
	 setcolor(DARKGRAY);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,180,0,RADIO_BUTTON_RADIUS-1);


	 setcolor(BLACK);
    if(Alignment==LEFT_TEXT)
    {
	  settextjustify(LEFT_TEXT,CENTER_TEXT);
	  outtextxy(Left+(2*RADIO_BUTTON_RADIUS)+4,Top+(Height/2)+1,Caption);
    }
     else
     {

	   settextjustify(RIGHT_TEXT,CENTER_TEXT);
	    outtextxy(Left+(Width)-((2*RADIO_BUTTON_RADIUS)+3),Top+(Height/2)+1,Caption);
      }


	  if(State)
	  {
		setfillstyle(SOLID_FILL,WHITE);
		setcolor(DARKGRAY);
		circle(Left+LeftAlign,Top+(Height/2)+1,RADIO_BUTTON_RADIUS/2);
		floodfill(Left+LeftAlign,Top+(Height/2)+1,DARKGRAY);

		RadioButtonId = ID;
	  }


   }

   void RadioButton::Enable()
   {


		int LeftAlign = RADIO_BUTTON_RADIUS + 1;

		if(Alignment==RIGHT_TEXT)
		    LeftAlign=Width-RADIO_BUTTON_RADIUS - 1;

		mouse.HideMouse();

		setfillstyle(SOLID_FILL,WHITE);
		setcolor(DARKGRAY);
		circle(Left+LeftAlign,Top+(Height/2)+1,RADIO_BUTTON_RADIUS/2);
		floodfill(Left+LeftAlign,Top+(Height/2)+1,DARKGRAY);

		RadioButtonId = ID;

		mouse.ShowMouse();
   }


    void RadioButton::Disable()
   {

	int LeftAlign = RADIO_BUTTON_RADIUS + 1;

		if(Alignment==RIGHT_TEXT)
		    LeftAlign=Width-RADIO_BUTTON_RADIUS - 1;


	      //	mouse.HideMouse();

	 setfillstyle(SOLID_FILL,LIGHTGRAY);
	 setcolor(LIGHTGRAY);
	 circle(Left + LeftAlign,Top + (Height/2) + 1,RADIO_BUTTON_RADIUS);
	 floodfill(Left + LeftAlign,Top + (Height/2) + 1,LIGHTGRAY);

	 setcolor(DARKGRAY);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,0,180,RADIO_BUTTON_RADIUS);
	 setcolor(BLACK);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,0,180,RADIO_BUTTON_RADIUS-1);
	 setcolor(WHITE);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,180,0,RADIO_BUTTON_RADIUS);
	 setcolor(DARKGRAY);
	 arc(Left + LeftAlign,Top + (Height/2) + 1,180,0,RADIO_BUTTON_RADIUS-1);


	      //	mouse.ShowMouse();
   }


   bool RadioButton::IsMouseInside(int R_Xpos,int R_Ypos,int M_Xpos,int M_Ypos)
   {
	   double dx,dy;
	   double dist;

	   dx = M_Xpos - R_Xpos;
	   dy = M_Ypos - R_Ypos;

	   dist = sqrt(dx*dx + dy*dy);

	   return (dist < (RADIO_BUTTON_RADIUS + MOUSE_RADIUS));

   }


   void RadioButton::EnableRadioButton()
   {
		RadioButtonId = ID;
   }

   void RadioButton::DisableRadioButton()
   {
		RadioButtonId = 0;
   }


   void RadioButton::EnableClickHandler()
   {

	if(IsComboClick || IsMenuClick)return;

	int LeftAlign = RADIO_BUTTON_RADIUS + 1;

	  if(Alignment==RIGHT_TEXT)
		LeftAlign=Width-RADIO_BUTTON_RADIUS - 1;

		if(RadioButtonId != ID )
		 Disable();







		if(IsMouseInside(Left + LeftAlign,Top + (Height/2) + 1,mouse.GetPosX(),mouse.GetPosY()))
		{

			   if(mouse.GetButton() == MOUSE_LBUTTON)
				   radioBtnStatus = RADIO_BUTTON_STATUS_DOWN;



			else if(mouse.GetButton() == MOUSE_NORMAL && radioBtnStatus == RADIO_BUTTON_STATUS_DOWN)
			{
				 Enable();
				 radioBtnStatus = RADIO_BUTTON_STATUS_NORMAL;

			}




		}




	}

	void RadioButton::SetText(char text[])
	{

		strcpy(Caption,text);
		Draw();

	}

	char *RadioButton::GetText()
	{
		return Caption;
	}

	void RadioButton::Clear()
	{
		strcpy(Caption,"");
		Draw();
	}


   #endif //RADIOBTN_CPP




















	

 
