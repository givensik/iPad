#include <iostream>
#include <string>

// C++ 템플릿 공부
/*
    아래의 Test 클래스의 경우 data 값이 int, char, string 등 다양하게 넣으려고 함. 근데 이걸 하나하나 선언하기 힘드니까?
    템플릿 기능을 이용해서 하는 거임

    template <typename 타입이름>
    class 클래스템플릿이름
    {
        // 클래스 멤버의 선언
    }

    * 템플릿 특수화
    template <typename A, typename B, typename C>
    class test {};
    
    이런 경우에서 A는 int이고, C는 char일 때 따로 처리하고 싶다? 이러면
    
    template <typename B>
    class test<int, B, double> {};
    
    이렇게 사용하면 된다. 이렇게 특수화 하면 A가 int이고, C가 double인 경우에 대한 동작만 변경 가능
    컴파일러는 전달된 인수에 정확히 대응하는 특수화된 정의를 발견하면, 더는 다른 템플릿을 찾지 않고 해당 정의를 사용합니다.


    클래스 템플릿의 특징
    1. 하나 이상의 템플릿 인수를 가지는 클래스 템플릿을 선언할 수 있습니다.
        template <typename T, int i> // 두 개의 템플릿 인수를 가지는 클래스 템플릿을 선언함.
        근데 이러면 int i는 왜 씀??
    2. 클래스 템플릿에 디폴트 템플릿 인수를 명시할 수 있습니다.
        template <typename T = int, int i> // 디폴트 템플릿 인수의 타입을 int형으로 명시함.
    3. 클래스 템플릿를 기초 클래스로 하여 상속할 수 있습니다.
        template <typename Type>
        class Y : public X <Type> // 클래스 템플릿 X를 상속받음.
        { ... }
*/
template <typename T>
class Test{
    T data;

    public:
    Test(T a);

    void print();

};

// 이런식으로 선언, 근데 클래스 선언 안에서는 함수 선언이 안되나?? 뭔가 typename 특수화 때문에 안될거같음
template <typename T>
Test<T>::Test(T a){
    data = a;
};

// 위에서 template으로 선언한 순간 저거는 class Test가 아니라 class Test<T>가 된거임 그래서 선언시에 무조건 이렇게 해야하는 듯?
// template <typename T> 없애고, void Test::print()로 컴파일 해봤는데 오류남
template <typename T>
void Test<T>::print(){
    std::cout << data << std::endl;
}


int main(){
    // Test<int> int_test = Test<int>();
    Test<int> int_test(12);
    // 템플릿도 이렇게 인스턴스화를 시켜야 저 T의 값이 int로 변경된 코드가 새로 생성이 되는 거임

    int_test.print();
    Test<std::string> str_test("C++ Test");
    str_test.print();

    return 0;
}