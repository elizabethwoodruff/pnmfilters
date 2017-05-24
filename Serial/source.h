#include <image.h>
#ifndef SOURCE_H
#define SOURCE_H
class Source{
        protected:
        Image data_member;	
        virtual void  Execute() = 0;
	const char *name;
        public:
	Source(void) {data_member.parent = this;};
        Image* GetOutput(){return &data_member;};
        virtual void Update();
	virtual const char* SourceName() = 0;
};
#endif


