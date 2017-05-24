#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Source;

#ifndef PIXEL_H
#define PIXEL_H
typedef struct{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}Pixel;

struct Image
{	
	private:
		mutable Pixel *pixel;
		mutable int width;
		mutable int height;
	public:
		Image(void);
		Image(int w, int h);
		Image(Image &i);
		virtual ~Image();
		void SetSize(int w, int h) const;
		int GetW() const ;
		int GetH() const ;
		void  SetW(int w);
		void  SetH(int h);
		Pixel* GetP()const;
		void Update() const;
		mutable bool isUpdated;
		mutable Source* parent;	 
}; 

#endif



