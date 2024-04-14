

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
int N, M;

int main() {
    cin.tie(0);
    // freopen("in", "r", stdin);
    cin >>  N >> M;
    vector<int> walk = vector<int>(N);
    for (int i = 0; i < M; i ++) {
        int en; int ex;
        cin >> en >> ex;
        walk[en]++;
        walk[ex]--;
    }
    int num = 0; 
    int f = 0;
    for (int value: walk) {
        int prev = num;
        num += value;
        if (num == 0) {
            f++;
        }
    }
    cout << f << endl;
}