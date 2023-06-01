/*
https://cses.fi/problemset/task/1068/ 

Recommended Compile Command: 
g++ -std=c++17 wierd_algorithm.cpp 
*/


#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

long long N;

int main() {
    cin >> N;
    while (N != 1) {
        cout << N << " ";
        if (N % 2 == 0) {
            N /= 2;
        }
        else {
            N *= 3;
            N += 1;
        }
    }
    cout << 1 << endl;

}