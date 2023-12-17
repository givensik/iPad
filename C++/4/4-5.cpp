#include <iostream>
#include <cstring>

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string(const char *s);
  string(const string &s);
//   ~string();    // 소멸자

   void add_string(const string &s);   // str 뒤에 s 를 붙인다.
   void copy_string(const string &s);  // str 에 s 를 복사한다.
  int strlength();                       // 문자열 길이 리턴
};

string::string(char c, int n){
    std::cout << "string 생성" << std::endl;
    str = new char[n+1];
    for(int i=0; i<n; i++){
        str[i] = c;
    }
    str[n] = 0;
    len = n;
}

string::string(const char *s){
    std::cout << "string 생성 2 "<< std::endl;
    str = new char[strlen(s)+1];
    strcpy(str, s);
    len = strlen(str);
}


int string::strlength(){
    std::cout << "strlen();" <<std::endl;
    return len;
}

string::string(const string &s){
    std::cout << "복사 생성자" << std::endl;
    str = s.str;
    len = s.len;   
}

void string::add_string(const string &s){
    std::cout << "add_string() : "<< str << s.str << std::endl;
    strcat(str, s.str);
    len += s.len;
    std::cout << "after : "<< str << std::endl;
}

void string::copy_string(const string &s){
    std::cout << "copy_string() : " << std::endl;
    strcpy(str, s); // 이거 왜 라이브러리 없냐 시밤
    len = s.len;
}

int main(){
    string S('c',3);
    std::cout << S.strlength() << std::endl;
    char test[100] = "Hello";    
    string S2("Hello");
    std::cout << S2.strlength() << std::endl;
    string S3(S2);
    std::cout << S3.strlength() << std::endl;
    S.add_string(S2);
    std::cout << S.strlength() << std::endl;
    S.copy_string(S3);
    std::cout << S.strlength() << std::endl;
    return 0;
}