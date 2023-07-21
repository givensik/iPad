// sequential list
#include <stdio.h>

//추가, 삭제, 조회, 길이

//List의 i번째 원소에 원소값 a추가
int insertList(int *List, int n, int* len, int i, int a){
   //안되는 경우
   if(i>n-1 || i<0){
      return 0;
   }
   if(*len+1==n){
      return 0;
   }
   int j;
   for(j=*len;j>=i;j--){
      List[j+1]=List[j];
   }
   List[i] = a;
   *len = *len +1;
   printf("%d, %d\n", List[i], *len);
   return 0;
}

//List i 번째 원소에 원소값 삭제
int removeList(int *List, int n, int* len, int i){
   int tmp = List[i];
   if(*len==-1||*len+1==n){
      return 0;
   }
   if(i>n-1 || i<0){
      return 0;
   }
   int j;
   for(j=i;j<=*len;j++){
      List[j]=List[j+1];
   }
   *len = *len - 1;
   return tmp;//삭제한 원소 반환
}

int main() {
   int List[10]={0,}, len;   
   len = -1;
   insertList(List, 10, &len, 0,1);
   insertList(List, 10, &len, 1,2);
   insertList(List, 10, &len, 2,3);
   removeList(List, 10, &len, 2);
   
   int i;
   for(i=0;i<10;i++){
      printf("%d ",List[i]);
   }
   printf("\nlength = %d\n",len);

   return 0;
}