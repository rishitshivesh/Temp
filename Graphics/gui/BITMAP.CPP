

	
	
	#ifndef BITMAP_CPP
	#define BITMAP_CPP 
 
	#include <bitmap.h>
	#include <fstream.h>
	#include <conio.h>
	#include <graphics.h>
	#include <string.h>
	#include <iostream.h>
	#include <stdlib.h>
	#include <malloc.h>

 
	Bitmap::Bitmap(int left, int top, int width, int height, char file[35])
	{
		Left = left;
		Top = top;
		Width = width;
		Height = height;
		strcpy(bmpfile,file);
		LoadBitmap();
	}
	
	
	bool Bitmap::ImgType()
	{
		WORD type;
		fstream file;
		file.open(bmpfile,ios::in|ios::binary);
		file.read((char *) &type,sizeof(WORD));
		file.close();
		if(type == 19778) 
		return true;
		else
		return false;
	}
	
	
	void Bitmap::LoadBitmap()
	{
		fstream bitmap_file;

		/*****************************************************/
		
		DWORD index;
		BYTE ch,str;
		BYTE rgbquad[4];
		
		int Xpos = Left;
		int Ypos = Top;
		
		/*****************************************************/

		/* Open bitmap file. */

		bitmap_file.open(bmpfile,ios::in|ios::binary);

		if(!bitmap_file)
		{
			cout<<"Error opening file "<<bmpfile;
			exit(1);
		}
		
		/* check to see if it is a valid bitmap file */

		if(ImgType() == false)
		{
			bitmap_file.close();
			cout<<bmpfile<<" is not a bitmap file.";
			exit(1);
		}
		
		/* Skip Header */
		
		bitmap_file.seekg(54,ios::beg);
		
		/* Read the palette information. */
		
		for(index = 0;index < 256;index++)
		{
			bitmap_file.read((char *) &rgbquad,4);
			
			Palette_Data[(int)index*3+2] = rgbquad[0];
			Palette_Data[(int)index*3+1] = rgbquad[1];
			Palette_Data[(int)index*3+0] = rgbquad[2];
		}
		
		
		/* Draw Bitmap */

		for(int i=0;i<Height;i++)
		{
			for(int j=0;j<Width;j++)
			{
				bitmap_file.read((char *) &ch,1);
				putpixel(Xpos+j,Ypos+Height-1-i,(int)ch);
			}
		}

		buff = malloc(imagesize(Left,Top,Left+Width,Top+Height));
		getimage(Left,Top,Left+Width,Top+Height,buff);
		
		bitmap_file.close();

	}

	
	void Bitmap::DrawBitmap(int left, int top, int value)
	{
		putimage(left,top,buff,value);	
	}
	
	void Bitmap::SetPalette()
	{
		int i;

		outp(PALETTE_INDEX,0);              /* tell the VGA that palette data
                                         is coming. */
		for(i=0;i<256*3;i++)
			outp(PALETTE_DATA,Palette_Data[i]);    /* write the data */
	}

        void Bitmap::RotatePalette()
	{
		int i,red,green,blue;

		red  = Palette_Data[3];
		green= Palette_Data[4];
		blue = Palette_Data[5];

		for(i=3;i<256*3-3;i++)
			Palette_Data[i]=Palette_Data[i+3];

		Palette_Data[256*3-3]=red;
		Palette_Data[256*3-2]=green;
		Palette_Data[256*3-1]=blue;

		SetPalette();
	}
	
	void Bitmap::FreeBlock()
	{
		free(buff);
	}
	
  #endif //BITMAP_CPP
























	
  