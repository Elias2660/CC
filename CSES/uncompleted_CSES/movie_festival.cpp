/*
Recommended Compile Command: 
g++ -std=c++17 movie_festival.cpp 
*/


#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;


int N;
vector<vector<int> > movie_list;

int main() {
    freopen("sample_input.in", "r", stdin);
    cin >> N;
    for (int n = 0; n < N; n++) {
        int begin, end; cin >> begin >> end;
        vector<int> add{begin, end};
        movie_list.push_back(add);
    }
    //sorting by last 
    auto sort_struct = [] (const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    };
    sort(movie_list.rbegin(), movie_list.rend(), [] (const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    });

    int cur_num = 0, total = 0;
    for (vector<int> const& movie:movie_list) {
        if (movie[0] >= cur_num) {
            cur_num = movie[1];
            total++;
        }
    }
    cout << total << endl;

}