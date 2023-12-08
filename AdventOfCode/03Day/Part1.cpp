// USED ANOTHER SOLUTION: MINE DIDN:T WORK
// /*


// Recommended Compile Command:
// clang++ -std=c++11 -stdlib=libc++ Part1.cpp
// */

// #include <cctype>
// #include <iostream>
// #include <string>
// #include <vector>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::isdigit;
// using std::string;
// using std::vector;
// long long count = 0;

// int main() {
//   freopen("test.txt", "r", stdin);
//   vector<string> map;
//   string line;
//   cin >> line;
//   string end;
//   for (int i = 0; i < line.size() + 2; i++) {
//     end += ".";
//   }
//   map.push_back(end);
//   map.push_back("." + line + ".");
//   cout << end << endl;
//   cout << "." + line + "." << endl;
//   while (!cin.eof()) {
//     string line;
//     cin >> line;
//     map.push_back("." + line + ".");
//     cout << "." + line + "." << endl;
//   }
//   cout << end << endl;
//   map.push_back(end);

//   for (int i = 1; i < map.size() - 1; i++) {
//     // find the index values of each specific number
//     string str_num = "";
//     vector<string> surrounding;
//     for (int j = 1; j < map[i].size() - 1; j++) {
//       // if one can find a non . or digit character in the box, ++
//       if (!isdigit(map[i][j]) && str_num != "") {
//         bool check = false;
//         for (int ci : {-1 + i, i, 1 + i}) {
//           cout << map[ci].substr(j - str_num.size() - 1, str_num.size() + 2) << endl;
//           if (map[ci]
//                   .substr(j - str_num.size() - 1, str_num.size() + 2)
//                   .find_first_not_of("0123456789.") != string::npos) {
//             check = !check;

//             // cout << map[ci].substr(j - str_num.size() - 1, str_num.size() + 2) << endl;
//           }
//         }
//         if (check) {
//           count += (long long) stoi(str_num);
//         }
//         str_num = "";
//       } else if (isdigit(map[i][j])) {
//         str_num += map[i][j];
//       }
//     }
//     // // cout << "---------" << endl;

//     // for (string item:map) {
//     //   cout << item << endl;
//     // }
//   }
//   cout << count << endl;
// }
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Number {
  int col; 
  int row; 
  int number; 
  int order; // number of digits in number
};

int main(int argc, char * argv[]) {
  std::string input = "test.txt";
  if (argc > 1) {
    input = argv[1];
  }

  std::string line;
  std::fstream file(input);

  std::vector<std::string> map;
  std::vector<Number> numbers; // store numbers and their location
  while(std::getline(file, line)) {
    map.push_back(line);
    bool is_number = false;
    int number = -1;
    int start = 0;
    int order = 0;
    const auto add_util = [&]() {
        Number n;
        n.row = map.size() - 1;
        n.col = start;
        n.number = number;
        n.order = order;
        numbers.push_back(n);
        number = -1;
        start = 0;
        order = 0;
    };

    for (int i = 0; i < line.size(); i++) {
      const char c = line[i];
      if (c >= '0' && c <= '9') {
        if (is_number == false) {
          number = 0;
          start = i;
          order = 0;
        } 
        is_number = true;
        number = (number * 10) + int (c - '0');
        order++;
      } else {
        is_number = false;
      }
      if (number != -1 && !is_number) {
        add_util();
      }
    }
    if (number != -1) {
      add_util();
    }
  }
  std::vector<int> parts;
  for (const auto& n : numbers) {
    bool still_searching = true;
    for (int row = n.row - 1; (row <= n.row + 1) && still_searching; row++) {
      if (row < 0 || row >= map.size()) continue;
      // Only need to check the points around the number
      // ????????
      // ?number?
      // ????????
      // Check only the first and last element in the row that contains the number
      const int col_increment = (row == n.row) ? n.order + 1 : 1;
      for (int col = n.col - 1; (col <= n.col + n.order) && still_searching; col += col_increment) {
        if (col < 0 || col >= map[row].size()) continue;
        if (map[row][col] != '.' && !(map[row][col] >= '0' && map[row][col] <= '9')) {
          still_searching = false;
          parts.push_back(n.number);
        }
      }
    }
  }

  const auto total = std::accumulate(std::begin(parts), std::end(parts), 0);
  std::cout << total << '\n';
  return 0;
}