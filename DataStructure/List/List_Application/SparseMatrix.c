// 희소 행렬 -> 3-튜플로 구현
// 2차원 배열로
#include <stdio.h>
#include <stdlib.h>

/*
    예시
    6,6,5(희렬행렬 정보)
    0,1,12
    0,5,21
    2,4,1
    4,0,13
    4,4,17
*/
// m*n 행렬에 k개에 0이 아닌 원소가 들어감

// function elementMatrix
// x,y에 있는 원소 반환
int elementMatrix(int M[][3],int m, int n, int k){
    int i;
    for(i=0;i<k;i++){
        if(M[i][0] == m && M[i][1] == n){
            return M[i][2];
        }
    }

    return 0;
}

//function printMatrix
void printMatrix(int M[][3]){
    printf("printMatrix\n");
    int i,j,a=1;
    // printf("%d\n",M[0][0]);
    int flag = 0;
    for(i=0;i<M[0][0];i++){
        // printf("i=%d\n",i);

        for(j=0;j<M[0][1];j++){
            // printf("i=%d, j=%d\n",i,j);
            if(M[a][0]==i && M[a][1]==j && flag == 0){
                printf(" %d",M[a][2]);
                if(a == M[0][2]){
                    flag = 1;
                };
                a++;
            }else{
                printf(" 0");
            }
        }
        printf("\n");
    }
    
}

// transposeMatrix
// 희소 행렬을 전치행렬로 바꾸기(m->n, n->m)
int transposeMatrix(int M[][3], int t[][3]){
    int i,j,m,n,k;
    m = M[0][0];
    n = M[0][1];
    k = M[0][2];
    
    t[0][0] = n;
    t[0][1] = m;
    t[0][2] = k;

    //행, 열 바꾸기 O(km)인데, O(k+m)으로 바꿀 수 있음 그거 해봐야함
    int cnt=1;
    for(i=1;i<n;i++){
        for(j=1;j<k;j++){
            // i는 작은거부터 시작하니까 
            if(M[j][1] == i){
                t[cnt][0] = M[j][1];
                t[cnt][1] = M[j][0];
                t[cnt][2] = M[j][2];
                cnt++;
            }
        }
    }


    return 0;
}
/*
 0 0 0 0 0 0
 0 0 6 0 0 0
 0 8 0 0 0 0

 2중배열 -> 3*6
 2중배열 -> 3*3

*/

/*
    예시
    6,6,5(희소 행렬 정보) 
    0,1,12
    0,5,21
    2,4,1
    4,0,13
    4,4,17
*/

int main(){
    int M[100][3]; //sparse matrix
    int m,n,k;
    scanf("%d %d %d",&m, &n, &k);
    M[0][0] = m;
    M[0][1] = n;
    M[0][2] = k;
    //insert sparse matrix
    int i,tm,tn,td;
    for(i=0;i<k;i++){
        scanf("%d %d %d",&tm,&tn,&td);
        M[i+1][0] = tm;
        M[i+1][1] = tn;
        M[i+1][2] = td;
    }
    int j;
    
    printf("elementMatrix(M,0,5,k) = %d\n",elementMatrix(M,0,5,k));
    
    printMatrix(M);


    return 0;
}