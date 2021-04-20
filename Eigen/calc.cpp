#include<iostream>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Geometry>

int main(){


//行列,ベクトルの演算について

using Matrix2d = Eigen::Matrix2d;
using Matrix3d = Eigen::Matrix3d;

Matrix2d Matrix_a,Matrix_b;

Matrix_a << 1,2,3,4;
Matrix_b <<5,6,7,8;

//普通の行列積 (行列Xベクトルも同じく書ける)

//std::cout<<Matrix_a*Matrix_b<<std::endl;

//アダマール積　( .array() Matrix -> Array の変換メソッドを用いる　)
// arrayの演算は Rのベクトルの演算と一緒

//std::cout<<Matrix_a.array()*Matrix_b.array()<<std::endl;

// i列目

//std::cout<<Matrix_a.col(0)<<std::endl;

// j行目

//std::cout<<Matrix_a.row(0)<<std::endl;

using Vector3d = Eigen::Vector3d;

Vector3d vector_1,vector_2;

vector_1 << 1,2,3;
vector_2 << 4,5,6;

//ノルム

//std::cout<<vector_1.norm()<<std::endl;

//転置


//std::cout<<Matrix_a.transpose()<<std::endl;
//std::cout<<vector_1.transpose()<<std::endl;

//回転行列


Vector3d axis;
Matrix3d Rot_matrix;
double rot_angle;

axis << Eigen::Vector3d::UnitZ();
rot_angle = M_PI/2;


Rot_matrix = Eigen::AngleAxisd(rot_angle,axis);

std::cout<<Rot_matrix<<std::endl;


/* その他

size:

Matrix_a.cols(), Matrix_a.rows(), vector_1.size()

trace:

Matrix_a.trase()

sumation:

vector_1.sum()

set vector as diagonal elements of matrix:

Matrix_a = vector_1.asDiagonal()

diagonal elements:

Matrix_a.diagonal()

head and tail of vector:

vector_1.head(i), vector_1.tail(i)


*/


    return 0;
}