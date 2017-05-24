#include <filters.h>
void Invert::Update(){
   if (pointer1->isUpdated == false){
        pointer1->Update();
}
        Execute();

}
void Invert::Execute(){
 int width = pointer1->GetW();
 int height = pointer1->GetH();
 GetOutput()->SetSize(width, height);
  unsigned char *buffer = (unsigned char*)GetOutput()->GetP();
  const unsigned char *buffer1 = (const unsigned char*)pointer1->GetP();
  tbb::parallel_for (
	tbb::blocked_range<int>(0, width),[&] (tbb::blocked_range<int> v){
		for (size_t i = v.begin(); i != v.end(); ++i){
               for (int j = 0; j < height; j++){
		int idx1 = j*width+i;
		int idx = j*width+i;
                buffer[3*idx] =    255 - buffer1[3*idx];
                buffer[3*idx+1] =  255 - buffer1[3*idx+1];
                buffer[3*idx+2] =  255 -  buffer1[3*idx+2];
		}
			

		}


	}



);

/*	
	for (int i= 0; i < width; i++){
               for (int j = 0; j < height; j++){
		int idx1 = j*width+i;
		int idx = j*width+i;
                buffer[3*idx] =    255 - buffer1[3*idx];
                buffer[3*idx+1] =  255 - buffer1[3*idx+1];
                buffer[3*idx+2] =  255 -  buffer1[3*idx+2];
		}
        }*/
return; 
}
