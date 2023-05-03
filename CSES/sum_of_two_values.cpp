/*
Sum of Two Values
Link to problem:
https://cses.fi/problemset/task/1640 

Recommended Compile Command: 
g++ -std=c++17 sum_of_two_values.cpp 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::map;
using std::pair;

int N, X;
vector<int> nums;
map<int, vector<int> > num_positions;

int main() {
    //freopen("1.in", "r", stdin);
    cin >> N >> X;
    nums.resize(N);
    int index = 0;
    for (int& num:nums) {
        cin >> num;
        if (num_positions.count(num) == 0) {
            num_positions.insert(pair<int, vector<int> >(num, vector<int>()));
        }
        num_positions[num].push_back(index);
        index ++;
    }

    sort(nums.begin(), nums.end());

    int min_index = 0, max_index = N - 1;


    if (max_index == min_index) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
        }


    while (nums[min_index] + nums[max_index] != X) {
        //use two pointer solution
        if (nums[min_index] + nums[max_index] > X) {
            max_index--;
        }
        else {
            min_index++;
        }
        if (max_index <= min_index && nums.size() != 1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        }



    if (nums[min_index] == nums[max_index]) {
        //another edge case
        cout << num_positions[nums[min_index]][0] + 1 << " " <<  num_positions[nums[max_index]][1] + 1 << endl;
        return 0;
    }
    cout << num_positions[nums[min_index]][0] + 1 << " " << num_positions[nums[max_index]][0] + 1 << endl;
}