#include <image.h> 
#ifndef SINK_C
#define SINK_C
class Sink{
	protected:
	Image const *pointer1;
	Image const *pointer2;
	public:
	Sink(){ pointer1 = NULL; pointer2 = NULL;}
	void SetInput(Image* input){pointer1 = input;};
	void SetInput2(Image *input){pointer2 = input;};
	Image const  *GetInput(){return pointer1;};
	Image const  *GetInput2(){return pointer2;};
	virtual const char* SinkName()=0;
};
#endif

