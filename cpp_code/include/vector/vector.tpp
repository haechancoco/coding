// #include "vector.hpp"

// 소멸자, 생성자
template <typename T>
Vector<T>::~Vector() {
  if (m_data) {
    delete[] m_data;
  }
}

template <typename T>
Vector<T>::Vector(int n) : m_data(new T[n]), m_capacity(n), m_length(0) {}

// 함수
// 맨 뒤에 새로운 원소를 추가한다.
template <typename T>
void Vector<T>::push_back(T s) {
  if (m_capacity <= m_length) {
    T* temp = new T[m_capacity * 2];
    for (int i = 0; i < m_length; ++i) {
      temp[i] = m_data[i];
    } 
    delete[] m_data;
    m_data = temp;
    m_capacity *= 2;
  }

  m_data[m_length] = s;
  m_length++;
}
// 임이의 위치의 원소에 접근한다.
template <typename T>
T& Vector<T>::operator[](int i) {
  return m_data[i];
}
// x 번째 위치한 원소를 제거한다.
template <typename T>
void Vector<T>::remove(int x) {
  for (int i = x + 1; i < m_length; ++i) {
    m_data[i - 1] = m_data[i];
  }
  m_length--;
}
// 현재 벡터의 크기를 구한다.
template <typename T>
int Vector<T>::size() {
  return m_length;
}
