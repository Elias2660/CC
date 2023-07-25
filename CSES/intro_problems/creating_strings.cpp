/*
Recommended Compile Command: 
g++ -std=c++17 creating_strings.cpp 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::vector;
using std::map;

string letters;
vector<char> opts; vector<string> strings;
map<char, int> letterFrequency;


void createSubstrings(map<char, int> frequencyLeft, int letters_left, string substring) {
    if (letters_left == 0) {
        strings.push_back(substring);
    }
    else {
        for (char opt:opts) {
            if (frequencyLeft[opt] > 0) {
                map<char, int> nf = frequencyLeft;
                nf[opt] --;
                createSubstrings(nf, letters_left-1, substring + opt);
            }
        }
    }
}

int main() {
    cin >> letters;
    sort(letters.begin(), letters.end());
    for (int i = 0; i < letters.length(); i++) {
        if (!(i < letters.length() - 1) || !(letters[i] == letters[i+1])) {
            opts.push_back(letters[i]);
        }
        letterFrequency[letters[i]] += 1;
    }


    createSubstrings(letterFrequency, letters.length(), "");

    cout << strings.size() << endl;
    for (string substring:strings) {
        cout << substring << endl;
    }
}