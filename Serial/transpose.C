void Transpose::Update(){
	if (pointer1->isUpdated == false){
	pointer1->Update();
}
	Execute();
}


void Transpose::Execute(){
 int height = pointer1->GetW();
 int width = pointer1->GetH(); 
 GetOutput()->SetSize(width, height);
 unsigned char *buffer = (unsigned char*)GetOutput()->GetP();
 const unsigned char *buffer1 = (const unsigned char*)pointer1->GetP();
    for (int i = 0 ; i < width; i++)
        for (int j = 0 ; j < height ; j++)
        {
            int idx1 = i*height+j;
	    int idx = j*width+i;
	    buffer[3*idx] = buffer1[3*idx1];
	    buffer[3*idx+1] = buffer1[3*idx1+1];
	    buffer[3*idx+2] = buffer1[3*idx1+2];
        }
}




