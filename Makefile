CXX      = gcc   # for Linux RedHat 6.1, g++ version 2.95.2

CPPFLAGS = -Wall
LDFLAGS  = -lstdc++ -lCCfits -lgzstream -lz
INCLUDE  = -I/home/kgullikson/Applications/gzstream/gzstream
LIBRARY  = -L/home/kgullikson/Applications/gzstream/gzstream


default:  Fit


Fit:   Fit.o
	${CXX} ${CPPFLAGS} ${LIBRARY} -o Fit Fit.o ${LDFLAGS}


Fit.o:  Fit.cxx
	${CXX} ${CPPFLAGS} ${INCLUDE} -c Fit.cxx
	


clean:
	rm Fit
	rm *.o
