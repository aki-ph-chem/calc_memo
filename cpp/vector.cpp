#include<iostream>
#include<vector>

int main(){

//1 dimentional vector

using vector_1d = std::vector<double>;

vector_1d v_1 = {1,2,3};  //具体的な値で初期化
vector_1d v_2(3);        //長さ３に指定して初期化しない
vector_1d v_3(3,0);      //長さ3ですべて0で初期化
vector_1d v_4;           //長さも成分も初期化しない
vector_1d v_5();         //同じく

//長さを指定して宣言したとき
for(int i=0;i<3;i++){

    v_2[i] = i+1;
}

//長さを指定せずに宣言した時
for(int i=0;i<3;i++){

    v_4.push_back(i+1);
}

//v_1のサイズ

std::cout<<"size of v_1 ; "<<v_1.size()<<std::endl;

// v_1を長さ３から長さ２に変更
v_1.resize(2);

std::cout<<"size of v_1 ; "<<v_1.size()<<std::endl;



// 2 dimentional vector

using vector_2d = std::vector<std::vector<double>>;

vector_2d w_1;     //サイズを指定せずに宣言
vector_2d w_2();  //同じく

vector_2d w_3(4); //?? 要素数が4になる?
vector_2d w_4(2,vector_1d(2)); //１次元配列に１次元配列を入れる形で宣言(サイズ固定)
vector_2d w_5(2,vector_1d(2,0)); //すべて0で2x2の２次元配列を初期化

vector_1d input_v_1 = {1,2};
vector_1d input_v_2 = {3,4};


//これはいける

w_1.push_back(input_v_1);
w_1.push_back(input_v_2);

// w_1のサイズ

std::cout<<"size of w_1 ; "<<w_1.size()<<std::endl;

// w_1を2x2から1x1にリサイズ

w_1.resize(1);

for(int i=0;i<2;i++){
  
  w_1[i].resize(1);
}

std::cout<<"size of w_1 ; "<<w_1.size()<<std::endl;


//これはダメ
/*
vector_1d input_v_3 = {1,2,3,4};

w_1.push_back(input_v_3);
*/

/*

for(int i=0;i<2;i++){
    std::cout<<w_1[i][0]<<","<<w_1[i][1]<<std::endl;
}

*/



//これはダメ
/*

w_3.push_back(input_v_1);
w_3.push_back(input_v_2);


for(int i=0;i<2;i++){
    std::cout<<w_3[i][0]<<","<<w_3[i][1]<<std::endl;
}

*/

vector_2d w_6;

vector_1d x_1 = {1,2,3};
vector_1d x_2 = {4,5,6};
vector_1d x_3 = {7,8,9};

w_6.push_back(x_1);
w_6.push_back(x_2);
w_6.push_back(x_3);



for(int i=0;i<3;i++){
    std::cout<<w_6[i][0]<<","<<w_6[i][1]<<","<<w_6[i][2]<<std::endl;
}



// size of w_6
 std::cout<<w_6[0].size()<<std::endl;


// for w_3,w_4





for(int i=0;i<2;i++){
  
  for(int j=0;j<2;j++){
    
    w_4[i][j] = i + j;
  }
}

for(int k=0;k<2;k++){
  
  std::cout<<w_4[k][0]<<","<<w_4[k][1]<<std::endl;
}


    return 0;
}