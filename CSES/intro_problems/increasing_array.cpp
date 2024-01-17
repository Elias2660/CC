/*
Recommended Compile Command:
g++ -std=c++17 increasing_array.cpp
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

long long N, last, steps = 0;

int main() {
  cin >> N;
  cin >> last;
  for (int n = 0; n < N - 1; n++) {
    int num;
    cin >> num;
    steps += last > num ? last - num : 0;
    last = last > num ? last : num;
  }
  cout << steps << endl;
}
