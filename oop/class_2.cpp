#include<iostream>

class c_d{
    public: void input(double input_1,double input_2);
            void print_result();
            void do_calc();

            c_d();  // コンストラクタ
            ~c_d(); //デストラクタ
    
    private: double var_1, var_2;
             
             void add();
             double result_of_add;

             void mul();
             double result_of_mul;

};

c_d::c_d():var_1(0),var_2(0){

    std::cout<<"変数を初期化しました"<<std::endl;
}

c_d::~c_d(){

    std::cout<<"ジョブ終わり"<<std::endl;
}

void c_d::input(double input_1,double input_2){

    var_1 = input_1;
    var_2 = input_2;
}

void c_d::add(){

result_of_add = var_1 + var_2;

}

void c_d::mul(){

result_of_mul = var_1 * var_2;

}

void c_d::do_calc(){

    this->add();
    this->mul();
}

void c_d::print_result(){

    std::cout<<"result of add: "<<result_of_add<<std::endl;

    std::cout<<"result of mul: "<<result_of_mul<<std::endl;
}

int main(){

//このコードではインスタンス化される時にコンストラクタが走り、
//main()の最後でデストラクタが走る

/*
    c_d C;

    C.input(1,2);

    C.do_calc();

    C.print_result();
*/

// new, deleteでコンストラクタ、デストラクタのタイミングを調整できる



c_d* CC = nullptr;

CC = new c_d(); //インスタンス化

CC->input(1,2);
CC->do_calc();
CC->print_result();

delete CC;　//デストラクタ


return 0;
}