// linked stack
// insert, delete
// top, stack
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   int data;
   struct node* before;   
}node;

typedef struct stack{
   node* top; 
}stack;



//function push
int push(stack* S, int a){
   // 비어있는 스택일 때
   if(S->top == NULL){
      S->top = malloc(sizeof(node));
      S->top->data = a;
      S->top->before = NULL;
      
   }else{
      node* tmp = malloc(sizeof(node));
      tmp->data = a;
      tmp->before = S->top;
      S->top = tmp;
   }
   
   return a;
}

// pop
int pop(stack* S){
   // 스택이 비어있을 때
   if(S->top == NULL){
      printf("ERROR\n");
      return -1;
   }
   int tmp;
   node* ntmp;
   ntmp = S->top;
   tmp = S->top->data;
   S->top = S->top->before;
   free(ntmp);

   return tmp;
}

stack* init(){
   stack* S = malloc(sizeof(stack));
   S->top = NULL;
   return S;
}

void printStack(stack* S){
   node* tmp = S->top;
   while(tmp != NULL){
      printf(" %d", tmp->data);
      tmp = tmp->before;
   }
}

int main() {
   stack* S = init();

   push(S,5);
   push(S,1);
   push(S,2);
   push(S,3);
   printStack(S);
   pop(S);
   pop(S);
   pop(S);
   printStack(S);
   pop(S);
   pop(S);
   
   return 0;
}