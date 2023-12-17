#include <iostream>
#include <cstring>

// 문자열을 통해 복소수 계산하기
class Complex {
 private:
  double real, img;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) {real = c.real, img = c.img;}
  Complex(const char *str);
  Complex operator+(const Complex& c) const;

  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& B) const {
    Complex temp(real + B.real, img + B.img);
    return temp;
}

Complex Complex::operator+(const char *str){
    int start =0, end = strlen(str), i_pos=0;
    
    double a, b;

    for(int i=0; i<end; i++){
        // i가 있으면 그 위치 저장
        if(str[i] == 'i'){
            i_pos = i;
            break;
        }
    }
    // i_pos가 0이면 실수임
    if(i_pos == 0){
        a = get_number(str, start, end);
        b = 0;
    }else{
        a = get_number(str, start, i_pos-1);
        b = get_number(str, i_pos, end);
    }

    Complex temp Complex(a,b);   
    return temp;
}

int main(){
    Complex   
    return 0;
}