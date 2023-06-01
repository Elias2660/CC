/*


Recommended Compile Command: 
g++ -std=c++17 two_knights.cpp 
*/


#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::floor;

long long N;

int main() {
    cin >> N;
    for (long long n=1; n <= N; n++) {
        if (n == 1) {
            cout << 0 << endl;
        }

        if (n == 2) {
            cout << 6 << endl;
        }
        if (n == 3) {
            cout << 28 << endl;
        }

        if (n > 3) {
            long long total = ( (n*n) * (n * n -1))/2 ;

            //corners have two possible
            total -= 8/2;
            
            //remove the 3s
            total -= 24/2;

            //remove the 4s
            total -= 4 * 4 * (n - 4)/2;
            total -= 16/2;

            // remove the 6s
            total -= 4*6*(n-4)/2;

            //remove the 8s
            total -= (n-4)*(n-4)*8/2;

            cout << total << endl;
        }
    }
}
