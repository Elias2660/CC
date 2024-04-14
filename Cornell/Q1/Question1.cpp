/*


Recommended Compile Command:
clang++ -std=c++11 -stdlib=libc++ starter.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
vector<int> nums = vector<int>(9);

int main() { 
    // freopen("in", "r", stdin);
    for (int& obj: nums) {
        int n;
        cin >> n;
        obj = n;
    }
    sort(nums.begin(), nums.end());
    bool flag = true;

    for (int i = 1; i < 9; i++) {
        if (nums[i] - 1 != nums[i-1]) {
            flag = false;
        }
    }

    if (nums[0] != 1 || flag == false) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
 }