// https://atcoder.jp/contests/dp/tasks/dp_d
/*
! clang++ -std=c++11 -stdlib=libc++ Knapsack1.cpp
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::max;
using std::min;
using std::string;
using std::vector;
const int INF = -1e9;

/*
This problem is a dp solution
That means that we're going to have an array with length of the weight; which is
less that 1e6 We're going to have to iterate through the array ! d[weight] will
return the maximum value that can be gained with the weight taken That  that
we're going t
*/

int main() {
  freopen("input", "r", stdin);
  int N, W;
  cin >> N >> W;
  vector<long long> dp = vector<long long>(W+1, INF);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    int w, v;
    cin >> w >> v;
    // take in the item values
    for (int j = W - w + 1; j >= 0; j--) {
      // iterating backwards because you don't want double counting
      // in addition, we're going to have to check backwards from the earlier things b/c  things
      // that weight too much don't work
      if (dp[j] != INF) {
        // if the value exists
        /*
        ! to Explain this code

        If the value exists, then we can says that the maximum value of an
        element with the next element with the weight of the current element +
        the value of the current element
        */
        dp[j + w] = max(dp[j + w], dp[j] + v);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}