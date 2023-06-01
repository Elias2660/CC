/*
Sum of Four Values

Link to problem:
https://cses.fi/problemset/task/1642

Recommended Compile Command: 
g++ -std=c++17 sum_of_four_values.cpp 

*/



#include <iostream>
#include <vector>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;


int const MAX_N = 1001;
map<int, vector<int > > pos;
vector<int> left, right;
int N, X;

int main() {
    cin >> N >> X;
    for (int l = 0; l < floor(N/2); l++) {
        int i; cin >> i;
        left.push_back(i);
        pos[i].push_back(l);
    }
    for (int l = floor(N/2); l < N; l++)

}