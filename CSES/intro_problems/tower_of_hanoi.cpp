/*


Recommended Compile Command:
g++ -std=c++17 tower_of_hanoi.cpp
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int N, totalSteps = 1;

void findSteps(int diskNum, int fromRod, int toRod, int auxRod) {
  if (!diskNum) {
    return;
  }
  findSteps(diskNum - 1, fromRod, auxRod, toRod);
  cout << fromRod << " " << toRod << endl;
  findSteps(diskNum - 1, auxRod, toRod, fromRod);
}

int main() {
  cin >> N;
  for (int i = N - 1; i > 0; i--) {
    totalSteps += totalSteps + 1;
  }
  cout << totalSteps << endl;
  findSteps(N, 1, 3, 2);
}
