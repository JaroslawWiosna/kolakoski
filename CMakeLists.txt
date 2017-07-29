cmake_minimum_required (VERSION 2.8)

option(BUILD_TESTS "Build tests" OFF)

SET(CMAKE_CXX_STANDARD 14)
SET(COMPILE_FLAGS "-g -std=c++14 -std=gnu++14 -Wall")
SET(LINK_FLAGS "-lgtest -lpthread -lm")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}" )
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINK_EXECUTABLE} ${LINK_FLAGS}" )
include_directories(${GTEST_INCLUDE_DIRS})
#include_directories(  )
set(files
#
)

find_package(Gtest)
add_executable(kolakoski main.cpp ${files}) 
target_link_libraries(kolakoski gtest)
 
if(BUILD_TESTS)
  add_subdirectory(test)
endif()

