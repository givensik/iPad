// 단순 연결 리스트
// 추가, 삭제, 조회, 대체, 개수
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
   int data;
   struct node* next;
}node;

typedef struct List{
   node* first;
   int len;
}List;

//function findElement
// index : i
node* findElement(List* L, int i){
   // printf("find %dth element\n",i);
   node* tmp = NULL;
   if(L->len==0){
      return NULL;
   }
   int j;
   // 1 2 3 4
   tmp = L->first;
   for(j=1;j<i;j++){
      tmp = tmp->next;
   }
   // printf("find : %d\n",tmp->data);
   return tmp;

}

// function insertList
// a : data, i : index
int insertList(List* L, int i, int a){
   printf("insert %d to %d\n",a,i);
   //error
   if(i>L->len+1 || i<0){
      return 0;
   }
   
   //create tmp node
   node* tmp=malloc(sizeof(node));
   tmp->data = a;
   tmp->next =NULL;

   //first element
   // if(L->len==0){
   //    L->first = tmp;
   //    L->len = L->len+1;
   //    return 1;
   // }
   if(i==0){
      tmp->next=L->first;
      L->first = tmp;
      L->len = L->len+1;
      return 1;   
   }

   node* inode =findElement(L, i);
   printf("findnode : %d\n",inode->data);
   tmp->next = inode->next;
   
   inode->next = tmp;
   L->len = L->len+1;
   return 0;
}


//function DeleteElement
// index : i
int DeleteElement(List* L, int i){
   //error
   if(i>L->len|| i<0){
      return -1;
   }

   node* tmp;
   node* dnode= findElement(L,i);//delete node 
   //first node
   if(i==0){ 
      L->first->next = dnode->next;
      free(dnode);
      return 0;
   }else{
      // i-1 node
      tmp = findElement(L,i-1);
      tmp->next = dnode->next;
      free(dnode);
      return 0;
   }


   return 0;
}




int main() { 
   printf("준식시치의 자료구조 수업\n");
   List* A;
   A = malloc(sizeof(List));
   A->len = 0;
   insertList(A,0,1);
   insertList(A,1,2);
   insertList(A,0,3);
   insertList(A,3,4);
   int i,a;
   node* tmp=A->first;
   while(tmp!=NULL){
      printf(" %d",tmp->data);
      tmp = tmp->next;
   } 
   printf("\n");

   if(DeleteElement(A,1)==-1){
      printf("Error\n");
   }else{
      printf("Success\n");
   }

   free(A);

   return 0;
}