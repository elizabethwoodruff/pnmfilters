#include <filters.h>
#ifndef TB_C
#define TB_C
class TBConcat: public filter {
	public:
	const char* FilterName(){return "TBConcat";};
	TBConcat(){GetOutput()->parent = this; name = "TBConcat";};
	virtual void Execute();
	virtual void Update();


};
void TBConcat::Execute(){

Image* topInput = pointer1;
 Image* bottomInput = pointer2;
Image* output = GetOutput();
        output->SetSize(topInput->GetW(), topInput->GetH() + bottomInput->GetH());
        for (int i = 0; i < output->GetW(); i++){
                for (int j = 0; j < output->GetH(); j++){
                        if (j < topInput->GetH()){
                        output->GetP()[j*output->GetW()+(i)] = topInput->GetP()[j*topInput->GetW()+i];
                        }
                        else{
                        output->GetP()[j*output->GetW()+i] = bottomInput->GetP()[(j-topInput->GetH())*bottomInput->GetW()+i];
                        }
                }

        }
        return;

}
void TBConcat::Update(){
	char msg[128];
	sprintf(msg, "%s:about to execute", name);
	Logger::LogEvent(msg);
	if (pointer1->isUpdated == false){
	pointer1->Update();
	}
	if (pointer2->isUpdated == false){
	pointer2->Update();
	}
	Execute();
	sprintf(msg, "%s:done executing", name);
	Logger::LogEvent(msg);
	return;

}


#endif
