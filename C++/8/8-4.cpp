#include <iostream>

template <typename T>
class Vector {
  T* data;
  int length;
  int capacity;

  public:
    Vector(int n = 1) :data(new T[n]), length(n), capacity(n) {};

    void push(T a){
      // length가 capacity를 넘어서면 추가가 안되니가 크기를 늘리기
      if(length >= capacity){
        capacity *= 2;
        T* tmp = new T[capacity];
        for(int i =0; i< length ; i++){
          tmp[i] = data[i]; 
        }
        delete[] data;
        data = tmp;
      }
      // 마지막 원소 뒤에 값 추가
      data[length] = a;
      length++;
    };
    // 모든 데이터 출력
    void print(){
      std::cout << "print all" << std::endl;
      for(int i =0;i<length;i++){
        std::cout << data[i]<< " ";
      }
      std::cout << std::endl;
    }
    
    int size(){
      return length;
    }

    void swap(int i, int j){
      // printf("swap\n");
      T tmp = data[i];
      data[i] = data[j];
      data[j] = tmp;
    }
    
    
    // data에 접근
    T operator[](int i){
      return data[i];
    }

    ~Vector(){
      if(data){
        delete[] data;
      }
    }


};

// cont[i] > cont[j]에서 > 를 Comp라는 함수로 바꿀 수 있다.
template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp){
  for (int i = 0; i < cont.size(); i++) {
    for (int j = i + 1; j < cont.size(); j++) {
      // 이런식으로 함수는 아니지만 함수인 객체를 함수 객체 (Function Object, Functor)라고 함
      if (comp(cont[i], cont[j])) {
        cont.swap(i, j);
      }
    }
  }
}
/*
  이런식으로 typename Cont일때랑, typename Comp까지 추가했을 때랑 선언을 해두면
  bubble_sort(a); 이러면 Cont만 있을 때의 코드를 인스턴스화 하고,
  bubble_sort(a, b); 이러면 두번째 코드로 읽는다. 
*/
template <typename Cont>
void bubble_sort(Cont& cont){
  for (int i = 0; i < cont.size(); i++) {
    for (int j = i + 1; j < cont.size(); j++) {
      if (cont[i] > cont[j]) {
        cont.swap(i, j);
      }
    }
  }
}

// 위의 경우에는 Comp()이니까 연산자 오버로딩을 해야함
struct Comp1 {
  bool operator()(int a, int b) { return a > b; }
};

struct Comp2 {
  bool operator()(int a, int b) { return a < b; }
};



int main(){

  Vector<int> int_vec;
  int_vec.push(12);
  int_vec.push(4);
  int_vec.push(1);
  int_vec.push(2);
  int_vec.push(15);
  int_vec.print();

  Comp1 comp1;
  Comp2 comp2;

  bubble_sort(int_vec, comp1);
  bubble_sort(int_vec, comp2);
  
  int_vec.print();

  // std::cout << int_vec[1] <<std::endl;
  return 0;
}