/*
원소 x (1 <= x <= 20)
1 <= 연산 수 <= 3,000,000

범위가 크지 않으니 원소는 계수 정렬을 사용하여 저장
*/


#include <iostream>
#include <string>

using namespace std;

class Set {
	enum Arr {
		kArrSize = 21
	};
  bool m_arr[kArrSize] = {0};

	public:
  enum TypeOper {
    kNone,
    kAdd,
    kRemove,
    kCheck,
    kToggle,
    kAll,
    kEmpty
  };

	Set(void) = default;

	void add(int x);			// x를 집합에 추가한다
	void remove(int x);		// x를 집합에서 제거한다
	void check(int x);		// 집합에 x가 있으면 1을, 없으면 0을 출력한다
	void toggle(int x);		// 집합에 x가 있으면 x를 제거하고, 없으면 x를 추가한다
	void all(void);				// 집합에 모든 원소를 추가한다
	void empty(void);			// 집합을 공집합으로 만든다

  TypeOper parse_str_oper(const string& str);    // 문자열 입력이 어떤 연산인지 알아낸다

  void show_all_ele(void);    // (디버깅)집합의 모든 원소 상태를 출력한다
};



void Set::add(int x) {
	m_arr[x] = true;
}
void Set::remove(int x) {
	m_arr[x] = false;
}
void Set::check(int x) {
	cout << m_arr[x] << "\n";
}
void Set::toggle(int x) {
	m_arr[x] = 1 - m_arr[x];
}
void Set::all(void) {
	for (bool& i : m_arr) {
		i = true;
	}
}
void Set::empty(void) {
	for (bool& i : m_arr) {
    i = false;
  }
}



Set::TypeOper Set::parse_str_oper(const string& str) {
  if (str == "add") return kAdd;
  else if (str == "remove") return kRemove;
  else if (str == "check") return kCheck;
  else if (str == "toggle") return kToggle;
  else if (str == "all") return kAll;
  else if (str == "empty") return kEmpty;
  else return kNone;
}




void Set::show_all_ele(void) {
  cout << "**집합 원소 상태**" << endl;
  for (int i = 1; i < kArrSize; ++i) {
    cout << i << "(" << m_arr[i] << ")" << ", ";
  }
  cout << endl;
}



void oper_exec(Set::TypeOper to, Set& s) {
  int x = -1;
  switch (to) {
    case Set::kNone:
      cout << "should not happen" << endl;
      break;
    case Set::kAdd:
      cin >> x;
      s.add(x);
      break;
    case Set::kRemove:
      cin >> x;
      s.remove(x);
      break;
    case Set::kCheck:
      cin >> x;
      s.check(x);
      break;
    case Set::kToggle:
      cin >> x;
      s.toggle(x);
      break;
    case Set::kAll:
      s.all();
      break;
    case Set::kEmpty:
      s.empty();
      break;
  }
}



int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m;
  cin >> m;

  Set s;

  while (m--) {
    string str;
    int x;
    cin >> str;

    Set::TypeOper to = s.parse_str_oper(str);
    oper_exec(to, s);
    // s.show_all_ele();   // 디버깅용
  }
    
	return 0;
}