#include <iostream>
#include <fstream>
#include <string>


int main(){
  std::ifstream in("data.txt");
  char buf[100];

  if(!in.is_open()){
    std::cout << "파일이 없음" <<std::endl;  
    return 0;
  }

  while (in) {
    // 이거 말고도 std::string에서 getline 함수를 지원한다.
    // std::string s; 
    // getline(in, s); 이런식으로 buf크기를 지정하지 않아도 괜찮음
    in.getline(buf, 100);
    std::cout << buf << std::endl;
  }

  return 0;
}