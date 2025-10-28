#include <iostream>
#include <cstring>

class Trash {
  static int total_trash;    // 모든 쓰레기들의 개수

  char* name_;               // 이름
  const bool recyclable_;    // 재활용 가능 여부
  const int volume_;         // 부피

  public:
    ~Trash();                                           // 소멸자
    Trash(void);                                        // 기본 생성자, 재활용 불가능, 부피 0으로 설정
    Trash(const Trash& t);                              // 복사 생성자
    Trash(char* name, bool recyclable, int volume);     // 이름, 재활용 가능여부, 부피를 설정

    static void show_total_trash(void);   // 모든 쓰레기들의 개수를 출력한다

    void show_status(void);   // 쓰레기의 설정값을 출력한다.
};

// https://en.cppreference.com/w/cpp/language/default_constructor.html
// https://en.cppreference.com/w/cpp/language/as_operator.html

// 기본 생성자와 기본 할당 및 복사 연산자를 지원
// 근데 이게 조건에 따라서 제공하지 않기도 함
// 따로 찾아볼 것

Trash::~Trash() {
  std::cout << "** 소멸자 호출! **" << std::endl;
  total_trash--;

  delete [] name_;

  Trash trash;
}

Trash::Trash(void) : 
    name_(NULL), recyclable_(false), volume_(0) {
  std::cout << "** 기본 생성자 호출! **" << std::endl;
  total_trash++;
}

Trash::Trash(const Trash& t) :
    name_(NULL), recyclable_(t.recyclable_), volume_(t.volume_) {
  total_trash++;
  name_ = new char[strlen(t.name_)];
  strcpy(name_, t.name_);
}

Trash::Trash(char* name, bool recyclable, int volume) : 
    name_(NULL), recyclable_(recyclable), volume_(volume) {
  std::cout << "** 생성자 호출! **" << std::endl;
  total_trash++;
  name_ = new char[strlen(name)];
  strcpy(name_, name);
}



void Trash::show_total_trash(void) {
  std::cout << "모든 쓰레기들의 개수: " << total_trash << std::endl;
}


void Trash::show_status(void) {
  std::cout << ""
}


int mainv(void) {

}

