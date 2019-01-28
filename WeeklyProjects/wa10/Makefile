SOURCE = disjoint.cpp \
         util.cpp \
         drawGrid.cpp \
         function.cpp \
         event.cpp \
         main.cpp

TEST_SRC = testFind.cpp testFind2.cpp testFind3.cpp testMakeSet.cpp \
           testMakeSet2.cpp testMakeSet3.cpp testUnion.cpp

OBJS = $(SOURCE:.cpp=.o)
TEST_OBJS = $(TEST_SRC:.cpp=.o)
TEST_EXES = $(TEST_OBJS:.o=)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O -std=c++11
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lglut -lGLU -lGL -lm -lpthread

.PHONY: clean

# Targets include all, clean, debug, tar

all : main

main: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

tests: $(TEST_EXES)

testFind: testFind.cpp
	$(GCC) -o $@ $^ disjoint.cpp $(CFLAGS) $(LIBS)

testFind2: testFind2.cpp
	$(GCC) -o $@ $^ disjoint.cpp $(CFLAGS) $(LIBS)

testFind3: testFind3.cpp
	$(GCC) -o $@ $^ disjoint.cpp $(CFLAGS) $(LIBS)

testMakeSet: testMakeSet.cpp
	$(GCC) -o $@ $^ disjoint.cpp $(CFLAGS) $(LIBS)

testMakeSet2: testMakeSet2.cpp
	$(GCC) -o $@ $^ disjoint.cpp $(CFLAGS) $(LIBS)

testMakeSet3: testMakeSet3.cpp
	$(GCC) -o $@ $^ disjoint.cpp $(CFLAGS) $(LIBS)

testUnion: testUnion.cpp
	$(GCC) -o $@ $^ disjoint.cpp $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o *.d core main $(TEST_EXES)

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: main

tar: clean
	tar zcvf main.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make main  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; /usr/bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

