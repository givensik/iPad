#include <iostream>

class Complex {
 private:
  double real, img;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) {real = c.real, img = c.img;}


  Complex operator+(const Complex& c) const; // 왜 const를 붙이는가? -> 연산시 피연산자 값은 바뀌지 않으니까
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;   
  Complex operator/(const Complex& c) const;
  /*
    여기서 Complex&이 아니라 Complex를 반환하는 이유
    Complex는 값의 복사 있음 -> 속도 저하 o
    Complex&는 레퍼런스를 반환 -> 속도 저하 x
    레퍼런스를 반환하면 연산이 틀려 질 수 있음, this를 통해 반환하면 원래 값이 바뀌니까
    -> 사칙연산의 경우는 무조건 값을 리턴해야함
  */
  Complex& operator=(const Complex& c);
  /*
    근데 operator=가 없어도 기본적으로 대입이 됨. 컴파일러에서 디폴트 대입 연산자가 있기 때문
    그래서
    Class a = b;
    -> 이건 a의 복사 생성자를 생성하는 거고
    Class a;
    a = b;
    -> 이건 a를 생성하고, a = b로 디폴트 대입 연산자를 수행한다.
  */
  Complex operator+=(const Complex& c);
  Complex operator-=(const Complex& c);
  Complex operator*=(const Complex& c);
  Complex operator/=(const Complex& c);

  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& B) const {
    Complex temp(real + B.real, img + B.img);
    return temp;
}

Complex Complex::operator-(const Complex& B) const {
    Complex temp(real - B.real, img - B.img);
    return temp;
}

// a+ bi * c + di = ac - bd + (ad + bc)i
Complex Complex::operator*(const Complex& B) const{
    Complex temp( real*B.real - img*B.img , real*B.img + img+B.real);
    return temp;
}
// a + bi / c + di = (a + bi)(c - di)/ (c^2 - d^2)
// (ac + bd + (bc - ad)i) / 
Complex Complex::operator/(const Complex& B) const{
    double mo = B.real*B.real - B.img*B.img;
    Complex temp( (real*B.real + img*B.img)/mo , (img+B.real - real*B.img)/mo);
    return temp;
}

Complex& Complex::operator=(const Complex& B){
    real = B.real;
    img = B.img;
    return *this;
}

Complex Complex::operator+=(const Complex& B){
    *this = *this + B;
    return *this;
}


Complex Complex::operator-=(const Complex& B){
    *this = *this - B;
    return *this;
}

Complex Complex::operator*=(const Complex& B){
    *this = *this * B;
    return *this;
}

Complex Complex::operator/=(const Complex& B){
    *this = *this / B;
    return *this;
}

int main(){
    Complex A(1.0,1.0);
    std::cout << "A : ";
    A.println();
    Complex B(3.0,-2.0);
    std::cout << "B : ";
    B.println();

    Complex C = A+B;
    std::cout << "A+B : ";
    C.println();

    C=A-B;
    std::cout << "A-B : ";
    C.println();

    C=A*B;
    std::cout << "A*B : ";
    C.println();

    C=A/B;
    std::cout << "A/B : ";
    C.println();

    C = A;
    std::cout << "C = A : ";
    C.println();
    return 0;
}