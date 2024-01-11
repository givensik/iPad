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


int main(){

  Vector<int> int_vec;
  int_vec.push(12);
  int_vec.push(4);
  int_vec.push(1);
  int_vec.push(2);
  int_vec.push(15);
  int_vec.print();

  bubble_sort(int_vec);
  int_vec.print();

  // std::cout << int_vec[1] <<std::endl;
  return 0;
}