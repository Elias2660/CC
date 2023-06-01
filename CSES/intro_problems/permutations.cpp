/*


Recommended Compile Command: 
g++ -std=c++17 starter.cpp 
*/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int N;

void solve() {
    if (N <= 3  && N != 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (N % 2 == 1) {
        for (int n  = 1; n <= N; n += 2) {
            cout << n << " ";
        }
        for (int n = 2; n < N; n += 2) {
            cout << n << " ";
        }
        cout << endl;
        return;
    }
    else {
        for (int n = 2; n <= N; n += 2) {
            cout  << n << " ";
        }
        for (int n = 1; n < N; n += 2) {
            cout << n << " ";
        }
        cout << endl;
        return;
    }
}

int main() {
    //freopen("in", "r", stdin);
    cin >> N;
    solve() ;
}
