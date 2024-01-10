#include <iostream>
#include <fstream>
#include <string>

/*
일단 엑셀의 셀들의 정보 (일단 단순한 std::string 이라고 생각합시다) 에 대한 Cell 클래스가 있고 이 Cell 객체들을 모아두는 Table 클래스가 있습니다. 
Table 클래스에는 2차원 배열로 Cell 객체들에 대한 정보 (참고로 Cell 객체가 생성 될 때 마다 동적으로 Cell 객체를 생성합니다.) 가 보관되어 있습니다. 또한 Table 클래스에 전체 데이터를 출력하는 print_table 함수가 가상으로 정의되어 있습니다.

여러분은 Table 클래스를 상속 받는 TextTable, CSVTable, HTMLTable 클래스를 만들어서 print_table 함수를 오버라이드 할 함수들을 제작할 것입니다. 예를 들어 TextTable 클래스의 print_table 함수는 텍스트 형식으로, CSVTable 은 CSV 파일 형식으로 등등 만들어야 겠지요? 제가 아래 대충 프로그램의 골격을 잡아 놓았으니 여러분들은 이를 채우기만 하면 됩니다.
*/


class Table;

class Cell {
  protected:
    Table* table;  // 어느 테이블에 속해있는지
    std::string data;
    int x, y;  // 테이블 에서의 위치
  public:
    Cell(std::string data, int x, int y, Table* table);
    std::string get_string(); // x,y에 해당하는 원소 반환
};

Cell::Cell(std::string data, int x, int y, Table* table) : data(data), x(x), y(y), table(table){};

std::string Cell::get_string(){
  return data;
};  // 해당 위치의 Cell 데이터를 얻는다.

class Table {
  Cell*** data_base;  // 왜 3중 포인터 인지 잘 생각해보세요!
  int max_row, max_col;
 public:
  Table(int max_row, int max_col);
  std::string print_table();
  void reg_cell(Cell* c, int row, int col);  // Cell 을 등록한다
  std::string get_cell(int row, int col);  // 해당 위치의 Cell 데이터를 얻는다.
  ~Table();
};

// table 생성자
Table::Table(int max_row, int max_col):max_row(max_row), max_col(max_col){
  data_base = new Cell**[max_row];
  for(int i =0; i < max_row ;i++){
    data_base[i] = new Cell*[max_col];
    for(int j =0; j< max_col; j++){
      data_base[i][j] = NULL;
    }
  }
};


// table 삭제
Table::~Table(){
  for(int i =0; i < max_row ;i++){
    for(int j =0; j< max_col; j++){
      if(data_base[i][j]){
        delete data_base[i][j];
      }
    }
    delete[] data_base[i];
  }
  delete[] data_base;
}

void Table::reg_cell(Cell* c, int row, int col){
  // std::cout << "row : " << row << ", col : "<< col << std::endl;
  data_base[row][col] = c;
}

// 해당 위치의 Cell 데이터를 얻는다.
std::string Table::get_cell(int row, int col){
  std::string s = data_base[row][col]->get_string();
  return s;
} 


std::string Table::print_table(){
  // std::cout << "table start" << std::endl;
  std::string ftable = "     |";
  
  for(int i =0; i < max_row ;i++){
    for(int j =0; j< max_col; j++){
      if(i==0){
        ftable += std::to_string(j+1);
        ftable += "    |";
      }else{
        if(j==0){
          ftable += std::to_string(i);
          ftable += "    |";
        }else{
          if(data_base[i][j]){
            // std::cout<< "i : " << i <<", j : " << j << ", string : "<< get_cell(i,j) << std::endl;
            ftable += get_cell(i,j);
            ftable += "    |";
          }else{
            ftable += "     |";
          }
        }
      }
    }
    ftable += "\n";
  }


  std::cout << ftable << std::endl;
  return ftable;
}

// std::ostream& operator<<(std::ostream& o, Table& t) {
//   o << t.print_table();
//   return o;
// }


int main(){
  Table TxtTable = Table(5,5);
  std::ofstream out("test.txt");

  TxtTable.reg_cell(new Cell("a", 1,1, &TxtTable),1,1);
  TxtTable.reg_cell(new Cell("b", 3,1, &TxtTable),3,1);
  TxtTable.reg_cell(new Cell("c", 2,4, &TxtTable),2,4);
  std::string s = TxtTable.print_table();
  if(out.is_open()){
    out << s;
  }

  return 0;
}