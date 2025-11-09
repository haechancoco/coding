#ifndef TXT_TABLE_HPP
#define TXT_TABLE_HPP

#include "table.hpp"

class TxtTable : public Table {
  std::string repeat_char(char c, int n);
  std::string col_num_to_str(int n);

  public:
  TxtTable(int row, int col);

  std::string print_table();
};


#endif