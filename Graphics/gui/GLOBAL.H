
	
	
	
	
	#ifndef __GLOBAL_H
	#define __GLOBAL_H
	
	
		// Message Box Buttons Type
		#define jcOKOnly 			1
		#define jcOKCancel 			2
		#define jcAbortRetryIgnore 	3
		#define jcYesNoCancel 		4
		#define jcYesNo 			5
		#define jcRetryCancel 		6
		
		// Icons
		#define jcCritical			16
		#define jcQuestion			32
		#define jcExclamation		48
		#define jcInformation       64
		#define jcAbout             80
		#define jcNone				90

		//Buttons 
		#define jcOK				8001
		#define jcCancel			8002
		#define jcAbort             8003
		#define jcRetry             8004
		#define jcIgnore            8005
		#define jcYes               8006
		#define jcNo                8009
		
		
		#define MAX_WORD_IN_LINE      30
		
		#define TITLEBARHEIGHT		  21
		#define BORDERWIDTH			  1
		#define MSGBTNDEFAULTWIDTH    60
		#define MSGBTNDEFAULTHEIGHT   25 
		#define MSGBOXDEFAULTWIDTH	  80
		#define MSGBOXDEFAULTHEIGHT   80
		#define ICONWIDTH			  20
		#define ICONHEIGHT            20  	
	
		int ButtonId;
		int LabelId;
		int MenuId;
		int MenuItemId;
		int TextBoxId;
		int RadioButtonId;
		int PictureBoxId;
		int WindowLeft;
		int WindowTop;
		int WindowWidth;
		int NumberOfMenus=-1;
		int MenuWidth[70];
		enum bool{false,true};
		enum BUTTON{MOUSE_NORMAL = 0,MOUSE_LBUTTON=1,MOUSE_RBUTTON=2,MOUSE_MBUTTON=4};  	
		bool IsComboClick = false;
		bool IsMenuClick = false;
		bool IsMenuBarCreated=false;
		
		/* buffer area used for storing portion of images temporarily */
		/* the address 0xa000a000l represents the starting of second  */

			//char far *buffer=(char far *)0xa000a000l;
			void far *buffer=(void far *)0xa000a000l;
		
	
	#endif // __GLOBAL_H