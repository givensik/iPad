#include "bar.h"
#include "foo.h"

int main() {
  foo();
  bar();
}

/*
  Makefile 공부
  main.cpp, foo.h, foo.cpp, bar.h, bar.cpp
  이렇게 있을 때

  clang++ -c main.cpp 
  -> main.cpp 파일을 컴파일해서 목적 파일(object file)을 생성하라는 명령어
  -> 이러면 main.o(어셈블리코드)가 생성됨

  근데 main.o에는 foo()를 실행하고, bar()를 실행하라 라고 되어있는데, 그거에 대한 정보는 없음
  그래서 foo.o랑, bar.o가 필요함
  main.cpp -컴파일-> main.o
  foo.cpp  -컴파일-> foo.o
  bar.cpp  -컴파일-> bar.o 
  
  목적파일들 -> 링킹 -> main 이렇게 해야함
  그렇게 하는 명령어가 
  clang++ main.o foo.o bar.o -o main
  이거임 (-o 는 실행파일 명을 뜻함)
  그래서 makefile에
  clang++ -c main.cpp
  clang++ -c foo.cpp
  clang++ -c bar.cpp
  clang++ main.o foo.o bar.o -o main
  이렇게임 이제 졸리니까 내일 하기
*/