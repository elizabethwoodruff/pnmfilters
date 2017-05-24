#include <image.h> 
#include <sink.C>
#ifndef PNM_WRITER_H
#define PNM_WRITER_H
class PNMwriter : public Sink{
	public:
		PNMwriter();
		virtual ~PNMwriter();
		void Write(char* name);
		const char* SinkName();
};

#endif
