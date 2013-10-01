CC=g++

LIBS=`pkg-config --cflags --libs opencv`

test: test.cpp ImageAnalyzer.cpp VideoAnalyzer.cpp Colors.hpp Config.hpp 
	${CC} $^ ${LIBS} -o $@