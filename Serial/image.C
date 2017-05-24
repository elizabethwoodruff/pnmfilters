#include <image.h>
Image::Image(int w, int h)
	{	
	width = w; 
	height =h; 
	pixel = new Pixel[width*height];
	parent = NULL;
	isUpdated = false;
	}

Image::Image(Image &i)
	{
	height = i.height; 
	width = i.width; 
	pixel = new Pixel[width*height]; 
	memcpy(pixel, i.pixel, i.height*i.width*sizeof(Pixel));
	parent = i.parent;
	isUpdated = i.isUpdated;
	}

Image::Image(void)
 {
	width = 0; 
	height = 0;
	pixel = NULL;
	parent = NULL;
	isUpdated = false;
}
void Image::SetSize(int w, int h) const{
	width = w;
	height = h;
	pixel = new Pixel[width*height];
	parent = NULL;
	isUpdated = false;
	}
Image::~Image(){
	delete [] pixel;

	}
int Image::GetH() const {
	return height;
}
int Image::GetW() const{
	return width;
}
Pixel* Image::GetP()const { 
	return pixel;
}
void Image::SetW(int w){
	width = w;
	return;
}
void Image::SetH(int h){
	height = h;
	return;
}

