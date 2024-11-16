cmake_minimum_required(VERSION 3.28)
project(NeoSnakeGame)

set(CMAKE_CXX_STANDARD 20)

#cpp
file(GLOB SystemCPPS "./src/system/*.cpp")
file(GLOB RenderCPPS "./src/renderer/*.cpp")
file(GLOB ObjectCPPS "./src/object/*.cpp")

include_directories("./include")

add_executable(NeoSnakeGame main.cpp ${RenderCPPS} ${ObjectCPPS} ${SystemCPPS} ${HEADERS}
        include/system/LockQueue.h)
