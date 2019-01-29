#Aliases
SOURCE = line.cpp \
         ellipse.cpp \
         FilledEllipse.cpp \
         rectangle.cpp \
         FilledRectangle.cpp \
         functions.cpp \
         main.cpp


OBJS = $(SOURCE:.cpp=.o)

GCC = g++

LINK = g++

CFLAGS = -Wall -O3 -std=c++11 -I.
CXXFLAGS = $(CFLAGS)

LIBS = -lglut -lGL -lGLU -lm -std=gnu++0x

.PHONY: clean

# Commands:

all : main

main : $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d *.gch core main

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: main

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; /usr/bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@
