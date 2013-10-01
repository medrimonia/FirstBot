CC=g++

LIBS=`pkg-config --cflags --libs opencv`

test: test.cpp ImageAnalyzer.cpp VideoAnalyzer.cpp
	${CC} $^ ${LIBS} -o $@