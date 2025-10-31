#include <iostream>
#include <fstream>
#include "../../lib/excel/excel.hpp"

using namespace std;

int main(void) {
  TxtTable table(5, 5);
  ofstream out("test_excel.txt");

  table.reg_cell(new Cell("Hello~", 0, 0, &table), 0, 0);

  // table.print_cell(0, 0);

  cout << endl << table.print_table();
  out << table.print_table();

  return 0;
}