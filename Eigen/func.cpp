#include<iostream>
#include<eigen3/Eigen/Core>


using Matrix3d = Eigen::Matrix3d;


// Matrix を引数にするときは参照渡しにする
double array_func(Matrix3d & x_matrix){

    double value;

    value  = x_matrix(0,0);

    return value;
}

// 


int main(){


    Matrix3d A_matrix;

    A_matrix << 1,2,3,
                4,5,6,
                7,8,9;

    
    std::cout<< array_func(A_matrix) <<std::endl;



    return 0;
}