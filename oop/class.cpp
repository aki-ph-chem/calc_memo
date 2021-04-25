#include<iostream>

class sample{
    
    // publicはインスタンスからアクセスすることのできる変数、関数
    // privateはインスタンスからはアクセスすることができない
    //そのため変数を設定、関数を実行するためのpublic メソッドを作る必要がある(カプセル化)
    

    public: void set(int input_1,int input_2);
           
            void add_num();
            void print_result();

            void do_dv_num();
            void print_result_2();

            

    private: int var_1,var_2,result,result_2;
             void dv_num();
             bool dv_by_0;
};

void sample::set(int input_1,int input_2){

    var_1 = input_1;
    var_2 = input_2;
}

void sample::add_num(){

    result = var_1 + var_2;
}

void sample::print_result(){
    
    std::cout<<"result = "<<result<<std::endl;
}



void sample::dv_num(){

    if(var_2 == 0){
        std::cout<<"Error! var_1 is devided by 0"<<std::endl;

        dv_by_0 = true;

       
    }

    else{

       result_2 = (var_1/var_2);

       dv_by_0 = false;
        }
    
}

void sample::do_dv_num(){
     
     //class中でclassのメソッドを呼び出す時にはclass自体を示すpointer thisを用いる
    
    this->dv_num();
}

void sample::print_result_2(){

    if(dv_by_0){

        std::cout<<"this calc is invalid!"<<std::endl;
    }
    
    else{
       std::cout<<"result_2 = "<<result_2<<std::endl;
    }
}



int main(){

  
    
    sample S;

    
    S.set(2,3);
    S.add_num();

    S.print_result();

    S.set(4,2);
    S.do_dv_num();
    S.print_result_2();

    S.set(0,1);
    S.do_dv_num();
    S.print_result_2();

    S.set(9,0);
    S.do_dv_num();
    S.print_result_2();


    return 0;
}