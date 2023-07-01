/*


Recommended Compile Command: 
g++ -std=c++17 coin_piles.cpp 
*/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

int T;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0){
            if (max(a, b) <= 2*min(a, b)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }
}