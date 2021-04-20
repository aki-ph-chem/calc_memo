#include<iostream>
#include<eigen3/Eigen/Core>


int main(){

//////dynamic size 

//Matrixxdによる方法

Eigen::MatrixXd A_mat(3,3);
Eigen::VectorXd A_vec(3);

// 上の書き方だと()のせいで関数とみられてclassの変数にできなかった
//　あとRowMajoer, ColMajorの指定もできない

// tenplateによる方法


Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> a_mat;

const int v_a = -1;  // Eigen::Dynamicの意味

Eigen::Matrix<double,v_a,v_a> b_mat; 

double test_array[9] = {1,2,3,4,5,6,7,8,9};

b_mat = Eigen::Map<Eigen::Matrix<double,v_a,v_a,Eigen::RowMajor>>(&test_array[0],3,3);

//std::cout<<b_mat<<std::endl;

//using r_m = Eigen::RowMajor;

const int r_m = 1; // Eigen::RowMajorの意味

Eigen::Matrix<double,v_a,v_a,r_m> c_mat;

const int c_m = 0;  // Eigen::ColMajorの意味

c_mat = Eigen::Map<Eigen::Matrix<double,v_a,v_a,r_m>>(&test_array[0],3,3);


Eigen::Matrix<double,v_a,v_a,c_m> d_mat;

d_mat = Eigen::Map<Eigen::Matrix<double,v_a,v_a,c_m>>(&test_array[0],3,3);

std::cout<<d_mat<<std::endl;

    return 0;
    }