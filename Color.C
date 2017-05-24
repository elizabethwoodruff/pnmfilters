#include <filters.h>
Color::Color(int width, int height, unsigned char red, unsigned char green, unsigned char blue){
	GetOutput()->parent = this;
	GetOutput()->SetSize(width, height);
	r  = red;
	g = green;
	b = blue;
	Execute();
}
void Color::Update(){
	if (GetOutput()->isUpdated == false){
	GetOutput()->Update();
	}
	Execute();
}
void Color::Execute(){	
	int width = GetOutput()->GetW();
	int height = GetOutput()->GetH();
	tbb::parallel_for ( tbb::blocked_range<int> (0, width), 
	[&] (tbb::blocked_range<int> v){
		for (size_t i=v.begin(); i != v.end(); ++i) {
			for ( int j = 0; j < height; j++){
				int idx = j*width + i;
				GetOutput()->GetP()[idx].r = r;
				GetOutput()->GetP()[idx].g = g;
				GetOutput()->GetP()[idx].b = b;


			}

		}

	});	
/*
	for (int i= 0; i < width; i++){
               for (int j = 0; j < height; j++){
                int idx = j*width+i;
		GetOutput()->GetP()[idx].r = r;
		GetOutput()->GetP()[idx].g = g;
		GetOutput()->GetP()[idx].b = b;
		
                }

        }
	return;
*/
	return;
}

