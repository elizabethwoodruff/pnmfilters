#include <source.h>
#include <sink.C>
#include<logging.h>
#include <tbb/tbb.h>
#ifndef FILTER_C
#define FILTER_C 
class filter : public Sink, public Source{
	public:
	filter();
	virtual const char* FilterName()=0;
	const char* SourceName(){return FilterName();};
	const char* SinkName(){return FilterName();};
	
};


class LRConcat : public filter {
	public:
        const char* FilterName(){return "LRConcat";};
        LRConcat(){pointer1 = NULL; pointer2 = NULL; GetOutput()->parent = this;};
        virtual void Execute();
        virtual void Update();
};

class Crop : public filter
{ 
  private:
    int Istart, Istop, Jstart, Jstop;
 	public:
    
	 Crop()  { Istart = Istop = Jstart = Jstop = -1; GetOutput()->parent = this; pointer1 = NULL; pointer2 = NULL; };
 	 virtual const char *FilterName() { return "Crop"; };
   	 virtual void   Execute();
	 virtual void Update();
    	void SetRegion(int Istart_, int Istop_, int Jstart_, int Jstop_)
                      {
                        Istart = Istart_;
                        Istop  = Istop_;
                        Jstart = Jstart_;
                        Jstop  = Jstop_;
                      };

};
class Transpose:public filter{
	public:
	Transpose(){GetOutput()->parent = this; pointer1 = NULL; pointer2 = NULL;};
	void Execute();
	void Update();
	const char* FilterName(){return "Transpose";};
};

class Invert:public filter{
	public:
	Invert(){GetOutput()->parent = this;};
	void Execute();
	void Update();
	const char* FilterName(){return "Invert";};

};
class Checkerboard:public filter{
	public: 
	Checkerboard(){GetOutput()->parent = this;};
	void Execute();
        void Update();
	const char* FilterName(){return "Checkerboard";};
};
class Color:public Source{
	unsigned char r, g, b;
	Pixel P;
	public:
	Color(int width, int height, unsigned char r, unsigned char green, unsigned char blue);
	void Execute();
        void Update();
	const char* SourceName(){return "Color";};
	

};
class CheckSum:public Sink{
	public:
	 CheckSum();
	~CheckSum();
	void Execute(){;};
	void OutputCheckSum(const char*);
	const char* SinkName(){return "CheckSum";};

};
#endif 
