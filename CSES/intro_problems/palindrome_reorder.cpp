/*


Recommended Compile Command:
g++ -std=c++17 palindrome_reorder.cpp
*/

#include <iostream>
#include <map>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

string N, front, end, middle = "";
map<char, int> chars;

int main() {
  cin >> N;
  for (int i = 0; i < N.size(); i++) {
    chars[N[i]] += 1;
  }

  for (auto const& [letter, number] : chars) {
    if (number % 2 == 1) {
      if (middle == "") {
        middle = string(number, letter);
      } else {
        cout << "NO SOLUTION" << endl;
        return 0;
      }
    } else {
      front = string(number / 2, letter) + front;
      end += string(number / 2, letter);
    }
  }
  cout << front + middle + end << endl;
}
