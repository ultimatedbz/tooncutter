# CSE 167 Fall 2014 Makefile for Mac OSX 10.9 by Tyler Levine
# Adapted from Aaron Schwartz' OSX Makefile from Fall 2010

NAME    = cube
ECHO    = @echo
CC      = @llvm-gcc
LIBS    = -framework GLUT -framework OpenGL -framework Cocoa -L/opt/local/lib -lpng16
LDFLAGS = -lstdc++
INC = -I/opt/local/include/libpng16
CFLAGS  =
SOURCES = $(wildcard *.c)
OBJS    = $(patsubst %.c, %.o, $(SOURCES))

.SUFFIXES: .c .h .o

.cpp.o:
	$(ECHO) "Compiling $<"
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(ECHO) "Linking $@..."
	$(CC) -o $@ *.o $(LIBS) $(LDFLAGS) -o $(NAME)
	$(ECHO) "Built $@!"

clean:
	$(RM) core *.o $(NAME)
	$(ECHO) "All clean!"

new:
	make clean
	make
