/*


Recommended Compile Command: 
clang++ -std=c++11 -stdlib=libc++ Part1.cpp
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <ctype.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void replaceAll(string& str, const string& from, const string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main() {
    string a;
    int count = 0;
    freopen("test.txt", "r", stdin);
    while(!cin.eof()) {
        cin >> a;
        replaceAll(a, "one", "o1e");
        replaceAll(a, "two", "t2o");
        replaceAll(a, "three", "t3ree");
        replaceAll(a, "four", "f4or");
        replaceAll(a, "five", "f5ive");
        replaceAll(a, "six", "s6x");
        replaceAll(a, "seven", "se7en");
        replaceAll(a, "eight", "ei8ht");
        replaceAll(a, "nine", "n9ne");
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

