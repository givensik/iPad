#include <fstream>
#include <iostream>
#include <string>

int main() {
  // 파일 쓰기준비
  /*
    out 객체를 생성할 때 옵션
    ios::ate : 자동으로 파일 끝에서 부터 읽기와 쓰기를 실시합니다. (즉 파일을 열 때 위치 지정자가 파일 끝을 가리키고 있게 됩니다)

ios::trunc : 파일 스트림을 열면 기존에 있던 내용들이 모두 지워집니다. 기본적으로 ofstream 객체를 생성할 때 이와 같은 설정으로 만들어집니다.

ios::in, std::ios::out : 파일에 입력을 할 지 출력을 할 지 지정하며, ifstream 과 ofstream 객체를 생성할 때 각각은 이미 설정되어 있습니다.
  */
  std::ofstream out("test.txt", std::ios::app);

  std::string s;
  if (out.is_open()) {
    out << "덧붙이기";
  }

  return 0;
}