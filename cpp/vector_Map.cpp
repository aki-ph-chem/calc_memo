#include<iostream>
#include<vector>
#include<eigen3/Eigen/Core>

using vector_1d = std::vector<double>;
using vector_2d = std::vector<std::vector<double>>;

using Matrix3d = Eigen::Matrix<double,3,3,1>;



vector_1d x = {1,2,3};
vector_1d y = {4,5,6};
vector_1d z = {7,8,9};

vector_2d vv;

double vv_2[3][3] = {1,2,3,
                     4,5,6,
                     7,8,9};

Matrix3d Matrix_1;
Matrix3d Matrix_2;


int main(){

vv.push_back(x);
vv.push_back(y);
vv.push_back(z); 

Matrix_1 = Eigen::Map<Matrix3d>(&vv_2[0][0],3,3);


// １次元配列を２次元配列にpush_back()することによって二次元配列に格納していくと
// メモリのアドレスが連続にならないのでMapメソッドがうまく働かない

//Matrix_2 = Eigen::Map<Matrix3d>(&(vv[0][0]),3,3);

//std::cout<<Matrix_1<<std::endl;


//普通の２次元配列とstd::vector<std::vector<double>>のアドレスを調べる

std::cout<<"adress of vv_2"<<std::endl;

for(int j=0;j<3;j++){
    for(int i=0;i<3;i++){
    std::cout<<&vv_2[j][i]<<std::endl;
    }
}

std::cout<<"adress of vv"<<std::endl;


for(int j=0;j<3;j++){
    for(int i=0;i<3;i++){
    std::cout<<&vv[j][i]<<std::endl;
    }
}

std::cout<<"adress of x (1st row of vv)"<<std::endl;

for(int i=0;i<3;i++){

    std::cout<<&x[i]<<std::endl;

}


return 0;
}