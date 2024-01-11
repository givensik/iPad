#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float find_gap(int x1, int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
  int x1, y1, r1, x2, y2, r2;
  int n;
  float r;
  float d;
  scanf("%d", &n);

  for(int i = 0; i< n; i++){
    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    d = find_gap(x1,y1,x2,y2);
    r  = abs(r1-r2);
    // printf("%f\n", find_gap(x1,y1,x2,y2));
    
    // 두 점이 같은 경우
    if(d == 0){
      if(r == 0){ // 두 원이 같은 경우
        printf("-1\n");
      }else{ // 두 원이 아예 안겹치는 경우
        printf("0\n");
      }
    }else{// 두 점이 다른 경우 
      if(d == r1 + r2){// 바깥에서 접하는 경우
        printf("1\n");
      }else if(d < r1+r2 && d > r){// 두 점에서 접하는 경우
        printf("2\n");
      }else if(d == r){ // 하나가 안에 들어갔는데 접하는 경우
        printf("1\n");
      }else if(d < r){ // 하나가 안에 있는데 안접하는 경우
        printf("0\n");
      }else if(d > r1+ r2){
        printf("0\n");
      }
    }
    
  }

  return 0;
}

