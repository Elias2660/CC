/*
Recommended Compile Command: 
g++ -std=c++17 digit_queries.cpp 
*/


#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::string;

int Q; 

int main() {
    // freopen("in", "r", stdin);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        long long k,  length = 1;
        cin >> k;
        while (k > (length) * 9 * (long long) pow(10, length - 1) ) {
            long long nextGroup = 9 * (long long) pow(10,(length-1)) * length;
            k -= nextGroup;
            length++;
        }
        k--;
        long long remaining = k % length;
        long long numbersAbove = (k - remaining)/length;

        // cout << spacesLeft << " : " << remaining << " : " << numbersAbove << ": " << length << endl;
        long long ans_num = (long long)pow(10,length - 1) + numbersAbove;
        string ans_letter = to_string(ans_num);

        cout << ans_letter[remaining] << endl ;
        // cout << ans_num << endl;
    }
}
