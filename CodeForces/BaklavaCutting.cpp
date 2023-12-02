/*


Recommended Compile Command: 
clang++ -std=c++11 -stdlib=libc++ BaklavaCutting.cpp
*/


#include <iostream>
#include <math.h>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::pow;
using std::setprecision;


int main() {
    double L, K;
    cin >> L >> K;
    cout << setprecision(69)<< (L * L) / pow((double)2.0, K) << endl;
}
