PROGRAM=002

a.out:
	g++ $(PROGRAM).cpp -Werror -Wall

inputs:
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.in -O $(PROGRAM)a.in
	wget http://dis.um.es/profesores/ginesgm/files/doc/aed/practicas/$(PROGRAM)a.out -O $(PROGRAM)a.out

diff:
	./a.out < $(PROGRAM)a.in > $(PROGRAM).out
	diff $(PROGRAM).out $(PROGRAM)a.out || (echo "output validation failed"; exit 1)

clean:
	rm -f *.o *.in *.out *.tar

tar:
	# tar -cf archivo.tar *.cpp *.h *.hpp Makefile
	tar -cf archivo.tar *.cpp Makefile

.PHONY: clean diff inputs tar