#include <string>
#include "excel/table.hpp"
#include "excel/html_table.hpp"

using namespace std;

HtmlTable::HtmlTable(int row, int col) : Table(row, col) {}

string HtmlTable::print_table() {
    string s = "<table border='1' cellpadding='10'>";
}