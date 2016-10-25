Linerlist: linerlist.o
	g++ -o Linerlist linerlist.o
linerlist.o : linerlist.cpp
	g++ -o linerlist.o -c linerlist.cpp
clean:
	rm -rf *.o Linerlist