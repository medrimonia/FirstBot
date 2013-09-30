CC=g++

LIBS=`pkg-config --cflags --libs opencv`

test: test.cpp LineAnalyzer.cpp
	${CC} $^ ${LIBS} -o $@