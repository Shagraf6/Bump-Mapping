//////////////////////////////////////////////////////////////////////////////////////////
//	IMAGE.h
//	Image class declaration
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Modified:	9th November 2002	-	Corrected stride for TGA textures
//									-	Split up .cpp files
//									-	Added support for paletted textures
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

//#include <malloc.h>
//#include <stdio.h>
////#include <GL/gl.h>
////#include <glut.h>
//#include <math.h>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <assert.h>

#ifndef IMAGE_H
#define IMAGE_H

class GBA { // the name RGBA is already used by Windows

public:

	unsigned char r, g, b, a;
	GBA() { r = g = b = 0; a = 255; }
	GBA(GBA &p) { r = p.r; g = p.g; b = p.b; a = p.a; }
	GBA(unsigned char rr, unsigned char gg, unsigned char bb, unsigned char aa)
	{
		r = rr; g = gg; b = bb; a = aa;
	}

	void set(unsigned char rr, unsigned char gg, unsigned char bb, unsigned char aa)
	{
		r = rr; g = gg; b = bb; a = aa;
	}

};
class IMAGE
{
public:
	GBA *pixel;  // array of pixels
	int nRows, nCols;
	//unsigned int bpp;				//bits per pixel
	//unsigned int width, height;		//size
	//unsigned int stride;			//bytes per row, including padding bytes
	//GLuint format;					//format (eg GL_RGBA)

	IMAGE()	:	data(NULL), bpp(0), width(0), height(0), stride(0),
				paletted(false), paletteBpp(0), palette(NULL)
	{}

	~IMAGE()
	{
		if(data)
			delete [] data;
		data=NULL;

		if(palette)
			delete [] palette;
		palette=NULL;
	}

	void mDraw()
	{
		if (nRows == 0 || nCols == 0)
			return;

		// tell OpenGL: don't align pixels with 4-byte boundaries in memory
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glDrawPixels(nCols, nRows, GL_RGBA, GL_UNSIGNED_BYTE, pixel);

	}




	//Load image
	bool Load(char * filename);

	//Use the color indices from a paletted image as the alpha channel for this image
	bool LoadAlpha(const IMAGE & alphaImage);

protected:
	//Load BMPs
	bool LoadBMP(char * filename);
	bool Load8BitBMP(char * filename);
	bool Load24BitBMP(char * filename);

	//Load TGAs
	bool LoadTGA(char * filename);
	bool LoadUncompressed8BitTGA(char * filename);
	bool LoadUncompressedTrueColorTGA(char * filename);
	bool LoadCompressedTrueColorTGA(char * filename);

	//Calculate the number of bytes in a row, including padding bytes
	unsigned int CalculateStride(unsigned int testBpp=-1, unsigned int testWidth=-1);
	//Do not pass values to use class members

public:
	//Alter the image
//	int readBMPFile(string fname, float para);
	void FlipVertically(void);
	void MirrorHorizontally(void);
	void ExpandPalette(void);		//convert a paletted image into a non-paletted one
	
	unsigned int bpp;				//bits per pixel
	unsigned int width, height;		//size
	unsigned int stride;			//bytes per row, including padding bytes
	GLuint format;					//format (eg GL_RGBA)

	//Data
	GLubyte * data;
	
	//palette data (256 entries)
	bool paletted;

	unsigned int paletteBpp;
	GLuint paletteFormat;
	GLubyte * palette;
};

//Bitmap ID
const DWORD bitmapID=0x4D42;
//
#endif	//IMAGE_H


	




