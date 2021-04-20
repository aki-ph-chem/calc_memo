#include<iostream>
#include<eigen3/Eigen/Core>


/* header ファイルの読み込みは　Eigen/Coreが基本で必要に応じて色々足す

Eigen/Geometry -> 回転行列、ベクトル積

Eigen/Eigenvalues -> 固有値

等々

*/

int main(){

////////////fixed size



//4次まで(4次以上、長方形行列はtemplateで指定)

Eigen::Matrix2d matrix_1;
Eigen::Matrix3d matrix_2;
Eigen::Matrix4d matrix_3;


matrix_1 << 1,2,
            3,4;

matrix_2 << 1,2,3,
            4,5,6,
            7,8,9;

matrix_3 << 1,2,3,4,
            2,3,4,5,
            3,4,5,6,
            4,5,6,7;


std::cout<< matrix_1 <<std::endl;

std::cout << matrix_2 <<std::endl;

std::cout << matrix_3 <<std::endl;





//template を用いる方法　


// typedefで定義

typedef Eigen::Matrix<double, 3,3> matrix_3x3;

// using で定義 (C++ 11の方法)

using matrix_2x2 = Eigen::Matrix<double,2,2>;

matrix_3x3 A;

matrix_2x2 B;

A << 1,2,3,
     4,5,6,
     7,8,9;

B <<1,2,
    3,4;

std::cout<<A<<std::endl;

std::cout<< "A_{0,0} 成分は A(0,0)と書くすなわち" << A(0,0) <<std::endl;

std::cout << B <<std::endl;





// Map による方法

// 1) 1 dimentional array -> matrix

double my_array_2x2[4] = {1,2,3,4};

Eigen::Matrix2d A_mat;
Eigen::Matrix2d B_mat;

//引数に配列の先頭のアドレスを入れる

A_mat = Eigen::Map<Eigen::Matrix2d> (&my_array_2x2[0],2,2);
B_mat = Eigen::Map<Eigen::Matrix<double,2,2>>(&my_array_2x2[0],2,2);

//デフォルトではColMajor
std::cout<<A_mat<<std::endl; 
std::cout<<B_mat<<std::endl;

// 2) 2 dimentional array -> 

double my_array_2d[2][2] = {1,2,
                            3,4};

Eigen::Matrix2d C_mat;

C_mat = Eigen::Map<Eigen::Matrix<double,2,2>>(&my_array_2d[0][0],2,2);

std::cout<<C_mat<<std::endl;



// Matrix -> container

Eigen::Matrix<double,2,2,Eigen::RowMajor> D_mat;
Eigen::Matrix<double,2,2,Eigen::ColMajor> E_mat;


D_mat <<1,2,3,4;
E_mat << 1,2,3,4;

double a_r_r_a_y_1[4];
double a_r_r_a_y_2[4];

Eigen::Map< Eigen::Matrix<double,2,2,Eigen::RowMajor> > (&a_r_r_a_y_1[0],2,2) = D_mat;
Eigen::Map< Eigen::Matrix<double,2,2,Eigen::ColMajor> > (&a_r_r_a_y_2[0],2,2) = E_mat;

for(int i=0;i<4;i++){

std::cout<<a_r_r_a_y_1[i]<<std::endl;

};

for(int i=0;i<4;i++){

std::cout<<a_r_r_a_y_2[i]<<std::endl;

};






// ColMajor or RowMajor

using matrix_2x2_RowMajor = Eigen::Matrix<double,2,2,Eigen::RowMajor>;
using matrix_2x2_ColMajor = Eigen::Matrix<double,2,2,Eigen::ColMajor>;

matrix_2x2_RowMajor matrix_a;
matrix_2x2_ColMajor matrix_b;

double test_array_2d[4] = {1,2,3,4};


matrix_a = Eigen::Map<matrix_2x2_RowMajor>(&test_array_2d[0]);
matrix_b = Eigen::Map<matrix_2x2_ColMajor>(&test_array_2d[0]);


std::cout<<matrix_a<<std::endl;
std::cout<<matrix_b<<std::endl;



// 初期化するときのやり方


Eigen::Matrix2d A_Matrix;

A_Matrix = Eigen::MatrixXd::Zero(2,2); //zeroで初期化



//以下のような方法がある



//A_Matrix = Eigen::MatrixXd::Ones(2,2);   //1で初期化
//A_Matrix = Eigen::MatrixXd::Constant(2,2,3.14); //3.14で初期化
//A_Matrix = Eigen::MatrixXd::Identity(2,2); //単位行列
//A_Matrix = Eigen::MatrixXd::Zero(2,2);
//A_Matrix = Eigen::MatrixXd::Random(2,2); //random






std::cout<<A_Matrix<<std::endl;




return 0;

}