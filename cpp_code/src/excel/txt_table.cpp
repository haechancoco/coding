// #include <iostream>
#include <algorithm>  // max() 사용을 위해 추가
#include "excel/txt_table.hpp"
#include "excel/cell.hpp"

using namespace std;

// private

// c 를 n 번 반복한 문자열을 반환한다
string TxtTable::repeat_char(char c, int n) {
  string s = "";
  for (int i = 0; i < n; ++i) s.push_back(c);
  
  return s;
}
// index 번호가 n 인 열의 이름을 반환한다. ex) n 이 0 이면 A, 2 이면 C 인 형식이다.
string TxtTable::col_num_to_str(int n) {
  const int kAlphNum = 26;
  string s = "";

  ++n;

  do {
    --n; 
    s.insert(0, 1, 'A' + n % kAlphNum);
    n /= kAlphNum;
  }while (n > 0);
  
  return s;
}

// public
// 생성자
TxtTable::TxtTable(int row, int col) : Table(row, col) {};

// 함수
string TxtTable::print_table() {
  const string kSAButton = "    ";  // 맨 위 좌측 빈공간(Select All button)
  const int kDefaultWide = 2;       // cell 이 비어있으면 기본적으로 2칸의 공백을 표시한다.
  const string kDelim = " | ";      // cell 을 구분해주는 구분자이다.

  // i번열의 최대 문자열 길이를 구한다.
  int* col_max_wide = new int[m_max_col_size];  // 각 열에 저장된 string의 최대 길이를 저장한다.
  for (int i = 0; i < m_max_col_size; ++i) {
    unsigned int max_wide = kDefaultWide;
    for (int j = 0; j < m_max_row_size; ++j) {
      if (m_data_table[j][i] &&
          m_data_table[j][i]->stringify().length() > max_wide) {
        max_wide = m_data_table[j][i]->stringify().length();
      }
    }
    col_max_wide[i] = max_wide;
  }
  // 맨 상단에 열 정보 표시
  string total_table = kSAButton;                       // 전체 table 을 string 으로 저장
  int total_wide = total_table.length();                // table 의 행 길이를 저장
  for (int i = 0; i < m_max_col_size; ++i) {
    int max_len = max(kDefaultWide, col_max_wide[i]);   // 각 열의 cell에 저장된 string 의 최대 길이를 저장
    total_table += kDelim + col_num_to_str(i);
    total_table += repeat_char(' ', max_len - col_num_to_str(i).length());

    total_wide += (max_len + kDelim.length());  
  }

  total_table += "\n";
  // 0 번째 행부터 stirng 으로 변환
  for (int i = 0; i < m_max_row_size; ++i) {
    total_table += repeat_char('-', total_wide);
    total_table += "\n" + to_string(i + 1);
    total_table += repeat_char(' ', kSAButton.length() - to_string(i + 1).length());
    // 
    for (int j = 0; j < m_max_col_size; ++j) {
      if (col_max_wide[j]) {
        int max_len = max(2, col_max_wide[j]);  // 각 열의 cell에 저장된 string 의 최대 길이를 저장 

        string s = "";
        if (m_data_table[i][j]) {
          s  = m_data_table[i][j]->stringify();
        }
        total_table += " | " + s;
        total_table += repeat_char(' ', max_len - s.length());
      }
    }
    total_table += "\n";
  }  

  return total_table;
}

