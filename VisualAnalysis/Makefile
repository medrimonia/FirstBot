CC=g++

LIBS=`pkg-config --cflags --libs opencv`

main: main.cpp ImageAnalyzer.cpp VideoAnalyzer.cpp Colors.hpp Config.hpp Driver.cpp Driver.hpp Order.cpp
	${CC} $^ ${LIBS} -o $@

test: test.cpp ImageAnalyzer.cpp VideoAnalyzer.cpp Colors.hpp Config.hpp 
	${CC} $^ ${LIBS} -o $@