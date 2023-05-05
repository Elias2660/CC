/*
Recommended Compile Command: 
g++ -std=c++17 robotz.cpp 
*/
#include <iostream>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::floor;

int N;
vector<int> left_x, right_x, left_y, right_y;


void find_different_directions()

int main() {
    cin >> N;
    for (int _ = 0; _ < floor(N/2); _++) {
        int x, y; cin >> x >> y;
        left_x.push_back(x); left_y.push_back(y);

    }
    for (int _ = 0; _ < floor(N/2); _++) {
        int x, y; cin >> x >> y;
        right_x.push_back(x); right_y.push_back(y);
    }

    
}