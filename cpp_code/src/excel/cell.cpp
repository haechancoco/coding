#include "excel/cell.hpp"

using namespace std;



Cell::Cell(string data, int x, int y, Table* table)
  : m_data(data), m_x(x), m_y(y), m_table(table) {}

string Cell::stringify() { return m_data; };

int Cell::to_numeric() { return 0; };
