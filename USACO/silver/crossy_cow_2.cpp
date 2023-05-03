/*
C++ Solution

USACO 2017 February Contest, Silver
Problem 2. Why Did the Cow Cross the Road II
Link to Problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=715 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

int N, K, B, num, sum;
vector<int> broken_signals;

void find_shortest_possible() {
  for (int i = 0; i <= N; i++) {
    //for each possible length
    for (int b = 0; b <= B - i; b++) {
      //for each substring
      num = broken_signals[b + i + 1] - broken_signals[b] - 1;
      if (num >= K) {
        cout << i << endl;
        return;
      }
    }
  }
  cout << 0 << endl;
}

int main() {
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);
  cin >> N >> K >> B;
  broken_signals.push_back(0);
  for (int i = 0; i < B; i++) {
    cin >> num;
    broken_signals.push_back(num);
    }
  broken_signals.push_back(N + 1); 

  sort(broken_signals.begin(), broken_signals.end());

  find_shortest_possible();
}

