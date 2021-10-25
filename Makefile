CC=gcc
RM=rm -rf
EXENAME=test.exe
INCDIR=-I src
LDFLAG=-l stdc++
CFLAG=-Wall $(INCDIR) 
PI=-D NO_PI
CSRCS=main.cpp src/lib.cpp

all: clean
	$(CC) $(CSRCS) $(CFLAG) $(PI) -o ./build/$(EXENAME) $(LDFLAG)
	
clean:
	$(RM) ./build/*

run: all
	./build/$(EXENAME)