// 함수 템플릿
// 안한거 template 메타 프로그래밍 안함




#include <iostream>
#include <string>

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