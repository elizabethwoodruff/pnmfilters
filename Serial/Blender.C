#include <filters.h>

#ifndef BLENDER_C
#define BLENDER_C

class Blender : public filter{
	private:
	float factor; 
	public:

	const char* FilterName(){return "Blender";};
	Blender(){factor = 0; GetOutput()->parent = this; };
	void SetFactor(float fact);
	virtual void Execute();
	virtual void Update();	
};
void Blender::Update(){
	char msg[128];
	sprintf(msg, "%s:about to execute", SourceName());
	Logger::LogEvent(msg);
	if (pointer1->isUpdated == false){
		pointer1->Update();
	}
	if (pointer2->isUpdated == false){
		pointer2->Update();
	}	
	Execute();
	sprintf(msg, "%s: done executing", SourceName());
	Logger::LogEvent(msg);
	return;

}
void Blender::SetFactor(float fact){
	factor = fact;
	return;

}
void Blender::Execute(){
	if (factor > 1){
		char msg[1024];
		sprintf(msg, "%s: factor must be less than one and greater than 0: %f", SinkName(),factor);
		DataFlowException e(SinkName(),msg);
	throw e;
	}
	try{

	Image* output = GetOutput();
	const Image* input1 = pointer1;
	const Image* input2 = pointer2;
	float off = 1 - factor;
	output->SetSize(input2->GetW(), input1->GetH());
	for (int i = 0; i < output->GetW(); i++){
		for( int j = 0; j <output->GetH();j++){
			output->GetP()[j*output->GetW()+i].r = factor*input1->GetP()[j*input1->GetW()+i].r + off*input2->GetP()[j*input2->GetW()+i].r;
			output->GetP()[j*output->GetW()+i].g = factor*input1->GetP()[j*input1->GetW()+i].g + off*input2->GetP()[j*input2->GetW()+i].g;
			output->GetP()[j*output->GetW()+i].b = factor*input1->GetP()[j*input1->GetW()+i].b + off*input2->GetP()[j*input2->GetW()+i].b;
			

}
}
}
	catch(DataFlowException &e){
}
	return;
}


#endif
