GCC = g++
LINK = g++

CFLAGS = -Wall -O3 -std=c++11
CXXFLAGS = $(CFLAGS)

EXES = main mainBFS mainDFS

all : $(EXES)

main: main.o graph.o
	$(LINK) -o $@ $^

mainDFS: mainDFS.o graph.o dfsPaths.o
	$(LINK) -o $@ $^

mainBFS: mainBFS.o graph.o bfsPaths.o
	$(LINK) -o $@ $^

clean:
	rm -rf *.o $(EXES)
