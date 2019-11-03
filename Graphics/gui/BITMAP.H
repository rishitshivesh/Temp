
	  
	#ifndef __BITMAP_H
	#define __BITMAP_H

 
	#include <global.h>
 
 
 #define PALETTE_INDEX       0x03c8
 #define PALETTE_DATA        0x03c9
 
 typedef unsigned char BYTE;
 typedef unsigned int WORD;
 typedef unsigned long DWORD;
 typedef signed long LONG;

 BYTE Palette_Data[256*3];
 void *buff; 	
 
 
 class Bitmap
 {
 
	private:
	
	int Left,Top,Width,Height;
	char bmpfile[35];
	void LoadBitmap();
	bool ImgType();
	public:
	void DrawBitmap(int left, int top, int value);
	Bitmap(int left, int top, int width, int height, char file[35]);
	void SetPalette();
	void RotatePalette();
	void FreeBlock();
 };
 
 #endif //__BITMAP_H
 

























	
  