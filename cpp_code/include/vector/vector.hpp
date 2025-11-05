#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class Vector {
  T*  m_data;
  int m_capacity;
  int m_length;

  public:
  // 소멸자, 생성자
    ~Vector();
    Vector(int n = 1);

  // 함수
    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s);
    // 임이의 위치의 원소에 접근한다.
    T operator[](int i);
    // x 번째 위치한 원소를 제거한다.
    void remove(int x);
    // 현재 벡터의 크기를 구한다.
    int size();

};

#include "vector.tpp"

#endif