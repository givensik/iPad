#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = date;
  }
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);
  void ShowDate(){
    std::cout << year_ << month_ << day_ << std::endl;
  }
};

int main(){
    Date date;

    date.SetDate(2001, 6, 21);
    date.ShowDate();
    return 0;
}