/*
Recommended Compile Command: 
g++ -std=c++17 starter.cpp 
*/


#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

string sequence;
char last_letter;
int cur, longest;

int main() {
    //freopen("sample_input.in", "r", stdin);
    cin >> sequence;

    cur = 1; longest = 1; last_letter = sequence[0];
    for (int n = 1; n < sequence.length(); n++){
        char cur_letter = sequence[n];
        if (cur_letter  != last_letter) {
            cur = 0;
            last_letter = cur_letter;
        }
        cur++;
        longest = max(cur, longest);
    }
    cout << longest << endl;
}
