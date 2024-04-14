/*


Recommended Compile Command:
clang++ -std=c++11 -stdlib=libc++ Question5.cpp
*/

#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
int N, M;

int main() {
  cin.tie();
  freopen("in", "r", stdin);
  cin >> N >> M;
  vector<int> inner;
  vector<int> outer;
  for (int i = 0; i < M; i++) {
    int en;
    int ex;
    cin >> en >> ex;
    inner.push_back(en);
    outer.push_back(ex);
  }
  sort(inner.begin(), inner.end());
  sort(outer.begin(), outer.end());
  vector<int>::iterator a = inner.begin();
  vector<int>::iterator b = outer.begin();
  int num = 0, last = 0, f = 0;
  while (true) {
    int innerVal = *a;
    int outerVal = *b;
    if (innerVal > outerVal) {
      if (num == 0) {
        cout << innerVal << endl;
        f += innerVal - last;
      }
      num++;
      a++;
    } else if (innerVal < outerVal) {
      // if the next thing to occur is an end;
      num--;
      b++;
      last = outerVal;
    } else {
      b++;
      a++;
    }
    if (*b == outer[outer.size() - 1]) {
      break;
    }
  }
  f += inner[0];
  f += M - outer[outer.size() - 1 ];
  cout << f << endl;
}