#include<iostream>
#include<vector>

using vector_d = std::vector<double>;

//配列を引数にするならばポインタ渡し
double func_p(double* array,int i){

return array[i];

 }

// std::vectorを用いて参照渡し
double func_ref(vector_d& array,int i){

    return array[i];
}



int main(){

//double array_sample[3] = {1,2,3};
vector_d array_sample = {1,2,3};

for(int i=0;i<3;i++){
    
    std::cout<<func_ref(array_sample,i)<<std::endl;
}


}