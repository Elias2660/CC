#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;

int pasture[1002][1002], N;

void check_neighbors(int row, int column) {
    if (pasture[row][column] != 0) {
        if (pasture[row + 1][column]) {pasture[row][column]++;};
        if (pasture[row - 1][column]) {pasture[row][column]++;};
        if (pasture[row ][column + 1]) {pasture[row][column]++;};
        if (pasture[row ][column - 1]) {pasture[row][column]++;};
    }
}



int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int row, column;
        cin >> row >> column;
        pasture[row][column] = 1;
    }}