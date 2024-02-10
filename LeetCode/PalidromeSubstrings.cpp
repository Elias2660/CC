/*
! Brute force, need to refactor to something more simple

https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    for (int add = i + 1; add <= s.length(); add++) {
      string n = s.substr(i, add - i);
      reverse(n.begin(), n.end());
      if (s.substr(i, add - i) == n) {
        count++;
      }
    }
  }
  return count;
}