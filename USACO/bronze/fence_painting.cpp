/*
C++ SOLUTION


USACO 2015 December Contest, Bronze
Problem 1. Fence Painting
Link to problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=567
*/


#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;
using std::min;

int min_john, max_john, min_cow, max_cow;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    cin >> min_john >> max_john;
    cin >> min_cow >> max_cow;

    if ((max_cow >= min_john && min_cow <= min_john) || (max_john >= min_cow && min_john <= min_cow)) {
        cout << max(max_cow, max_john) - min(min_cow, min_john) << endl;
    }
    else {
        cout << (max_cow - min_cow) + (max_john - min_john);
    }
    
}