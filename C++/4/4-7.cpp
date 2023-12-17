#include <iostream>

class A {
  mutable int data_; // mutable int로 선언하면 const 함수에서도 멤버 값 변경 가능

 public:
  A(int data) : data_(data) {}
  void DoSomething(int x) const {
    data_ = x;  // 불가능!
  }

  void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
  A a(10);
  a.DoSomething(3);
  a.PrintData();
}