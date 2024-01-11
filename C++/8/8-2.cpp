// 함수 템플릿
// 안한거 template 메타 프로그래밍 안함




#include <iostream>
#include <string>

// 이거도 클래스 탬플릿과 마찬가지로 인스턴스화 되기 전 까지는 컴파일 시엔 아무런 코드로 변환안지 않음
// 대신 함수는 호출시에 max<int> 이런식으로 안해도 자동으로 인식을 한다.
template <typename T>
T max(T& a, T& b) {
  return a > b ? a : b;
}

int main() {
  int a = 1, b = 2;
  std::cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << std::endl;

  std::string s = "hello", t = "world";
  std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
}

