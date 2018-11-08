PROGRAM=004

a.out: Date.o Tweet.o Messages.o
	g++ $(PROGRAM).cpp Date.o Tweet.o Messages.o -Werror -Wall

Messages.o: Messages.hpp
	g++ -c Messages.cpp

Tweet.o: Tweet.cpp Tweet.hpp Date.hpp
	g++ -c Tweet.cpp

Date.o: Date.cpp Date.hpp
	g++ -c Date.cpp

inputs:
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.in -O $(PROGRAM)a.in
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.out -O $(PROGRAM)a.out

diff:
	./a.out < $(PROGRAM)a.in > $(PROGRAM).out
	diff $(PROGRAM).out $(PROGRAM)a.out || (echo "output validation failed"; exit 1)

clean:
	rm -f *.o *.in *.out *.tar

tar:
	tar -cf archivo.tar *.cpp *.hpp Makefile

.PHONY: clean diff inputs tar