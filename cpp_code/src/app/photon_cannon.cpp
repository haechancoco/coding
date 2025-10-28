// photon_cannon.cpp
#include <cstring>
#include <iostream>

class Photon_Cannon {
  int coord_x_, coord_y_;   // 위치
  int hp_;                  // 체력
  int shield_;              // 방어막 체력
  int damage_;              // 공격력

  char *name_;               // 이름

  public:
    ~Photon_Cannon();                                       // 소멸자
    Photon_Cannon(const Photon_Cannon& pc);                 // 복사 생성자
    Photon_Cannon(int x, int y);                            // x, y 좌표에 포토케논 생성
    Photon_Cannon(int x, int y, const char* cannon_name);   // x, y좌표설정과 이름설정
    
    void show_status(void);   // 상태를 보여준다.
  };
Photon_Cannon::~Photon_Cannon(void) {
  std::cout << "Photon : " << name_ << " 제거" << std::endl;
  delete[] name_;
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
  std::cout << "복사 생성자 호출 !" << std::endl;
  coord_x_ = pc.coord_x_;
  coord_y_ = pc.coord_y_;
  hp_ = pc.hp_;
  shield_ = pc.shield_;
  damage_ = pc.damage_;

  name_ = new char[strlen(pc.name_) + 1];
  strcpy(name_, pc.name_);
}
Photon_Cannon::Photon_Cannon(int x, int y) {
  std::cout << "생성자 호출 !" << std::endl;
  coord_x_ = x;
  coord_y_ = y;
  hp_ = 100;
  shield_ = 100;
  damage_ = 20;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
  coord_x_ = x;
  coord_y_ = y;
  hp_ = 100;
  shield_ = 100;
  damage_ = 20;

  name_ = new char[strlen(cannon_name) + 1];
  strcpy(name_, cannon_name);
}

void Photon_Cannon::show_status(void) {
  std::cout << "Photon cannon " << std::endl;
  std::cout << "Location : ( " << coord_x_ << " , " << coord_y_ << " ) " << std::endl;
  std::cout << " HP : " << hp_ << std::endl;
}

int main(void) {
  Photon_Cannon pc1(3, 3, "cannon");
  Photon_Cannon pc2 = pc1;

  pc1.show_status();
  pc2.show_status();

  return 0;
}
