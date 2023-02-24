/*
USACO 2016 January Contest, Bronze
Problem 2. Angry Cows

Link to Problem: 
http://www.usaco.org/index.php?page=viewproblem2&cpid=592

*/



#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::copy;
using std::vector;
using std::max;


int n;
vector<int> blocs;



int number_destroyed  (int cow_loc, int direction) {

    int blast_radius = 1;
    int before = cow_loc;

    //foward direction
    while (true) {
        int next = before;
        //find the furthest out haybale that explodes
        while (
            next + direction >= 0
            && next + direction < n
            && abs(blocs[next + direction] - blocs[before]) <= blast_radius) 
            {next += direction;}

        if (next==before) {
            break;
        }

        before = next;
        blast_radius++;
    }
    return abs(before - cow_loc);

}

int main()
{
    //uncomment to submit
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    
    //get the stuff
    cin >> n;
    blocs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> blocs[i];
    }

    sort(blocs.begin(), blocs.end());

    int highest_destroyed = 0;

    for (int f = 0;f <= n; f++) {
        //for each location, count the number destroyed
        //compare with current highest
        int x = number_destroyed(f, -1) + 1 + number_destroyed(f, 1);
        highest_destroyed = max(highest_destroyed, x);

    }

    cout << highest_destroyed << endl;

}