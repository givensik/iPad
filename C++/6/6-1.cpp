/*
    6-1~6-2
    Class A : public B 의 의미
    * 클래스 A는 클래스 B의 모든 기능을 포함한다.
    * 클래스 A는 B의 기능을 수행하니까 A를 B로 칭해도 무방하다.
    * 모든 A는 B이다.(A is a B, is a 관계)

    is a 관계
    프로그래머 is 사람이지만
    사람 -> 프로그래머는 기님
    그래서 상속 될 수록 좀 더 특수화(구체화; specialize)됨 
    반대로 기반 클래스로 거슬러 올라가면 좀 더 일반화(generalize) 됨

    has a 관계
    자동차 클래스 has a 엔진, 브레이크, 오디오 클래스 등
    

*/

#include <iostream>
#include <string>

class Base {
  std::string s;

 public:
  Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

  virtual void what() { std::cout << s << std::endl; }
//   void what() { std::cout << s << std::endl; }
};
class Derived : public Base {
  std::string s;

 public:
  Derived() : s("파생") { std::cout << "파생 클래스" << std::endl; }

  void what() { std::cout << s << std::endl; }
};
int main() {
  std::cout << " === 기반 클래스 생성 ===" << std::endl;
  Base p;

  p.what();

  std::cout << " === 파생 클래스 생성 ===" << std::endl;
  Derived c;

  c.what();
  
  std::cout << "=== 포인터 버전 ===" << std::endl;
  Base* p_c = &c;
  /*
    여기서 왜 Base의 포인터인데 Derived를 넣을 수 있느냐?
    Derived 객체는 따지면 Base이기 때문에 Base *p_c가 가리키는 부분은 base라고 볼 수 있음
    그래서 p_c 객체에서 what()을 실행하면 base의 what이 실행됨
    이러한 형태의 캐스팅(파생 클래스에서 기반 클래스로 캐스팅 하는 것) = 업 캐스팅

  */
  p_c->what();
  // 다운 캐스팅
  /* 
  Derived* p_p = &p;
  p_p->what();
  이렇게 하면 derived -> base가 되는데 derived는 base+추가 기능 인데 base는 이게 없으므로 컴파일 에러
  */
  // 아래처럼 하면 Base를 Derived가 가리키는게 돼서 안되는데, p_c가 사실
  // Derived를 가리키기 때문에 
  // 타입 변환을 하면됨(근데 dynamic_cast를 이용)
  // Derived* p_p = p_c;
  Derived* p_p = static_cast<Derived*>(p_c);
  p_c->what();

  /*
    근데 이런 문제를 바로 해결하는 방법 : virtual 키워드
    virtual 키워드를 Base에 클래스에 있는 what 함수 앞에 붙이면 
    what함수를 실행할 때, Base 포인터여도 이게 실제로는 Derived 객체인지, Base 객체인지 구분을 한다
    -> 이런식으로 컴파일 시에 어떤 함수가 실행될 지 정해지지 않고 런타임 시에 정해지는 일을 동적 바인딩(dynamic binding)이라고 한다.
    즉, p->what();에서 어떤 객체의 what()을 실행할 지는 런타임에서 이루어진다.
    근데 오버라이드가 일어나려면 두 객체의 what()의 형태가 똑같아야함
    override 키워드를 사용하면 실수로 오버라이드 하지 않는 경우를 막을 수 있음

    ** 하나의 메소드를 호출했음에도 불구하고 여러가지 다른 작업들을 하는 것 : 다형성(polumorphism)
  */
  std::cout<<"virtual"<<std::endl;
  Base* pc = &c;// c->Derived 객체
  Base* pp = &p;// p->Base 객체

  std::cout << " == 실제 객체는 Base == " << std::endl;
  pp->what();

  std::cout << " == 실제 객체는 Derived == " << std::endl;
  pc->what();

  return 0;
}