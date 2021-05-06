
# ルートディレクトリでのCMakeLists.txt

cmake_minimum_required(VERSION 3.16.3)
project(cmake_test CXX)

# サブディレクトリを登録
add_subdirectory(test)
add_subdirectory(src)