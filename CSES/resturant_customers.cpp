/*
CSES PROBLEM: Restaurant Customers

Link to problem: https://cses.fi/problemset/task/1619



Recommended Compile Command:
clang++ -std=c++11 -stdlib=libc++ starter.cpp
*/
#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
vector<int> arrivalTimes;
vector<int> departureTimes;
int N, sum = 0;

int main() {
  freopen("in", "r", stdin);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, d;
    cin >> a >> d;
    arrivalTimes.push_back(a);
    departureTimes.push_back(d);
  }
  sort(arrivalTimes.begin(), arrivalTimes.end());
  sort(arrivalTimes.begin(), arrivalTimes.end());
  vector<int>::iterator arrival = arrivalTimes.begin();
  vector<int>::iterator departure = departureTimes.begin();
  for (int i = 0; i < N; i++) {
    int dep = *departure, arr = *arrival;
    if (dep > arr) {

    } 
  }
}