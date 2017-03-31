#include<filters.h>
CheckSum::CheckSum(){

	;
}
CheckSum::~CheckSum(){
	;
}
void CheckSum::OutputCheckSum(const char* filename){
	FILE* file;
	file  = fopen(filename, "w");
	unsigned char red_chanel = 0;
	unsigned char green_chanel = 0;
	unsigned char blue_chanel = 0;
	unsigned char* buffer =(unsigned char*)pointer1->GetP();
	 int height = pointer1->GetH();
 	int width = pointer1->GetW();
    for (int i = 0 ; i < width ; i++)
	{
        for (int j = 0 ; j < height ; j++)
        {
            int idx = j*width+i;
            red_chanel += buffer[3*idx];
            green_chanel += buffer[3*idx+1];
            blue_chanel += buffer[3*idx+2];
        }
	}
	fprintf(file, "CHECKSUM: %i, %i, %i\n", red_chanel, green_chanel, blue_chanel);

	fclose(file);
	return;
}
