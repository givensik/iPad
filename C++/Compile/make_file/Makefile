foo.o : foo.cpp foo.h
  clang++ -c foo.cpp

bar.o : bar.cpp bar.h
  clang++ -c bar.cpp

main.o : main.cpp foo.h bar.h
  clang++ -c main.cpp

main.out : main.o foo.o bar.o
  clang++ main.o foo.o bar.o -o main.out