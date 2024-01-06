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
    in.getline(buf, 100);
    std::cout << buf << std::endl;
  }

  return 0;
}