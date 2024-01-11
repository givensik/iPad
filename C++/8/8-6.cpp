#include <iostream>
#include <array>

// 크기를 지정한 array도 (ex : array<int, 4>) 템플릿 인자로 이용가능하다.
template <typename T>
void print_array(const T &arr){
  for(int i=0;i<arr.size();i++){
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  /*
    C와서와 다르게 배열의 크기를 템플릿 인자로 넣어서 함수에 배열을 전달할 때 배열의 크기를 잃어버리지 않게 만들 수 있다.(이러면 배열의 크기는 컴파일 과정에서 정해지는 거니까)

    Array 사용법
    std::array<배열의 타입, 배열의 크기> 변수명 = {초기화 값};

  */
  std::array<int, 5> arr ={1,2,3,4,5}; // {}으로 배열의 원소도 선언할 수 있음
  std::array<int, 3> arr2 ={2,4,5};
  
  print_array(arr);
  print_array(arr2);

}