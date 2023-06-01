/*
Recommended Compile Command: 
g++ -std=c++17 two_sets.cpp 
*/


#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

long long N, sum, target, left_size = 0, right_size = 0;
vector<int> left, right;

int main() {
    cin >> N;
    sum = N*(N + 1) / 2;
    target = sum /2;
    for (int n = N; n > 0; n --) {
        if (target - left_size >= n) {
            left_size += n;
            left.push_back(n);
        } 
        else {
            right_size += n;
            right.push_back(n);
        }
    }
    if(left_size != right_size) {
        cout << "NO" << endl;
    } 
    else {
        cout << "YES" << endl;
        cout << left.size() << endl;
        for (int item:left) {
            cout << item << " ";
        }
        cout << "\n" << right.size() << endl;
        for (int item:right) {
            cout << item << " ";
        }
        cout << endl;
    }

}
