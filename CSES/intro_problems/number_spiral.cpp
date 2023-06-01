/*
https://cses.fi/problemset/task/1071

Recommended Compile Command: 
g++ -std=c++17 number_spiral.cpp 
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::pow;
using std::min;

long long T, X, Y;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> X >> Y;
        long long base_num = max(X, Y) * max(X, Y) - max(X, Y) + 1;
        if (max(X, Y) % 2 == 1) {
            base_num += X > Y? -(max(X, Y) - min(X, Y)): max(X, Y) - min(X, Y);
        }
        if (max(X, Y) % 2 == 0) {
            base_num += X > Y? max(X, Y) - min(X, Y): -(max(X, Y) - min(X, Y));
        }
        cout << base_num << endl;
    }
}
