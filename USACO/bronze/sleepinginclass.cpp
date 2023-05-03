/*
C++ SOLUTION

USACO 2022 February Contest, Bronze
Problem 1. Sleeping in Class
Link to problem:
http://usaco.org/index.php?page=viewproblem2&cpid=1203 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;



int T;

void solve() {
    int N, sum = 0; 
    cin >> N;
    vector<int> nums(N);
    for (int& num:nums) {
        cin >> num;
        sum += num;
    }
    for (int num = N; num > 0; num--) {
        if (sum % num == 0) {
            bool ok = true;
            int target = sum / num;
            int current = 0;
            for (int num:nums) {
                current += num;
                if (current > target) {
                    ok = false;
                    break;
                }
                if (current == target) {
                current = 0;
                }
            } 
            if (ok) {
                cout << N - num << endl;
                break;
            }
    }}
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}