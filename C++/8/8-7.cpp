#include <iostream>


template<typename T>
struct Compare{
  bool operator() (const T& a, const T& b) const {
    return a<b;
  }
};

// 템플릿 디폴트 타입 설정 예시
template<typename T, typename Comp = Compare<T> >
T Min(T a, T b){ 
  Comp comp;
  if(comp(a,b)){
    return a;
  }
  return b;
}

int main(){
  int a = 3;
  int b = 4;
  std::cout << Min(a,b) << std::endl; 

  return 0;
}