/*


Recommended Compile Command: 
g++ -std=c++17 bit_strings.cpp 
*/


#include <iostream>
#include <cmath>
#include <cstdint>
using std::cin;
using std::cout;
using std::endl;
using std::pow;

long long N, sum = 1;
const long long mod = (int)1e9+7;

int main() {
    //freopen("in", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++) {
        sum *= 2;
        sum %= mod;
    }
    cout << sum << endl;
}
