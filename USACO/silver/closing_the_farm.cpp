/*
C++ SOLUTION

USACO 2016 US Open Contest, Silver
Problem 3. Closing the Farm
Link to problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=644

LESSONS LEARNED

- never index with maps if you can do it with vectors
since vectors' indexing is so much faster than that of 
map
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::fill;

int N, M, lowest_working = 0, count;
int const highest = 3001;
vector<vector<int> > connections(highest);
vector<bool> removed(highest), visited(highest);
vector<int> ord_removed;

void dfs(int key) {
    //basic depth-first search
    visited[key - 1] = true;
    count++;
    for (int index = 0; index < connections[key].size(); index++) {
        int element = connections[key][index];
        if (!visited[element - 1] && !removed[element-1]) {
            dfs(element);
        }
    }
}

string out() {
    //find the first element is not removed
    dfs(ord_removed[N-1]);

    if (count == N) return "YES";
    return "NO";
}

int main() {
   freopen("closing.in", "r", stdin);
   freopen("closing.out", "w", stdout);
    cin >> N >> M;

    //get inputs and add them to index (that acts like a dictionary)
    for (int m = 0; m < M; m++) {
        int c1, c2;
        cin >> c1 >> c2;
        connections[c1].push_back(c2);
        connections[c2].push_back(c1);
    }

    for (int n=0;n < N; n++) {
        //add the ordered elements
        int r; cin >> r;
        ord_removed.push_back(r);
        }

    //output whether the thing is fully connected or not
    for (int n = 0; n < N; n++) {
        count = n;
        fill(visited.begin(), visited.begin() + N, false);
        cout << out() << endl;

        removed[ord_removed[n] - 1] = true;
    }



}

