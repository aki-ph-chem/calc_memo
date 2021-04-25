#include<iostream>

class static_sample{

    public: void input(double input_1, double input_2);
            void do_calc();
            void print_result();

            static double delt;


    private: double var_1, var_2;

             void add_two_values();
             double result_of_add;

             void mul_two_values();
             double result_of_mul;
             
             void div_two_values();
             double result_of_div;
             bool div_by_zero; 
};

double static_sample::delt = 0;

void static_sample::input(double input_1,double input_2){
    var_1 = input_1;
    var_2 = input_2;
}

void static_sample::add_two_values(){

    result_of_add = var_1 + var_2 + delt;
}

void static_sample::mul_two_values(){

    result_of_mul = var_1*var_2 + delt;
}

void static_sample::div_two_values(){

    if(var_2 == 0){

        div_by_zero = true;
    }
   else{
    result_of_div = var_1/var_2 + delt ;

      div_by_zero = false;
   }
}

void static_sample::do_calc(){

    this->add_two_values();
    this->mul_two_values();
    this->div_two_values();
}

void static_sample::print_result(){

    std::cout<<"result_of_add "<<result_of_add<<std::endl;
    std::cout<<"result_of_mul "<<result_of_mul<<std::endl;

    if(div_by_zero){
        std::cout<<"Error! input_1 is divided by 0"<<std::endl;
    }
    else{
        std::cout<<"result_of_div "<<result_of_div<<std::endl;
    }
}

int main(){

    //public ,private 変数はインスタンスによって違うことがあり得るが
    //static変数は同じクラスならばインスタンスによらない
    
    static_sample::delt = 0.005;

    static_sample S;

    S.input(3,0);
    S.do_calc();
    S.print_result();

    static_sample SS;

    SS.input(3,8);
    SS.do_calc();
    SS.print_result();

    return 0;
}