// Created on iPad.

#include <iostream>
#include <fstream>


int main() {
    // file input
    std::ifstream in("data.txt");
    std::string s;

    if(in.is_open()){
        in >> s;
        std::cout << "input : " << s << std::endl; 
    }else{
        std::cout << "No data.txt"<< std::endl;
    }

    in.close();
    // 새로운 파일을 열려면 close()를 통해 파일을 닫아야함
    in.open("other.txt");

    if(in.is_open()){
        in >> s;
        std::cout << "input : " << s << std::endl; 
    }else{
        std::cout << "No data.txt"<< std::endl;
    }

    return 0;
}