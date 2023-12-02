/*
https://codeforces.com/gym/104835/problem/A

Recommended Compile Command: 
clang++ -std=c++11 -stdlib=libc++ BaklavaLayers.cpp
*/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int T;

int main() {
    cin.tie(0);
    // freopen("text", "r", stdin);
        cin >> T;
    for (int i = 0; i < T; i++) {
        int L, N;
        cin >> L >> N;
        cout << ((L * 2 + N - 1) * N)/ 2 << endl;
    }
}
