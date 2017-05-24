#include <filters.h>
#ifndef LR_CONCAT_C
#define LR_CONCAT_C
/*class LRConcat : public filter {
	public:
	const char* FilterName(){return "LRConcat";};
	LRConcat(){pointer1 = NULL; pointer2 = NULL; GetOutput()->parent = this;};
	virtual void Execute();
	virtual void Update();
};*/
void LRConcat::Execute(){
	 if (pointer1->GetH()!= pointer2->GetH()){
		char msg[1024];
		sprintf(msg, "%s:heights must match: %d, %d", SinkName(), pointer1->GetH(), pointer2->GetH());
		DataFlowException e(SinkName(), msg);
		throw e;
	}
 try{
	 const Image* leftInput = pointer1;
	 const Image* rightInput = pointer2;
		
	Image* output = GetOutput();
	output->SetSize(leftInput->GetW() + rightInput->GetW(), leftInput->GetH());        
	for (int i = 0; i < output->GetW(); i++){
		for (int j = 0; j < output->GetH(); j++){
			if (i < leftInput->GetW()){
			output->GetP()[j*output->GetW()+(i)] = leftInput->GetP()[j*leftInput->GetW()+i];
			}
			else{
			output->GetP()[j*output->GetW()+i] = rightInput->GetP()[j*rightInput->GetW()+(i-leftInput->GetW())];
			}
		}

	}
	}
catch(const DataFlowException &e){
	throw e;
}        

	return;

}
#endif
 
void LRConcat::Update(){
	if(pointer1 == NULL){
	char msg[1024];
	sprintf(msg, "%s: input1 was null", SinkName());
	DataFlowException e(SinkName(), msg);
	throw e;
	}
	if (pointer1->isUpdated == false){
	pointer1->Update();
	}
	if(pointer2 == NULL){
	char msg[1024];
	sprintf(msg, "%s: input2 was null", SinkName());
	DataFlowException e(SinkName(), msg);
	throw e;
	}
	char msg[128];
	sprintf(msg, "%s:about to execute", SourceName());
	try{
	Logger::LogEvent(msg);
	if (pointer2->isUpdated == false){
	pointer2->Update();
	}	
	Execute();
	}
	catch (DataFlowException &e){
	}
//	Execute();
	sprintf(msg, "%s:done executing", SourceName());
	Logger::LogEvent(msg);
	return;

}


