BinaryTree.o : BinaryTree.c BinaryTree.h
  clang -c BinaryTree.c BinaryTree.o

BinaryTreeMain.o : BinaryTreeMain.c
  clang -c BinaryTreeMain.c BinaryTreeMain.o

main.out : BinaryTree.o BinaryTreeMain.o
  clang -c BinaryTreeMain.o BinaryTree.o -o main.out