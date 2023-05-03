/*
C++ Solution

USACO 2015 December Contest, Silver
Problem 3. Breed Counting
Link to problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=572
*/
#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);


    int N, Q;
    cin >> N >> Q;
    vector<int> holstein(N + 1, 0), guernsey(N + 1,0), jersey(N + 1, 0);
    for (int i = 1;  i <= N; i++) {
        int x;
        cin >> x; 

        holstein[i] = (x == 1)? holstein[i - 1] + 1 : holstein[i - 1];
        guernsey[i] = (x == 2)? guernsey[i - 1] + 1 : guernsey[i - 1];
        jersey[i] = (x == 3)? jersey[i - 1] + 1 : jersey[i - 1];
        }

    for (int i = 0; i < Q; i++) {
        int first, last;
        cin >> first >> last;

        cout <<
         holstein[last] - holstein[first - 1] << " " <<
          guernsey[last] - guernsey[first - 1] << " " <<
           jersey[last] - jersey[first - 1] <<
            endl; 

    }
}