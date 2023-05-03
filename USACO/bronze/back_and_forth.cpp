/*
C++ SOLUTION


USACO 2018 December Contest, Bronze
Problem 3. Back and Forth

Link to Problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=857
*/

#include <algorithm>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::string;
using std::vector;
using std::back_inserter;

set<int> possible;

void get_possible(int tank1, int tank2, vector<int> b1, vector<int> b2, int day) {
    //recursively get the number of buckets

    if (day==4) {
        possible.insert(tank1);
    }
    else {
        for (int i = 0; i < b1.size(); i++) {
            //recursivly do all transfers from b1 to b2
            int num = b1[i];

            //create new vectors to transfer
            vector<int> new_b1 = b1;
            vector<int> new_b2 = b2;
            //transfer
            new_b1.erase(begin(new_b1) + i);
            new_b2.push_back(num);

            //recursizely call
            get_possible(tank2 + num, tank1 - num, new_b2, new_b1, day + 1);
        }  
    }
 
}


int main()
{
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out","w", stdout);
    vector<int> a(10);
    vector<int> b(10);
    for (int& i:a) {
       cin >> i;
    }
    for (int& i:b) {
        cin >> i;
    }

    get_possible(1000, 1000, a, b, 0);
    cout << possible.size() << endl;
}