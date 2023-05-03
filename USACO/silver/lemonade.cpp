/*
C++ SOLUTION


USACO 2018 US Open Contest, Silver
Problem 2. Lemonade Line
Link to Problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=835
*/

#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::greater;
using std::sort;

int N;
vector<int> line;

int find_end() {
    for (int c = 0; c < N; c++) {
        if (line[c] < c) {
            return c;
        }
    }
    return N;
}

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    cin >> N;
    line.resize(N);
    
    for (int& cow:line) {
       cin >> cow;
    }

    sort(line.begin(), line.end(), greater<int>());

    cout << find_end() << endl;
}
