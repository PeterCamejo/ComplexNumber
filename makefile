CC = g++ -std=c++0x

all: Complex.h
	$(CC) -c Complex.cpp
test: all
	$(CC) -o UnitTest UnitTest.cpp Complex.o && ./UnitTest
clean:
	rm -rf *.o core && rm -rf *exe UnitTest
zip:
	zip -r Complex Complex.cpp Complex.h UnitTest.cpp include makefile README.txt
