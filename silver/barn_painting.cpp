/*
C++ Solution**

Got lots of help from official answer at USACO

USACO 2019 February Contest, Silver
Problem 2. Painting the Barn
Link to Problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=919
*/

#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::min;
using std::max;

int N, K, exact(0);
int barn_wall[1000][1000];

int main() {
    freopen("paintbarn.in","r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> N >> K;
    while (N--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        barn_wall[x1][y1]++;
        barn_wall[x1][y2]--;
        barn_wall[x2][y1]--;
        barn_wall[x2][y2]++;
    }
    for (int y = 0; y < 1000; y++) {
        for (int x = 0; x < 1000; x++) {
            if (y) barn_wall[y][x] += barn_wall[y - 1][x];
            if (x) barn_wall[y][x] += barn_wall[y][x - 1];
            if (x && y) barn_wall[y][x] -= barn_wall[y - 1][x - 1];
            if (barn_wall[y][x]==K) exact++;
        }

    }


    cout << exact << endl;
}
