/*


Recommended Compile Command: 
g++ -std=c++17 trailing_zeros.cpp 
*/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

long long N, total = 0, cur_top = 5;

int main() {
    cin >> N;
    while (cur_top <= N) {
        total += ((N - (N%cur_top))/cur_top);
        cur_top *= 5;
    }
    cout << total << endl;
}
