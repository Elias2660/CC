/*
https://cses.fi/problemset/task/1083
Recommended Compile Command: 
g++ -std=c++17 missing_number.cpp 
*/

#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

long long N, sum;

int main() {
    cin >> N;
    sum = ((N+ 1) * N)/2;
    for (int i = 0; i < N - 1; i++) {
        int num;
        cin >> num;
        sum -= num;
    }
    cout << sum << endl;
}