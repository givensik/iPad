/*
    표준 "string" 클랫ㅡ


*/

#include <iostream>

class Base {
  std::string s;

 protected:
  std::string BaseStr;

 public:
  Base() : s("기반") {  std::cout << "기반 클래스" <<  std::endl; }

  void what() {  std::cout << s <<  std::endl; }
};
/*
 derived가 base를 public 형식으로 상속 받겠다는 의미
 이러면 Derived 클래스는 
 Base class의 string s, Base(), what()을 그대로 가진 것 처럼 된다.


*/
class Derived : public Base {
  std::string s;

 public:
  
  Derived() : Base(), s("파생") {
     std::cout << "파생 클래스" <<  std::endl;

    // Base 에서 what() 을 물려 받았으므로
    // Derived 에서 당연히 호출 가능하다
    what();
    /*
        만약 상속받는 클래스에서 상속하는 클래스의 private 멤버 변수의 값에 접근하려면
        protected를 사용하면 된다.
        * priviate : (부모님들한테 안가르쳐 주는) 자신만의 비밀번호
        * protected : 집 현관문 비밀번호 ( 가족들은 알지만 그 외의 사람들은 접근불가)
        * public : 집 주소 (가족 뿐만이 아니라 다른 사람들도 알 수 있다)
        이렇게 생각하면 된다.
    */
    BaseStr = "바꾸기 가능";

  }
  // 파생 클래스에서도 what() 함수가 있는 경우 상속받은 what보다 이걸 우선순위에 둠
  // -> 오버라이딩(overriding)이라고 함


  void what() {  std::cout << s <<  std::endl; }
};

int main(){
    
    std::cout << " === 기반 클래스 생성 ===" <<  std::endl;
  Base p;

   std::cout << " === 파생 클래스 생성 ===" <<  std::endl;
  Derived c;
    
    return 0;

}