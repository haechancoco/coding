#ifndef TABLE_CPP
#define TABLE_CPP

#include <string>

class Cell;

class Table {
  protected:
  int m_max_row_size, m_max_col_size; // 행, 열 최대 크기

  Cell*** m_data_table;               // table의 데이터를 보관, cell* 를 저장하는 2차원 배열 형태

  public:
  ~Table();
  Table(int max_row_size, int max_col_size);

  void reg_cell(Cell* c, int row, int col);     // 새로운 셀을 row 행 col 열에 등록한다
  int to_numeric(int row, int col);             // row 행 col 열에 위치한 cell 의 정수 데이터를 반환한다
  int to_numeric(const std::string& s);         // "A3" 이나 "B6" 같은 문자열로 cell 의 위치를 받아 그 cell 의 정수 데이터를 반환한다. 문자는 1개만 나오는 걸로 가정
  std::string stringify(int row, int col);      // row 행 col 열에 위치한 cell 의 문자열 데이터를 반환한다
  std::string stringify(const std::string& s);  // "A3" 이나 "B6" 같은 문자열로 cell 의 위치를 받아 그 cell 의 문자열 데이터를 반환한다. 문자는 1개만 나오는 걸로 가정

  virtual std::string print_table() = 0;
};

#endif