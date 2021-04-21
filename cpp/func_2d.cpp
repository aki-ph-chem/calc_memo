#include<iostream>

double array[3][3] ={

    1,2,3,
    4,5,6,
    7,8,9
};

//２次元配列を引数にするとき、シングルポインタを用いる
double func(double *array,int i,int j){

    return array[3*i + j];
}

int main(){

  double* pointer_of_array = &array[0][0];

  std::cout<<func(pointer_of_array,0,0)<<std::endl;

  return 0;

}