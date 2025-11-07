#include "excel/table.hpp"
#include "excel/cell.hpp"
using namespace std;



Table::~Table() {
  // 말단 Cell* 해제
  for (int i = 0; i < m_max_row_size; ++i) {
    for (int j = 0; j < m_max_col_size; ++j) {
      if (m_data_table[i][j]) delete m_data_table[i][j];
    }
  }
  // Cell* 배열(열) 해제
  for (int i = 0; i < m_max_row_size; ++i) {
    delete[] m_data_table[i];
  }
  // Cell** 배열(행) 해제
  delete[] m_data_table;
}

Table::Table(int max_row_size, int max_col_size)
    : m_max_row_size(max_row_size), m_max_col_size(max_col_size) {
  m_data_table = new Cell**[m_max_row_size];      // 행
  for (int i = 0; i < m_max_row_size; ++i) {
    m_data_table[i] = new Cell*[m_max_col_size];  // 열
    for (int j = 0; j < m_max_col_size; ++j) {
      m_data_table[i][j] = nullptr;
    }
  }
}



void Table::reg_cell(Cell* c, int row, int col) {
  if (!(row < m_max_row_size && col < m_max_col_size)) return;

  if (m_data_table[row][col]) delete m_data_table[row][col];

  m_data_table[row][col] = c;
}

int Table::to_numeric(const string& s) {
  int col = s[0] - 'A';
  int row = atoi(s.c_str() + 1) - 1;

  return Table::to_numeric(row, col);
}
int Table::to_numeric(int row, int col) {
  if (row < m_max_row_size && col < m_max_col_size && m_data_table[row][col]) {
    return m_data_table[row][col]->to_numeric();
  }
  return 0;
}

string Table::stringify(const string& s) {
  int col = s[0] - 'A';
  int row = atoi(s.c_str() + 1) - 1;

  if (row < m_max_row_size && col < m_max_col_size) {
    if (m_data_table[row][col]) {
      return m_data_table[row][col]->stringify();
    }
  }
  return "";
}
string Table::stringify(int row, int col) {
  if (row < m_max_row_size && col < m_max_col_size && m_data_table[row][col]) {
    return m_data_table[row][col]->stringify();
  }
  return "";
}

ostream& operator<<(ostream& o, Table& table) {
  o << table.print_table();
  return o;
}



