// 다항식 리스트로 구현
// 1. 1차배열, 2. 2차배열, 3. 연결리스트로 구현

#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode{
   int coef;
   int exp;
   struct polyNode *next;
}polyNode;

typedef struct poly{
   struct polyNode *head;
}poly;

// 추가, 함수 더하기

// 초기화(입력)   head->1->2->....
poly* initPoly(){
   poly* f = malloc(sizeof(poly));
   polyNode* tmp = malloc(sizeof(polyNode));
   polyNode* tmp1;
   f->head = tmp; // f의 첫 노드 생성
   
   printf("init Poly Start\n");
   int c, e;
   scanf("%d %d", &c, &e); // 첫번째 원소
   tmp->coef = c;
   tmp->exp = e;

   while(1){
      scanf("%d %d", &c, &e);
      if(c == -1 && e == -1){
         tmp->next = NULL;
         break;
      }
      tmp1 = malloc(sizeof(polyNode));
      tmp1->coef = c;
      tmp1->exp = e;
      tmp->next = tmp1;
      tmp = tmp1;
   }
   return f;
}
void printPoly(poly* f){
   polyNode* tmp = f->head;
   int i;
   while(1){
      printf(" %dx^%d",tmp->coef, tmp->exp);
      if(tmp->next == NULL) break;
      tmp = tmp->next;
   }
   printf("\n");
}

poly* plusPoly(poly* f, poly* g){
   polyNode* ftmp = f->head;
   polyNode* gtmp = g->head;
   poly* h = malloc(sizeof(poly));
   h->head = malloc(sizeof(polyNode));
   polyNode* htmp = h->head;
   polyNode* htmp1;
   printf("start, f head = %dx^%d, g head = %dx^%d\n",ftmp->coef, ftmp->exp, gtmp->coef, gtmp->exp);
   while(ftmp !=NULL || gtmp != NULL){
      printf("f:x^%d g:x^%d\n",ftmp->exp,gtmp->exp);
      //ftmp->next == NULL일떄
      if(ftmp == NULL){
         htmp1 = malloc(sizeof(polyNode));
         htmp1->coef = gtmp->coef;
         htmp1->exp = gtmp->exp;
         htmp->next = htmp1;
         htmp = htmp->next;
         gtmp = gtmp->next;
         continue;   
      }else if(gtmp == NULL){
         htmp1 = malloc(sizeof(polyNode));
         htmp1->coef = ftmp->coef;
         htmp1->exp = ftmp->exp;
         htmp->next = htmp1;
         htmp = htmp->next;
         ftmp = ftmp->next;
         continue;
      }

      //f의 차수가 더 클때 -> f를 다음 노드로
      if(ftmp->exp > gtmp->exp){
         printf("fexp>gexp\n");
         htmp->coef = ftmp->coef;
         htmp->exp = ftmp->exp;
         ftmp = ftmp->next;
      }else if(ftmp->exp < gtmp->exp){ //g의 차수가 더 클때 -> g를 다음 노드로
         printf("fexp<gexp\n");
         htmp->coef = gtmp->coef;
         htmp->exp = gtmp->exp;
         gtmp = gtmp->next;
      }else{
         printf("fexp=gexp\n");
         htmp->coef = ftmp->coef + gtmp->coef;
         htmp->exp = gtmp->exp;
         ftmp = ftmp->next;
         gtmp = gtmp->next;
      }
      // f함수에 노드 추가
      htmp1 = malloc(sizeof(polyNode));
      htmp->next = htmp1;
      htmp = htmp->next;
   }
   return h;
}
void freeNode(poly* f){
   polyNode* tmp = f->head;
   polyNode* ex;
   while(tmp !=NULL){
      ex = tmp;
      tmp = tmp->next;
      free(ex);
   }
   free(f);
}
int main(){
   // 1차원 배열로 구현(귀찮음)
   // fx[0] = a
   // fx[2n] = 차수
   // fx[2n-1] = 계수

   // 2차원 배열로 구현(귀찮음)
   // fx[0] = 배열 정보
   // fx[n][0] = 차수
   // fx[n][1] = 계수

   // 연결리스트로 구현 지수가 큰 순서대로 내림차순

   poly* fx;
   poly* gx;
   poly* hx;
   fx = initPoly();
   printf("f(x) = ");
   printPoly(fx);  
   gx = initPoly();
   printf("g(x) = ");
   printPoly(gx);
   
   printf("f(x)+g(x)\n");
   hx = plusPoly(fx,gx);
   printPoly(hx);  
   freeNode(fx);
   freeNode(gx);
   freeNode(hx);
   
   return 0;
}