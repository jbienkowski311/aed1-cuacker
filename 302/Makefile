PROGRAM=302

a.out: AVL.o Command.o Date.o HashTable.o Tweet.o TweetDictionary.o
	g++ -std=c++11 -O3 $(PROGRAM).cpp AVL.o Command.o Date.o HashTable.o Tweet.o TweetDictionary.o -Werror -Wall

AVL.o: AVL.hpp Date.hpp Tweet.hpp
	g++ -std=c++11 -c AVL.cpp -Werror -Wall

Command.o: Command.hpp Date.hpp TweetDictionary.hpp
	g++ -std=c++11 -c Command.cpp -Werror -Wall

HashTable.o: HashTable.hpp Tweet.hpp
	g++ -std=c++11 -c HashTable.cpp -Werror -Wall

Tweet.o: Tweet.hpp Date.hpp
	g++ -std=c++11 -c Tweet.cpp -Werror -Wall

TweetDictionary.o: TweetDictionary.hpp AVL.hpp HashTable.hpp Tweet.hpp
	g++ -std=c++11 -c TweetDictionary.cpp -Werror -Wall

Date.o: Date.hpp
	g++ -std=c++11 -c Date.cpp -Werror -Wall

inputs:
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.in -O $(PROGRAM)a.in
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.out -O $(PROGRAM)a.out

diff:
	./a.out < 200a.in > 200.out
	diff 200.out 200a.out && (echo "validation passed"; exit 0) || (echo "output validation 200 failed"; exit 1)
	./a.out < 300a.in > 300.out
	diff 300.out 300a.out && (echo "validation passed"; exit 0) || (echo "output validation 300a failed"; exit 1)
	./a.out < 300b.in > 300.out
	diff 300.out 300b.out && (echo "validation passed"; exit 0) || (echo "output validation 300b failed"; exit 1)
	./a.out < 301a.in > 301.out
	diff 301.out 301a.out && (echo "validation passed"; exit 0) || (echo "output validation 301 failed"; exit 1)
	./a.out < $(PROGRAM)a.in > $(PROGRAM).out
	diff $(PROGRAM).out $(PROGRAM)a.out && (echo "validation passed"; exit 0) || (echo "output validation failed"; exit 1)

clean:
	#rm -f *.o *.in *.out *.tar
	rm -f *.o *.tar

tar:
	tar -cf archivo.tar *.cpp *.hpp Makefile

.PHONY: clean diff inputs tar