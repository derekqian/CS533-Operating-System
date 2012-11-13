CC	= /usr/bin/g++
CFLAGS	= -Wall
CXXFLAGS=-O3

all : ./lib/libbinpro.so test

./lib/libbinpro.so : binpro.o
	$(CC) $(CXXFLAGS) -shared -fPIC -Wl,-rpath=./lib binpro.o -L./lib -ldyninstAPI -ldwarf -linstructionAPI -lsymtabAPI -lcommon -lparseAPI -o ./lib/libbinpro.so

binpro.o: binpro.C
	$(CC) -g -fPIC -c $(CFLAGS) -I./include binpro.C

test : test.o
	$(CC) $(CXXFLAGS) test.o -L./lib -lbinpro -liberty -o test

test.o: test.C
	$(CC) -g -c $(CFLAGS) -I./include test.C

example : example.o
	$(CC) $(CXXFLAGS) example.o -L./lib -ldyninstAPI -ldwarf -linstructionAPI -lsymtabAPI -lcommon -lparseAPI -liberty -lc -o example

example.o: example.C
	$(CC) -g -c $(CFLAGS) -I./include example.C

coverage : coverage.o
	$(CC) coverage.o -L./lib -ldyninstAPI -lsymtabAPI -lcommon -liberty -o coverage

coverage.o: coverage.C
	$(CC) -g -c $(CFLAGS) -I./include coverage.C

maxarg : maxarg.o
	$(CC) $(CXXFLAGS) maxarg.o -L./lib -ldyninstAPI -ldwarf -linstructionAPI -lsymtabAPI -lcommon -lparseAPI -liberty -lc -o maxarg

maxarg.o: maxarg.C
	$(CC) -g -c $(CFLAGS) -I./include maxarg.C

clean:
	@rm -f *.o coverage maxarg test

