/* 

*/
/*
제일 위의 top은 0 level
실재 int 가 저장되는 곳은 dim level 으로 하자.

ex) [3][2][1] 배열
top(level 0) -> level 1 -> level 2 -> (실재 정보가 저장)level 3
*/

class Array {
  const int kDim;   // 몇 차원 배열인지
  int* m_size;      //  각 level의 원소 개수를 저장한다

  struct Address {
    int level;  // 맨 마지막 레벨(dim - 1) 데이터 배열을 가리키고, 그 위 상위
    void* next; // 레벨에서는 다음 Address 배열을 가리킨다.
  };

  Address* m_top;

  void initialize_address(Address* current);      // address를 초기화 하는 함수이다. 재귀 호출로 구성되어 있다.
  void delete_address(Address* current);          // 동적 할당된 공간을 해재한다.
  void copy_address(Address* dst, Address* src);  // 값을 복사한다

  public:
  ~Array();                         // 소멸자
  Array(int dim, int* array_size);  // dim차원, [array_size[0]][array_size[1]]... 배열 생성
  Array(const Array& arr);          // 복사 생성자
};



Array::~Array() {
  delete_address(m_top);
  delete[] m_size;
}

Array::Array(int dim, int *array_size) : kDim(dim) {
  m_size = new int[dim];
  for (int i = 0; i < kDim; i++) m_size[i] = array_size[i];

  m_top = new Address;
  m_top->level = 0;

  initialize_address(m_top);
}

Array::Array(const Array& arr) : kDim(arr.kDim) {
  m_size = arr.m_size;
  for (int i = 0; i < kDim; ++i) m_size[i] = arr.m_size[i];

  m_top = new Address;
  m_top->level = 0;

  initialize_address(m_top);

  // 내용물 복사
  copy_address(m_top, arr.m_top);
}



void Array::initialize_address(Address* current) {
  // NULL 들어올 시 아무 동작 하지 않음.
  if (!current) return;
  // 기저 사례
  if (current->level == kDim - 1) {
    current->next = new int[m_size[current->level]];
    return;
  }
  current->next = new Address[m_size[current->level]];
  for (int i = 0; i < m_size[current->level]; ++i) {
    (static_cast<Address*>(current->next) + i)->level = current->level + 1; 

    initialize_address(static_cast<Address*>(current->next) + i);
  }
}

void Array::delete_address(Address* current) {
  // NULL들어올 시 아무 동작 하지 않음
  if (!current) return;
  for (int i = 0; current->level < kDim - 1 && i < m_size[current->level]; ++i) {
    delete_address(static_cast<Address*>(current->next) + 1);
  }
  // 마지막 노드
  if (current->level == kDim - 1) {
    delete[] static_cast<int*>(current->next);
    current->next = nullptr;
  }
  // 중간 노드
  else {
    delete[] static_cast<Address*>(current->next);
  }
}

void Array::copy_address(Address* dst, Address* src) {
  // 뼈대는 initialize_address로 만들어 졌다.
  // 그러므로 dim level의 실재 값만 복사하면 된다.
  // 기저 사례
  if (dst->level == kDim - 1) {
    for (int i = 0; i < m_size[dst->level]; ++i) {
      static_cast<int*>(dst->next)[i] = static_cast<int*>(src->next)[i];
    }
    return;
  }
  for (int i = 0; i < m_size[dst->level]; ++i) {
    Address* tmp_dst = static_cast<Address*>(dst->next) + i;
    Address* tmp_src = static_cast<Address*>(src->next) + i;
    copy_address(tmp_dst, tmp_src);
  }
}