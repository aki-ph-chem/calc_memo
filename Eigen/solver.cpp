
#include<iostream>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Eigenvalues>

using Matrix3d = Eigen::Matrix3d;
using Matrix2d = Eigen::Matrix2d;

int main(){

Matrix3d M;

M << 1.0,0.5,2.3,
     0.5,0.9,-1.6,
     2.3,-1.6,4.8;
/*
Eigen::SelfAdjointEigenSolver<Matrix3d> ES(M); // ソルバーのインスタンス化と計算を同時に

if(ES.info() != Eigen::Success) abort();

std::cout<<"Eigen Value; "<<ES.eigenvalues().transpose() <<std::endl;
*/


// コンストラクタだけ先に呼び出して後で計算する
//ループ中で対角化する時などに

Eigen::SelfAdjointEigenSolver<Matrix3d> ES;

ES.compute(M);

if(ES.info() != Eigen::Success) abort();


std::cout<<"Eigen Value; "<<ES.eigenvalues().transpose() <<std::endl;

std::cout<<"Eigen vector; "<<ES.eigenvectors().transpose() <<std::endl;

return 0;

}