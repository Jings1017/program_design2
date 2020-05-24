Demo: Demo.o HugeInt.o
	g++ -o Demo HugeInt.o Demo.o
Demo.o: HugeInt.h Demo.cpp
	g++ -c Demo.cpp
HugeInt.o: HugeInt.h HugeInt.cpp
	g++ -c HugeInt.cpp

clean:
	rm Demo *.o