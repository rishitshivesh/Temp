




	#ifndef MOUSE_CPP
	#define MOUSE_CPP 
	
	#include <mouse.h>
	
	

	int Mouse::InstallMouse()
	{
 
		in.x.ax = 0;
		int86(51,&in,&out);
		return out.x.ax;
  
	}
	int Mouse::ShowMouse()
	{
  
		in.x.ax = 1;
		int86(51,&in,&out);
		return 1;
  
	}  
	int Mouse::HideMouse()
	{

		in.x.ax = 2;
		int86(51,&in,&out);
		return 1;

	}
	void Mouse::GetMouseStatus()
	{

		in.x.ax = 3;
		int86(51,&in,&out);
		MouseXpos = out.x.cx;
		MouseYpos = out.x.dx;
		MouseBtn = out.x.bx;

	}
	BUTTON Mouse::GetButton()
	{
		return MouseBtn;
	}
	
	int Mouse::GetPosX()
	{
		return MouseXpos;
	}

	int Mouse::GetPosY()
	{
		return MouseYpos;
	}
	
	void Mouse::SetMousePosi(int &xpos, int &ypos)
	{
		in.x.ax = 4;
		in.x.cx = xpos;
		in.x.dx = ypos;
		int86(51,&in,&out);
	}
	int Mouse::MouseInside(int x1, int y1, int x2, int y2)
	{
		int x_pos, y_pos;
		in.x.ax = 3;
		int86(51,&in,&out);
		x_pos = out.x.cx;
		y_pos = out.x.dx;
  
		if(x_pos >= x1 && y_pos >= y1 && x_pos <= x2 && y_pos <= y2)
			return 1;
		else 
			return 0;
  
	}
	void Mouse::RestrictMousePtr(int x1, int y1, int x2, int y2)
	{

		in.x.ax = 7;
		in.x.cx = x1;
		in.x.dx = x2;
		int86(51,&in,&out);  

		in.x.ax = 8;
		in.x.cx = y1;
		in.x.dx = y2;
		int86(51,&in,&out);  

	}
	
	
	#endif  // MOUSE_CPP