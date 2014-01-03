CXX      = gcc   # for Linux RedHat 6.1, g++ version 2.95.2

CPPFLAGS = -Wall
LDFLAGS  = -lstdc++ -lCCfits


default:  Fit


Fit:   Fit.o
	${CXX} ${CPPFLAGS} -o Fit Fit.o ${LDFLAGS}


Fit.o:  Fit.cxx
	${CXX} ${CPPFLAGS} -c Fit.cxx
	


clean:
	rm Fit
	rm *.o
