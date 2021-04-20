#include<iostream>
#include<eigen3/Eigen/Core>

int main(){

///////fixed size

//4次まで

using Vector3d = Eigen::Vector3d;
using Vector4d = Eigen::Vector4d;

//５次以上(templateで指定)

using Vector5d = Eigen::Matrix<double,5,1>; //Nx1行列として宣言

//Mapによる方法

double my_array[3] = {1,2,3};

Vector3d vector_1 = Eigen::Map<Vector3d>(&my_array[0],3,1);

std::cout<<vector_1<<std::endl;


//初期化の方法


Vector3d v1,v2,v3,v4,v5,v6,v7;


v1 = Eigen::Vector3d::Zero(); 
v2 = Eigen::Vector3d::Ones();
v3 = Eigen::Vector3d::UnitX();
v4 = Eigen::Vector3d::UnitY();
v5 = Eigen::Vector3d::UnitZ();
v6 = Eigen::Vector3d::Random();
v7 = Eigen::Vector3d::Constant(334);




    return 0;
}