#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;


int find_next_not_equal(vector<int> asleep, int length) {
    int num = asleep[length - 1];
    for (int index = asleep.size() -2; index >= 0; index--) {
        if (asleep[index] != num) {
            return index;
        }
    }
    return 0;
}

int find_modifications(vector<int> asleep, int N){
    int length(N), modifications(0);
    
    sort(asleep.begin(), asleep.end());

    while (asleep[0] < asleep[length-1]) {
        if (asleep.size() == 1) {
        return modifications;
        }
        int not_equal_index = find_next_not_equal(asleep, length);
        if (asleep[0] + asleep[not_equal_index] > asleep[length-1]) {
            asleep.push_back(asleep[0] + asleep[not_equal_index]);
            asleep.erase(asleep.begin()); asleep.erase(asleep.begin() + not_equal_index);
            modifications++;
            length--;
            continue;
        }

        if (asleep[0] + asleep[not_equal_index] <= asleep[length-1]) {
            asleep[not_equal_index] += asleep[0];
            asleep.erase(asleep.begin());
            modifications++;
            length--;
            continue;
        }
    }
    return modifications;
}


int T;

int main() {
    //freopen("paint.in", "r", stdin);
    cin >> T;
    while (T--) {
        int N;
        vector<int> asleep;

        cin >> N;
        asleep.resize(N);
        for (int& section:asleep) {
            cin >> section;
        }

        cout << find_modifications(asleep, N) << endl;
    }
}