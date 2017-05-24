SRC=main3G.C image.C sink.C source.C PNMreader.C PNMwriter.C filters.C logging.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	icpc -fPIC $(OBJ) -fopenmp -o proj3G

.C.o: $<
	icpc -fPIC -g -I. -c $<

clean:
	rm *.o proj3G
