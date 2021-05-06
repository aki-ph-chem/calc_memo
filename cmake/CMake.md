
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

1) 