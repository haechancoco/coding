/* 
  카라츠바 빠른 곱셈 알고리즘은 두 수를 절반으로 쪼겐다. a 와 b
  가 각각 256 자리라면 a1 과 b1 은 큰 쪽 128자리, a0 와 b0 은 그
  다음 128 자리를 저장하도록 하는 것이다.

  a = a1 * 10^128 + a0
  b = b1 * 10^128 + b0

  카라츠바는 이때 a * b 를 4개의 조각으로 표현하는 방법을 사용한다

  a * b = (a1*10^128 + a0)*(b1*10^128 + b0)
        = a1*b1*10^256 + (a1*b0 + a0*b1)*10^128 + a0*b0

  이 방법으로 큰 정수 두개를 한 번 곱하는 데신 절반 크기로 나눈
  작은 조각을 4번 곱한다(10의 거듭제곱은 뒤에 0을 붙이는 쉬프트
  연산으로 구현하면 되니 곱셈을 치지 않는다). 이대로 각각을 재귀
  호출해서 해결하면 분할 정봅 알고리즘이라고 할 수 있는데...
  이 자체로는 복잡도가 O(n^2)으로 같다.

  카라츠바가 발견한 것은 다음과 같이 a * b 를 표현했을 때 4번
  대신 3번의 곱셈으로만 이 값을 발견할 수 있다는 거다!

  a * b = a1*b1*10^256 + (a1*b0 + a0*b1)*10^128 + a0*b0
  z2 = a1*b1
  z1 = (a1*b0 + a0*b1)
  z0 = a0*b0

  위 식에서 z0 과 z2 를 각각 1번의 곱셈으로 구한 후 다음 식을 이
  용해

  (a0 + a1)*(b0 + b1) = (a0*b0) + (a1*b0 + a0*b1) + (a1*b1)
                           z0            z1            z2
  
  z0 과 z2 를 위 식에서 빼면 z1을 구할 수 있다.

  z2 = a1*b1
  z0 = a0*b0
  z1 = (a0 + a1)*(b0 + b1) - z2 - z0

  이 과정은 곱셈을 3번밖에 사용하지 않는다!
*/

#include <vector>

using namespace std;

// a += b * (10^k); 를 구현한다
void addTo(vector<int>& a, const vector<int>& b, int k);

//a -= b; 를 구현한다. a >= b 를 가정한다
void subFrom(vector<int>& a, vector<int>& b);

// 두 긴 정수의 곱을 반환한다.
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
  int an = a.size(), bn = b.size();

  // a 가 b 보다 짧을 경우 둘을 바꾼다
  if (an < bn) return karatsuba(b, a);

  // 기저 사례: a 나 b 가 비어 있는 경우
  if (an == 0 || bn == 0) return vector<int>();
}

