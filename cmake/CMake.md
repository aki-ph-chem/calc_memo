
# CMake の導入

terminalで　sudo apt-get install cmakeで　導入　（最新ではないらしい)

Qiitaのこの記事を参考にした

>https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
>https://qiita.com/shohirose/items/637f4b712893764a7ec1



# 　STEP 1やってみる

1) souce codeのあるディレクトリに CMakeLists.txtに以下のように書き込む




>cmake_minimum_required(VERSION 3.16.3)    # CMake version

>project(test_cmake CXX)                   # project名と使用する言語を設定

>add_executable(a.out main.cpp souce.cpp) #実行ファイル a.out をmain.cpp souce.cpp から生成



2) souce codeのあるディレクトリ内にビルド用のディレクトリを作成する

ここではbuildとする

>mkdir build

>cd    build

3) ビルド用ディレクトリ内でビルドを実行

>cmake ..
>make

実行ファイルはbuild下に生成されている

# STEP 2 　静的・共有ライブラリを作成

### 静的ライブラリ

1) ソースをコンパイル -> オブジェクトファイル(*.oファイル)

> g++ -c  souce.cpp  good.cpp　 

2) オブジェクトファイルから静的ライブラリ(*.a ファイル) を作成

> ar rvs test.a souce.o good.o 

3) main.cppをコンパイルする際にリンクして実行ファイルを作成する

> g++ main.cpp test.a

### 共有ライブラリ

1) このやり方はよくわからなかったので自分でbuildする方法は後回し

## CMakeでやってみる

### 静的ライブラリ


> cmake_minimum_required(VERSION 3.16.3)

> project(cmake_test CXX)

> add_library( test STATIC good.cpp souce.cpp ) # good.cpp souce.cpp　をコンパイルして静的ライブラリ　test.aを作成


> add_executable(a.out main.cpp) # main.cppからa.outを作成

> target_link_libraries(a.out test) # main.cppからa.outを作成

### 共有ライブラリを経由する方法


>cmake_minimum_required(VERSION 3.16.3)
>project(cmake_test CXX)


>add_library(test SHARED good.cpp souce.cpp ) # good.cpp souce.cpp をコンパイルして共有ライブラリ　test.soを作成


>add_executable(a.out main.cpp) # main.cpp から a.outを作成 


>target_link_libraries(a.out test) # a.outを作成する際には test.soをリンクする



# STEP 3 souce code がサブディレクトリに分散している場合


> ---/
> |
> | ---include/
> |      | --good.h
> |      | --class.h
> |
> | --- src/
> |      | -- good.cpp
> |      | -- souce.cpp
> |
> | --- main/
> |      | --- main.cpp     



## サブディレクトリが存在するときはディレクトリごとにCMakeLists.txtを書く


1) @ ルートディレクトリ



ルートディレクトリでのCMakeLists.txt

>cmake_minimum_required(VERSION 3.16.3)
>project(cmake_test CXX)

 サブディレクトリを登録
>add_subdirectory(test)
>add_subdirectory(src)


2) @ src


サブディレクトリ(souce file)でのCMakeLists.txt

共有ライブラリ sourceのコンパイルの仕方を指定

>add_library(sample

>SHARED

>good.cpp
>souce.cpp

>)

 testライブラリのinclude pathを指定

 ここで PROJECT_SOURCE_DIRはプロジェクトのルートディレクトリの絶対path

>target_include_directories(sample

>PUBLIC ${PROJECT_SOURCE_DIR}/include

>)


3) @ test

 main.cppディレクトリでのCMakeLists.txt


 main.cppからa.outを作成

>add_executable(a.out main.cpp)

 a.out を作成する際にtestをリンクする

>target_link_libraries(a.out sample)




