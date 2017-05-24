#include <PNMwriter.h>
PNMwriter::PNMwriter(){
	;

}
PNMwriter::~PNMwriter(){
	;
}
const char* PNMwriter::SinkName(){
	return "PNMwriter";
}

void PNMwriter::Write(char *filename){
	FILE* file;
	file = fopen(filename, "w");
	fprintf(file, "P6\n%d %d\n255\n", this->GetInput()->GetW(), this->GetInput()->GetH());
	fwrite(this->GetInput()->GetP(), sizeof(Pixel), this->GetInput()->GetW()*this->GetInput()->GetH(), file);
	fclose(file);
	return;
}
