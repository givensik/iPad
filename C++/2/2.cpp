#include <iostream>

/*
int& val(int p){
  int a = p;
  int&b = a;
  return b;
}
이러면 a라는 지역변수의 레퍼런스 b가 반환 -> 지역 변수는 삭제 -> 레퍼런스 값 없음
*/
int val(int p){
  int a = p;
  return a;
}
// 리턴되는 레퍼런스 값이 외부에 있어야함 만약 int p로 파라미터를 받아오면
int main() {
  int number = 5;

  std::cout << number << std::endl;
  const int result = val(number);
  std::cout << number << std::endl;
  std::cout << result << std::endl;
}