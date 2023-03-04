/*
C++ SOLUTION


USACO 2016 January Contest, Silver
Problem 2. Subsequences Summing to Sevens
Link to Problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=595
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using std::cin;
using std::vector;
using std::cout;
using std::endl;
using std::max;

int N;
vector<long long> id_changes;


int find_max() {
    //find substrings to get lengths
    for (int length = N; length > 0; length--) {
        int p = N - length + 1;
        for (int min = 0; min != p; min++) {
            int max = min + length;
            long long change = id_changes[max] - id_changes[min];
            if (change % 7 == 0) {
                return length;
            }

        }
    
    }
    return 0;
}

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    cin >> N;
    id_changes.push_back(0);
    for (int i = 1; i <= N; i++) {
        long long ID; cin >> ID;
        id_changes.push_back(ID + id_changes[i - 1]);
    }

    cout << find_max() << endl;

}