#include <iostream>

int main(){
    int* n = new int; // 메모리 할당
    *n = 10;

    std::cout << *n << std::endl;

    delete n; // 메모리 할당 해제
    return 0;
}