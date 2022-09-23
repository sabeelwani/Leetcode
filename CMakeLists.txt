cmake_minimum_required(VERSION 3.23)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)


include_directories(.)
include_directories(problems)
include_directories(template)

#add_executable(Leetcode
#        template/template.h problems/leetcode_120.cpp)
add_executable(Leetcode
        template/template.h
        problems/Leetcode_85.cpp)