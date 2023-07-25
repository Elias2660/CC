/*


Recommended Compile Command: 
g++ -std=c++17 apple_division.cpp 
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::greater;
using std::min;
using std::abs;

long long N, shortest_diff = 1e9;
vector<long long> apples;

void find_shortest_diff(vector<long long> remaining_apples, long long diff, long long number_left) {
    if (number_left == 0) {
        shortest_diff = min(shortest_diff, abs(diff));
    }
    else {
        vector<long long> new_apples= remaining_apples;
        new_apples.pop_back();
        find_shortest_diff(new_apples, diff + remaining_apples[number_left - 1], number_left-1);
        find_shortest_diff(new_apples, diff - remaining_apples[number_left - 1], number_left-1);
    }
}

int main() {
    cin >> N;
    apples.resize(N);
    for (long long& apple:apples) {
        cin >> apple;
    }

    find_shortest_diff(apples, 0, N);
    cout << shortest_diff << endl;
}
