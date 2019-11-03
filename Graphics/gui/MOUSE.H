


	#ifndef __MOUSE_H
	#define __MOUSE_H
	
	#ifndef __GUI_H
	#include <gui.h>
	#endif //__GUI_H

	#include <dos.h>
	#include <global.h>


	class Mouse

	{
	
	
		private: 
		
			int MouseXpos, MouseYpos;
			BUTTON MouseBtn;
			union REGS in,out;

		public:

			int InstallMouse();
			int ShowMouse();
			int HideMouse();
			void GetMouseStatus();
			BUTTON GetButton();
			int GetPosX();
			int GetPosY();
			void SetMousePosi(int &xpos, int &ypos);
			int MouseInside(int x1, int y1, int x2, int y2);
			void RestrictMousePtr(int x1, int y1, int x2, int y2);

	};
	#endif // __MOUSE_H

