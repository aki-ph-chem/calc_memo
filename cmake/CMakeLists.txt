
# CMakeのversion

cmake_minimum_required(VERSION 3.16.3)

# project name & langage 

project(test_cmake CXX)

# 実行ファイル a.outを main.cpp souce.cpp から生成

add_executable(a.out main.cpp souce.cpp)

