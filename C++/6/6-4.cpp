#include <iostream>

class Animal {
 public:
  Animal() {}
  virtual ~Animal() {}
  virtual void speak() = 0;
  /*
    이 함수를 보면 아무것도 안적혀있음. 이것 처럼 "무엇을 정의하지 않은 함수"를 순수 가상 함수(pure virtual function)이라고 한다.
    그래서 반드시 Override가 되어야 한다.

    이런식으로 순수 가상 함수를 적어도 1개 가지고 있는 클래스로는 객체를 생성할 수 없다.
    이런 클래스를 추상 클래스(abstract class)라고 한다.
  */ 
};

class Dog : public Animal {
 public:
  Dog() : Animal() {}
  void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
 public:
  Cat() : Animal() {}
  void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
  // 추상 클래스는 객체를 생성할 수 없지만 
  // 추상 클래스를 포인터로 선언할 수는 있다.
  Animal* dog = new Dog();
  Animal* cat = new Cat();

  dog->speak();
  cat->speak();
}