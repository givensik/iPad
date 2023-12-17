#include <iostream>
#include <cmath>

class Point {
 public:
  int x, y;
  Point(int pos_x, int pos_y){
    x=pos_x;
    y=pos_y;
  };
};


class Geometry {
 public:
  Geometry() {
    num_points = 0;
  }

  void AddPoint(const Point &point) {
    point_array[num_points ++] = new Point(point.x, point.y);
  }

  // 모든 점들 간의 거리를 출력하는 함수 입니다.
  void PrintDistance();

  // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
  // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
  // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
  // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
  void PrintNumMeets();

private:
  // 점 100 개를 보관하는 배열.
  Point* point_array[100];
  int num_points;
};

/*
    function PrintDistance()
    print distances between pointers in Pointer_array
*/
void Geometry::PrintDistance(){
    int l,dx,dy;
    for(int i=0; i<num_points-1 ; i++){
        std::cout << "i :"<< i << std::endl;
        dx = point_array[i]->x - point_array[i+1]->x;
        dy = point_array[i]->y - point_array[i+1]->y;
        l = sqrt(pow(dx,2) + pow(dy,2));
        std::cout << "length = " << l <<std::endl;
    }
}
/*
    방향벡터 (u1, u2)일때, x=x1, y=y1
    b = -u1
    a = u2
    ax+by+c = 0
    u2x -u1y +u1y1 -u2x1 =0
    bx-ay b
*/

void Geometry::PrintNumMeets(){
    
    int u1,u2;
    int a,b,c;
    for(int i=0; i<num_points-1 ; i++){
        // 방정식 구하기
        u1 = point_array[i]->x - point_array[i+1]->x; // 3 0
        u2 = point_array[i]->y - point_array[i+1]->y; // 4 0
        a = u2; // 3
        b = u1 * -1; // -4
        c = u1*point_array[i]->y - u2*point_array[i]->x;
        std::cout << a << "x +" << b << "y +" << c <<std::endl;
        //

    }
    std::cout << "걍 귀찮아 그냥 끝내" << std::endl;

}   



int main(){
    
    Point A(3,4); // x=3,y=4인 객체 A 생성
    Point B(0,0); 
    Point C(1,1);
    Point D(4,3);
    Geometry G;
    G.AddPoint(A);
    G.AddPoint(B);
    G.AddPoint(C);
    G.AddPoint(D);
    G.PrintDistance();
    G.PrintNumMeets();
    return 0;
}