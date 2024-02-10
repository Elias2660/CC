/*
Link to problem:
https://cses.fi/problemset/task/1628

TODO: Ask on CCC for help
g++ -std=c++17 meet_in_the_middle.cpp 

*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::floor;
using std::string;
using std::sort;
using std::lower_bound;
using std::upper_bound;

long long N, X, total_number = 0;
vector<long long> left, right,left_subarray_sums, right_subarray_sums;


//use a recoursive strategy to solve the problem, but one could also use bitwise operators
void find_subarray_sums(vector<long long> arr, long long sum, long long index, long long stop, string side) {
    //find subarray sums using recoursion 
    if (index == stop) {
        if (side == "left") {
                left_subarray_sums.push_back(sum);
        }
        if (side == "right") {
                right_subarray_sums.push_back(sum);
        }
        return;

        }
    else {
        if (sum+arr[index] <= X) {
            find_subarray_sums(arr, sum + arr[index], index +1, stop, side);
        }
        find_subarray_sums(arr, sum, index+1, stop, side);    
    }

}



int main() {
    //freopen("sample_input.in", "r", stdin);
    cin >> N >> X;
    //get inputs, split into left and right parts of the array
    left.resize(floor(N/2));
    right.resize(N - floor(N/2));
    for (long long& item:left) {
        cin >> item;
    }
    for (long long & item:right) {
        cin >> item;
    }
    //using the left array, find the subarray sums for those values
    find_subarray_sums(left, 0, 0,floor(N/2), "left");
    find_subarray_sums(right, 0, 0,N-floor(N/2), "right");
    sort(left_subarray_sums.begin(), left_subarray_sums.end());
    sort(right_subarray_sums.begin(), right_subarray_sums.end());

    for (int const& item:left_subarray_sums) {
        auto lower = lower_bound(right_subarray_sums.begin(), right_subarray_sums.end(), X - item);
        auto upper = upper_bound(right_subarray_sums.begin(), right_subarray_sums.end(), X - item);
        int start_index = lower - right_subarray_sums.begin(), end_index = upper - right_subarray_sums.begin();
        total_number += end_index - start_index;
    }

    cout << total_number << endl;
}
