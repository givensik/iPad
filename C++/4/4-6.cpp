#include <iostream>
#include <cstring>

class MyString {
    char* str; // 문자열
    int len; // 길이

    public:
    
        MyString(char c, int n);
        MyString(char* s);
        MyString(const MyString& str);  
        void Mstrlen();
        void print_str();
        MyString& assign(const MyString& str);
        MyString& assign(char *s);
};

MyString::MyString(char c, int n){
    std::cout << "문자열 생성 by char" <<std::endl;
    len = n;
    char* a = new char[n+1];
    for(int i=0; i<n; i++){
        a[i] = c;
    }
    a[n] = '\0';
    str = a;
    // std::cout << str << std::endl;
}

MyString::MyString(char *s){
    std::cout << "문자열 생성 by str" <<std::endl;
    int len = 0;
    for(char *p =s; p; p++){
        len++;
        if(*p == '\0'){
            break;
        }
    }
    char *a = new char[len];
    for(int i=0; i<len;i++){
        a[i] = s[i];
    }
    str = a;
}

void MyString::print_str(){
    std::cout << str << std::endl;
}

void MyString::Mstrlen(){
    int len = 0;
    for(char *p =str; p; p++){
        std::cout << "c = " << *p <<std::endl;
        if(*p == '\0'){
            break;
        }
        len++;
    }
    std::cout << "length : " << len << std::endl; 
}

MyString& MyString::assign(const MyString& A){
    delete[] str;
    str = new char[strlen(A.str)];
    for(int i=0; A.str[i] ; i++){
        str[i] = A.str[i];
    }
    return *this;
}

MyString& MyString::assign(char *s){
    delete[] str;
    str = new char[strlen(s)];
    
    for(int i=0; s[i]; i++){
        str[i] = s[i];
    }

    return *this;
}

int main(){

    MyString S1('a', 3);
    S1.print_str();
    S1.Mstrlen();
    char x[100] = "Hello\0";
    
    MyString S2(x);
    S2.print_str();
    S2.Mstrlen();

    MyString S3('b',4);
    S3 = S1.assign(S3);
    S1.print_str();

    return 0;
}