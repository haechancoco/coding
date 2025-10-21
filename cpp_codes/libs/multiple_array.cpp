/*
제일 위의 top은 0 level
실재 int 가 저장되는 곳은 dim level 으로 하자.
*/

class Array {
  const int m_kDim; // 몇 차원 배열인지
  int* m_size;      //  각 차원의 원소 개수를 저장한다

  struct Address {
    int m_level;  // 맨 마지막 레벨(dim - 1) 데이터 배열을 가리키고, 그 위 상위
    void* m_next; // 레벨에서는 다음 Address 배열을 가리킨다.
  };
  Address* m_top;

  void initialize_address(Address* current);  // address를 초기화 하는 함수이다. 재귀 호출로 구성되어 있다.
  void delete_address(Address* current);  // 동적 할당된 공간을 해재한다.

public:
  Array(int dim, int *array_size) : m_kDim(dim) {
    m_size = new int[dim];
    for (int i = 0; i < m_kDim; i++)
      m_size[i] = array_size[i];
  }
};

void Array::initialize_address(Address* current) {
  // 기저 사례
  if (current->m_level == m_kDim - 1) {
    current->m_next = new int[m_size[current->m_level]];
    return;
  }
  current->m_next = new Address[m_size[current->m_level]];
  for (int i = 0; i != m_size[current->m_level]; ++i) {
    (static_cast<Address*>(current->m_next) + i)->m_level = current->m_level + 1; 

    initialize_address(static_cast<Address*>(current->m_next) + i);
  }
}