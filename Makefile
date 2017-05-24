SRC=main.C image.C sink.C source.C PNMreader.C PNMwriter.C filters.C logging.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	icpc -fPIC -I$(TBBROOT)/include -std=c++11 $(OBJ) -o proj -L$(TBBLIB) -ltbb -fopenmp 

.C.o: $<
	icpc  -g  -fPIC -I$(TBBROOT)/include -std=c++11 -L$(TBBLIB) -ltbb -I. -c $<

clean:
	rm *.o proj
