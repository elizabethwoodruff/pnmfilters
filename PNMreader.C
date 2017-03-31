#include <PNMreader.h>
PNMreader::PNMreader(char *name){
	filename = new char[256];
	strcpy(filename, name);
	GetOutput()->parent = this;
	
}
PNMreader::~PNMreader(){
	delete filename;
}
void  PNMreader::Execute(){
	int w;
	int h;
	FILE* in_file;
	Image *image = GetOutput();
	in_file = fopen(filename, "rb");
	fscanf(in_file, "P6\n%d %d\n255\n", &w, &h);
	image->SetSize(w, h);	
	fread(image->GetP(), sizeof(Pixel), image->GetW()*image->GetH(), in_file);
	fclose(in_file);
	return;
}
void PNMreader::Update(){
	Execute();
	return;
}




















