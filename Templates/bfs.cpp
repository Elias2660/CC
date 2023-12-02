// A Quick implementation of BFS using
// vectors and queue
#include <vector>
#include <queue>
#include <iostream>
#define pb push_back
 
using namespace std;
 
vector<bool> v;
vector<vector<int> > g;
 
void edge(int a, int b)
{
    g[a].pb(b);
 
    // for undirected graph add this line
    // g[b].pb(a);
}
 
void bfs(int u)
{
    queue<int> q;
 
    q.push(u);
    v[u] = true;
 
    while (!q.empty()) {
 
        int f = q.front();
        q.pop();
 
        cout << f << " ";
 
        // Enqueue all adjacent of f and mark them visited 
        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}