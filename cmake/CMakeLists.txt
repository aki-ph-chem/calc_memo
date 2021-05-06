

##### 普通にビルドする方法######

#の後はコメント文


#   CMakeのversion

#cmake_minimum_required(VERSION 3.16.3)

#   project name & langage 

#project(test_cmake CXX)

#   実行ファイル a.outを main.cpp souce.cpp から生成

#add_executable(a.out main.cpp souce.cpp)


###静的ライブラリを経由する方法###


cmake_minimum_required(VERSION 3.16.3)

project(cmake_test CXX)

# good.cpp souce.cpp　をコンパイルして静的ライブラリ　test.aを作成

add_library( test STATIC good.cpp souce.cpp )

# main.cppからa.outを作成

add_executable(a.out main.cpp)

# a.outを作成する際にはtest.aをリンクする

target_link_libraries(a.out test)

