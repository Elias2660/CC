/*


Recommended Compile Command:
clang++ -std=c++11 -stdlib=libc++ starter.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::reverse;
int N, R, Q;

int main() { 
    //  freopen("in", "r", stdin);
    cin >> N >> R >> Q;
    vector<vector<int>> RLI; 
    for (int i = 0; i < R; i++) {
        vector<int> n;
        int a, b;
        cin >> a >> b;
        n.push_back(a);
        n.push_back(b);
        RLI.push_back(n);
    }
    reverse(RLI.begin(), RLI.end());
    
    vector<int> QLI; 
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        QLI.push_back(a);
    }
    for(int G: QLI) {
        for(vector<int> r: RLI) {
            if(G >= r[0] && G <= r[1]) {
                G = r[0] + r[1] - G;
            }
        }
        cout << G << endl;
    }
}