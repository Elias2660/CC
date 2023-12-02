/*


Recommended Compile Command: 
clang++ -std=c++11 -stdlib=libc++ Part1.cpp
*/

#include "../../bits-stdc++.h"
#include <iostream>
#include <string>
#include <ctype.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {
    string a;
    int count = 0;
    freopen("test.txt", "r", stdin);
    while(!cin.eof()) {
        cin >> a;
        int num = 0;
        for (int i = 0; i < a.size(); i++) {
            if (isdigit(a[i])) {
                // cout << a[i] << endl;
                num += (char) a[i] - '0';
                break;
            }
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            if (isdigit(a[i])) {
                num *= 10;
                num += (char) a[i] - '0';
                break;
            }
        }
        count += num;
    }
    cout << count << endl;

}
