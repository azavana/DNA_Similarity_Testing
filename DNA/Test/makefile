test.exe: DNA.o test.o
		g++ test.o DNA.o -o test.exe
test.o: test.cpp DNA.h
	   g++ -c test.cpp
DNA.o: DNA.cpp DNA.h
	  g++ -c DNA.cpp 
