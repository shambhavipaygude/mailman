cmake_minimum_required(VERSION 3.30)
project(mailman)

set(CMAKE_CXX_STANDARD 20)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

add_executable(mailman main.cpp
        request.cpp
        request.h
        validator.cpp
        validator.h
)

target_link_libraries(mailman ${CURL_LIBRARIES})
