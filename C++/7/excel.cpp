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
  Table* table;  // 어느 테이블에 속해있는지
  std::string data;
  int x, y;  // 테이블 에서의 위치
 public:
  Cell(const std::string& data) : data(data){};
};

class Table {
  Cell*** data_base;  // 왜 3중 포인터 인지 잘 생각해보세요!
 public:
  Table();
  virtual std::string print_table() = 0;
  void reg_cell(Cell* c, int row, int col);  // Cell 을 등록한다
  std::string get_cell_std::string(int row, int col);  // 해당 위치의 Cell 데이터를 얻는다.
  ~Table();
};

void Table::reg_cell(Cell* c, int row, int col){
  std::cout << "row : "<< row << "col : "<< col << std::endl;
  data_base[row][col] = c;
  c.x = row;
  c.y = col;
  c.table = this;
}


ostream& operator<<(std::ostream& o, Table& t) {
  o << t.print_table();
  return o;
}

class TextTable : public Table {

public:
  // 생성자
  TextTable() : Table() {};

  std::string print_table() override {
    std::cout << "Text table" << std::endl;
    
  }
};
class CSVTable : public Table {
  
public:
  std::string print_table() override {
    std::cout << "CSV table" << std::endl;
  }

};
class HTMLTable : public Table {
  
public:
  std::string print_table() override {
    std::cout << "HTML table" << std::endl;
  }


};

int main(){
  Table Text = new TextTable();
  Cell c1 = new Cell("first");

  return 0;
}