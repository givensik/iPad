#include <fstream>
#include <iostream>
#include <string>


int main(){

  std::ifstream in("data.txt");
  std::string s;

  if(in.is_open()){
    // 위치 지정자를 파일의 끝으로 옮기기
    in.seekg(0, std::ios::end);
    // 파일의 크기 tellg() -> 파일 지정자의 위치를 반환(바이트)
    int size = in.tellg();
    
    s.resize(size);
    in.seekg(0,std::ios::beg);

    // s에 in에서 size만큼 읽어서 저장하기
    in.read(&s[0],size);

    std::cout << s << std::endl;
  }else{
    std::cout << "파일이 없어요" << std::endl;
  }


  return 0;
}