/*
C++ SOLUTION

Ferris Wheel
Recommended Compile Command: 
g++ -std=c++17 ferris_wheel.cpp 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int N, X,count;
vector<int> passengers;

int main() {
    cin >> N >> X;
    passengers.resize(N);
    for (int& passenger:passengers) {
        cin >> passenger;
    }
    sort(passengers.begin(), passengers.end());

    int highest_index = N - 1, lowest_index = 0;

    while(highest_index != lowest_index &&  lowest_index - highest_index != 1) {
        if (passengers[highest_index] + passengers[lowest_index] <= X) {
            count += 1;
            highest_index--; lowest_index++;
        }
        else {
            count++;
            highest_index--;
        }
    }
    count += highest_index == lowest_index? 1:0;
    cout << count << endl;
}
