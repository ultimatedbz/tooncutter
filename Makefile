# CSE 167 Fall 2014 Makefile for Mac OSX 10.9 by Tyler Levine
# Adapted from Aaron Schwartz' OSX Makefile from Fall 2010

NAME    = ToonCutter 
ECHO    = @echo
CC      = @llvm-gcc
LIBS    = -framework GLUT -framework OpenGL -framework Cocoa -L/opt/local/lib -lpng16
INC = -I/opt/local/include/libpng16
LDFLAGS = -lstdc++
CFLAGS  =
SOURCES = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SOURCES))
CSOURCES = $(wildcard *.c)
COBJS = $(patsubst %.c, %.o, $(CSOURCES))

.SUFFIXES: .c .cpp .h .o

.c.cpp.o:
	$(ECHO) "Compiling $<"
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(COBJS)
	$(ECHO) "Linking $@..."
	$(CC) -o $@ *.o $(LIBS) $(LDFLAGS) -o $(NAME)
	$(ECHO) "Built $@!"

clean:
	$(RM) core *.o $(NAME)
	$(ECHO) "All clean!"

new:
	make clean
	make
