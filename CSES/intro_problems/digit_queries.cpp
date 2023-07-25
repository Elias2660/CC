/*
Recommended Compile Command: 
g++ -std=c++17 digit_queries.cpp 
*/


#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

long long max_d = 1e18;
int Q;


int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int number;
        cin >> number;

        int digs = 1, total_space_taken = 0;
        while (number > total_space_taken) {
            total_space_taken = (digs * 10 - digs)*digs;
            digs ++;
            
        }    
    }
}
