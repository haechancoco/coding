#ifndef CELL_CPP
#define CELL_CPP

#include <string>

class Table;

// 큰 테이블에서의 한 칸
class Cell {
  protected:
  Table* m_table; // 소속한 table
  
  int m_x, m_y;   // cell 의 table 에서의 위치

  std::string m_data;  // cell 의 값 

  public:
  Cell(std::string data, int x, int y, Table* table);

  virtual std::string stringify(void); // 셀 값을 문자열로 변환한다
  virtual int to_numeric(void);   // 셀 값을 정수로 변환한다
};

#endif