#include <stdio.h>
#include <stdlib.h>

void makeField(int** p, int M, int N, int K){
   int x;
   int y;
   /*
   p = (int**)malloc(sizeof(int*)*N);
      // p[N]
   for(int j = 0; j < N ; j++){
         p[j] = (int*)malloc(sizeof(int)*M);
   }
   */
      // 기본 값으로 0 입력
      for(int j = 0; j < N ; j++){
         for(int k = 0; k< M; k++){
             p[j][k] = 0;
         }
      }
       // K개 만큼 x, y 입력 -> 1로 바꾸기
      for(int j = 0; j < K ; j++){
         scanf("%d %d",&x, &y);
         p[y][x] = 1;
      }
      // 출력하는 코드
      /*
      for(int j = 0; j < N ; j++){
         for(int k = 0; k< M; k++){
            printf(" %d", p[j][k]);
         }
         printf("\n");
      }
      */
}

void freeField(int** p, int M, int N){
   for(int j = 0; j < N ; j++){
         free(p[j]);
   }
   free(p);
}

int findBug(int** p, int M, int N, int K){
   int cnt = 0;

   for(int j = 0; j < N ; j++){
      for(int k = 0; k< M; k++){
            if(p[j][k] == 1){
               printf("j:%d, k:%d일때 일단 1이야\n",j,k);
               // k>0, j>0
               if( j>0 && k>0){
                  // 위 왼쪽 모두 0일 때 -> 카운트 세기(새로 나온 애니까)
                  if(p[j-1][k] == 0 && p[j][k-1] == 0 ){
                     cnt++;
                  }
                  continue;
               }
               // (0,0) 이야?
               if(j==0 && k == 0){// (0,0) -> 1이니까 그냥 카운트
                     cnt++;
                     continue;
               }
               // j가 0이야? 그리고 k!=0 -> 왼쪽만 보면 됨
               if(j == 0){ 
                  if(p[j][k-1] == 0){
                        cnt++; 
                     }
                  continue;
               }
               // k가 0이야? 그리고 j!=0 -> 위만 보면 됨
               if(k==0){
                  if(p[j-1][k] == 0){
                        cnt++; 
                     }
                  continue;
               }
            }
      }
   }

   return cnt;
}

int main(){
   int T;
   int M,N,K;
   int** p;

   int x,y; // x : 세로길이 , y : 가로길이
   // T 입력
   scanf("%d", &T);
   for(int i =0; i < T; i++){
      scanf("%d %d %d", &M, &N, &K);

      p = (int**)malloc(sizeof(int*)*N);
      for(int j = 0; j < N ; j++){
         p[j] = (int*)malloc(sizeof(int)*M);
      }

      makeField(p, M, N, K);      
      // printf("test %d\n", p[1][1]);
      printf("%d\n", findBug(p, M, N, K));

      freeField(p, M, N);
   }

   return 0;
}
/*
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
*/