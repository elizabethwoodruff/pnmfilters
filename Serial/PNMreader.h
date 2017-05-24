#include <image.h>
#include <source.h>
#ifndef PNM_READER_H
#define PNM_READER_H
class PNMreader : public Source
{
	private:
	char* filename;
	public:
	PNMreader(char *name);
	virtual ~PNMreader();
	virtual void  Execute();
	virtual void Update();
	const char* SourceName(){return "PNMreader";};
};

#endif
