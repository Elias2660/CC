/*


Recommended Compile Command:
clang++ -std=c++11 -stdlib=libc++ starter.cpp
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() { return 0;     vector<vector<int>> RLI; 
    for (int i = 0; i < R; i++) {
        vector<int> n;
        int a, int b;
        cin >> a >> b;
        n.push_back(a);
        n.push_back(b);
        RLI.push_back(n);
    }
    vector<int> QLI; 
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        QLI.push_back(a);
    }
    for(int G: QLI) {
        for(vector<int> r: RLI) {
            
        }
    }
}