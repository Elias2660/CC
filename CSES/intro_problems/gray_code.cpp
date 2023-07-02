/*


Recommended Compile Command: 
g++ -std=c++17 gray_code.cpp 
*/


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pow;
using std::vector;
using std::reverse;

int N, total_number, step_size;
vector<string> nums, footprint;





int main() {
    cin >> N;
    total_number = pow(2, N);
    //first layer
    nums.resize(total_number/2, "0");
    nums.resize(total_number, "1");
    for (int l = N - 1; l > 0; l--) {
        // for each other layer, iterate and add stuff
        step_size = pow(2, l);
        footprint = {"0", "1"};
        for (int step = 0; step < total_number; step += step_size) {
            for (int i = step; i < step + (step_size/2); i++) {
                nums[i] += footprint[0];
            }
            for (int i = step + (step_size/2); i < step + step_size; i++) {
                nums[i] += footprint[1];
            }
            reverse(footprint.begin(), footprint.end());
        }
    }
    for (string item:nums) {
        cout << item << endl;
    }
}

