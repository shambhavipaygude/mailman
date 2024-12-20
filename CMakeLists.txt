cmake_minimum_required(VERSION 3.22)
project(mailman)

set(CMAKE_CXX_STANDARD 20)

#find curl
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

#include directories
include_directories(${CMAKE_SOURCE_DIR}/include)


add_executable(mailman src/main.cpp
        src/request.cpp
        src/get.cpp
        include/get.h
)

target_include_directories(mailman PRIVATE ${CMAKE_SOURCE_DIR}/include ${CURL_INCLUDE_DIRS})
target_link_libraries(mailman ${CURL_LIBRARIES})
