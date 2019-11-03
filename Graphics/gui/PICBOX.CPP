
	#ifndef PICBOX_CPP
	#define PICBOX_CPP 
	
	#include <picbox.h>
	#include <graphics.h>
	#include <string.h>


	PictureBox::PictureBox(int left, int top, int width, int height, char *path, int Id)
	{
		Left = left;
		Top = top;
		Width = width;
		Height = height;
		strcpy(Path,path);
		ID = Id;
		btnStatus = BUTTON_STATUS_NORMAL;
		State = false;

		pBitmap = new Bitmap(Left,Top,Width,Height,Path);

	}

	void PictureBox::DrawFrame()
	{
		int left,top,width,height;
		left=Left-2;
		top=Top-2;
		width=Width+4;
		height=Height+4;

		setfillstyle(SOLID_FILL,WHITE);
		bar(left,top,left+width,top+height);


		setcolor(WHITE);
		line(left,top,left+width,top);
		line(left,top,left,top+height);

		setcolor(BLACK);
		line(left+width,top,left+width,top+height);
		line(left,top+height,left+width,top+height);

	}
	
	void PictureBox::MouseDown()
   {
	    int left,top,width,height;
	    left=Left-2;
		top=Top-2;
		width=Width+4;
		height=Height+4;

		mouse.HideMouse();

		setcolor(BLACK);
		line(left,top,left+width,top);
		line(left,top,left,top+height);

		setcolor(WHITE);
		line(left+width,top,left+width,top+height);
		line(left,top+height,left+width,top+height);

		mouse.ShowMouse();


   }

   void PictureBox::MouseUp()
   {
		int left,top,width,height;
	    left=Left-2;
		top=Top-2;
		width=Width+4;
		height=Height+4;
		
		mouse.HideMouse();

		setcolor(WHITE);
		line(left,top,left+width,top);
		line(left,top,left,top+height);

		setcolor(BLACK);
		line(left+width,top,left+width,top+height);
		line(left,top+height,left+width,top+height);

		mouse.ShowMouse();

   }

	void PictureBox::Draw()
	{
		DrawFrame();
		pBitmap->DrawBitmap(Left,Top,COPY_PUT);

	}
	
	void PictureBox::EnableClickHandler()
   {

		if(IsComboClick || IsMenuClick)return;

		if(State)
		{
			PictureBoxId = 0;
			State = false;
			return;
		}
	
		if(mouse.MouseInside(Left,Top,Left+Width,Top+Height) == 1)
		{

			if(mouse.GetButton() == MOUSE_LBUTTON)
			{
				MouseDown();
				btnStatus = PICTURE_BUTTON_STATUS_DOWN;
			}

			else if(btnStatus == PICTURE_BUTTON_STATUS_DOWN && mouse.GetButton() == MOUSE_NORMAL) 
			{
				MouseUp();
				PictureBoxId = ID;
				btnStatus = PICTURE_BUTTON_STATUS_NORMAL;
				State = true;
				
			}

		}

	}

	#endif //PICBOX_CPP