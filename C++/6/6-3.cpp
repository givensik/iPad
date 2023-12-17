#include <iostream>

class Parent {
 public:
  Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
  ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};

class Child : public Parent {
 public:
  Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
  ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};

int main() {
  std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
  { Child c; }
  /*
   이때 parent가 먼저 생성자 호출되고, child가 다음에 생성자가 호출된다.
   소멸자는 child 먼저, 그리고 parent가 소멸자를 호출함
  */
  std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
  {
    Parent *p = new Child();
    delete p;
  }
  // 이땐 생성자는 Parent -> Child이고 소멸자는 Parent만 호출된다.
  // 이러면 메모리 누수가 발생하므로 Parent 소멸자를 virtual 함수로 만들면 된다.
  

}