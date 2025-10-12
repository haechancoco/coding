#include <iostream>
#include <cstring>


class string {
  char* str_;
  int len_;

  public:
    ~string();                 // 소멸자
    string(const string& s);   // 복사 생성자
    string(char c, int n);     // 문자 c 가 n 개 있는 문자열로 정의
    string(const char* s);     // 문자열 s 복사해서 저장.

    void check(void);;
string::~string() {
  std::cout << "소멸자 호출 : " << str_ << std::endl;
  delete[] str_;
}
string::string(const string& s) {
  std::cout << "복사 생성자 호출" << std::endl;
  len_ = s.len_;
  str_ = new char[len_ + 1];
  strcpy(str_, s.str_);
}
string::string(char c, int n) {
  len_ = n;
  str_ = new char[len_ + 1];
  memset(str_, c, sizeof(char) * n);
  str_[n] = '\0';
}
string::string(const char* s) {
  len_ = strlen(s);
  str_ = new char[len_ + 1];
  strcpy(str_, s);
}

void check(void) {
  std::cout << "확인" << std::endl;
  std::cout << "str_ : " << str_ << std::endl;
  std::cout << "len_ : " << len_ << std::endl;
}
int main(void) {
  string s('a', 3);
  s.check();
}