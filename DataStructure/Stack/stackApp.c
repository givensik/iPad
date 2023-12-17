// stack application
#include <stdio.h>
#define N 100

int insertStack(int S[], int* top, int x);
int deleteStack(int S[], int* top);
int rank(int x);


int rank();


int main() {
   
   int S[N];
   int top; // define Stack
   top = -1;
   /* 스택 초기화 */
   
   char exp[N];
   scanf("%s",exp);
   //(A+B)*C+E/(F+A*D)+C
   int i;

   /* 
      중위식 -> 후위식
      피연산자 -> 그대로 출력
      연산자 -> 원소의 우선순위가 스택의 탑원소보다 높으면 스택에 추가

   */
   for(i=0;i<N;i++){
      //피연산자(A~F)인 경우
      if('A'<=exp[i] && exp[i]<='F'){
         printf(" %c", exp[i]);
      }else{// 연산자인 경우
         //스택이 비어있는 경우
         if(top == -1){
            insertStack(S, &top, exp[i])
         }else if(exp[i] == '('){
            printf("%c",exp[i]);
         }else{ 
            if(rank(S[top]) < rank(exp[i])){
               insertStack(S, &top, exp[i]);
            }else{

            }
         }
      }
   }
   printf("\n");
   
   return 0;
}

int rank(int x){
   return 0;
}


int insertStack(int S[], int* top, int x){
   //공집합 일때
   if(*top == -1){
      S[0] = x;
      *top = *top+1;
      return x;
   }else{
      *top = *top+1;
      S[*top] = x;
      return x;
   }

   return 0;
}

int deleteStack(int S[], int* top){
   int tmp;
   if(*top == -1){
      return -1;
   }else{
      tmp = S[*top];
      *top = *top -1;
      return tmp;
   }
   
}