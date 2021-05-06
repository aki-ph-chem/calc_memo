
#サブディレクトリ(souce file)でのCMakeLists.txt

# 共有ライブラリ sourceのコンパイルの仕方を指定

add_library(sample

SHARED

good.cpp
souce.cpp

)

# testライブラリのinclude pathを指定

# ここで PROJECT_SOURCE_DIRはプロジェクトのルートディレクトリの絶対path

target_include_directories(sample

PUBLIC ${PROJECT_SOURCE_DIR}/include

)

