PROGRAM=300

a.out: AVL.o Command.o Date.o Tweet.o TweetDictionary.o
	g++ -std=c++11 -O3 $(PROGRAM).cpp AVL.o Command.o Date.o Tweet.o TweetDictionary.o -Werror -Wall

AVL.o: AVL.hpp Date.hpp Tweet.hpp
	g++ -std=c++11 -c AVL.cpp -Werror -Wall

Command.o: Command.hpp Date.hpp TweetDictionary.hpp
	g++ -std=c++11 -c Command.cpp -Werror -Wall

Tweet.o: Tweet.hpp Date.hpp
	g++ -std=c++11 -c Tweet.cpp -Werror -Wall

TweetDictionary.o: TweetDictionary.hpp AVL.hpp Tweet.hpp
	g++ -std=c++11 -c TweetDictionary.cpp -Werror -Wall

Date.o: Date.hpp
	g++ -std=c++11 -c Date.cpp -Werror -Wall

inputs:
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.in -O $(PROGRAM)a.in
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.out -O $(PROGRAM)a.out

diff:
	./a.out < $(PROGRAM)a.in > $(PROGRAM).out
	diff $(PROGRAM).out $(PROGRAM)a.out && (echo "validation passed"; exit 0) || (echo "output validation failed"; exit 1)

clean:
	rm -f *.o *.in *.out *.tar

tar:
	tar -cf archivo.tar *.cpp *.hpp Makefile

.PHONY: clean diff inputs tar