
// #include <array>
// #include <vector>

// #include <memory>

#include <iostream>
#include <cstring>
class Marine {
  static int total_marine_num_;   // 모든 마린의 수

  const int kDefaultDamage;   // 기본 공격력

  char* name_;              // 이름
  int coord_x_, coord_y_;   // 위치   
  int hp_;                  // 체력
  bool is_dead_;            // 생존 여부
  

  public:
    ~Marine();                                        // 소멸자
    Marine(void);                                     // 기본 생성자
    Marine(int x, int y);                             // x, y 좌표설정
    Marine(int x, int y, const int kDefaultDamage);   // x, y 좌표설정, 기본데미지 설정
    Marine(int x, int y, const char* marine_name);    // x, y 좌표설정, 이름 설정

    static void show_total_marine(void);   // 전체 마린 수 출력

    void move(int x, int y);                // 새로운 위치
    int attack(void) const;                 // 데미지를 리턴
    Marine& be_attacked(int damage_earn);   // 입은 데미지만크 hp 감소

    void show_status(void);   // 상태를 보여준다.
};



int Marine::total_marine_num_ = 0;



Marine::~Marine() {
  std::cout << "__소멸자 호출 !__" << std::endl;
  total_marine_num_--;

  delete[] name_;  // nullptr일 수도 있지만 안전하다.
}
Marine::Marine() 
    : name_(NULL), coord_x_(0), coord_y_(0), hp_(50), is_dead_(false), kDefaultDamage(5) {
  total_marine_num_++;
}
Marine::Marine(int x, int y) 
    : name_(NULL), coord_x_(x), coord_y_(y), hp_(50), is_dead_(false), kDefaultDamage(5) {
  total_marine_num_++;
}
Marine::Marine(int x, int y, const int kDefaultDamage) 
    : name_(NULL), coord_x_(x), coord_y_(y), hp_(50), is_dead_(false), kDefaultDamage(kDefaultDamage) {
  total_marine_num_++;
}
Marine::Marine(int x, int y, const char* marine_name) 
    : name_(NULL), coord_x_(x), coord_y_(y), hp_(50), is_dead_(false), kDefaultDamage(5) {
  total_marine_num_++;

  name_ = new char[strlen(marine_name) + 1];
  strcpy(name_, marine_name);
}



void Marine::show_total_marine(void) {
  std::cout << "전체 마린 수 : " << total_marine_num_ << std::endl;
}



void Marine::move(int x, int y) {
  coord_x_ = x;
  coord_y_ = y;
}
int Marine::attack(void) const {
  return kDefaultDamage;
}
Marine& Marine::be_attacked(int damage_earn) {
  hp_ -= damage_earn;
  if (hp_ < 0) is_dead_ = true;

  return *this;
}
void Marine::show_status(void) {
  if (name_ != NULL) std::cout << "*** Marine : " << name_ << " ***" << std::endl;
  else std::cout << "*** Marine ***" << std::endl;

  std::cout << " Location : ( " << coord_x_ << " , " << coord_y_ << " ) " << std::endl;
  std::cout << " HP : " << hp_ << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num_<< std::endl;
}



int main(void) {
  Marine marine1(2, 3);
  marine1.show_status();

  Marine marine2(3, 5);
  marine2.show_status();


  std::cout << '\n' << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}