all:
	g++ libioapp.cpp -std=c++17 -Os -Wall -c -fpic
	g++ -shared -o libioapp.so libioapp.o

install:
	#You'll probably want to run this as root.
	#Tested to work for Arch Linux
	install -m 755 -s libioapp.so /usr/lib/
	mkdir -p /usr/include/
	install -m 755 libioapp.hpp /usr/include/
clean:
	rm *.o *.so
