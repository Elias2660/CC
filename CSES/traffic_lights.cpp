/*
CSES Problem Set
Traffic Lights

https://cses.fi/problemset/task/1163


clang++ -std=c++11 -stdlib=libc++ traffic_lights.cpp
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <quene>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::priority_quene;
int X, N, max = 0, last;
priority_quene<int> traffic;

int main() {
    cin >> X >> N;
    freopen("in", "r", stdin);
    for (int i =0; i<N; i++) {
        int n; cin  >> n;
        traffic.push(n);
        int last = X;
        for (auto light:traffic) {
            int distance = X - light;
            if 
        }
    }

}
