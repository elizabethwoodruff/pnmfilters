#include <filters.h>
void Checkerboard::Update(){
 if (pointer1->isUpdated == false){
	pointer1->Update();
}
 if (pointer2->isUpdated == false){
	pointer2->Update();
}
Execute();
}
void Checkerboard::Execute(){
 int width = pointer1->GetW();
 int height = pointer2->GetH();
 GetOutput()->SetSize(width, height);
 unsigned char *buffer = (unsigned char*)GetOutput()->GetP();
 const unsigned char *buffer1 = (const unsigned char*)pointer1->GetP();
 const unsigned char *buffer2 = (const unsigned char*)pointer2->GetP();  
    for (int i = 0 ; i < width ; i++)
        for (int j = 0 ; j < height ; j++)
        {
            int idx1 = j*width+i;
            int idx = j*width+i;
	    if (((int)i/10 + (int)j/10)%2 ==0){
            buffer[3*idx] = buffer1[3*idx1];
            buffer[3*idx+1] = buffer1[3*idx1+1];
            buffer[3*idx+2] = buffer1[3*idx1+2];
		}
	    else{
            buffer[3*idx] = buffer2[3*idx1];
            buffer[3*idx+1] = buffer2[3*idx1+1];
            buffer[3*idx+2] = buffer2[3*idx1+2];
		
		}	
        }


	

	return;


}


