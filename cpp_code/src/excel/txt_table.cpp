#include <iostream>
#include <algorithm>  // max() 사용을 위해 추가
#include "excel/txt_table.hpp"
#include "excel/cell.hpp"

using namespace std;

// private

// c 를 n 번 반복한 문자열을 반환한다
string TxtTable::repeat_char(int n, char c) {
  string s = "";
  for (int i = 0; i < n; ++i) s.push_back(c);
  
  return s;
}
// index 번호가 n 인 열의 이름을 반환한다. ex) n 이 0 이면 A, 2 이면 C 인 형식이다.
string TxtTable::col_num_to_str(int n) {
  string s = "";
  if (n < 26) {
    s.push_back('A' + n);
  } else {
    char first = 'A' + n / 26 - 1;
    char second = 'A' + n % 26;
    
    s.push_back(first);
    s.push_back(second);
  }
  
  return s;
}

// public
// 생성자
TxtTable::TxtTable(int row, int col) : Table(row, col) {};

// 함수
string TxtTable::print_table() {
  string total_table;

  // i번열의 최대 문자열 길이를 구한다.
  int* col_max_wide = new int[m_max_col_size];
  for (int i = 0; i < m_max_col_size; ++i) {
    unsigned int max_wide = 2;
    for (int j = 0; j < m_max_row_size; ++j) {
      if (m_data_table[j][i] &&
          m_data_table[j][i]->stringify().length() > max_wide) {
        max_wide = m_data_table[j][i]->stringify().length();
      }
    }
    col_max_wide[i] = max_wide;
  }
  // 맨 상단에 열 정보 표시
  total_table += "    ";  // 맨 위 좌측 빈공간을 표현
  int total_wide = 4;
  for (int i = 0; i < m_max_col_size; ++i) {
    if (col_max_wide[i]) {
      int max_len = max(2, col_max_wide[i]);
      total_table += " | " + col_num_to_str(i);
      total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

      total_wide += (max_len + 3);
    }
  }

  total_table += "\n";
  // 일단 기본적으로 최대 9999 번째 행 까지 지원한다고 생각한다.
  for (int i = 0; i < m_max_row_size; ++i) {
    total_table += repeat_char(total_wide, '-');
    total_table += "\n" + to_string(i + 1);
    total_table += repeat_char(4 - to_string(i + 1).length(), ' ');

    for (int j = 0; j < m_max_col_size; ++j) {
      if (col_max_wide[j]) {
        int max_len = max(2, col_max_wide[j]);

        string s = "";
        if (m_data_table[i][j]) {
          s  = m_data_table[i][j]->stringify();
        }
        total_table += " | " + s;
        total_table += repeat_char(max_len - s.length(), ' ');
      }
    }
    total_table += "\n";
  }  

  return total_table;
}

