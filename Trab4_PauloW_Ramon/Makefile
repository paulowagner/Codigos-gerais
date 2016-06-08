OS := $(shell uname -s)

all:
    ifeq ("$(OS)", "Darwin")
	g++ Trab04.cpp Canon.cpp Object.cpp Rectangle.cpp Circle.cpp -o Trab03  -framework OpenGL -framework GLUT
    else
	g++ Trab04.cpp Canon.cpp Object.cpp Bala.cpp Rectangle.cpp Circle.cpp Tanque.cpp tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp -o Trab04 -lGL -lGLU -lglut
    endif

clean:
	rm -rf Trab04

run:
	./Trab04
