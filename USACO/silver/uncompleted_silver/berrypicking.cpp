/*
Solve Problem!!

Link to problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=990
*/

#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::greater;

int N, K;
vector<int> trees;

int main() {
    freopen("sample_input.in", "r", stdin);

    cin >> N >> K;
    trees.resize(N);
    for (int& tree:trees) {
        cin >> tree;
    }

    sort(trees.begin(), trees.end(), greater<int>());

   for (int tree:trees) {
    cout << tree << endl;
   }
    
}