#include <iostream>
#include <array>


// 타입이 아니ㅏㄹ 템플릿 인자로 typename이 아니라 자료형이 들어갈 수도 있다.
/*
  템플릿 인자로 들어갈 수 있는 타입
  - 정수 타입들 (bool, char, int, long 등등). 당연히 float 과 double 은 제외
  - 포인터 타입
  - enum 타입
  - std::nullptr_t (널 포인터)

  그리고 디폴트 템플릿 인자 값을 지정할 수도 있는데
  그냥 아래의 경우에는 template <typename T, int num = 디폴트 값 > 이런식으로 = 디폴트 값을 지정하면 된다.

  템플릿 말고 인자도 디폴트를 지정할 수 있다. -> 8-7.cpp
*/

template <typename T, int num>
T add_num(T t) {
  return t + num;
}

void print_array(const std::array<int,5> &arr){
  for(int i=0;i<5;i++){
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int x = 3; 
  std::cout << "x : " << add_num<int, 5>(x) << std::endl; // 이런 식으로 작성하면 typename T에는 int가, int num에는 5가 들어기게 된다.
  /*
    C와서와 다르게 배열의 크기를 템플릿 인자로 넣어서 함수에 배열을 전달할 때 배열의 크기를 잃어버리지 않게 만들 수 있다.(이러면 배열의 크기는 컴파일 과정에서 정해지는 거니까)

    Array 사용법
    std::array<배열의 타입, 배열의 크기> 변수명 = {초기화 값};

  */
  std::array<int, 5> arr ={1,2,3,4,5}; // {}으로 배열의 원소도 선언할 수 있음

  
  print_array(arr);

}