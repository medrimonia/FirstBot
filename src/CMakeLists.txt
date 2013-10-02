cmake_minimum_required (VERSION 2.6)
project (Robot)

find_package (OpenCV REQUIRED)

set (SOURCES
    Driver.cpp
    Order.cpp
    ImageAnalyzer.cpp
    Robot.cpp
    serialib.cpp
    VideoAnalyzer.cpp
    )

add_executable (Robot main.cpp ${SOURCES})
add_executable (testVision test.cpp ${SOURCES})
target_link_libraries (Robot ${OpenCV_LIBS})
target_link_libraries (testVision ${OpenCV_LIBS})