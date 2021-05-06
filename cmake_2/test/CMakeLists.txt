
# main.cppディレクトリでのCMakeLists.txt


# main.cppからa.outを作成

add_executable(a.out main.cpp)

# a.out を作成する際にtestをリンクする

target_link_libraries(a.out sample)