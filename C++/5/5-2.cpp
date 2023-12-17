#include <iostream>

/*
    N차원 배열 만들기

    Array 클래스
    top(address 객체) : 레벨 0
    address          : 레벨 1
    address          : 레벨 2
    ...
    실질적 데이터 저장되는 곳 ; 레벨 n-1

*/



class Array{
    int dim;
    int *size; // 레벨마다 size값이 다름

    struct Address {
        int level;
        void* next;
    };

    Address *top;

    public:
    // 생성자
    Array(int dim, int *array_size) : dim(dim){
        // 내가 만약 A[2][3][4]를 만든다.
        // dim = 2
        // array_size[] = 2
        // 이런식으로 하려나
        size = new int[dim];
        for (int i = 0; i < dim; i++) size[i] = array_size[i];
        
        top = new Address;
        top->level = 0;

    }

    // 복사 생성자
    Array(const Array &A) : dim(A.dim){
        // 내가 만약 A[2][3][4]를 만든다.
        // dim = 2
        // array_size[] = 2
        // 이런식으로 하려나
        size = new int[A.dim];
        for (int i = 0; i < A.dim; i++) size[i] = A.size[i];
        
        top = new Address;
        top->level = 0;

        copy_address(top, A.top);
    }

    void copy_address(Address *dst, Address *src){
        if(dst->level == dim-1){
            for(int i=0; i<size[dst->level]; i++){
                static_cast<int *>(dst->next)[i] = static_cast<int *>(src->next)[i];
            }
            return;
        }
        //다음으로 넘기기
        for (int i = 0; i != size[dst->level]; i++) {
            Address *new_dst = static_cast<Address *>(dst->next) + i;
            Address *new_src = static_cast<Address *>(src->next) + i;
            copy_address(new_dst, new_src);
        }

    }

    /*
        재귀함수를 만드는 방법
        1. 현재 단계에서 다음 단계로 넘어가는 과정
        2. 함수를 종료하는 조건은 무엇인지
    */
    void init_address(Address *current){
        // 종료 조건
        if(current->level == dim-1){
            //size의 값 = 해당하는 level의 사이즈 
            // A[2][3][4]면 0레벨의 사이즈는 2, 1레벨의 사이즈는 3, 2레벨의 사이즈는 4니까 
            current->next = new int[size[current->level]];
            return ;
        }
        // 종료조건이 아님 -> 새로운 int* 배열 생성 + Address에 level, next를 해야하기 때문
        current->next = new int*[size[current->level]];
        for(int i=0; i!=size[current->level]; i++){
            // static_cast를 하는 이유는 Address 구조체의 next가 void*이기 때문
            (static_cast<Address *>(current->next) + i)->level = current->level + 1;
        }
        init_address(static_cast<Address *>(current->next));
        

    }

    void delete_address(Address *current) {
        if (!current) return;
        for (int i = 0; current->level < dim - 1 && i < size[current->level]; i++) {
            delete_address(static_cast<Address *>(current->next) + i);
        }

        if (current->level == dim - 1) {
            delete[] static_cast<int *>(current->next);
        }

        delete[] static_cast<Address *>(current->next);
    }

};


int main(){

    return 0;
}