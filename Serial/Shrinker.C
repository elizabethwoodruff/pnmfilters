#include <filters.h>
#ifndef SHRINKER_C
#define SHRINKER_C
class Shrinker : public filter{
	public:
	const char* FilterName(){return "Shrinker";};
	Shrinker(){GetOutput()->parent = this;};
	virtual void Execute();
	virtual void Update();
};
void Shrinker::Execute(){
	if (pointer1 == NULL){
	char msg[1024];
	sprintf(msg, "%s: Input cannot be NULL", SinkName());
	DataFlowException e(SinkName(),msg);
	throw e;
	}
	try{
	Image* input = pointer1;
	Image* output = GetOutput();
        output->SetSize(input->GetW()/2, input->GetH()/2);
	for (int i = 0; i < input->GetW(); i++){
		for (int j = 0; j < input->GetH(); j++){
			output->GetP()[j/2*output->GetW() + i/2] = input->GetP()[j*input->GetW()+i];
		}
	}
	}
	catch(DataFlowException& e){
	}
	return;
}
void Shrinker::Update(){
	char msg[128];
	sprintf(msg, "%s:about to execute", SourceName());
	Logger::LogEvent(msg);
	if (pointer1->isUpdated == false){
	pointer1->Update();
	} 
	Execute();
	sprintf(msg, "%s:done executing", SourceName());
	Logger::LogEvent(msg);
	return;

}
#endif
