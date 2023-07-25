/*


Recommended Compile Command: 
g++ -std=c++17 chessboard_and_queens.cpp 
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::find;
using std::remove;



long long combinations = 0;

vector<vector<char> > chessboard;
vector<int> cols = {0, 1, 2, 3, 4, 5, 6, 7}, d = {};

void find_combinations(int queens, int row, vector<int> cols_left, vector<int> diags, vector<int> cross_diags, vector<vector<char> > left_chessboard) {
   if (queens == 8) {
       combinations++;
       return;
   }
   for (int col:cols_left) {
    if (chessboard[row][col] != '*' &&
     !(find(diags.begin(), diags.end(), row - col) != diags.end()) &&
      !(find(cross_diags.begin(), cross_diags.end(),col + row) != cross_diags.end())) {
        vector<int> new_cross_diags = cross_diags, new_diags = diags, new_cols_left = cols_left;
        vector<vector<char> > new_chessboard = left_chessboard;
        new_chessboard[row][col] = 'Q';
        new_diags.push_back(row - col);
        new_cross_diags.push_back(col + row);
        new_cols_left.erase(remove(new_cols_left.begin(), new_cols_left.end(), col), new_cols_left.end());
        find_combinations(queens+1, row +1, new_cols_left, new_diags, new_cross_diags, new_chessboard);
      }
    }
}


void get_chessboard_values() {
        for (int i = 0; i < 8; i++) {
        string row;
        cin >> row; 
        vector<char> r;
        for (char const& c: row) {
            r.push_back(c);

        }
        chessboard.push_back(r);
    }
}


int main() {
    // freopen("in", "r", stdin);
    get_chessboard_values();
    find_combinations(0, 0, cols, d, d, chessboard);
    cout << combinations << endl;
}