/*
C++ Solution

USACO 2017 January Contest, Silver
Problem 2. Hoof, Paper, Scissors
Link to problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=691
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <initializer_list>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::max;

int N;
vector<int> hoof(1, 0), paper(1, 0), sissors(1, 0);

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        // for each row, sort them into the different sets
        char move;
        cin >> move;
        paper.push_back(paper[i - 1]);
        sissors.push_back(sissors[i - 1]);
        hoof.push_back(hoof[i - 1]);
        if (move == 'P') {
            paper[i]++;
        }
        if (move == 'H') {
            hoof[i]++;
        }
        if (move == 'S') {
            sissors[i]++;
        }
    }

    int max_score(0);

    for (int i = 1; i  <= N; i++) {
        int prev = max( max(hoof[i], paper[i]), sissors[i]);
        int post = max( max(hoof[N] - hoof[i], sissors[N] - sissors[i]), paper[N] - paper[i]);

        max_score = max(max_score, prev + post);
    }
    cout << max_score << endl;
}