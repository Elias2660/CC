/*
Recommended Compile Command: 
g++ -std=c++17 digit_queries.cpp 
*/


#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::string;

int Q; 

int main() {
    freopen("in", "r", stdin);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        double K;
        cin >> K;
        K--;
        double digs = 0, space_taken = 0;
        //find the decimal place that the locs go above
        if (K > 9) {
            while (K > (digs + 1) * 9 * pow(10, digs) + space_taken) {
                digs ++;
                space_taken += digs * 9 * pow(10, digs - 1);
            } 
        }       
        //for the locs left, find the specific number that it relates to
        double lastTakenNum = pow(10, digs) - 1;
        double numbersAbove = floor((K - space_taken)/(digs + 1)); 
        string num = to_string(lastTakenNum + numbersAbove + 1);
        
        double index = fmod((K - space_taken), (digs + 1));
        cout <<  index << ":" << num  << " : " << fmod(K - space_taken, 10)  << " : " << K  << " : " << space_taken<< endl;
    }
}
