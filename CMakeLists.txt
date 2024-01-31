cmake_minimum_required(VERSION 3.23)
project(jvmpro)

set(CMAKE_CXX_STANDARD 14)

add_executable(jvmpro main.cpp swap.cpp swap.h)
add_executable(thread_create thread_create.cpp)
add_executable(addDemo addDemo.cpp)
add_executable(myadd myadd.cpp)
