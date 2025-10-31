#ifndef HTML_TABLE_CPP
#define HTML_TABLE_CPP

#include <string>
#include "excel/table.hpp"

class HtmlTable : public Table {
  public:
  HtmlTable(int row, int col);

  std::string print_table();
};

#endif