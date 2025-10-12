
// #include <array>
// #include <vector>

// #include <memory>

#include <iostream>
#include <cstring>
class Marine {
  int coord_x_, coord_y_;   // 위치   
  int hp_;                  // 체력
  int damage_;              // 공격력
  bool is_dead_;            // 생존 여부

  char* name_;              // 이름

  public:
    ~Marine(void);                                   // 소멸자
    Marine(void);                                    // 기본 생성자
    Marine(int x, int y);                            // x, y 좌표에 마린 생성
    Marine(int x, int y, const char* marine_name);   // x, y 좌표에 마린 생성, 마린 이름 지정

    int attack(void);                    // 데미지를 리턴한다.
    void be_attacked(int damage_earn);   // 입은 데미지
    void move(int x, int y);             // 새로운 위치

    void show_status(void);   // 상태를 보여준다.
};
Marine::~Marine(void) {
  std::cout << name_ << "의 소멸자 호출 ! " << std::endl;
  delete[] name_;  // nullptr일 수도 있지만 안전하다.
}
Marine::Marine() {
  coord_x_= coord_y_ = 0;
  hp_ = 50;
  damage_ = 5;
  is_dead_ = false;
  name_ = NULL;
}
Marine::Marine(int x, int y) {
  coord_x_ = x;
  coord_y_ = y;
  hp_ = 50;
  damage_ = 5;
  is_dead_ = false;
  name_ = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
  coord_x_= coord_y_ = 0;
  hp_ = 50;
  damage_ = 5;
  is_dead_ = false;
  name_ = new char[strlen(marine_name) + 1];
  strcpy(name_, marine_name);
}

void Marine::move(int x, int y) {
  coord_x_ = x;
  coord_y_ = y;
}
int Marine::attack(void) {
  return damage_;
}
void Marine::be_attacked(int damage_earn) {
  hp_ -= damage_earn;
  if (hp_ < 0) is_dead_ = true;
}
void Marine::show_status(void) {
  std::cout << "*** Marine : " << name_ << " ***" << std::endl;
  std::cout << " Location : ( " << coord_x_ << " , " << coord_y_ << " ) " << std::endl;
  std::cout << " HP : " << hp_ << std::endl;
}

int main(void) {
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();

  std::cout << '\n' << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}